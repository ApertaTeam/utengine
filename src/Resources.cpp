#include "Resources.h"

#include <iostream>
#include <fstream>

namespace UT
{
    Resources::Resources()
    {
        
    }

    GLuint Resources::LoadShader(std::string shaderPath, GLenum shaderType)
    {
        GLint isShaderCompiled;

        std::string src = "";

        // Open and read shader
        std::ifstream in_file;
        in_file.open(shaderPath);

        if (in_file.is_open())
        {
            std::string temp = "";

            while (std::getline(in_file, temp))
            {
                src += temp + "\n";
            }
        }
        else
        {
            std::cout << "ERROR: Could not open shader file.\n" << shaderPath << std::endl;
            return -1;
        }

        in_file.close();


        // Compile shader
        GLuint shader = glCreateShader(shaderType);
        const GLchar* shaderSrc = src.c_str();

        glShaderSource(shader, 1, &shaderSrc, NULL);
        glCompileShader(shader);

        glGetShaderiv(shader, GL_COMPILE_STATUS, &isShaderCompiled);
        if (!isShaderCompiled)
        {
            char infoLog[512];
            glGetShaderInfoLog(shader, 512, NULL, infoLog);

            std::cout << "ERROR: Could not compile shader." << std::endl;
            std::cout << infoLog << std::endl;

            return -1;
        }


        return shader;
    }

    GLuint Resources::loadTexture(const char* filename)
    {
        int image_width = 0;
        int image_height = 0;

        GLuint texture = loadTexture(filename, &image_width, &image_height);

        return texture;
    }

    GLuint Resources::loadTexture(const char* filename, int* widthVar, int* heightVar)
    {
        unsigned char* image = SOIL_load_image(filename, widthVar, heightVar, NULL, SOIL_LOAD_RGBA);

        GLuint texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


        if (image)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, *widthVar, *heightVar, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            std::cout << "ERROR: Texture loading failed.\n" << filename << std::endl;
        }

        glActiveTexture(0);
        glBindTexture(GL_TEXTURE_2D, 0);
        SOIL_free_image_data(image);

        return texture;
    }
}