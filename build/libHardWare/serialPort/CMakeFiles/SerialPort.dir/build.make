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
include libHardWare/serialPort/CMakeFiles/SerialPort.dir/depend.make

# Include the progress variables for this target.
include libHardWare/serialPort/CMakeFiles/SerialPort.dir/progress.make

# Include the compile flags for this target's objects.
include libHardWare/serialPort/CMakeFiles/SerialPort.dir/flags.make

libHardWare/serialPort/CMakeFiles/SerialPort.dir/src/serial_interface.cpp.o: libHardWare/serialPort/CMakeFiles/SerialPort.dir/flags.make
libHardWare/serialPort/CMakeFiles/SerialPort.dir/src/serial_interface.cpp.o: ../libHardWare/serialPort/src/serial_interface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wyx/程序/sentry_autoaim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libHardWare/serialPort/CMakeFiles/SerialPort.dir/src/serial_interface.cpp.o"
	cd /home/wyx/程序/sentry_autoaim/build/libHardWare/serialPort && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SerialPort.dir/src/serial_interface.cpp.o -c /home/wyx/程序/sentry_autoaim/libHardWare/serialPort/src/serial_interface.cpp

libHardWare/serialPort/CMakeFiles/SerialPort.dir/src/serial_interface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SerialPort.dir/src/serial_interface.cpp.i"
	cd /home/wyx/程序/sentry_autoaim/build/libHardWare/serialPort && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wyx/程序/sentry_autoaim/libHardWare/serialPort/src/serial_interface.cpp > CMakeFiles/SerialPort.dir/src/serial_interface.cpp.i

libHardWare/serialPort/CMakeFiles/SerialPort.dir/src/serial_interface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SerialPort.dir/src/serial_interface.cpp.s"
	cd /home/wyx/程序/sentry_autoaim/build/libHardWare/serialPort && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wyx/程序/sentry_autoaim/libHardWare/serialPort/src/serial_interface.cpp -o CMakeFiles/SerialPort.dir/src/serial_interface.cpp.s

libHardWare/serialPort/CMakeFiles/SerialPort.dir/src/serial_packet.cpp.o: libHardWare/serialPort/CMakeFiles/SerialPort.dir/flags.make
libHardWare/serialPort/CMakeFiles/SerialPort.dir/src/serial_packet.cpp.o: ../libHardWare/serialPort/src/serial_packet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wyx/程序/sentry_autoaim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object libHardWare/serialPort/CMakeFiles/SerialPort.dir/src/serial_packet.cpp.o"
	cd /home/wyx/程序/sentry_autoaim/build/libHardWare/serialPort && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SerialPort.dir/src/serial_packet.cpp.o -c /home/wyx/程序/sentry_autoaim/libHardWare/serialPort/src/serial_packet.cpp

libHardWare/serialPort/CMakeFiles/SerialPort.dir/src/serial_packet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SerialPort.dir/src/serial_packet.cpp.i"
	cd /home/wyx/程序/sentry_autoaim/build/libHardWare/serialPort && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wyx/程序/sentry_autoaim/libHardWare/serialPort/src/serial_packet.cpp > CMakeFiles/SerialPort.dir/src/serial_packet.cpp.i

libHardWare/serialPort/CMakeFiles/SerialPort.dir/src/serial_packet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SerialPort.dir/src/serial_packet.cpp.s"
	cd /home/wyx/程序/sentry_autoaim/build/libHardWare/serialPort && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wyx/程序/sentry_autoaim/libHardWare/serialPort/src/serial_packet.cpp -o CMakeFiles/SerialPort.dir/src/serial_packet.cpp.s

libHardWare/serialPort/CMakeFiles/SerialPort.dir/src/serial_port.cpp.o: libHardWare/serialPort/CMakeFiles/SerialPort.dir/flags.make
libHardWare/serialPort/CMakeFiles/SerialPort.dir/src/serial_port.cpp.o: ../libHardWare/serialPort/src/serial_port.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wyx/程序/sentry_autoaim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object libHardWare/serialPort/CMakeFiles/SerialPort.dir/src/serial_port.cpp.o"
	cd /home/wyx/程序/sentry_autoaim/build/libHardWare/serialPort && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SerialPort.dir/src/serial_port.cpp.o -c /home/wyx/程序/sentry_autoaim/libHardWare/serialPort/src/serial_port.cpp

libHardWare/serialPort/CMakeFiles/SerialPort.dir/src/serial_port.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SerialPort.dir/src/serial_port.cpp.i"
	cd /home/wyx/程序/sentry_autoaim/build/libHardWare/serialPort && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wyx/程序/sentry_autoaim/libHardWare/serialPort/src/serial_port.cpp > CMakeFiles/SerialPort.dir/src/serial_port.cpp.i

