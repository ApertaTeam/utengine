#include "TileMapTest.h"

#include <TextureHandler.h>

namespace UTSandbox
{
    TileMapTest::TileMapTest()
        : tileset(TextureHandler::LoadTextureFromFile("tileset.png"))
    {
        
    }

    void TileMapTest::Init()
    {
        TileSet set = {{0, sf::IntRect(300, 120, 20, 20)}};
        
        int x = 0, y = 0;
        int column = 0;
        for (int i = 1; i < 112; ++i, ++column)
        {
            if (column == 16)
            {
                column = 0;
                y += 20;
                x = 0;
            }

            set[i] = sf::IntRect(x, y, 20, 20);
            x += 20;
        }

        set[set.size()] = sf::IntRect(60, 70, 20, 20);
        set[set.size()] = sf::IntRect(40, 70, 20, 20);
        set[set.size()] = sf::IntRect(80, 70, 20, 20);

        set[set.size()] = sf::IntRect(130, 10, 20, 20);
        
        map = TileMap(tileset, {
            {17,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36, 18},
            {21,  51,  52,  52,  52,  52,  52,  11,  12,  52,  52,  52,  52,  52,  53, 19},
            {21,  51,  52,  52,  52,  52,  52,  27,  28,  52,  52,  52,  52,  52,  53, 19},
            {21,  67,  68,  68,  68,  68,  68,  43,  44,  68,  68,  68,  68,  68,  69, 19},
            {21,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22, 19},
            {21,  22,   7, 115, 115,   8,  22,  22,  22,  22,   7, 115, 115,   8,  22, 19},
            {21,  22, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115,  22, 19},
            {21,  22, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115,  22, 19},
            {21,  22,  23, 115, 115,  24,  22,  22,  22,  22,  23, 115, 115,  24,  22, 19},
            {21,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22, 19},
            {21,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22, 19},
            {33,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4, 34},
        },set);
    }

    void TileMapTest::Update(float delta)
    {
        
    }

    void TileMapTest::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(map);
    }
}
