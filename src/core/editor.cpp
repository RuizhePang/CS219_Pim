#include <ncurses.h>

#include <fstream>
#include <iostream>
#include <stdexcept>

#include "editor.h"
#include "buffer.h"

namespace Pim
{
  Editor::Editor(const std::string &filename) : m_filename(filename)
  {
    if (!filename.empty())
    {
      m_buffer.loadFromFile(filename);
    }
    else
    {
      m_buffer.insertNewLine(0);
    }

    m_buffer.saveSnapshot(m_currentLine, m_currentColumn, m_startLine, m_startColumn);

    initScreen();
  }

  Editor::~Editor() { endwin(); }

  void Editor::initScreen()
  {
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    scrollok(stdscr, true);

    if (has_colors() == FALSE)
    {
      endwin();
      throw std::runtime_error("Your terminal does not support color");
    }
    refresh();
  }

  void Editor::run()
  {
    std::string cmd;
    while (true)
    {
      drawStatusLine();
      drawContent();

      raw();
      doupdate();

      int ch = getch();

      if (m_isCommandMode)
      {
        switch (ch)
        {
        case 18:
          cmd = "CTRL_R";
          break;
        case KEY_LEFT:
          cmd = "KEY_LEFT";
          break;
        case KEY_RIGHT:
          cmd = "KEY_RIGHT";
          break;
        case KEY_UP:
          cmd = "KEY_UP";
          break;
        case KEY_DOWN:
          cmd = "KEY_DOWN";
          break;
        default:
          cmd += ch;
          break;
        }
        commandMode(cmd);
      }
      else
      {
        insertMode(ch);
      }
      refresh();
    }
  }

  void Editor::drawContent()
  {

    for (size_t i = m_startLine; i < static_cast<size_t>(m_startLine + LINES - 2); i++)
    {
      std::string line;
      if (i < m_buffer.getLines().size() && m_buffer.getLines()[i].size() >= m_startColumn)
        line = m_buffer.getLines()[i].substr(m_startColumn, COLS - 1);
      else
        line = "";
      mvprintw(i - m_startLine, 0, "%s", line.c_str());
      clrtoeol();
    }
    move(m_currentLine - m_startLine, m_currentColumn - m_startColumn);
  }

  void Editor::drawStatusLine()
  {
    mvprintw(LINES - 2, 0, "%s %s %s", m_filename.empty() ? "[No Name]" : m_filename.c_str(), std::to_string(m_currentLine).c_str(), std::to_string(m_startColumn).c_str());
    mvprintw(LINES - 1, 0, "%s", m_isCommandMode ? "" : "-- INSERT --");
    clrtoeol();
  }

