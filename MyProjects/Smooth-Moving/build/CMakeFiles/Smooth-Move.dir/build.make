# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:\OpenGL\MyProjects\Smooth-Moving

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\OpenGL\MyProjects\Smooth-Moving\build

# Include any dependencies generated for this target.
include CMakeFiles/Smooth-Move.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Smooth-Move.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Smooth-Move.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Smooth-Move.dir/flags.make

CMakeFiles/Smooth-Move.dir/src/main.cpp.obj: CMakeFiles/Smooth-Move.dir/flags.make
CMakeFiles/Smooth-Move.dir/src/main.cpp.obj: CMakeFiles/Smooth-Move.dir/includes_CXX.rsp
CMakeFiles/Smooth-Move.dir/src/main.cpp.obj: G:/OpenGL/MyProjects/Smooth-Moving/src/main.cpp
CMakeFiles/Smooth-Move.dir/src/main.cpp.obj: CMakeFiles/Smooth-Move.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=G:\OpenGL\MyProjects\Smooth-Moving\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Smooth-Move.dir/src/main.cpp.obj"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Smooth-Move.dir/src/main.cpp.obj -MF CMakeFiles\Smooth-Move.dir\src\main.cpp.obj.d -o CMakeFiles\Smooth-Move.dir\src\main.cpp.obj -c G:\OpenGL\MyProjects\Smooth-Moving\src\main.cpp

CMakeFiles/Smooth-Move.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Smooth-Move.dir/src/main.cpp.i"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\OpenGL\MyProjects\Smooth-Moving\src\main.cpp > CMakeFiles\Smooth-Move.dir\src\main.cpp.i

CMakeFiles/Smooth-Move.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Smooth-Move.dir/src/main.cpp.s"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\OpenGL\MyProjects\Smooth-Moving\src\main.cpp -o CMakeFiles\Smooth-Move.dir\src\main.cpp.s

CMakeFiles/Smooth-Move.dir/src/glad.c.obj: CMakeFiles/Smooth-Move.dir/flags.make
CMakeFiles/Smooth-Move.dir/src/glad.c.obj: CMakeFiles/Smooth-Move.dir/includes_C.rsp
CMakeFiles/Smooth-Move.dir/src/glad.c.obj: G:/OpenGL/MyProjects/Smooth-Moving/src/glad.c
CMakeFiles/Smooth-Move.dir/src/glad.c.obj: CMakeFiles/Smooth-Move.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=G:\OpenGL\MyProjects\Smooth-Moving\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Smooth-Move.dir/src/glad.c.obj"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Smooth-Move.dir/src/glad.c.obj -MF CMakeFiles\Smooth-Move.dir\src\glad.c.obj.d -o CMakeFiles\Smooth-Move.dir\src\glad.c.obj -c G:\OpenGL\MyProjects\Smooth-Moving\src\glad.c

CMakeFiles/Smooth-Move.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Smooth-Move.dir/src/glad.c.i"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E G:\OpenGL\MyProjects\Smooth-Moving\src\glad.c > CMakeFiles\Smooth-Move.dir\src\glad.c.i

CMakeFiles/Smooth-Move.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Smooth-Move.dir/src/glad.c.s"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S G:\OpenGL\MyProjects\Smooth-Moving\src\glad.c -o CMakeFiles\Smooth-Move.dir\src\glad.c.s

CMakeFiles/Smooth-Move.dir/src/vao.cpp.obj: CMakeFiles/Smooth-Move.dir/flags.make
CMakeFiles/Smooth-Move.dir/src/vao.cpp.obj: CMakeFiles/Smooth-Move.dir/includes_CXX.rsp
CMakeFiles/Smooth-Move.dir/src/vao.cpp.obj: G:/OpenGL/MyProjects/Smooth-Moving/src/vao.cpp
CMakeFiles/Smooth-Move.dir/src/vao.cpp.obj: CMakeFiles/Smooth-Move.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=G:\OpenGL\MyProjects\Smooth-Moving\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Smooth-Move.dir/src/vao.cpp.obj"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Smooth-Move.dir/src/vao.cpp.obj -MF CMakeFiles\Smooth-Move.dir\src\vao.cpp.obj.d -o CMakeFiles\Smooth-Move.dir\src\vao.cpp.obj -c G:\OpenGL\MyProjects\Smooth-Moving\src\vao.cpp

CMakeFiles/Smooth-Move.dir/src/vao.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Smooth-Move.dir/src/vao.cpp.i"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\OpenGL\MyProjects\Smooth-Moving\src\vao.cpp > CMakeFiles\Smooth-Move.dir\src\vao.cpp.i

