#ifndef UT_CAMERA_H
#define UT_CAMERA_H

#include "Object.h"

#include <glm/vec2.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

namespace UT
{
    // Handles the game camera movement
    class Camera
    {
    public:
        Camera(glm::vec2 viewSize = glm::vec2(320, 240), Object* trackedObject = nullptr);

        virtual void Update();

        // Getters
        glm::vec2 GetViewSize();
        glm::vec4 GetProjectionRect();
        glm::mat4 GetProjectionMatrix();
        Object* GetTrackedObject();

        // Setters
        void SetTrackedObject(Object* trackedObject);

    private:
        glm::vec2 viewSize;
        glm::vec4 projectionRect;
        glm::mat4 projectionMatrix;

        Object* trackedObject;
    };
}

#endif