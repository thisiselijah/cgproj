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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.30.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.30.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/elijah/cg/finalproj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/elijah/cg/finalproj/build

# Include any dependencies generated for this target.
include CMakeFiles/main2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main2.dir/flags.make

CMakeFiles/main2.dir/src/main.cpp.o: CMakeFiles/main2.dir/flags.make
CMakeFiles/main2.dir/src/main.cpp.o: /Users/elijah/cg/finalproj/src/main.cpp
CMakeFiles/main2.dir/src/main.cpp.o: CMakeFiles/main2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/elijah/cg/finalproj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main2.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main2.dir/src/main.cpp.o -MF CMakeFiles/main2.dir/src/main.cpp.o.d -o CMakeFiles/main2.dir/src/main.cpp.o -c /Users/elijah/cg/finalproj/src/main.cpp

CMakeFiles/main2.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main2.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/elijah/cg/finalproj/src/main.cpp > CMakeFiles/main2.dir/src/main.cpp.i

CMakeFiles/main2.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main2.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/elijah/cg/finalproj/src/main.cpp -o CMakeFiles/main2.dir/src/main.cpp.s

CMakeFiles/main2.dir/component/particlesys.cpp.o: CMakeFiles/main2.dir/flags.make
CMakeFiles/main2.dir/component/particlesys.cpp.o: /Users/elijah/cg/finalproj/component/particlesys.cpp
CMakeFiles/main2.dir/component/particlesys.cpp.o: CMakeFiles/main2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/elijah/cg/finalproj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main2.dir/component/particlesys.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main2.dir/component/particlesys.cpp.o -MF CMakeFiles/main2.dir/component/particlesys.cpp.o.d -o CMakeFiles/main2.dir/component/particlesys.cpp.o -c /Users/elijah/cg/finalproj/component/particlesys.cpp

CMakeFiles/main2.dir/component/particlesys.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main2.dir/component/particlesys.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/elijah/cg/finalproj/component/particlesys.cpp > CMakeFiles/main2.dir/component/particlesys.cpp.i

CMakeFiles/main2.dir/component/particlesys.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main2.dir/component/particlesys.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/elijah/cg/finalproj/component/particlesys.cpp -o CMakeFiles/main2.dir/component/particlesys.cpp.s

CMakeFiles/main2.dir/component/camera.cpp.o: CMakeFiles/main2.dir/flags.make
CMakeFiles/main2.dir/component/camera.cpp.o: /Users/elijah/cg/finalproj/component/camera.cpp
CMakeFiles/main2.dir/component/camera.cpp.o: CMakeFiles/main2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/elijah/cg/finalproj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main2.dir/component/camera.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main2.dir/component/camera.cpp.o -MF CMakeFiles/main2.dir/component/camera.cpp.o.d -o CMakeFiles/main2.dir/component/camera.cpp.o -c /Users/elijah/cg/finalproj/component/camera.cpp

CMakeFiles/main2.dir/component/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main2.dir/component/camera.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/elijah/cg/finalproj/component/camera.cpp > CMakeFiles/main2.dir/component/camera.cpp.i

CMakeFiles/main2.dir/component/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main2.dir/component/camera.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/elijah/cg/finalproj/component/camera.cpp -o CMakeFiles/main2.dir/component/camera.cpp.s

CMakeFiles/main2.dir/component/background.cpp.o: CMakeFiles/main2.dir/flags.make
CMakeFiles/main2.dir/component/background.cpp.o: /Users/elijah/cg/finalproj/component/background.cpp
CMakeFiles/main2.dir/component/background.cpp.o: CMakeFiles/main2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/elijah/cg/finalproj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main2.dir/component/background.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main2.dir/component/background.cpp.o -MF CMakeFiles/main2.dir/component/background.cpp.o.d -o CMakeFiles/main2.dir/component/background.cpp.o -c /Users/elijah/cg/finalproj/component/background.cpp

CMakeFiles/main2.dir/component/background.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main2.dir/component/background.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/elijah/cg/finalproj/component/background.cpp > CMakeFiles/main2.dir/component/background.cpp.i

CMakeFiles/main2.dir/component/background.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main2.dir/component/background.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/elijah/cg/finalproj/component/background.cpp -o CMakeFiles/main2.dir/component/background.cpp.s

CMakeFiles/main2.dir/component/shader.cpp.o: CMakeFiles/main2.dir/flags.make
CMakeFiles/main2.dir/component/shader.cpp.o: /Users/elijah/cg/finalproj/component/shader.cpp
CMakeFiles/main2.dir/component/shader.cpp.o: CMakeFiles/main2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/elijah/cg/finalproj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main2.dir/component/shader.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main2.dir/component/shader.cpp.o -MF CMakeFiles/main2.dir/component/shader.cpp.o.d -o CMakeFiles/main2.dir/component/shader.cpp.o -c /Users/elijah/cg/finalproj/component/shader.cpp

CMakeFiles/main2.dir/component/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main2.dir/component/shader.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/elijah/cg/finalproj/component/shader.cpp > CMakeFiles/main2.dir/component/shader.cpp.i

CMakeFiles/main2.dir/component/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main2.dir/component/shader.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/elijah/cg/finalproj/component/shader.cpp -o CMakeFiles/main2.dir/component/shader.cpp.s

