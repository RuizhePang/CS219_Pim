#include <ncurses.h>

#include <fstream>
#include <string>
#include <vector>

#include "core/editor.h"

int main(int argc, char* argv[]) {
  std::string filename;
  if (argc > 1) {
    filename = argv[1];
  }

  try {
    Pim::Editor editor(filename);
    editor.run();
  } catch (const std::exception& e) {
    endwin();
    fprintf(stderr, "Error: %s\n", e.what());
    return 1;
  }
  
  return 0;
}
