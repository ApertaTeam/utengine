#ifndef SANDBOX_SECONDARY_TILE_MAP_TEST_H
#define SANDBOX_SECONDARY_TILE_MAP_TEST_H

#include <Object.h>
#include <TileMap.h>

using namespace UT;

namespace UTSandbox
{
    class SecondaryTileMapTest : public TileMap
    {
    public:
        SecondaryTileMapTest();

        void Init() override;
        void Update(float delta) override;
    };
}

#endif