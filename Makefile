# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/bin/cmake3

# The command to remove a file.
RM = /usr/bin/cmake3 -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/csmajs/rwyat002/assignment-team_robert_kosuke

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/csmajs/rwyat002/assignment-team_robert_kosuke

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake3 -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake3 -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake3 -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake3 -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake3 -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake3 -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake3 -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake3 -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/csmajs/rwyat002/assignment-team_robert_kosuke/CMakeFiles /home/csmajs/rwyat002/assignment-team_robert_kosuke/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/csmajs/rwyat002/assignment-team_robert_kosuke/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named rshell

# Build rule for target.
rshell: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 rshell
.PHONY : rshell

# fast build rule for target.
rshell/fast:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/build
.PHONY : rshell/fast

#=============================================================================
# Target rules for targets named test

# Build rule for target.
test: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 test
.PHONY : test

# fast build rule for target.
test/fast:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/build
.PHONY : test/fast

#=============================================================================
# Target rules for targets named gmock_main

# Build rule for target.
gmock_main: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gmock_main
.PHONY : gmock_main

# fast build rule for target.
gmock_main/fast:
	$(MAKE) -f googletest/googlemock/CMakeFiles/gmock_main.dir/build.make googletest/googlemock/CMakeFiles/gmock_main.dir/build
.PHONY : gmock_main/fast

#=============================================================================
# Target rules for targets named gmock

# Build rule for target.
gmock: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gmock
.PHONY : gmock

# fast build rule for target.
gmock/fast:
	$(MAKE) -f googletest/googlemock/CMakeFiles/gmock.dir/build.make googletest/googlemock/CMakeFiles/gmock.dir/build
.PHONY : gmock/fast

#=============================================================================
# Target rules for targets named gtest_main

# Build rule for target.
gtest_main: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gtest_main
.PHONY : gtest_main

# fast build rule for target.
gtest_main/fast:
	$(MAKE) -f googletest/googletest/CMakeFiles/gtest_main.dir/build.make googletest/googletest/CMakeFiles/gtest_main.dir/build
.PHONY : gtest_main/fast

#=============================================================================
# Target rules for targets named gtest

# Build rule for target.
gtest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gtest
.PHONY : gtest

# fast build rule for target.
gtest/fast:
	$(MAKE) -f googletest/googletest/CMakeFiles/gtest.dir/build.make googletest/googletest/CMakeFiles/gtest.dir/build
.PHONY : gtest/fast

src/DoubleAnd.o: src/DoubleAnd.cpp.o

.PHONY : src/DoubleAnd.o

# target to build an object file
src/DoubleAnd.cpp.o:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/DoubleAnd.cpp.o
.PHONY : src/DoubleAnd.cpp.o

src/DoubleAnd.i: src/DoubleAnd.cpp.i

.PHONY : src/DoubleAnd.i

# target to preprocess a source file
src/DoubleAnd.cpp.i:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/DoubleAnd.cpp.i
.PHONY : src/DoubleAnd.cpp.i

src/DoubleAnd.s: src/DoubleAnd.cpp.s

.PHONY : src/DoubleAnd.s

# target to generate assembly for a file
src/DoubleAnd.cpp.s:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/DoubleAnd.cpp.s
.PHONY : src/DoubleAnd.cpp.s

src/DoubleSlash.o: src/DoubleSlash.cpp.o

.PHONY : src/DoubleSlash.o

# target to build an object file
src/DoubleSlash.cpp.o:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/DoubleSlash.cpp.o
.PHONY : src/DoubleSlash.cpp.o

src/DoubleSlash.i: src/DoubleSlash.cpp.i

.PHONY : src/DoubleSlash.i

# target to preprocess a source file
src/DoubleSlash.cpp.i:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/DoubleSlash.cpp.i
.PHONY : src/DoubleSlash.cpp.i

src/DoubleSlash.s: src/DoubleSlash.cpp.s

.PHONY : src/DoubleSlash.s

# target to generate assembly for a file
src/DoubleSlash.cpp.s:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/DoubleSlash.cpp.s
.PHONY : src/DoubleSlash.cpp.s

src/ExecutableCommand.o: src/ExecutableCommand.cpp.o

.PHONY : src/ExecutableCommand.o

# target to build an object file
src/ExecutableCommand.cpp.o:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/ExecutableCommand.cpp.o
.PHONY : src/ExecutableCommand.cpp.o

