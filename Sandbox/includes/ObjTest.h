#ifndef SANDBOX_OBJ_TEST_H
#define SANDBOX_OBJ_TEST_H

#include "Sprite.h"

using namespace UT;

namespace UTSandbox
{
    class ObjTest : public Sprite
    {
    public:
        ObjTest();

        virtual void Init() override;

    private:

    };
}

#endif