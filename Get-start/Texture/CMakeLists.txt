# build
cmake_minimum_required(VERSION 3.5)
project (texture-demo)

# OpenGL
find_package( OpenGL REQUIRED )
include_directories( ${OPENGL_INCLUDE_DIRS} )

add_subdirectory(lib/glfw-3.4 EXCLUDE_FROM_ALL)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# src inc include 
set(SOURCES src/main.cpp src/glad.c src/vao.cpp src/vbo.cpp src/ebo.cpp src/stb.cpp 
src/shader.cpp)
add_executable(texture-demo ${SOURCES})
target_include_directories(texture-demo PUBLIC ${PROJECT_SOURCE_DIR}/inc ${PROJECT_SOURCE_DIR}/include)

# Link
target_link_libraries(texture-demo PRIVATE glfw)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

if(CMAKE_SYSTEM_NAME MATCHES "Linux")

elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -fexec-charset=GBK")#Windows 编码问题
endif()

# debug

message("CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message("PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")

message("SOURCES: ${SOURCES}")