src/ExecutableCommand.i: src/ExecutableCommand.cpp.i

.PHONY : src/ExecutableCommand.i

# target to preprocess a source file
src/ExecutableCommand.cpp.i:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/ExecutableCommand.cpp.i
.PHONY : src/ExecutableCommand.cpp.i

src/ExecutableCommand.s: src/ExecutableCommand.cpp.s

.PHONY : src/ExecutableCommand.s

# target to generate assembly for a file
src/ExecutableCommand.cpp.s:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/ExecutableCommand.cpp.s
.PHONY : src/ExecutableCommand.cpp.s

src/Line.o: src/Line.cpp.o

.PHONY : src/Line.o

# target to build an object file
src/Line.cpp.o:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Line.cpp.o
.PHONY : src/Line.cpp.o

src/Line.i: src/Line.cpp.i

.PHONY : src/Line.i

# target to preprocess a source file
src/Line.cpp.i:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Line.cpp.i
.PHONY : src/Line.cpp.i

src/Line.s: src/Line.cpp.s

.PHONY : src/Line.s

# target to generate assembly for a file
src/Line.cpp.s:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Line.cpp.s
.PHONY : src/Line.cpp.s

src/SemiColon.o: src/SemiColon.cpp.o

.PHONY : src/SemiColon.o

# target to build an object file
src/SemiColon.cpp.o:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/SemiColon.cpp.o
.PHONY : src/SemiColon.cpp.o

src/SemiColon.i: src/SemiColon.cpp.i

.PHONY : src/SemiColon.i

# target to preprocess a source file
src/SemiColon.cpp.i:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/SemiColon.cpp.i
.PHONY : src/SemiColon.cpp.i

src/SemiColon.s: src/SemiColon.cpp.s

.PHONY : src/SemiColon.s

# target to generate assembly for a file
src/SemiColon.cpp.s:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/SemiColon.cpp.s
.PHONY : src/SemiColon.cpp.s

src/Symbol.o: src/Symbol.cpp.o

.PHONY : src/Symbol.o

# target to build an object file
src/Symbol.cpp.o:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Symbol.cpp.o
.PHONY : src/Symbol.cpp.o

src/Symbol.i: src/Symbol.cpp.i

.PHONY : src/Symbol.i

# target to preprocess a source file
src/Symbol.cpp.i:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Symbol.cpp.i
.PHONY : src/Symbol.cpp.i

src/Symbol.s: src/Symbol.cpp.s

.PHONY : src/Symbol.s

# target to generate assembly for a file
src/Symbol.cpp.s:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Symbol.cpp.s
.PHONY : src/Symbol.cpp.s

src/UserInput.o: src/UserInput.cpp.o

.PHONY : src/UserInput.o

# target to build an object file
src/UserInput.cpp.o:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/UserInput.cpp.o
.PHONY : src/UserInput.cpp.o

src/UserInput.i: src/UserInput.cpp.i

.PHONY : src/UserInput.i

# target to preprocess a source file
src/UserInput.cpp.i:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/UserInput.cpp.i
.PHONY : src/UserInput.cpp.i

src/UserInput.s: src/UserInput.cpp.s

.PHONY : src/UserInput.s

# target to generate assembly for a file
src/UserInput.cpp.s:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/UserInput.cpp.s
.PHONY : src/UserInput.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install/strip"
	@echo "... install/local"
	@echo "... install"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... rshell"
	@echo "... test"
	@echo "... gmock_main"
	@echo "... gmock"
	@echo "... gtest_main"
	@echo "... gtest"
	@echo "... src/DoubleAnd.o"
	@echo "... src/DoubleAnd.i"
	@echo "... src/DoubleAnd.s"
	@echo "... src/DoubleSlash.o"
	@echo "... src/DoubleSlash.i"
	@echo "... src/DoubleSlash.s"
	@echo "... src/ExecutableCommand.o"
	@echo "... src/ExecutableCommand.i"
	@echo "... src/ExecutableCommand.s"
	@echo "... src/Line.o"
	@echo "... src/Line.i"
	@echo "... src/Line.s"
	@echo "... src/SemiColon.o"
	@echo "... src/SemiColon.i"
	@echo "... src/SemiColon.s"
	@echo "... src/Symbol.o"
	@echo "... src/Symbol.i"
	@echo "... src/Symbol.s"
	@echo "... src/UserInput.o"
	@echo "... src/UserInput.i"
	@echo "... src/UserInput.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
