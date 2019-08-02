#ifndef UT_CAMERA_H
#define UT_CAMERA_H

#include "Object.h"

#include "Common.h"

namespace UT
{
    // Handles the game camera movement
    class Camera
    {
    public:
        Camera(Vector2 viewSize = { 320, 240 }, Object* trackedObject = nullptr);

        virtual void Update();

        // Getters
        Object* GetTrackedObject();

        // Setters
        void SetTrackedObject(Object* trackedObject);

    private:
        Object* trackedObject;
    };
}

#endif