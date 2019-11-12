#include "TileMapTestB.h"

#include <TextureHandler.h>

namespace UTSandbox
{
    TileMapTestB::TileMapTestB()
    {
        textureId = TextureHandler::LoadTextureFromFile("tileset.png");
    }

    void TileMapTestB::Init()
    {
        tileset = { {0, sf::IntRect(300, 120, 20, 20)} };

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

            tileset[i] = sf::IntRect(x, y, 20, 20);
            x += 20;
        }

        tileset[tileset.size()] = sf::IntRect(60, 70, 20, 20);
        tileset[tileset.size()] = sf::IntRect(40, 70, 20, 20);
        tileset[tileset.size()] = sf::IntRect(80, 70, 20, 20);

        tileset[tileset.size()] = sf::IntRect(130, 10, 20, 20);
        
        grid = {
            {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0},
            {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0},
            {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0},
            {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0},
            {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0},
            {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0},
            {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0},
            {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0},
            {0, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 0},
            {0, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 0},
            {0, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 0},
            {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0},
        };

        InitSystem(grid, tileset);
    }

    void TileMapTestB::Update(float delta)
    {
        
    }
}
