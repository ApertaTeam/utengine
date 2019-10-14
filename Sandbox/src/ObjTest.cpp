#include "ObjTest.h"

#include <TextureHandler.h>

namespace UTSandbox
{
    ObjTest::ObjTest()
        :   testTexture(TextureHandler::LoadTextureFromFile("test.png")),
            testTileset(TextureHandler::LoadTextureFromFile("tileset.png"))
    {
    }

    void ObjTest::Init()
    {
        TileSet set =
        {
            {0, Sprite(testTileset, {100, 0, 20, 20})},
            {1, Sprite(testTileset, {100, 20, 20, 20})},
            {2, Sprite(testTileset, {120, 0, 20, 20})},
            {3, Sprite(testTileset, {140, 0, 20, 20})},
            {4, Sprite(testTileset, {120, 20, 20, 20})},
            {5, Sprite(testTileset, {140, 20, 20, 20})}
        };
        TileGrid grid =
        {
            {2, 0, 0, 3},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {4, 0, 0, 5}
        };
        testMap = TileMap(grid, set);
        testSprite = Sprite(testTexture, {0, 0, 215, 215});
        testSprite.setPosition((640.f/2)-(215.f/2), (480.f/2)-(215.f/2));
    }

    void ObjTest::Update(float delta)
    {
        // No updating necessary
    }

    void ObjTest::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(testSprite, states);
        target.draw(testMap, states);
    }
}