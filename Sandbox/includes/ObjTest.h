#ifndef SANDBOX_OBJ_TEST_H
#define SANDBOX_OBJ_TEST_H

#include <Object.h>
#include <TileMap.h>
#include <Sprite.h>

using namespace UT;

namespace UTSandbox
{
    class ObjTest : public Object
    {
    public:
        ObjTest();

        void Init() override;
        void Update() override;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    private:
        int testTexture;
		int testTileset;
        Sprite testSprite;
        TileMap testMap;
    };
}

#endif