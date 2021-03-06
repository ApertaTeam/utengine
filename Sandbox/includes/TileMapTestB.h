#ifndef SANDBOX_TILE_MAP_TEST_B_H
#define SANDBOX_TILE_MAP_TEST_B_H

#include <Object.h>
#include <TileMap.h>

using namespace UT;

namespace UTSandbox
{
    class TileMapTestB : public TileMap
    {
    public:
        TileMapTestB();

        void Init() override;
        void Update(float delta) override;
    };
}

#endif