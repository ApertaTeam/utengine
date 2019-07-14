add_executable(example main.cpp ObjTest.cpp)
target_link_libraries(example ${CONAN_LIBS} utengine)

configure_file(assets/shaders/shaderVertexPlain.glsl ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets/shaders/shaderVertexPlain.glsl COPYONLY)
configure_file(assets/shaders/shaderFragmentPlain.glsl ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets/shaders/shaderFragmentPlain.glsl COPYONLY)