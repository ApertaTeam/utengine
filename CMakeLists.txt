cmake_minimum_required(VERSION 3.13)
project(utengine)

add_definitions("-std=c++11")

option(BUILD_EXAMPLES "BUILD_EXAMPLES" ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(utengine)

add_subdirectory(src)
add_subdirectory(includes)

if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif(BUILD_EXAMPLES)

target_link_libraries(utengine ${CONAN_LIBS})