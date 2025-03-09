cmake_minimum_required(VERSION 3.31.2)
project(RaylibNvimTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED False)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# add_compile_definitions(SUPPORT_TRACELOG)
# set(CMAKE_BUILD_TYPE Debug)

find_package(raylib CONFIG REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
