# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\CPPProject\c_akinator-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CPPProject\c_akinator-master\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/c_akinator_master.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/c_akinator_master.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/c_akinator_master.dir/flags.make

CMakeFiles/c_akinator_master.dir/main.c.obj: CMakeFiles/c_akinator_master.dir/flags.make
CMakeFiles/c_akinator_master.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CPPProject\c_akinator-master\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/c_akinator_master.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\c_akinator_master.dir\main.c.obj   -c D:\CPPProject\c_akinator-master\main.c

CMakeFiles/c_akinator_master.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/c_akinator_master.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\CPPProject\c_akinator-master\main.c > CMakeFiles\c_akinator_master.dir\main.c.i

CMakeFiles/c_akinator_master.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/c_akinator_master.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\CPPProject\c_akinator-master\main.c -o CMakeFiles\c_akinator_master.dir\main.c.s

# Object files for target c_akinator_master
c_akinator_master_OBJECTS = \
"CMakeFiles/c_akinator_master.dir/main.c.obj"

# External object files for target c_akinator_master
c_akinator_master_EXTERNAL_OBJECTS =

c_akinator_master.exe: CMakeFiles/c_akinator_master.dir/main.c.obj
c_akinator_master.exe: CMakeFiles/c_akinator_master.dir/build.make
c_akinator_master.exe: CMakeFiles/c_akinator_master.dir/linklibs.rsp
c_akinator_master.exe: CMakeFiles/c_akinator_master.dir/objects1.rsp
c_akinator_master.exe: CMakeFiles/c_akinator_master.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CPPProject\c_akinator-master\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable c_akinator_master.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\c_akinator_master.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/c_akinator_master.dir/build: c_akinator_master.exe

.PHONY : CMakeFiles/c_akinator_master.dir/build

CMakeFiles/c_akinator_master.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\c_akinator_master.dir\cmake_clean.cmake
.PHONY : CMakeFiles/c_akinator_master.dir/clean

CMakeFiles/c_akinator_master.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CPPProject\c_akinator-master D:\CPPProject\c_akinator-master D:\CPPProject\c_akinator-master\cmake-build-debug D:\CPPProject\c_akinator-master\cmake-build-debug D:\CPPProject\c_akinator-master\cmake-build-debug\CMakeFiles\c_akinator_master.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/c_akinator_master.dir/depend

