#include "ActorTest.h"

#include <TextureHandler.h>

namespace UTSandbox
{
    ActorTest::ActorTest()
        : testTexture(TextureHandler::LoadTextureFromFile("tileset.png"))
    {
    }

    void ActorTest::Init()
    {
        std::vector<Sprite> testSprites = {
            Sprite(testTexture, {0, 0, 20, 20}),
            Sprite(testTexture, {20, 0, 20, 20})
        };

        sprite = AnimatedSprite(testSprites);

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

    void ActorTest::Interact()
    {

    }
}