  void Editor::commandMode(std::string &cmd)
  {
    std::string temp = cmd;
    cmd = "";
    if (temp == "i")
    {
      m_isCommandMode = false;
    }
    if (temp == "h" || temp == "KEY_LEFT")
    {
      if (m_currentColumn > 0 && m_currentColumn == m_startColumn)
      {
        if (m_startColumn > static_cast<size_t>(COLS / 2))
          m_startColumn -= COLS / 2;
        else
          m_startColumn = 0;
      }
      if (m_currentColumn > 0)
        m_currentColumn--;
    }
    if (temp == "l" || temp == "KEY_RIGHT")
    {
      if (m_currentColumn - m_startColumn == static_cast<size_t>(COLS - 2))
        m_startColumn += COLS / 2;
      if (m_buffer.getLines()[m_currentLine].size() != 0 && m_currentColumn < m_buffer.getLines()[m_currentLine].size() - 1)
        m_currentColumn++;
    }
    if (temp == "j" || temp == "KEY_DOWN")
    {
      if (m_currentLine - m_startLine + 10 == static_cast<size_t>(LINES - 2) && m_currentLine + 10 < m_buffer.getLines().size())
        m_startLine++;

      if (m_currentLine < m_buffer.getLines().size() - 1)
        m_currentLine++;
      m_currentColumn = (m_buffer.getLines()[m_currentLine].empty()) ? 0 : std::min(m_currentColumn, m_buffer.getLines()[m_currentLine].size() - 1);
    }
    if (temp == "k" || temp == "KEY_UP")
    {
      if (m_currentLine - m_startLine == 10 && m_startLine != 0)
        m_startLine--;

      if (m_currentLine > 0)
        m_currentLine--;
      m_currentColumn = (m_buffer.getLines()[m_currentLine].empty()) ? 0 : std::min(m_currentColumn, m_buffer.getLines()[m_currentLine].size() - 1);
    }
    if (temp == "0")
    {
      m_startColumn = 0;
      m_currentColumn = 0;
    }
    if (temp == "$")
    {
      m_currentColumn = m_buffer.getLines()[m_currentLine].size();
      if (m_currentColumn > static_cast<size_t>(COLS - 1))
        m_startColumn = m_currentColumn - COLS / 2;

      if (m_currentColumn > 0 && m_currentColumn == m_startColumn)
      {
        if (m_startColumn > static_cast<size_t>(COLS / 2))
          m_startColumn -= COLS / 2;
        else
          m_startColumn = 0;
      }
      if (m_currentColumn > 0)
        m_currentColumn--;
    }
    if (temp == "g")
    {
      cmd = temp;
    }
    if (temp == "gg")
    {
      m_startLine = 0;
      m_startColumn = 0;

      m_currentLine = 0;
      m_currentColumn = 0;
    }
    if (temp == "G")
    {
      m_currentLine = m_buffer.getLines().size();
      m_currentColumn = 0;

      if (m_currentLine > static_cast<size_t>(LINES - 2))
        m_startLine = m_currentLine - LINES + 2;
      else
        m_startLine = 0;
      m_startColumn = 0;
    }
    if (temp == "d")
    {
      cmd = temp;
    }
    if (temp == "dd")
    {
      m_buffer.getLines().erase(m_buffer.getLines().begin() + m_currentLine);
      m_currentColumn = 0;

      if (m_currentLine >= m_buffer.getLines().size())
      {
        if (m_currentLine - m_startLine == 10 && m_startLine != 0)
          m_startLine--;

        if (m_currentLine > 0)
          m_currentLine--;
      }
      if (m_buffer.getLines().size() == 0)
        m_buffer.insertNewLine(0);
      m_startColumn = 0;

      m_buffer.saveSnapshot(m_currentLine, m_currentColumn, m_startLine, m_startColumn);
    }
    if (temp == "y")
    {
      cmd = temp;
    }
    if (temp == "yy")
    {
      std::string context = m_buffer.getLines()[m_currentLine];
      m_buffer.setClipboard(context);
    }
    if (temp == "p")
    {
      std::string context = m_buffer.getClipboard();
      if (m_currentLine - m_startLine == static_cast<size_t>(LINES - 3))
        m_startLine++;
      m_startColumn = 0;

      m_buffer.insertNewLine(m_currentLine + 1);
      m_buffer.getLines()[m_currentLine + 1] = context;
      m_currentLine++;
      m_currentColumn = 0;

      m_buffer.saveSnapshot(m_currentLine, m_currentColumn, m_startLine, m_startColumn);
    }
    if (temp == "u")
    {
      Snapshot snapshot = m_buffer.undo(m_currentLine, m_currentColumn, m_startLine, m_startColumn);
      m_buffer.getLines() = snapshot.lines;
      m_currentLine = snapshot.cursorLine;
      m_currentColumn = snapshot.cursorColumn;
      m_startLine = snapshot.startLine;
      m_startColumn = snapshot.startColumn;
    }
    if (temp == "CTRL_R")
    {
      Snapshot snapshot = m_buffer.redo(m_currentLine, m_currentColumn, m_startLine, m_startColumn);
      m_buffer.getLines() = snapshot.lines;
      m_currentLine = snapshot.cursorLine;
      m_currentColumn = snapshot.cursorColumn;
      m_startLine = snapshot.startLine;
      m_startColumn = snapshot.startColumn;
    }
    if (temp == ":")
    {
      {
        mvprintw(LINES - 1, 0, ":");
        refresh();

        std::string command;
        int cmdCh;
        while ((cmdCh = getch()) != '\n')
        {
          if (cmdCh == KEY_BACKSPACE)
          {
            move(LINES - 1, command.size());
            command.pop_back();
            delch();
          }
          else
          {
            command += cmdCh;
            addch(cmdCh);
          }
        }

        if (command == "q")
        {
          endwin();
          exit(0);
        }
        if (command == "w" && !m_filename.empty())
        {
          m_buffer.saveToFile(m_filename);
        }
        if (command == "wq" && !m_filename.empty())
        {
          m_buffer.saveToFile(m_filename);
          endwin();
          exit(0);
        }
      }
    }
  }

