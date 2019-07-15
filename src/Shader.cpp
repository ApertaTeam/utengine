#include "Shader.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Resources.h"
#include "Common.h"

namespace UT
{
    Shader::Shader()
    {
        glID = 0;
    }
    
    Shader::Shader(const std::string& vertPath, const std::string& fragPath)
    {
        glID = glCreateProgram();
        Resources::LinkProgram(glID, Resources::LoadShader(GetExecutableDirectory() + vertPath, GL_VERTEX_SHADER), Resources::LoadShader(GetExecutableDirectory() + fragPath, GL_FRAGMENT_SHADER));
    }

    Shader::~Shader()
    {
        glDeleteProgram(glID);
    }

    void Shader::Bind() const
    {
        glUseProgram(glID);
    }

    void Shader::Unbind() const
    {
        glUseProgram(0);
    }

    template<>
    void Shader::SetUniform<glm::mat4>(const std::string& name, const glm::mat4& value)
    {
        glUniformMatrix4fv(glGetUniformLocation(glID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
    }

    template<>
    void Shader::SetUniform<int>(const std::string& name, const int& value)
    {
        glUniform1i(glGetUniformLocation(glID, name.c_str()), value);
    }
};