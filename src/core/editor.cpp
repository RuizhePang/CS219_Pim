#include <ncurses.h>

#include <fstream>
#include <iostream>
#include <stdexcept>

#include "editor.h"
namespace Pim {
Editor::Editor(const std::string &filename) : m_filename(filename) {
  if (!filename.empty()) {
    loadFile();
  } else {
    m_lines.push_back("");
  }

  initScreen();
}

Editor::~Editor() { endwin(); }

void Editor::initScreen() {
  initscr();
  keypad(stdscr, TRUE);
  raw();
  noecho();

  if (has_colors() == FALSE) {
    endwin();
    throw std::runtime_error("Your terminal does not support color");
  }
  refresh();
}

void Editor::run() {
  while (true) {
    drawContent();
    drawStatusLine();
    refresh();

    int ch = getch();

    if (m_isCommandMode) {
      commandMode(ch);
    } else {
      insertMode(ch);
    }
  }
}

void Editor::drawContent() {
  clear();

  for (size_t i = 0; i < m_lines.size() && i < static_cast<size_t>(LINES - 1);
       i++) {
    mvprintw(i, 0, "%s", m_lines[i].c_str());
  }

  move(m_currentLine, m_currentColumn);
}

void Editor::drawStatusLine() {
  mvprintw(LINES - 1, 0, "%s | %s | Line %d, Col %d",
           m_isCommandMode ? "COMMAND" : "INSERT",
           m_filename.empty() ? "[No Name]" : m_filename.c_str(),
           m_currentLine + 1, m_currentColumn + 1);
  clrtoeol();
}

void Editor::commandMode(int ch) {
  switch (ch) {
    case 'i':
      m_isCommandMode = false;
      break;
    case 'h':
      if (m_currentColumn > 0) m_currentColumn--;
      break;
    case 'l':
      if (m_currentColumn < m_lines[m_currentLine].length()) m_currentColumn++;
      break;
    case 'j':
      if (m_currentLine < m_lines.size() - 1) m_currentLine++;
      break;
    case 'k':
      if (m_currentLine > 0) m_currentLine--;
      break;
    case ':': {
      mvprintw(LINES - 1, 0, ":");
      refresh();

      std::string command;
      int cmdCh;
      while ((cmdCh = getch()) != '\n') {
        command += cmdCh;
        addch(cmdCh);
      }

      if (command == "q") {
        endwin();
        exit(0);
      }
      if (command == "w" && !m_filename.empty()) {
        saveFile();
      }
    } break;
  }
}

void Editor::insertMode(int ch) {
  switch (ch) {
    case 27:
      m_isCommandMode = true;
      break;
    case 106:
      if (m_currentColumn > 0) {
        m_lines[m_currentLine].erase(m_currentColumn - 1, 1);
        m_currentColumn--;
      }
      break;
    default:
      printw("%d", ch);
      m_lines[m_currentLine].insert(m_currentColumn, 1, ch);
      m_currentColumn++;
      break;
  }
}

void Editor::loadFile() {
  std::ifstream input(m_filename);
  if (!input) {
    m_lines.clear();
    m_lines.push_back("");
    return;
  }

  std::string line;
  while (std::getline(input, line)) {
    m_lines.push_back(line);
  }

  if (m_lines.empty()) {
    m_lines.push_back("");
  }
}

void Editor::saveFile() {
  if (m_filename.empty()) return;

  std::ofstream output(m_filename);
  for (const auto &line : m_lines) {
    output << line << std::endl;
  }
}

}  // namespace Pim
