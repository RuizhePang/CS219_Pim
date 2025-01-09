#ifndef BUFFER_H_
#define BUFFER_H_

#include <string>
#include <vector>
#include <stack>

namespace Pim
{
    struct Snapshot
    {
        std::vector<std::string> lines;
        size_t cursorLine;
        size_t cursorColumn;
    }

    class Buffer
    {
    private:
        std::vector<std::string> m_lines;
        std::stack<Snapshot> undoStack;
        std::stack<Snapshot> redoStack;
    public:
        Buffer();
        ~Buffer();

        void insertChar(size_t row, size_t col, char ch);
        void deleteChar(size_t row, size_t col);
        void insertNewLine(size_t row);
        void deleteLine(size_t row);
        void loadFromFile(const std::string &filename);
        void saveToFile(const std::string &filename) const;
        void saveSnapshot(size_t cursorLine, size_t cursorColumn);
        Snapshot undo();

        const std::vector<std::string> &getLines() const { return m_lines; }
        void setLines(const std::vector<std::string> &lines) { m_lines = lines; }
    };
}

#endif