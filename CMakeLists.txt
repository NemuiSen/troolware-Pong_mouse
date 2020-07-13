cmake_minimum_required(VERSION 3.5)

project(Pong_mouse)

file(GLOB SRC "src/*.cpp")
include_directories(include)

add_executable(${PROJECT_NAME} ${SRC})
set(EXECUTABLE_OUTPUT_PATH ../bin)

set(glfw3_DIR "D:/Core/sen/programacion/cpp_libs/glfw/GLFW/lib/cmake/glfw3")
find_package(glfw3 3.3 REQUIRED)
target_link_libraries(${PROJECT_NAME} glfw)
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)
