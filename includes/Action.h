#ifndef UT_ACTION_H
#define UT_ACTION_H

#include "Object.h"

namespace UT
{
    class Action
    {
    public:
        virtual void Run() = 0;
    };
}
#endif