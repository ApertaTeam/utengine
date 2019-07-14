#ifndef UTEXAMPLE_OBJ_TEST_H
#define UTEXAMPLE_OBJ_TEST_H

#include "Sprite.h"

using namespace UT;

namespace UTEXAMPLE
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