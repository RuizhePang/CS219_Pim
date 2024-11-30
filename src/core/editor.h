#include <vector>
#include <string>

namespace Pim
{
  class Editor
  {
  public:
    Editor(const std::string &filename = "");
    ~Editor();

    void run();

  private:
    std::string m_filename;
    std::vector<std::string> m_lines;

    int m_currentLine = 0;
    int m_currentColumn = 0;

    bool m_isCommandMode = true;

    void initScreen();

    void drawContent();
    void drawStatusLine();

    void handleInput(int ch);

    void insertMode(int ch);
    void commandMode(int ch);

    void loadFile();
    void saveFile();
  };

} // namespace Minivim
