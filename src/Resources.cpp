#include "Resources.h"

#include <iostream>
#include <fstream>

#include <SOIL2/SOIL2.h>

#include "Logger.h"

namespace UT
{
    Resources::Resources()
    {
        
    }

    GLuint Resources::CreateProgram()
    {
        GLuint program = glCreateProgram();


        return program;
    }

    void Resources::LinkProgram(GLuint program, GLuint vertexShader, GLuint fragmentShader)
    {
        GLint isProgramLinked;

        glAttachShader(program, vertexShader);
        glAttachShader(program, fragmentShader);

        glLinkProgram(program);

        glGetProgramiv(program, GL_LINK_STATUS, &isProgramLinked);
        if (!isProgramLinked)
        {
            char infoLog[512];
            glGetProgramInfoLog(program, 512, NULL, infoLog);

            GlobalLogger->Log(Logger::Error, "Could not link program.\n" + std::string(infoLog));

            return;
        }

        glUseProgram(0);
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
            GlobalLogger->Log(Logger::Error, "Could not open shader file.\n" + shaderPath);
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

            GlobalLogger->Log(Logger::Error, "Could not compile shader.\n" + (std::string)infoLog);

            return -1;
        }


        return shader;
    }

    GLuint Resources::LoadTexture(const char* filename)
    {
        int widthVar, heightVar;

        return LoadTexture(filename, &widthVar, &heightVar);
    }

    GLuint Resources::LoadTexture(const char* filename, int* widthVar, int* heightVar)
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
            GlobalLogger->Log(Logger::Error, "Texture loading failed.\n" + (std::string)filename);
        }

        glActiveTexture(0);
        glBindTexture(GL_TEXTURE_2D, 0);
        SOIL_free_image_data(image);

        return texture;
    }
}