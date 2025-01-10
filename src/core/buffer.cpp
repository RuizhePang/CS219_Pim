#include "buffer.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

namespace Pim
{
    Buffer::Buffer() {}

    Buffer::~Buffer() {}

    void Buffer::insertChar(size_t row, size_t col, char ch)
    {
        if (row < m_lines.size())
        {
            m_lines[row].insert(col, 1, ch);
        }
    }

    void Buffer::deleteChar(size_t row, size_t col)
    {
        if (row < m_lines.size() && col < m_lines[row].size())
        {
            m_lines[row].erase(col, 1);
        }
    }

    void Buffer::insertNewLine(size_t row)
    {
        if (row < m_lines.size())
        {
            m_lines.insert(m_lines.begin() + row, "");
        }
        else
        {
            m_lines.push_back("");
        }
    }

    void Buffer::deleteLine(size_t row)
    {
        if (row < m_lines.size())
        {
            m_lines.erase(m_lines.begin() + row);
        }
    }

    void Buffer::loadFromFile(const std::string &filename)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            throw std::runtime_error("Cannot open file for reading: " + filename);
        }

        m_lines.clear();
        std::string line;
        while (std::getline(file, line))
        {
            m_lines.push_back(line);
        }

        if (m_lines.empty())
        {
            m_lines.push_back("");
        }
    }

    void Buffer::saveToFile(const std::string &filename) const
    {
        std::ofstream file(filename);
        if (!file.is_open())
        {
            throw std::runtime_error("Cannot open file for writing: " + filename);
        }

        for (const auto &line : m_lines)
        {
            file << line << std::endl;
        }
    }

    void Buffer::saveSnapshot(size_t cursorLine, size_t cursorColumn)
    {
        undoStack.push({m_lines, cursorLine, cursorColumn});
    }

    void Buffer::setClipboard(const std::string context)
    {
        clipboard = context;
    }

    std::string Buffer::getClipboard()
    {
        return clipboard;
    }

    Snapshot Buffer::undo(size_t cursorLine, size_t cursorColumn)
    {
        if (!undoStack.empty())
        {
            Snapshot snapshot = undoStack.top();
            redoStack.push(snapshot);
            undoStack.pop();
            m_lines = snapshot.lines;
            return snapshot;
        }
        return {m_lines, cursorLine, cursorColumn};
    }

    Snapshot Buffer::redo(size_t cursorLine, size_t cursorColumn)
    {
        if (!redoStack.empty())
        {
            Snapshot snapshot = redoStack.top();
            undoStack.push(snapshot);
            redoStack.pop();
            m_lines = snapshot.lines;
            return snapshot;
        }
        return {m_lines, cursorLine, cursorColumn};
    }
}