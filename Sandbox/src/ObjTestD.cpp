#include "ObjTestD.h"

#include <TextureHandler.h>

namespace UTSandbox
{
    ObjTestD::ObjTestD()
        : testAnimatedTexture(TextureHandler::LoadTextureFromFile("tileset.png"))
    {
    }

    void ObjTestD::Init()
    {
        std::vector<Sprite> testSprites = {
            Sprite(testAnimatedTexture, {40, 20, 20, 20}),
            Sprite(testAnimatedTexture, {60, 20, 20, 20}),
            Sprite(testAnimatedTexture, {80, 20, 20, 20}),

            Sprite(testAnimatedTexture, {40, 40, 20, 20}),
            Sprite(testAnimatedTexture, {60, 40, 20, 20}),
            Sprite(testAnimatedTexture, {80, 40, 20, 20}),

            Sprite(testAnimatedTexture, {40, 60, 20, 20}),
            Sprite(testAnimatedTexture, {60, 60, 20, 20}),
            Sprite(testAnimatedTexture, {80, 60, 20, 20}),
        };

        testAnimatedSprite = AnimatedSprite(testSprites, 10);
    }

    void ObjTestD::Update(float delta)
    {
        if (InputHandler::IsInputHeld(InputActions::Confirm))
        {
            testAnimatedSprite.setPosition(testAnimatedSprite.getPosition().x + 4, testAnimatedSprite.getPosition().y + 4);
        }

        testAnimatedSprite.Update(delta);
    }

    void ObjTestD::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(testAnimatedSprite);
    }
}