CMakeFiles/Smooth-Move.dir/src/vao.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Smooth-Move.dir/src/vao.cpp.s"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\OpenGL\MyProjects\Smooth-Moving\src\vao.cpp -o CMakeFiles\Smooth-Move.dir\src\vao.cpp.s

CMakeFiles/Smooth-Move.dir/src/vbo.cpp.obj: CMakeFiles/Smooth-Move.dir/flags.make
CMakeFiles/Smooth-Move.dir/src/vbo.cpp.obj: CMakeFiles/Smooth-Move.dir/includes_CXX.rsp
CMakeFiles/Smooth-Move.dir/src/vbo.cpp.obj: G:/OpenGL/MyProjects/Smooth-Moving/src/vbo.cpp
CMakeFiles/Smooth-Move.dir/src/vbo.cpp.obj: CMakeFiles/Smooth-Move.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=G:\OpenGL\MyProjects\Smooth-Moving\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Smooth-Move.dir/src/vbo.cpp.obj"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Smooth-Move.dir/src/vbo.cpp.obj -MF CMakeFiles\Smooth-Move.dir\src\vbo.cpp.obj.d -o CMakeFiles\Smooth-Move.dir\src\vbo.cpp.obj -c G:\OpenGL\MyProjects\Smooth-Moving\src\vbo.cpp

CMakeFiles/Smooth-Move.dir/src/vbo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Smooth-Move.dir/src/vbo.cpp.i"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\OpenGL\MyProjects\Smooth-Moving\src\vbo.cpp > CMakeFiles\Smooth-Move.dir\src\vbo.cpp.i

CMakeFiles/Smooth-Move.dir/src/vbo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Smooth-Move.dir/src/vbo.cpp.s"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\OpenGL\MyProjects\Smooth-Moving\src\vbo.cpp -o CMakeFiles\Smooth-Move.dir\src\vbo.cpp.s

CMakeFiles/Smooth-Move.dir/src/ebo.cpp.obj: CMakeFiles/Smooth-Move.dir/flags.make
CMakeFiles/Smooth-Move.dir/src/ebo.cpp.obj: CMakeFiles/Smooth-Move.dir/includes_CXX.rsp
CMakeFiles/Smooth-Move.dir/src/ebo.cpp.obj: G:/OpenGL/MyProjects/Smooth-Moving/src/ebo.cpp
CMakeFiles/Smooth-Move.dir/src/ebo.cpp.obj: CMakeFiles/Smooth-Move.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=G:\OpenGL\MyProjects\Smooth-Moving\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Smooth-Move.dir/src/ebo.cpp.obj"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Smooth-Move.dir/src/ebo.cpp.obj -MF CMakeFiles\Smooth-Move.dir\src\ebo.cpp.obj.d -o CMakeFiles\Smooth-Move.dir\src\ebo.cpp.obj -c G:\OpenGL\MyProjects\Smooth-Moving\src\ebo.cpp

CMakeFiles/Smooth-Move.dir/src/ebo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Smooth-Move.dir/src/ebo.cpp.i"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\OpenGL\MyProjects\Smooth-Moving\src\ebo.cpp > CMakeFiles\Smooth-Move.dir\src\ebo.cpp.i

CMakeFiles/Smooth-Move.dir/src/ebo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Smooth-Move.dir/src/ebo.cpp.s"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\OpenGL\MyProjects\Smooth-Moving\src\ebo.cpp -o CMakeFiles\Smooth-Move.dir\src\ebo.cpp.s

CMakeFiles/Smooth-Move.dir/src/stb.cpp.obj: CMakeFiles/Smooth-Move.dir/flags.make
CMakeFiles/Smooth-Move.dir/src/stb.cpp.obj: CMakeFiles/Smooth-Move.dir/includes_CXX.rsp
CMakeFiles/Smooth-Move.dir/src/stb.cpp.obj: G:/OpenGL/MyProjects/Smooth-Moving/src/stb.cpp
CMakeFiles/Smooth-Move.dir/src/stb.cpp.obj: CMakeFiles/Smooth-Move.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=G:\OpenGL\MyProjects\Smooth-Moving\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Smooth-Move.dir/src/stb.cpp.obj"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Smooth-Move.dir/src/stb.cpp.obj -MF CMakeFiles\Smooth-Move.dir\src\stb.cpp.obj.d -o CMakeFiles\Smooth-Move.dir\src\stb.cpp.obj -c G:\OpenGL\MyProjects\Smooth-Moving\src\stb.cpp

