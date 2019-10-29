#ifndef SANDBOX_TILE_MAP_TEST_H
#define SANDBOX_TILE_MAP_TEST_H

#include <Object.h>
#include <TileMap.h>

using namespace UT;

namespace UTSandbox
{
    class TileMapTest : public Object
    {
    public:
        TileMapTest();

        void Init() override;
        void Update(float delta) override;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    private:
        TileMap map;
        int tileset;
    };
}

#endif