#include "Camera.h"

namespace UT
{
    Camera::Camera(Vector2 viewSize, Object* trackedObject)
    {
        this->trackedObject = trackedObject;
    }

    void Camera::Update()
    {
        
    }

    // Getters
    Object* Camera::GetTrackedObject()
    {
        return this->trackedObject;
    }

    // Setters
    void Camera::SetTrackedObject(Object* trackedObject)
    {
        this->trackedObject = trackedObject;
    }
}