CMakeFiles/Smooth-Move.dir/src/stb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Smooth-Move.dir/src/stb.cpp.i"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\OpenGL\MyProjects\Smooth-Moving\src\stb.cpp > CMakeFiles\Smooth-Move.dir\src\stb.cpp.i

CMakeFiles/Smooth-Move.dir/src/stb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Smooth-Move.dir/src/stb.cpp.s"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\OpenGL\MyProjects\Smooth-Moving\src\stb.cpp -o CMakeFiles\Smooth-Move.dir\src\stb.cpp.s

CMakeFiles/Smooth-Move.dir/src/shader.cpp.obj: CMakeFiles/Smooth-Move.dir/flags.make
CMakeFiles/Smooth-Move.dir/src/shader.cpp.obj: CMakeFiles/Smooth-Move.dir/includes_CXX.rsp
CMakeFiles/Smooth-Move.dir/src/shader.cpp.obj: G:/OpenGL/MyProjects/Smooth-Moving/src/shader.cpp
CMakeFiles/Smooth-Move.dir/src/shader.cpp.obj: CMakeFiles/Smooth-Move.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=G:\OpenGL\MyProjects\Smooth-Moving\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Smooth-Move.dir/src/shader.cpp.obj"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Smooth-Move.dir/src/shader.cpp.obj -MF CMakeFiles\Smooth-Move.dir\src\shader.cpp.obj.d -o CMakeFiles\Smooth-Move.dir\src\shader.cpp.obj -c G:\OpenGL\MyProjects\Smooth-Moving\src\shader.cpp

CMakeFiles/Smooth-Move.dir/src/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Smooth-Move.dir/src/shader.cpp.i"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\OpenGL\MyProjects\Smooth-Moving\src\shader.cpp > CMakeFiles\Smooth-Move.dir\src\shader.cpp.i

CMakeFiles/Smooth-Move.dir/src/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Smooth-Move.dir/src/shader.cpp.s"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\OpenGL\MyProjects\Smooth-Moving\src\shader.cpp -o CMakeFiles\Smooth-Move.dir\src\shader.cpp.s

CMakeFiles/Smooth-Move.dir/src/texture.cpp.obj: CMakeFiles/Smooth-Move.dir/flags.make
CMakeFiles/Smooth-Move.dir/src/texture.cpp.obj: CMakeFiles/Smooth-Move.dir/includes_CXX.rsp
CMakeFiles/Smooth-Move.dir/src/texture.cpp.obj: G:/OpenGL/MyProjects/Smooth-Moving/src/texture.cpp
CMakeFiles/Smooth-Move.dir/src/texture.cpp.obj: CMakeFiles/Smooth-Move.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=G:\OpenGL\MyProjects\Smooth-Moving\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Smooth-Move.dir/src/texture.cpp.obj"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Smooth-Move.dir/src/texture.cpp.obj -MF CMakeFiles\Smooth-Move.dir\src\texture.cpp.obj.d -o CMakeFiles\Smooth-Move.dir\src\texture.cpp.obj -c G:\OpenGL\MyProjects\Smooth-Moving\src\texture.cpp

CMakeFiles/Smooth-Move.dir/src/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Smooth-Move.dir/src/texture.cpp.i"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\OpenGL\MyProjects\Smooth-Moving\src\texture.cpp > CMakeFiles\Smooth-Move.dir\src\texture.cpp.i

CMakeFiles/Smooth-Move.dir/src/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Smooth-Move.dir/src/texture.cpp.s"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\OpenGL\MyProjects\Smooth-Moving\src\texture.cpp -o CMakeFiles\Smooth-Move.dir\src\texture.cpp.s

CMakeFiles/Smooth-Move.dir/src/camera.cpp.obj: CMakeFiles/Smooth-Move.dir/flags.make
CMakeFiles/Smooth-Move.dir/src/camera.cpp.obj: CMakeFiles/Smooth-Move.dir/includes_CXX.rsp
CMakeFiles/Smooth-Move.dir/src/camera.cpp.obj: G:/OpenGL/MyProjects/Smooth-Moving/src/camera.cpp
CMakeFiles/Smooth-Move.dir/src/camera.cpp.obj: CMakeFiles/Smooth-Move.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=G:\OpenGL\MyProjects\Smooth-Moving\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Smooth-Move.dir/src/camera.cpp.obj"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Smooth-Move.dir/src/camera.cpp.obj -MF CMakeFiles\Smooth-Move.dir\src\camera.cpp.obj.d -o CMakeFiles\Smooth-Move.dir\src\camera.cpp.obj -c G:\OpenGL\MyProjects\Smooth-Moving\src\camera.cpp

