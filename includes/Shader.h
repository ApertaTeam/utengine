#ifndef UT_SHADER_H
#define UT_SHADER_H

#include <string>

namespace UT
{
    class Shader
    {
    public:
        Shader(const std::string& vertPath, const std::string& fragPath);
        Shader();
        ~Shader();

        template<typename T>
        void SetUniform(const std::string& name, const T& value);

        void Bind() const;
        void Unbind() const;

        inline explicit operator int() const
        {
            return glID;
        }
    private:
        int glID;
    };
}

#endif