# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_SOURCE_DIR = /Users/stasyan/CLionProjects/PerfectHashing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/stasyan/CLionProjects/PerfectHashing/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PerfectHashing.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PerfectHashing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PerfectHashing.dir/flags.make

CMakeFiles/PerfectHashing.dir/main.cpp.o: CMakeFiles/PerfectHashing.dir/flags.make
CMakeFiles/PerfectHashing.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/stasyan/CLionProjects/PerfectHashing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PerfectHashing.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PerfectHashing.dir/main.cpp.o -c /Users/stasyan/CLionProjects/PerfectHashing/main.cpp

CMakeFiles/PerfectHashing.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PerfectHashing.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/stasyan/CLionProjects/PerfectHashing/main.cpp > CMakeFiles/PerfectHashing.dir/main.cpp.i

CMakeFiles/PerfectHashing.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PerfectHashing.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/stasyan/CLionProjects/PerfectHashing/main.cpp -o CMakeFiles/PerfectHashing.dir/main.cpp.s

# Object files for target PerfectHashing
PerfectHashing_OBJECTS = \
"CMakeFiles/PerfectHashing.dir/main.cpp.o"

# External object files for target PerfectHashing
PerfectHashing_EXTERNAL_OBJECTS =

PerfectHashing: CMakeFiles/PerfectHashing.dir/main.cpp.o
PerfectHashing: CMakeFiles/PerfectHashing.dir/build.make
PerfectHashing: CMakeFiles/PerfectHashing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/stasyan/CLionProjects/PerfectHashing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PerfectHashing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PerfectHashing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PerfectHashing.dir/build: PerfectHashing

.PHONY : CMakeFiles/PerfectHashing.dir/build

CMakeFiles/PerfectHashing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PerfectHashing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PerfectHashing.dir/clean

CMakeFiles/PerfectHashing.dir/depend:
	cd /Users/stasyan/CLionProjects/PerfectHashing/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/stasyan/CLionProjects/PerfectHashing /Users/stasyan/CLionProjects/PerfectHashing /Users/stasyan/CLionProjects/PerfectHashing/cmake-build-debug /Users/stasyan/CLionProjects/PerfectHashing/cmake-build-debug /Users/stasyan/CLionProjects/PerfectHashing/cmake-build-debug/CMakeFiles/PerfectHashing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PerfectHashing.dir/depend

