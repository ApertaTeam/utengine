#ifndef UT_RESOURCES_H
#define UT_RESOURCES_H

#include <string>

#include "GL/glew.h"

namespace UT
{
    class Resources
    {
    public:
        Resources();

        static GLuint LoadShader(std::string shaderPath, GLenum shaderType);
        static GLuint loadTexture(const char* filename);
        static GLuint loadTexture(const char* filename, int* widthVar, int* heightVar);

    private:

    };
}

#endif