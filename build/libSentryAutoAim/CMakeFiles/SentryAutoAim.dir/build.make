# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wyx/程序/sentry_autoaim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wyx/程序/sentry_autoaim/build

# Include any dependencies generated for this target.
include libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/depend.make

# Include the progress variables for this target.
include libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/progress.make

# Include the compile flags for this target's objects.
include libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/flags.make

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/sentry_behavior_tree.cpp.o: libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/flags.make
libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/sentry_behavior_tree.cpp.o: ../libSentryAutoAim/src/sentry_behavior_tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wyx/程序/sentry_autoaim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/sentry_behavior_tree.cpp.o"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SentryAutoAim.dir/src/sentry_behavior_tree.cpp.o -c /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/sentry_behavior_tree.cpp

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/sentry_behavior_tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SentryAutoAim.dir/src/sentry_behavior_tree.cpp.i"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/sentry_behavior_tree.cpp > CMakeFiles/SentryAutoAim.dir/src/sentry_behavior_tree.cpp.i

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/sentry_behavior_tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SentryAutoAim.dir/src/sentry_behavior_tree.cpp.s"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/sentry_behavior_tree.cpp -o CMakeFiles/SentryAutoAim.dir/src/sentry_behavior_tree.cpp.s

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/avoid_enemy_action.cpp.o: libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/flags.make
libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/avoid_enemy_action.cpp.o: ../libSentryAutoAim/src/actions/avoid_enemy_action.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wyx/程序/sentry_autoaim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/avoid_enemy_action.cpp.o"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SentryAutoAim.dir/src/actions/avoid_enemy_action.cpp.o -c /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/actions/avoid_enemy_action.cpp

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/avoid_enemy_action.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SentryAutoAim.dir/src/actions/avoid_enemy_action.cpp.i"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/actions/avoid_enemy_action.cpp > CMakeFiles/SentryAutoAim.dir/src/actions/avoid_enemy_action.cpp.i

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/avoid_enemy_action.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SentryAutoAim.dir/src/actions/avoid_enemy_action.cpp.s"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/actions/avoid_enemy_action.cpp -o CMakeFiles/SentryAutoAim.dir/src/actions/avoid_enemy_action.cpp.s

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/distinguish_armor_action.cpp.o: libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/flags.make
libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/distinguish_armor_action.cpp.o: ../libSentryAutoAim/src/actions/distinguish_armor_action.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wyx/程序/sentry_autoaim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/distinguish_armor_action.cpp.o"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SentryAutoAim.dir/src/actions/distinguish_armor_action.cpp.o -c /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/actions/distinguish_armor_action.cpp

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/distinguish_armor_action.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SentryAutoAim.dir/src/actions/distinguish_armor_action.cpp.i"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/actions/distinguish_armor_action.cpp > CMakeFiles/SentryAutoAim.dir/src/actions/distinguish_armor_action.cpp.i

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/distinguish_armor_action.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SentryAutoAim.dir/src/actions/distinguish_armor_action.cpp.s"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/actions/distinguish_armor_action.cpp -o CMakeFiles/SentryAutoAim.dir/src/actions/distinguish_armor_action.cpp.s

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/enemy_detect_action.cpp.o: libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/flags.make
libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/enemy_detect_action.cpp.o: ../libSentryAutoAim/src/actions/enemy_detect_action.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wyx/程序/sentry_autoaim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/enemy_detect_action.cpp.o"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SentryAutoAim.dir/src/actions/enemy_detect_action.cpp.o -c /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/actions/enemy_detect_action.cpp

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/enemy_detect_action.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SentryAutoAim.dir/src/actions/enemy_detect_action.cpp.i"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/actions/enemy_detect_action.cpp > CMakeFiles/SentryAutoAim.dir/src/actions/enemy_detect_action.cpp.i

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/enemy_detect_action.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SentryAutoAim.dir/src/actions/enemy_detect_action.cpp.s"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/actions/enemy_detect_action.cpp -o CMakeFiles/SentryAutoAim.dir/src/actions/enemy_detect_action.cpp.s

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/escape_action.cpp.o: libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/flags.make
libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/escape_action.cpp.o: ../libSentryAutoAim/src/actions/escape_action.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wyx/程序/sentry_autoaim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/escape_action.cpp.o"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SentryAutoAim.dir/src/actions/escape_action.cpp.o -c /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/actions/escape_action.cpp

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/escape_action.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SentryAutoAim.dir/src/actions/escape_action.cpp.i"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/actions/escape_action.cpp > CMakeFiles/SentryAutoAim.dir/src/actions/escape_action.cpp.i

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/escape_action.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SentryAutoAim.dir/src/actions/escape_action.cpp.s"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/actions/escape_action.cpp -o CMakeFiles/SentryAutoAim.dir/src/actions/escape_action.cpp.s

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/fast_patrol_action.cpp.o: libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/flags.make
libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/fast_patrol_action.cpp.o: ../libSentryAutoAim/src/actions/fast_patrol_action.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wyx/程序/sentry_autoaim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/fast_patrol_action.cpp.o"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SentryAutoAim.dir/src/actions/fast_patrol_action.cpp.o -c /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/actions/fast_patrol_action.cpp

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/fast_patrol_action.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SentryAutoAim.dir/src/actions/fast_patrol_action.cpp.i"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/actions/fast_patrol_action.cpp > CMakeFiles/SentryAutoAim.dir/src/actions/fast_patrol_action.cpp.i

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/fast_patrol_action.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SentryAutoAim.dir/src/actions/fast_patrol_action.cpp.s"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/actions/fast_patrol_action.cpp -o CMakeFiles/SentryAutoAim.dir/src/actions/fast_patrol_action.cpp.s

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/shooting_single_action.cpp.o: libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/flags.make
libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/shooting_single_action.cpp.o: ../libSentryAutoAim/src/actions/shooting_single_action.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wyx/程序/sentry_autoaim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/shooting_single_action.cpp.o"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SentryAutoAim.dir/src/actions/shooting_single_action.cpp.o -c /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/actions/shooting_single_action.cpp

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/shooting_single_action.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SentryAutoAim.dir/src/actions/shooting_single_action.cpp.i"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/actions/shooting_single_action.cpp > CMakeFiles/SentryAutoAim.dir/src/actions/shooting_single_action.cpp.i

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/shooting_single_action.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SentryAutoAim.dir/src/actions/shooting_single_action.cpp.s"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/actions/shooting_single_action.cpp -o CMakeFiles/SentryAutoAim.dir/src/actions/shooting_single_action.cpp.s

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/test/behavior_test_action.cpp.o: libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/flags.make
libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/test/behavior_test_action.cpp.o: ../libSentryAutoAim/src/test/behavior_test_action.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wyx/程序/sentry_autoaim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/test/behavior_test_action.cpp.o"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SentryAutoAim.dir/src/test/behavior_test_action.cpp.o -c /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/test/behavior_test_action.cpp

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/test/behavior_test_action.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SentryAutoAim.dir/src/test/behavior_test_action.cpp.i"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/test/behavior_test_action.cpp > CMakeFiles/SentryAutoAim.dir/src/test/behavior_test_action.cpp.i

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/test/behavior_test_action.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SentryAutoAim.dir/src/test/behavior_test_action.cpp.s"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/test/behavior_test_action.cpp -o CMakeFiles/SentryAutoAim.dir/src/test/behavior_test_action.cpp.s

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/test/behavior_test_tree.cpp.o: libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/flags.make
libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/test/behavior_test_tree.cpp.o: ../libSentryAutoAim/src/test/behavior_test_tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wyx/程序/sentry_autoaim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/test/behavior_test_tree.cpp.o"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SentryAutoAim.dir/src/test/behavior_test_tree.cpp.o -c /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/test/behavior_test_tree.cpp

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/test/behavior_test_tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SentryAutoAim.dir/src/test/behavior_test_tree.cpp.i"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/test/behavior_test_tree.cpp > CMakeFiles/SentryAutoAim.dir/src/test/behavior_test_tree.cpp.i

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/test/behavior_test_tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SentryAutoAim.dir/src/test/behavior_test_tree.cpp.s"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wyx/程序/sentry_autoaim/libSentryAutoAim/src/test/behavior_test_tree.cpp -o CMakeFiles/SentryAutoAim.dir/src/test/behavior_test_tree.cpp.s

