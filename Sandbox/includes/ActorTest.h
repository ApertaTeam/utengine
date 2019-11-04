#ifndef SANDBOX_ACTOR_TEST_H
#define SANDBOX_ACTOR_TEST_H

#include <Actor.h>

using namespace UT;

namespace UTSandbox
{
    class ActorTest : public Actor
    {
    public:
        ActorTest();

        void Init() override;
        void OnUpdate(float delta) override;
        void OnDraw(sf::RenderTarget& target, sf::RenderStates states) const override;

        void Run() override;

    private:
        int testTexture;
    };
}
#endif