  void Editor::insertMode(int ch)
  {
    switch (ch)
    {
    // ESC
    case 27:
      if (m_isCommandMode == true)
        return;
      m_isCommandMode = true;
      if (m_currentColumn > 0 && m_currentColumn == m_startColumn)
      {
        if (m_startColumn > static_cast<size_t>(COLS / 2))
          m_startColumn -= COLS / 2;
        else
          m_startColumn = 0;
      }
      if (m_currentColumn > 0)
        m_currentColumn--;
      m_buffer.saveSnapshot(m_currentLine, m_currentColumn, m_startLine, m_startColumn);
      break;
    // Enter
    case 10:
      if (m_currentLine - m_startLine == static_cast<size_t>(LINES - 3))
        m_startLine++;
      m_startColumn = 0;

      m_buffer.insertNewLine(m_currentLine + 1);
      m_buffer.getLines()[m_currentLine + 1] = m_buffer.getLines()[m_currentLine].substr(m_currentColumn);
      m_buffer.getLines()[m_currentLine] = m_buffer.getLines()[m_currentLine].substr(0, m_currentColumn);
      m_currentLine++;
      m_currentColumn = 0;
      break;
    case KEY_BACKSPACE:
      if (m_currentColumn > 0)
      {
        if (m_currentColumn == m_startColumn)
        {
          if (m_startColumn > static_cast<size_t>(COLS / 2))
            m_startColumn -= COLS / 2;
          else
            m_startColumn = 0;
        }
        m_buffer.deleteChar(m_currentLine, m_currentColumn - 1);
        m_currentColumn--;
      }
      else if (m_currentLine > 0)
      {
        if (m_currentLine == m_startLine + 10 && m_startLine != 0)
          m_startLine--;
        m_buffer.deleteLine(m_currentLine);
        m_currentLine--;
        m_currentColumn = m_buffer.getLines()[m_currentLine].size();
        if (m_currentColumn > m_startColumn + COLS)
          m_startColumn = m_currentColumn - COLS;
      }
      break;
    // Tab
    case 9:
      for (int i = 0; i < 4; i++)
      {
        if (m_currentColumn - m_startColumn == static_cast<size_t>(COLS - 2))
          m_startColumn += COLS / 2;
        m_buffer.insertChar(m_currentLine, m_currentColumn, ' ');
        m_currentColumn++;
      }
      break;
    case KEY_LEFT:
      if (m_currentColumn > 0 && m_currentColumn == m_startColumn)
      {
        if (m_startColumn > static_cast<size_t>(COLS / 2))
          m_startColumn -= COLS / 2;
        else
          m_startColumn = 0;
      }
      if (m_currentColumn > 0)
        m_currentColumn--;
      break;
    case KEY_RIGHT:
      if (m_currentColumn - m_startColumn == static_cast<size_t>(COLS - 2))
        m_startColumn += COLS / 2;
      if (m_buffer.getLines()[m_currentLine].size() != 0 && m_currentColumn < m_buffer.getLines()[m_currentLine].size() - 1)
        m_currentColumn++;
      break;
    case KEY_DOWN:
      if (m_currentLine - m_startLine + 10 == static_cast<size_t>(LINES - 2) && m_currentLine + 10 < m_buffer.getLines().size())
        m_startLine++;

      if (m_currentLine < m_buffer.getLines().size() - 1)
        m_currentLine++;
      m_currentColumn = (m_buffer.getLines()[m_currentLine].empty()) ? 0 : std::min(m_currentColumn, m_buffer.getLines()[m_currentLine].size() - 1);
      break;
    case KEY_UP:
      if (m_currentLine - m_startLine == 10 && m_startLine != 0)
        m_startLine--;

      if (m_currentLine > 0)
        m_currentLine--;
      m_currentColumn = (m_buffer.getLines()[m_currentLine].empty()) ? 0 : std::min(m_currentColumn, m_buffer.getLines()[m_currentLine].size() - 1);
      break;
    default:
      if (ch >= 32 && ch <= 126)
      {
        if (m_currentColumn - m_startColumn == static_cast<size_t>(COLS - 2))
          m_startColumn += COLS / 2;
        m_buffer.insertChar(m_currentLine, m_currentColumn, static_cast<char>(ch));
        m_currentColumn++;
      }
      break;
    }
    move(m_currentLine, m_currentColumn);
  }

} // namespace Pim
