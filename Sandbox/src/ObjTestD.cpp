#include "ObjTestD.h"

#include <TextureHandler.h>

#include <iostream>

namespace UTSandbox
{
    ObjTestD::ObjTestD()
        : testAnimatedTexture(TextureHandler::LoadTextureFromFile("tileset.png"))
    {
    }

    void ObjTestD::Init()
    {
        std::vector<sf::IntRect> testRects = {
            {40, 20, 20, 20},
            {60, 20, 20, 20},
            {80, 20, 20, 20},

            {40, 40, 20, 20},
            {60, 40, 20, 20},
            {80, 40, 20, 20},

            {40, 60, 20, 20},
            {60, 60, 20, 20},
            {80, 60, 20, 20},
        };

        testAnimatedSprite = AnimatedSprite(testAnimatedTexture, testRects, 10);
        testAnimatedSprite.setPosition(200, 160);
        setPosition(testAnimatedSprite.getPosition());

        collisionBox = { 0, 15, 20, 5 };
    }

    void ObjTestD::Update(float delta)
    {
        testAnimatedSprite.Update(delta);
    }

    void ObjTestD::Interact()
    {
        if (InputHandler::IsInputPressed(InputActions::Confirm))
        {
            std::cout << "Interation confirmed." << std::endl;
        }
    }

    void ObjTestD::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(testAnimatedSprite);
    }
}