# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2020.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\HanaSaku-Iroha\CLionProjects\DataStructExpriment7_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\HanaSaku-Iroha\CLionProjects\DataStructExpriment7_2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DataStructExpriment7_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DataStructExpriment7_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DataStructExpriment7_2.dir/flags.make

CMakeFiles/DataStructExpriment7_2.dir/main.c.obj: CMakeFiles/DataStructExpriment7_2.dir/flags.make
CMakeFiles/DataStructExpriment7_2.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\HanaSaku-Iroha\CLionProjects\DataStructExpriment7_2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/DataStructExpriment7_2.dir/main.c.obj"
	D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\DataStructExpriment7_2.dir\main.c.obj   -c C:\Users\HanaSaku-Iroha\CLionProjects\DataStructExpriment7_2\main.c

CMakeFiles/DataStructExpriment7_2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DataStructExpriment7_2.dir/main.c.i"
	D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\HanaSaku-Iroha\CLionProjects\DataStructExpriment7_2\main.c > CMakeFiles\DataStructExpriment7_2.dir\main.c.i

CMakeFiles/DataStructExpriment7_2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DataStructExpriment7_2.dir/main.c.s"
	D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\HanaSaku-Iroha\CLionProjects\DataStructExpriment7_2\main.c -o CMakeFiles\DataStructExpriment7_2.dir\main.c.s

# Object files for target DataStructExpriment7_2
DataStructExpriment7_2_OBJECTS = \
"CMakeFiles/DataStructExpriment7_2.dir/main.c.obj"

# External object files for target DataStructExpriment7_2
DataStructExpriment7_2_EXTERNAL_OBJECTS =

DataStructExpriment7_2.exe: CMakeFiles/DataStructExpriment7_2.dir/main.c.obj
DataStructExpriment7_2.exe: CMakeFiles/DataStructExpriment7_2.dir/build.make
DataStructExpriment7_2.exe: CMakeFiles/DataStructExpriment7_2.dir/linklibs.rsp
DataStructExpriment7_2.exe: CMakeFiles/DataStructExpriment7_2.dir/objects1.rsp
DataStructExpriment7_2.exe: CMakeFiles/DataStructExpriment7_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\HanaSaku-Iroha\CLionProjects\DataStructExpriment7_2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable DataStructExpriment7_2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DataStructExpriment7_2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DataStructExpriment7_2.dir/build: DataStructExpriment7_2.exe

.PHONY : CMakeFiles/DataStructExpriment7_2.dir/build

CMakeFiles/DataStructExpriment7_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DataStructExpriment7_2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DataStructExpriment7_2.dir/clean

CMakeFiles/DataStructExpriment7_2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\HanaSaku-Iroha\CLionProjects\DataStructExpriment7_2 C:\Users\HanaSaku-Iroha\CLionProjects\DataStructExpriment7_2 C:\Users\HanaSaku-Iroha\CLionProjects\DataStructExpriment7_2\cmake-build-debug C:\Users\HanaSaku-Iroha\CLionProjects\DataStructExpriment7_2\cmake-build-debug C:\Users\HanaSaku-Iroha\CLionProjects\DataStructExpriment7_2\cmake-build-debug\CMakeFiles\DataStructExpriment7_2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DataStructExpriment7_2.dir/depend

