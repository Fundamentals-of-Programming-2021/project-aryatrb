# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/arya/state.io

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arya/state.io

# Include any dependencies generated for this target.
include CMakeFiles/state.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/state.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/state.dir/flags.make

CMakeFiles/state.dir/src/load_everythingc.c.o: CMakeFiles/state.dir/flags.make
CMakeFiles/state.dir/src/load_everythingc.c.o: src/load_everythingc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arya/state.io/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/state.dir/src/load_everythingc.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/state.dir/src/load_everythingc.c.o   -c /home/arya/state.io/src/load_everythingc.c

CMakeFiles/state.dir/src/load_everythingc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/state.dir/src/load_everythingc.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arya/state.io/src/load_everythingc.c > CMakeFiles/state.dir/src/load_everythingc.c.i

CMakeFiles/state.dir/src/load_everythingc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/state.dir/src/load_everythingc.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arya/state.io/src/load_everythingc.c -o CMakeFiles/state.dir/src/load_everythingc.c.s

CMakeFiles/state.dir/src/main.c.o: CMakeFiles/state.dir/flags.make
CMakeFiles/state.dir/src/main.c.o: src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arya/state.io/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/state.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/state.dir/src/main.c.o   -c /home/arya/state.io/src/main.c

CMakeFiles/state.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/state.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arya/state.io/src/main.c > CMakeFiles/state.dir/src/main.c.i

CMakeFiles/state.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/state.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arya/state.io/src/main.c -o CMakeFiles/state.dir/src/main.c.s

CMakeFiles/state.dir/src/operations_of_the_game.c.o: CMakeFiles/state.dir/flags.make
CMakeFiles/state.dir/src/operations_of_the_game.c.o: src/operations_of_the_game.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arya/state.io/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/state.dir/src/operations_of_the_game.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/state.dir/src/operations_of_the_game.c.o   -c /home/arya/state.io/src/operations_of_the_game.c

CMakeFiles/state.dir/src/operations_of_the_game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/state.dir/src/operations_of_the_game.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arya/state.io/src/operations_of_the_game.c > CMakeFiles/state.dir/src/operations_of_the_game.c.i

CMakeFiles/state.dir/src/operations_of_the_game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/state.dir/src/operations_of_the_game.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arya/state.io/src/operations_of_the_game.c -o CMakeFiles/state.dir/src/operations_of_the_game.c.s

CMakeFiles/state.dir/src/rendercpy.c.o: CMakeFiles/state.dir/flags.make
CMakeFiles/state.dir/src/rendercpy.c.o: src/rendercpy.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arya/state.io/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/state.dir/src/rendercpy.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/state.dir/src/rendercpy.c.o   -c /home/arya/state.io/src/rendercpy.c

CMakeFiles/state.dir/src/rendercpy.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/state.dir/src/rendercpy.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arya/state.io/src/rendercpy.c > CMakeFiles/state.dir/src/rendercpy.c.i

CMakeFiles/state.dir/src/rendercpy.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/state.dir/src/rendercpy.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arya/state.io/src/rendercpy.c -o CMakeFiles/state.dir/src/rendercpy.c.s

CMakeFiles/state.dir/src/the_pages_themselves.c.o: CMakeFiles/state.dir/flags.make
CMakeFiles/state.dir/src/the_pages_themselves.c.o: src/the_pages_themselves.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arya/state.io/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/state.dir/src/the_pages_themselves.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/state.dir/src/the_pages_themselves.c.o   -c /home/arya/state.io/src/the_pages_themselves.c

CMakeFiles/state.dir/src/the_pages_themselves.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/state.dir/src/the_pages_themselves.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arya/state.io/src/the_pages_themselves.c > CMakeFiles/state.dir/src/the_pages_themselves.c.i

CMakeFiles/state.dir/src/the_pages_themselves.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/state.dir/src/the_pages_themselves.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arya/state.io/src/the_pages_themselves.c -o CMakeFiles/state.dir/src/the_pages_themselves.c.s

# Object files for target state
state_OBJECTS = \
"CMakeFiles/state.dir/src/load_everythingc.c.o" \
"CMakeFiles/state.dir/src/main.c.o" \
"CMakeFiles/state.dir/src/operations_of_the_game.c.o" \
"CMakeFiles/state.dir/src/rendercpy.c.o" \
"CMakeFiles/state.dir/src/the_pages_themselves.c.o"

# External object files for target state
state_EXTERNAL_OBJECTS =

state: CMakeFiles/state.dir/src/load_everythingc.c.o
state: CMakeFiles/state.dir/src/main.c.o
state: CMakeFiles/state.dir/src/operations_of_the_game.c.o
state: CMakeFiles/state.dir/src/rendercpy.c.o
state: CMakeFiles/state.dir/src/the_pages_themselves.c.o
state: CMakeFiles/state.dir/build.make
state: CMakeFiles/state.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arya/state.io/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable state"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/state.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/state.dir/build: state

.PHONY : CMakeFiles/state.dir/build

CMakeFiles/state.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/state.dir/cmake_clean.cmake
.PHONY : CMakeFiles/state.dir/clean

CMakeFiles/state.dir/depend:
	cd /home/arya/state.io && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arya/state.io /home/arya/state.io /home/arya/state.io /home/arya/state.io /home/arya/state.io/CMakeFiles/state.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/state.dir/depend

