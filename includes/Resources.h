#ifndef UT_RESOURCES_H
#define UT_RESOURCES_H

#include <string>

#include <GL/glew.h>

namespace UT
{
    // Handles resource management/loading
    class Resources
    {
    public:
        static void LinkProgram(GLuint program, GLuint vertexShader, GLuint fragmentShader);
        static GLuint LoadShader(std::string shaderPath, GLenum shaderType);
        static GLuint LoadTexture(const char* filename);
        static GLuint LoadTexture(const char* filename, int* widthVar, int* heightVar);

    private:
        Resources();
    };
}

#endif