libHardWare/serialPort/CMakeFiles/SerialPort.dir/src/serial_port.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SerialPort.dir/src/serial_port.cpp.s"
	cd /home/wyx/程序/sentry_autoaim/build/libHardWare/serialPort && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wyx/程序/sentry_autoaim/libHardWare/serialPort/src/serial_port.cpp -o CMakeFiles/SerialPort.dir/src/serial_port.cpp.s

libHardWare/serialPort/CMakeFiles/SerialPort.dir/src/serial_port_debug.cpp.o: libHardWare/serialPort/CMakeFiles/SerialPort.dir/flags.make
libHardWare/serialPort/CMakeFiles/SerialPort.dir/src/serial_port_debug.cpp.o: ../libHardWare/serialPort/src/serial_port_debug.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wyx/程序/sentry_autoaim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object libHardWare/serialPort/CMakeFiles/SerialPort.dir/src/serial_port_debug.cpp.o"
	cd /home/wyx/程序/sentry_autoaim/build/libHardWare/serialPort && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SerialPort.dir/src/serial_port_debug.cpp.o -c /home/wyx/程序/sentry_autoaim/libHardWare/serialPort/src/serial_port_debug.cpp

libHardWare/serialPort/CMakeFiles/SerialPort.dir/src/serial_port_debug.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SerialPort.dir/src/serial_port_debug.cpp.i"
	cd /home/wyx/程序/sentry_autoaim/build/libHardWare/serialPort && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wyx/程序/sentry_autoaim/libHardWare/serialPort/src/serial_port_debug.cpp > CMakeFiles/SerialPort.dir/src/serial_port_debug.cpp.i

libHardWare/serialPort/CMakeFiles/SerialPort.dir/src/serial_port_debug.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SerialPort.dir/src/serial_port_debug.cpp.s"
	cd /home/wyx/程序/sentry_autoaim/build/libHardWare/serialPort && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wyx/程序/sentry_autoaim/libHardWare/serialPort/src/serial_port_debug.cpp -o CMakeFiles/SerialPort.dir/src/serial_port_debug.cpp.s

# Object files for target SerialPort
SerialPort_OBJECTS = \
"CMakeFiles/SerialPort.dir/src/serial_interface.cpp.o" \
"CMakeFiles/SerialPort.dir/src/serial_packet.cpp.o" \
"CMakeFiles/SerialPort.dir/src/serial_port.cpp.o" \
"CMakeFiles/SerialPort.dir/src/serial_port_debug.cpp.o"

# External object files for target SerialPort
SerialPort_EXTERNAL_OBJECTS =

libHardWare/serialPort/libSerialPort.a: libHardWare/serialPort/CMakeFiles/SerialPort.dir/src/serial_interface.cpp.o
libHardWare/serialPort/libSerialPort.a: libHardWare/serialPort/CMakeFiles/SerialPort.dir/src/serial_packet.cpp.o
libHardWare/serialPort/libSerialPort.a: libHardWare/serialPort/CMakeFiles/SerialPort.dir/src/serial_port.cpp.o
libHardWare/serialPort/libSerialPort.a: libHardWare/serialPort/CMakeFiles/SerialPort.dir/src/serial_port_debug.cpp.o
libHardWare/serialPort/libSerialPort.a: libHardWare/serialPort/CMakeFiles/SerialPort.dir/build.make
libHardWare/serialPort/libSerialPort.a: libHardWare/serialPort/CMakeFiles/SerialPort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wyx/程序/sentry_autoaim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libSerialPort.a"
	cd /home/wyx/程序/sentry_autoaim/build/libHardWare/serialPort && $(CMAKE_COMMAND) -P CMakeFiles/SerialPort.dir/cmake_clean_target.cmake
	cd /home/wyx/程序/sentry_autoaim/build/libHardWare/serialPort && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SerialPort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libHardWare/serialPort/CMakeFiles/SerialPort.dir/build: libHardWare/serialPort/libSerialPort.a

.PHONY : libHardWare/serialPort/CMakeFiles/SerialPort.dir/build

libHardWare/serialPort/CMakeFiles/SerialPort.dir/clean:
	cd /home/wyx/程序/sentry_autoaim/build/libHardWare/serialPort && $(CMAKE_COMMAND) -P CMakeFiles/SerialPort.dir/cmake_clean.cmake
.PHONY : libHardWare/serialPort/CMakeFiles/SerialPort.dir/clean

libHardWare/serialPort/CMakeFiles/SerialPort.dir/depend:
	cd /home/wyx/程序/sentry_autoaim/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wyx/程序/sentry_autoaim /home/wyx/程序/sentry_autoaim/libHardWare/serialPort /home/wyx/程序/sentry_autoaim/build /home/wyx/程序/sentry_autoaim/build/libHardWare/serialPort /home/wyx/程序/sentry_autoaim/build/libHardWare/serialPort/CMakeFiles/SerialPort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libHardWare/serialPort/CMakeFiles/SerialPort.dir/depend
