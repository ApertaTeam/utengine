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

        // Getters
        int GetDepth();

        // Setters
        void SetDepth(int depth);

    protected:
        int depth;
    };
}

#endif