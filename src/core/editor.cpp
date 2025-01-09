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
    while (true)
    {
      drawStatusLine();
      drawContent();

      raw();
      doupdate();

      int ch = getch();

      if (m_isCommandMode)
      {
        commandMode(ch);
      }
      else
      {
        insertMode(ch);
      }
    }
  }

  void Editor::drawContent()
  {

    for (size_t i = m_startLine; i < m_buffer.getLines().size() /*&& i < static_cast<size_t>(m_startLine + LINES - 2)*/; i++)
    {
      std::string line = m_buffer.getLines()[i]/*.substr(m_startColumn, COLS - 1)*/;
      mvprintw(i - m_startLine, 0, "%s", line.c_str());
    }
    move(m_currentLine - m_startLine, m_currentColumn - m_startColumn);
  }

  void Editor::drawStatusLine()
  {
    mvprintw(LINES - 2, 0, "%s %s %s", m_filename.empty() ? "[No Name]" : m_filename.c_str(), std::to_string(m_currentColumn).c_str(), std::to_string(m_startColumn).c_str());
    mvprintw(LINES - 1, 0, "%s", m_isCommandMode ? "" : "-- INSERT --");
    clrtoeol();
  }

  void Editor::commandMode(int ch)
  {
    switch (ch)
    {
    case 'i':
      m_isCommandMode = false;
      break;
    case 'h':
      // if (m_currentColumn > 0 && m_currentColumn == m_startColumn)
      // {
      //   if (m_startColumn > COLS / 2)
      //     m_startColumn -= COLS / 2;
      //   else
      //     m_startColumn = 0;
      // }
      if (m_currentColumn > 0)
        m_currentColumn--;
      break;
    case 'l':
      // if (m_currentColumn - m_startColumn == static_cast<size_t>(COLS - 2))
      //   m_startColumn += COLS / 2;
      if (m_buffer.getLines()[m_currentLine].size() != 0 && m_currentColumn < m_buffer.getLines()[m_currentLine].size() - 1)
        m_currentColumn++;
      break;
    case 'j':
      // if (m_currentLine - m_startLine + 10 == static_cast<size_t>(LINES - 2) && m_currentLine + 10 < m_buffer.getLines().size())
      //   m_startLine++;

      m_currentColumn = (m_buffer.getLines()[m_currentLine].empty()) ? 0 : std::min(m_currentColumn, m_buffer.getLines()[m_currentLine].size());

      if (m_currentLine < m_buffer.getLines().size() - 1)
        m_currentLine++;
      break;
    case 'k':
      // if (m_currentLine - m_startLine == 10 && m_startLine != 0)
      //   m_startLine--;

      if (m_currentLine > 0)
        m_currentLine--;

      m_currentColumn = (m_buffer.getLines()[m_currentLine].empty()) ? 0 : std::min(m_currentColumn, m_buffer.getLines()[m_currentLine].size());
      break;
    case ':':
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
    }
    break;
    }
  }

  void Editor::insertMode(int ch)
  {
    switch (ch)
    {
    case 27:
      m_isCommandMode = true;
      break;
    case 10:
      // if (m_currentLine - m_startLine == static_cast<size_t>(LINES - 3))
      //   m_startLine++;
      m_buffer.insertNewLine(m_currentLine + 1);
      m_currentLine++;
      m_currentColumn = 0;
      break;
    case KEY_BACKSPACE:
      if (m_currentColumn > 0)
      {
        // if (m_currentColumn == m_startColumn)
        // {
        //   if (m_startColumn > COLS / 2)
        //     m_startColumn -= COLS / 2;
        //   else
        //     m_startColumn = 0;
        // }

        m_buffer.deleteChar(m_currentLine, m_currentColumn - 1);
        m_currentColumn--;
      }
      else if (m_currentLine > 0)
      {
        // if (m_currentLine == m_startLine + 10 && m_startLine != 0)
        //   m_startLine--;
        m_buffer.deleteLine(m_currentLine);
        m_currentLine--;
        m_currentColumn = m_buffer.getLines()[m_currentLine].size();
        // if (m_currentColumn > m_startColumn + COLS)
        //   m_startColumn = m_currentColumn - COLS;
      }
      break;
    case 9:
      for (int i = 0; i < 4; i++)
      {
        // if (m_currentColumn - m_startColumn == static_cast<size_t>(COLS - 2))
        //   m_startColumn += COLS / 2;
        m_buffer.insertChar(m_currentLine, m_currentColumn, ' ');
        m_currentColumn++;
      }
      break;
    default:
      if (ch >= 32 && ch <= 126)
      {
        // if (m_currentColumn - m_startColumn == static_cast<size_t>(COLS - 2))
        //   m_startColumn += COLS / 2;
        m_buffer.insertChar(m_currentLine, m_currentColumn, static_cast<char>(ch));
        m_currentColumn++;
      }
      break;
    }
    move(m_currentLine, m_currentColumn);
  }

} // namespace Pim
