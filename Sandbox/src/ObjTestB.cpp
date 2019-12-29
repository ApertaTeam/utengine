#include "ObjTestB.h"

#include <AssetHandler.h>

namespace UTSandbox
{
    ObjTestB::ObjTestB()
        : testRectTexture(AssetHandler::LoadTextureFromFile("rectslice.png"))
    {
    }

    void ObjTestB::Init()
    {
        std::array<Sprite, 9> set =
        {
            Sprite(testRectTexture, {0, 0, 25, 25}),
            Sprite(testRectTexture, {25, 0, 25, 25}),
            Sprite(testRectTexture, {50, 0, 25, 25}),

            Sprite(testRectTexture, {0, 25, 25, 25}),
            Sprite(testRectTexture, {25, 25, 25, 25}),
            Sprite(testRectTexture, {50, 25, 25, 25}),

            Sprite(testRectTexture, {0, 50, 25, 25}),
            Sprite(testRectTexture, {25, 50, 25, 25}),
            Sprite(testRectTexture, {50, 50, 25, 25}),
        };

        sf::Rect rect = {20, 20, 620, 460};

        testRectangle9Slice = Rectangle9Slice(rect, set);


        testRectangle9Slice.MoveToRect({120, 140, 520, 340}, 1000);
    }

    void ObjTestB::Update(float delta)
    {
        testRectangle9Slice.Update(delta);
    }

    void ObjTestB::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(testRectangle9Slice, states);
    }
}