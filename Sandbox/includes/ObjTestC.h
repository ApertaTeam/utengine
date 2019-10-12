#ifndef SANDBOX_OBJ_TEST_C_H
#define SANDBOX_OBJ_TEST_C_H

#include <Object.h>

#include <TextWriter.h>

using namespace UT;

namespace UTSandbox
{
    class ObjTestC : public Object
    {
    public:
        ObjTestC();

        void Init() override;
        void Update() override;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    private:
        int testTextTexture;
        TextWriter testTextWriter;
        Font testFont;
    };
}

#endif