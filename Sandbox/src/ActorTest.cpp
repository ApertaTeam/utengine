#include "ActorTest.h"

#include <AssetHandler.h>

namespace UTSandbox
{
    ActorTest::ActorTest()
        : testTexture(AssetHandler::LoadTextureFromFile("tileset.png"))
    {
    }

    void ActorTest::Init()
    {
        std::vector<sf::IntRect> testSprites = {
            {0, 0, 20, 20},
            {20, 0, 20, 20}
        };

        sprite = AnimatedSprite(testTexture, testSprites);

        speed = 1000;

        MoveTo({ 60, 60 });
    }
    
    void ActorTest::OnUpdate(float delta)
    {
        sprite.Update(delta);

        sprite.setPosition(position.x, position.y);
    }

    void ActorTest::OnDraw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(sprite);
    }

    void ActorTest::Run()
    {

    }
}