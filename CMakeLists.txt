cmake_minimum_required(VERSION 2.8)
project(utengine)

set(CMAKE_CXX_STANDARD 11)

find_package(glfw3 3.3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)
add_library(SOIL2 STATIC IMPORTED)

if(WIN32)
    set_target_properties(SOIL2 PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/dependencies/SOIL2/win32/soil2.lib)
elseif(UNIX AND NOT APPLE)
    set_target_properties(SOIL2 PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/dependencies/SOIL2/linux/libsoil2.a)
elseif(UNIX AND APPLE)
    set_target_properties(SOIL2 PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/dependencies/SOIL2/macos/libsoil2.a)
endif(WIN32)

include_directories(includes/
                    ${GLEW_INCLUDE_DIRS}
                    ${OPENGL_INCLUDE_DIR}
                    ${GLM_INCLUDE_DIRS}
                    dependencies/SOIL2/includes/)

file(GLOB PROJECT_HEADERS includes/*.h)
file(GLOB PROJECT_SOURCES src/*.cpp)

source_group("Headers" FILES ${PROJECT_HEADERS})
source_group("Sources" FILES ${PROJECT_SOURCES})

add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES} ${PROJECT_HEADERS})
target_link_libraries(${PROJECT_NAME} GLEW::GLEW
    ${OPENGL_gl_LIBRARY}
    glfw
    SOIL2)
