cmake_minimum_required(VERSION 3.13)
project(utengine)

add_definitions("-std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(utengine)

add_subdirectory(src)
add_subdirectory(includes)
add_subdirectory(examples)

target_link_libraries(utengine ${CONAN_LIBS})