CMakeFiles/main2.dir/component/texture.cpp.o: CMakeFiles/main2.dir/flags.make
CMakeFiles/main2.dir/component/texture.cpp.o: /Users/elijah/cg/finalproj/component/texture.cpp
CMakeFiles/main2.dir/component/texture.cpp.o: CMakeFiles/main2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/elijah/cg/finalproj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/main2.dir/component/texture.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main2.dir/component/texture.cpp.o -MF CMakeFiles/main2.dir/component/texture.cpp.o.d -o CMakeFiles/main2.dir/component/texture.cpp.o -c /Users/elijah/cg/finalproj/component/texture.cpp

CMakeFiles/main2.dir/component/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main2.dir/component/texture.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/elijah/cg/finalproj/component/texture.cpp > CMakeFiles/main2.dir/component/texture.cpp.i

CMakeFiles/main2.dir/component/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main2.dir/component/texture.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/elijah/cg/finalproj/component/texture.cpp -o CMakeFiles/main2.dir/component/texture.cpp.s

CMakeFiles/main2.dir/component/stb_image.cpp.o: CMakeFiles/main2.dir/flags.make
CMakeFiles/main2.dir/component/stb_image.cpp.o: /Users/elijah/cg/finalproj/component/stb_image.cpp
CMakeFiles/main2.dir/component/stb_image.cpp.o: CMakeFiles/main2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/elijah/cg/finalproj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/main2.dir/component/stb_image.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main2.dir/component/stb_image.cpp.o -MF CMakeFiles/main2.dir/component/stb_image.cpp.o.d -o CMakeFiles/main2.dir/component/stb_image.cpp.o -c /Users/elijah/cg/finalproj/component/stb_image.cpp

CMakeFiles/main2.dir/component/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main2.dir/component/stb_image.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/elijah/cg/finalproj/component/stb_image.cpp > CMakeFiles/main2.dir/component/stb_image.cpp.i

CMakeFiles/main2.dir/component/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main2.dir/component/stb_image.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/elijah/cg/finalproj/component/stb_image.cpp -o CMakeFiles/main2.dir/component/stb_image.cpp.s

CMakeFiles/main2.dir/component/stb_image_write.cpp.o: CMakeFiles/main2.dir/flags.make
CMakeFiles/main2.dir/component/stb_image_write.cpp.o: /Users/elijah/cg/finalproj/component/stb_image_write.cpp
CMakeFiles/main2.dir/component/stb_image_write.cpp.o: CMakeFiles/main2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/elijah/cg/finalproj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/main2.dir/component/stb_image_write.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main2.dir/component/stb_image_write.cpp.o -MF CMakeFiles/main2.dir/component/stb_image_write.cpp.o.d -o CMakeFiles/main2.dir/component/stb_image_write.cpp.o -c /Users/elijah/cg/finalproj/component/stb_image_write.cpp

CMakeFiles/main2.dir/component/stb_image_write.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main2.dir/component/stb_image_write.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/elijah/cg/finalproj/component/stb_image_write.cpp > CMakeFiles/main2.dir/component/stb_image_write.cpp.i

CMakeFiles/main2.dir/component/stb_image_write.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main2.dir/component/stb_image_write.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/elijah/cg/finalproj/component/stb_image_write.cpp -o CMakeFiles/main2.dir/component/stb_image_write.cpp.s

# Object files for target main2
main2_OBJECTS = \
"CMakeFiles/main2.dir/src/main.cpp.o" \
"CMakeFiles/main2.dir/component/particlesys.cpp.o" \
"CMakeFiles/main2.dir/component/camera.cpp.o" \
"CMakeFiles/main2.dir/component/background.cpp.o" \
"CMakeFiles/main2.dir/component/shader.cpp.o" \
"CMakeFiles/main2.dir/component/texture.cpp.o" \
"CMakeFiles/main2.dir/component/stb_image.cpp.o" \
"CMakeFiles/main2.dir/component/stb_image_write.cpp.o"

# External object files for target main2
main2_EXTERNAL_OBJECTS =

main2: CMakeFiles/main2.dir/src/main.cpp.o
main2: CMakeFiles/main2.dir/component/particlesys.cpp.o
main2: CMakeFiles/main2.dir/component/camera.cpp.o
main2: CMakeFiles/main2.dir/component/background.cpp.o
main2: CMakeFiles/main2.dir/component/shader.cpp.o
main2: CMakeFiles/main2.dir/component/texture.cpp.o
main2: CMakeFiles/main2.dir/component/stb_image.cpp.o
main2: CMakeFiles/main2.dir/component/stb_image_write.cpp.o
main2: CMakeFiles/main2.dir/build.make
main2: /Library/Developer/CommandLineTools/SDKs/MacOSX15.1.sdk/System/Library/Frameworks/OpenGL.framework
main2: /usr/local/lib/libGLEW.2.2.0.dylib
main2: /usr/local/lib/libglfw.3.4.dylib
main2: CMakeFiles/main2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/elijah/cg/finalproj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable main2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main2.dir/build: main2
.PHONY : CMakeFiles/main2.dir/build

CMakeFiles/main2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main2.dir/clean

CMakeFiles/main2.dir/depend:
	cd /Users/elijah/cg/finalproj/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/elijah/cg/finalproj /Users/elijah/cg/finalproj /Users/elijah/cg/finalproj/build /Users/elijah/cg/finalproj/build /Users/elijah/cg/finalproj/build/CMakeFiles/main2.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/main2.dir/depend

