#ifndef EDITOR_H
#define EDITOR_H

#include <string>
#include <vector>
#include "buffer.h"

namespace Pim
{

  class Editor
  {
  public:
    explicit Editor(const std::string &filename = "");

    ~Editor();

    void run();

  private:
    void initScreen();
    void drawContent();
    void drawStatusLine();
    void commandMode(std::string& cmd);
    void insertMode(int ch);

    std::string m_filename;

    size_t m_currentLine = 0;
    size_t m_currentColumn = 0;
    size_t m_startLine = 0;
    size_t m_startColumn = 0;

    bool m_isCommandMode = true;

    Buffer m_buffer;
  };

} // namespace Pim

#endif
