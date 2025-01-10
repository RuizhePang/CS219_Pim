# Pim - A Simple Text Editor

<img src="./png/logo.webp" alt="A logo inspired by the Vim text editor, featuring a bold and modern design with the text 'Pim' in the center. The logo should have a green and dark gray color scheme, with sharp edges and a geometric style. Surround the text with a diamond-shaped outline, similar to the classic Vim logo, and give it a slightly 3D look." style="width:150px; height:auto;" />

---

## **Overview**

Pim is a simplified version of the classic Vim editor, designed to provide essential text editing capabilities with three primary modes: **Normal**, **Insert**, and **Command-Line** modes.
---

## **Modes in Pim**

### **1. Normal Mode**
Normal Mode is the default mode when Pim starts. In this mode, users can navigate and manipulate text without directly entering new content.

Key actions in Normal Mode include:
- **Navigation**: Move the cursor using `h` (left), `j` (down), `k` (up), `l` (right), or arrow keys.
- **Text Manipulation**: Delete (`d`), copy (`y`), and paste (`p`) text.
- **Switch to Insert Mode**: Press `i` to start typing.
- **Switch to Command-Line Mode**: Press `:` to execute commands.

### **2. Insert Mode**
Insert Mode allows users to type and edit text.
- To enter Insert Mode, press `i` in Normal Mode.
- To return to Normal Mode, press `ESC`.

### **3. Command-Line Mode**
Command-Line Mode enables users to execute commands for file operations and other advanced functions.
- To enter Command-Line Mode, press `:` in Normal Mode.
- Common commands include:
  - `:w` - Save the file.
  - `:q` - Quit the editor.
  - `:wq` - Save and quit.

---

## **Key Features**

### **File and Mode Commands**
- `:w` - Save the file.
- `:q` - Quit the editor.
- `:wq` - Save and quit the editor.
- `i` - Switch to Insert Mode.
- `:` - Enter Command-Line Mode.

### **Cursor Movement**
In Normal Mode, move the cursor using:
- `h` - Left
- `j` - Down
- `k` - Up
- `l` - Right
- Arrow keys are also supported for navigation.

### **Line Navigation**
- `0` - Move to the beginning of the current line.
- `$` - Move to the end of the current line.
- `gg` - Jump to the first line of the file.
- `G` - Jump to the last line of the file.

---

## **Advanced Features**

- **Undo/Redo**: undo (`u`) and redo (`Ctrl + r`) commands.

---

## **Installation**

Follow these steps to build and run Pim:

### **1. Clone the Repository**
```bash
git clone https://github.com/RuizhePang/CS219_Pim.git
```

### **2. Navigate to the Project Directory**
```bash
cd CS219_Pim
```

### **3. Ensure CMake is Installed**
Verify that CMake is installed by running:
```bash
cmake --version
```

### **4. Create a Build Directory**
```bash
mkdir build && cd build
```

### **5. Generate Build Files with CMake**
```bash
cmake ..
```

### **6. Build the Project**
```bash
make
```

### **7. Run the Program**
```bash
./src/pim
```

---

## **Usage Example**

1. **Open the editor**:
   ```bash
   ./src/pim
   ```
2. **Switch to Insert Mode** by pressing `i` and start typing.
3. **Press `ESC`** to return to Normal Mode.
4. **Save the file** by typing `:w` in Command-Line Mode.
5. **Quit the editor** by typing `:q`.