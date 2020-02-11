#ifndef SANDBOX_OBJ_TEST_D_H
#define SANDBOX_OBJ_TEST_D_H

#include <Object.h>
#include <AnimatedSprite.h>
#include <Input.h>
#include <Interactable.h>

using namespace UT;

namespace UTSandbox
{
    class ObjTestD : public Interactable
    {
    public:
        ObjTestD();

        void Init() override;
        void Update(float delta) override;
        void Run() override;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    private:
        int testAnimatedTexture;
        AnimatedSprite testAnimatedSprite;
        AnimatedSprite characterSprite;

        bool isRunning = false;
    };
}

#endif