# Object files for target SentryAutoAim
SentryAutoAim_OBJECTS = \
"CMakeFiles/SentryAutoAim.dir/src/sentry_behavior_tree.cpp.o" \
"CMakeFiles/SentryAutoAim.dir/src/actions/avoid_enemy_action.cpp.o" \
"CMakeFiles/SentryAutoAim.dir/src/actions/distinguish_armor_action.cpp.o" \
"CMakeFiles/SentryAutoAim.dir/src/actions/enemy_detect_action.cpp.o" \
"CMakeFiles/SentryAutoAim.dir/src/actions/escape_action.cpp.o" \
"CMakeFiles/SentryAutoAim.dir/src/actions/fast_patrol_action.cpp.o" \
"CMakeFiles/SentryAutoAim.dir/src/actions/shooting_single_action.cpp.o" \
"CMakeFiles/SentryAutoAim.dir/src/test/behavior_test_action.cpp.o" \
"CMakeFiles/SentryAutoAim.dir/src/test/behavior_test_tree.cpp.o"

# External object files for target SentryAutoAim
SentryAutoAim_EXTERNAL_OBJECTS =

libSentryAutoAim/libSentryAutoAim.a: libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/sentry_behavior_tree.cpp.o
libSentryAutoAim/libSentryAutoAim.a: libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/avoid_enemy_action.cpp.o
libSentryAutoAim/libSentryAutoAim.a: libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/distinguish_armor_action.cpp.o
libSentryAutoAim/libSentryAutoAim.a: libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/enemy_detect_action.cpp.o
libSentryAutoAim/libSentryAutoAim.a: libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/escape_action.cpp.o
libSentryAutoAim/libSentryAutoAim.a: libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/fast_patrol_action.cpp.o
libSentryAutoAim/libSentryAutoAim.a: libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/actions/shooting_single_action.cpp.o
libSentryAutoAim/libSentryAutoAim.a: libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/test/behavior_test_action.cpp.o
libSentryAutoAim/libSentryAutoAim.a: libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/src/test/behavior_test_tree.cpp.o
libSentryAutoAim/libSentryAutoAim.a: libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/build.make
libSentryAutoAim/libSentryAutoAim.a: libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wyx/程序/sentry_autoaim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX static library libSentryAutoAim.a"
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && $(CMAKE_COMMAND) -P CMakeFiles/SentryAutoAim.dir/cmake_clean_target.cmake
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SentryAutoAim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/build: libSentryAutoAim/libSentryAutoAim.a

.PHONY : libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/build

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/clean:
	cd /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim && $(CMAKE_COMMAND) -P CMakeFiles/SentryAutoAim.dir/cmake_clean.cmake
.PHONY : libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/clean

libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/depend:
	cd /home/wyx/程序/sentry_autoaim/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wyx/程序/sentry_autoaim /home/wyx/程序/sentry_autoaim/libSentryAutoAim /home/wyx/程序/sentry_autoaim/build /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim /home/wyx/程序/sentry_autoaim/build/libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libSentryAutoAim/CMakeFiles/SentryAutoAim.dir/depend

