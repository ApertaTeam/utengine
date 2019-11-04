#ifndef UT_INTERACTABLE_H
#define UT_INTERACTABLE_H

#include "Object.h"

namespace UT {
    class Interactable
    {
    public:
        virtual void Run() = 0;
    };
}
#endif