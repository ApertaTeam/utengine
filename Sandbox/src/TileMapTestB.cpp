#include "TileMapTestB.h"

#include <TextureHandler.h>

namespace UTSandbox
{
    TileMapTestB::TileMapTestB()
        : tileset(TextureHandler::LoadTextureFromFile("tileset.png"))
    {

    }

    void TileMapTestB::Init()
    {
        TileSet set = { {0, sf::IntRect(300, 120, 20, 20)} };

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
            { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
            { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
            { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
            { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
            { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
            { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
            { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
            { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
            { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  70,  71,  71,  0},
            { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  70,  71,  71,  0},
            { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  70,  71,  71,  0},
            { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
            }, set);
    }

    void TileMapTestB::Update(float delta)
    {

    }

    void TileMapTestB::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(map);
    }
}