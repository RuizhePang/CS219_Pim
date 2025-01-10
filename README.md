<img src="./png/logo.webp" alt="A logo inspired by the Vim text editor, featuring a bold and modern design with the text 'Pim' in the center. The logo should have a green and dark gray color scheme, with sharp edges and a geometric style. Surround the text with a diamond-shaped outline, similar to the classic Vim logo, and give it a slightly 3D look." style="zoom:25%;" />

# Pim - A Simple Text Editor

## Overview

Pim is a simplified version of the classic Vim editor, implementing its core functionalities with three primary modes: Normal, Insert, and Command-Line mode. This project allows for basic text editing and navigation, mimicking the essential commands of Vim.

## Modes in Pim

### 1. **Normal Mode**
Normal Mode is the default mode when you open Pim. In this mode, the user cannot directly type text but instead issues commands to manipulate text. The key actions performed in Normal Mode are:

- **Navigation**: Move the cursor using `h`, `j`, `k`, `l` or arrow keys.
- **Text Manipulation**: Perform operations like deleting, copying and pasting lines.
- **Switch to Insert Mode**: Press `i` to enter Insert Mode.
- **Switch to Command-Line Mode**: Press `:` to enter Command-Line Mode.

### 2. **Insert Mode**
Insert Mode allows you to type and modify the text in the document. You can switch to Insert Mode by pressing `i` in Normal Mode.

* **Switch to Normal Mode**: Press `ESC` to enter Normal Mode.

### 3. **Command-Line Mode**
In Command-Line Mode, you can execute commands such as save, quit, and other advanced functions. To enter Command-Line Mode, press `:` from Normal Mode.

## Key Features

### File and Mode Commands

- `:w` - Save the file.
- `:q` - Quit the editor.
- `:wq` - Save the file and quit the editor.
- `i` - Switch to Insert Mode.
- `:` - Enter Command-Line Mode for more advanced commands.

### Cursor Movement

In **Normal Mode**, you can move the cursor using the following keys:

- `h` - Move left.
- `j` - Move down.
- `k` - Move up.
- `l` - Move right.
- Arrow keys are also functional for cursor navigation.

### Line Navigation

- `0` - Move the cursor to the beginning of the current line.
- `$` - Move the cursor to the end of the current line.
- `gg` - Move the cursor to the first line of the file.
- `G` - Move the cursor to the last line of the file.

## Advanced Features (Optional)
While the basic functionality is implemented, future enhancements can include:

- **Undo/Redo**: Implement undo and redo commands for better editing flexibility.

## Installation

To run Pim, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/minivim.git