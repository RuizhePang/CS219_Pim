# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/Codes/Cpp/Pim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/Codes/Cpp/Pim/build

# Include any dependencies generated for this target.
include src/CMakeFiles/modes_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/modes_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/modes_lib.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/modes_lib.dir/flags.make

src/CMakeFiles/modes_lib.dir/modes/normal_mode.cpp.o: src/CMakeFiles/modes_lib.dir/flags.make
src/CMakeFiles/modes_lib.dir/modes/normal_mode.cpp.o: /home/ubuntu/Codes/Cpp/Pim/src/modes/normal_mode.cpp
src/CMakeFiles/modes_lib.dir/modes/normal_mode.cpp.o: src/CMakeFiles/modes_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ubuntu/Codes/Cpp/Pim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/modes_lib.dir/modes/normal_mode.cpp.o"
	cd /home/ubuntu/Codes/Cpp/Pim/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/modes_lib.dir/modes/normal_mode.cpp.o -MF CMakeFiles/modes_lib.dir/modes/normal_mode.cpp.o.d -o CMakeFiles/modes_lib.dir/modes/normal_mode.cpp.o -c /home/ubuntu/Codes/Cpp/Pim/src/modes/normal_mode.cpp

src/CMakeFiles/modes_lib.dir/modes/normal_mode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/modes_lib.dir/modes/normal_mode.cpp.i"
	cd /home/ubuntu/Codes/Cpp/Pim/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/Codes/Cpp/Pim/src/modes/normal_mode.cpp > CMakeFiles/modes_lib.dir/modes/normal_mode.cpp.i

src/CMakeFiles/modes_lib.dir/modes/normal_mode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/modes_lib.dir/modes/normal_mode.cpp.s"
	cd /home/ubuntu/Codes/Cpp/Pim/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/Codes/Cpp/Pim/src/modes/normal_mode.cpp -o CMakeFiles/modes_lib.dir/modes/normal_mode.cpp.s

src/CMakeFiles/modes_lib.dir/modes/insert_mode.cpp.o: src/CMakeFiles/modes_lib.dir/flags.make
src/CMakeFiles/modes_lib.dir/modes/insert_mode.cpp.o: /home/ubuntu/Codes/Cpp/Pim/src/modes/insert_mode.cpp
src/CMakeFiles/modes_lib.dir/modes/insert_mode.cpp.o: src/CMakeFiles/modes_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ubuntu/Codes/Cpp/Pim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/modes_lib.dir/modes/insert_mode.cpp.o"
	cd /home/ubuntu/Codes/Cpp/Pim/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/modes_lib.dir/modes/insert_mode.cpp.o -MF CMakeFiles/modes_lib.dir/modes/insert_mode.cpp.o.d -o CMakeFiles/modes_lib.dir/modes/insert_mode.cpp.o -c /home/ubuntu/Codes/Cpp/Pim/src/modes/insert_mode.cpp

src/CMakeFiles/modes_lib.dir/modes/insert_mode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/modes_lib.dir/modes/insert_mode.cpp.i"
	cd /home/ubuntu/Codes/Cpp/Pim/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/Codes/Cpp/Pim/src/modes/insert_mode.cpp > CMakeFiles/modes_lib.dir/modes/insert_mode.cpp.i

src/CMakeFiles/modes_lib.dir/modes/insert_mode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/modes_lib.dir/modes/insert_mode.cpp.s"
	cd /home/ubuntu/Codes/Cpp/Pim/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/Codes/Cpp/Pim/src/modes/insert_mode.cpp -o CMakeFiles/modes_lib.dir/modes/insert_mode.cpp.s

src/CMakeFiles/modes_lib.dir/modes/command_mode.cpp.o: src/CMakeFiles/modes_lib.dir/flags.make
src/CMakeFiles/modes_lib.dir/modes/command_mode.cpp.o: /home/ubuntu/Codes/Cpp/Pim/src/modes/command_mode.cpp
src/CMakeFiles/modes_lib.dir/modes/command_mode.cpp.o: src/CMakeFiles/modes_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ubuntu/Codes/Cpp/Pim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/modes_lib.dir/modes/command_mode.cpp.o"
	cd /home/ubuntu/Codes/Cpp/Pim/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/modes_lib.dir/modes/command_mode.cpp.o -MF CMakeFiles/modes_lib.dir/modes/command_mode.cpp.o.d -o CMakeFiles/modes_lib.dir/modes/command_mode.cpp.o -c /home/ubuntu/Codes/Cpp/Pim/src/modes/command_mode.cpp

src/CMakeFiles/modes_lib.dir/modes/command_mode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/modes_lib.dir/modes/command_mode.cpp.i"
	cd /home/ubuntu/Codes/Cpp/Pim/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/Codes/Cpp/Pim/src/modes/command_mode.cpp > CMakeFiles/modes_lib.dir/modes/command_mode.cpp.i

src/CMakeFiles/modes_lib.dir/modes/command_mode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/modes_lib.dir/modes/command_mode.cpp.s"
	cd /home/ubuntu/Codes/Cpp/Pim/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/Codes/Cpp/Pim/src/modes/command_mode.cpp -o CMakeFiles/modes_lib.dir/modes/command_mode.cpp.s

# Object files for target modes_lib
modes_lib_OBJECTS = \
"CMakeFiles/modes_lib.dir/modes/normal_mode.cpp.o" \
"CMakeFiles/modes_lib.dir/modes/insert_mode.cpp.o" \
"CMakeFiles/modes_lib.dir/modes/command_mode.cpp.o"

# External object files for target modes_lib
modes_lib_EXTERNAL_OBJECTS =

src/libmodes_lib.a: src/CMakeFiles/modes_lib.dir/modes/normal_mode.cpp.o
src/libmodes_lib.a: src/CMakeFiles/modes_lib.dir/modes/insert_mode.cpp.o
src/libmodes_lib.a: src/CMakeFiles/modes_lib.dir/modes/command_mode.cpp.o
src/libmodes_lib.a: src/CMakeFiles/modes_lib.dir/build.make
src/libmodes_lib.a: src/CMakeFiles/modes_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ubuntu/Codes/Cpp/Pim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libmodes_lib.a"
	cd /home/ubuntu/Codes/Cpp/Pim/build/src && $(CMAKE_COMMAND) -P CMakeFiles/modes_lib.dir/cmake_clean_target.cmake
	cd /home/ubuntu/Codes/Cpp/Pim/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/modes_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/modes_lib.dir/build: src/libmodes_lib.a
.PHONY : src/CMakeFiles/modes_lib.dir/build

src/CMakeFiles/modes_lib.dir/clean:
	cd /home/ubuntu/Codes/Cpp/Pim/build/src && $(CMAKE_COMMAND) -P CMakeFiles/modes_lib.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/modes_lib.dir/clean

src/CMakeFiles/modes_lib.dir/depend:
	cd /home/ubuntu/Codes/Cpp/Pim/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/Codes/Cpp/Pim /home/ubuntu/Codes/Cpp/Pim/src /home/ubuntu/Codes/Cpp/Pim/build /home/ubuntu/Codes/Cpp/Pim/build/src /home/ubuntu/Codes/Cpp/Pim/build/src/CMakeFiles/modes_lib.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/modes_lib.dir/depend

