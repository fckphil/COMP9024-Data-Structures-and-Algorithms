# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/izual/Desktop/w9

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/izual/Desktop/w9/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/w9.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/w9.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/w9.dir/flags.make

CMakeFiles/w9.dir/main.c.o: CMakeFiles/w9.dir/flags.make
CMakeFiles/w9.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/izual/Desktop/w9/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/w9.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/w9.dir/main.c.o   -c /Users/izual/Desktop/w9/main.c

CMakeFiles/w9.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/w9.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/izual/Desktop/w9/main.c > CMakeFiles/w9.dir/main.c.i

CMakeFiles/w9.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/w9.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/izual/Desktop/w9/main.c -o CMakeFiles/w9.dir/main.c.s

CMakeFiles/w9.dir/trie.c.o: CMakeFiles/w9.dir/flags.make
CMakeFiles/w9.dir/trie.c.o: ../trie.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/izual/Desktop/w9/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/w9.dir/trie.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/w9.dir/trie.c.o   -c /Users/izual/Desktop/w9/trie.c

CMakeFiles/w9.dir/trie.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/w9.dir/trie.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/izual/Desktop/w9/trie.c > CMakeFiles/w9.dir/trie.c.i

CMakeFiles/w9.dir/trie.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/w9.dir/trie.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/izual/Desktop/w9/trie.c -o CMakeFiles/w9.dir/trie.c.s

# Object files for target w9
w9_OBJECTS = \
"CMakeFiles/w9.dir/main.c.o" \
"CMakeFiles/w9.dir/trie.c.o"

# External object files for target w9
w9_EXTERNAL_OBJECTS =

w9: CMakeFiles/w9.dir/main.c.o
w9: CMakeFiles/w9.dir/trie.c.o
w9: CMakeFiles/w9.dir/build.make
w9: CMakeFiles/w9.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/izual/Desktop/w9/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable w9"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/w9.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/w9.dir/build: w9

.PHONY : CMakeFiles/w9.dir/build

CMakeFiles/w9.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/w9.dir/cmake_clean.cmake
.PHONY : CMakeFiles/w9.dir/clean

CMakeFiles/w9.dir/depend:
	cd /Users/izual/Desktop/w9/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/izual/Desktop/w9 /Users/izual/Desktop/w9 /Users/izual/Desktop/w9/cmake-build-debug /Users/izual/Desktop/w9/cmake-build-debug /Users/izual/Desktop/w9/cmake-build-debug/CMakeFiles/w9.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/w9.dir/depend
