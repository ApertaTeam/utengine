#include "Shader.h"

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
    }

    Shader::~Shader()
    {
    }

    void Shader::Bind() const
    {
    }

    void Shader::Unbind() const
    {
    }
};