CMakeFiles/Smooth-Move.dir/src/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Smooth-Move.dir/src/camera.cpp.i"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\OpenGL\MyProjects\Smooth-Moving\src\camera.cpp > CMakeFiles\Smooth-Move.dir\src\camera.cpp.i

CMakeFiles/Smooth-Move.dir/src/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Smooth-Move.dir/src/camera.cpp.s"
	D:\Scoop\apps\mingw\13.1.0-rt_v11-rev1\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\OpenGL\MyProjects\Smooth-Moving\src\camera.cpp -o CMakeFiles\Smooth-Move.dir\src\camera.cpp.s

# Object files for target Smooth-Move
Smooth__Move_OBJECTS = \
"CMakeFiles/Smooth-Move.dir/src/main.cpp.obj" \
"CMakeFiles/Smooth-Move.dir/src/glad.c.obj" \
"CMakeFiles/Smooth-Move.dir/src/vao.cpp.obj" \
"CMakeFiles/Smooth-Move.dir/src/vbo.cpp.obj" \
"CMakeFiles/Smooth-Move.dir/src/ebo.cpp.obj" \
"CMakeFiles/Smooth-Move.dir/src/stb.cpp.obj" \
"CMakeFiles/Smooth-Move.dir/src/shader.cpp.obj" \
"CMakeFiles/Smooth-Move.dir/src/texture.cpp.obj" \
"CMakeFiles/Smooth-Move.dir/src/camera.cpp.obj"

# External object files for target Smooth-Move
Smooth__Move_EXTERNAL_OBJECTS =

G:/OpenGL/MyProjects/Smooth-Moving/Smooth-Move.exe: CMakeFiles/Smooth-Move.dir/src/main.cpp.obj
G:/OpenGL/MyProjects/Smooth-Moving/Smooth-Move.exe: CMakeFiles/Smooth-Move.dir/src/glad.c.obj
G:/OpenGL/MyProjects/Smooth-Moving/Smooth-Move.exe: CMakeFiles/Smooth-Move.dir/src/vao.cpp.obj
G:/OpenGL/MyProjects/Smooth-Moving/Smooth-Move.exe: CMakeFiles/Smooth-Move.dir/src/vbo.cpp.obj
G:/OpenGL/MyProjects/Smooth-Moving/Smooth-Move.exe: CMakeFiles/Smooth-Move.dir/src/ebo.cpp.obj
G:/OpenGL/MyProjects/Smooth-Moving/Smooth-Move.exe: CMakeFiles/Smooth-Move.dir/src/stb.cpp.obj
G:/OpenGL/MyProjects/Smooth-Moving/Smooth-Move.exe: CMakeFiles/Smooth-Move.dir/src/shader.cpp.obj
G:/OpenGL/MyProjects/Smooth-Moving/Smooth-Move.exe: CMakeFiles/Smooth-Move.dir/src/texture.cpp.obj
G:/OpenGL/MyProjects/Smooth-Moving/Smooth-Move.exe: CMakeFiles/Smooth-Move.dir/src/camera.cpp.obj
G:/OpenGL/MyProjects/Smooth-Moving/Smooth-Move.exe: CMakeFiles/Smooth-Move.dir/build.make
G:/OpenGL/MyProjects/Smooth-Moving/Smooth-Move.exe: lib/glfw-3.4/src/libglfw3.a
G:/OpenGL/MyProjects/Smooth-Moving/Smooth-Move.exe: CMakeFiles/Smooth-Move.dir/linkLibs.rsp
G:/OpenGL/MyProjects/Smooth-Moving/Smooth-Move.exe: CMakeFiles/Smooth-Move.dir/objects1.rsp
G:/OpenGL/MyProjects/Smooth-Moving/Smooth-Move.exe: CMakeFiles/Smooth-Move.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=G:\OpenGL\MyProjects\Smooth-Moving\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable G:\OpenGL\MyProjects\Smooth-Moving\Smooth-Move.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Smooth-Move.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Smooth-Move.dir/build: G:/OpenGL/MyProjects/Smooth-Moving/Smooth-Move.exe
.PHONY : CMakeFiles/Smooth-Move.dir/build

CMakeFiles/Smooth-Move.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Smooth-Move.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Smooth-Move.dir/clean

CMakeFiles/Smooth-Move.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\OpenGL\MyProjects\Smooth-Moving G:\OpenGL\MyProjects\Smooth-Moving G:\OpenGL\MyProjects\Smooth-Moving\build G:\OpenGL\MyProjects\Smooth-Moving\build G:\OpenGL\MyProjects\Smooth-Moving\build\CMakeFiles\Smooth-Move.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Smooth-Move.dir/depend

