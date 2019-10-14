#ifndef SANDBOX_OBJ_TEST_D_H
#define SANDBOX_OBJ_TEST_D_H

#include <Object.h>
#include <AnimatedSprite.h>

using namespace UT;

namespace UTSandbox
{
    class ObjTestD : public Object
    {
    public:
        ObjTestD();

        void Init() override;
        void Update() override;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    private:
        int testAnimatedTexture;
        AnimatedSprite testAnimatedSprite;
        sf::Clock clock;
    };
}

#endif