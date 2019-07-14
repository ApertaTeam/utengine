#ifndef UT_OBJECT_H
#define UT_OBJECT_H

namespace UT
{
    // Alpha variety in texture to be rendered
    enum RenderTypes
    {
        AlphaNull = 0,         // Standard null value for render type
        AlphaFull = 1,         // Image is completely opaque
        AlphaFullClear = 2,    // Image contains only pixels with 100% alpha or 0% alpha
        AlphaAll = 3           // Image has pixels with alpha values other than 0% or 100%
    };

    // The abstract parent of all game objects
    class Object
    {
    public:
        Object();
        
        virtual void Init();
        virtual void Update();
        virtual void Render();

        // Getters
        int GetDepth();
        RenderTypes GetRenderType();

        // Setters
        void SetDepth(int depth);
        void SetRenderType(RenderTypes renderType);

    protected:
        RenderTypes renderType;
        int depth;
    };
}

#endif