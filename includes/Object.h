#ifndef UT_OBJECT_H
#define UT_OBJECT_H

namespace UT
{
    // The abstract parent of all game objects
    class Object
    {
    public:
        Object();
        
        virtual void Render();
    private:

    };
}

#endif