#include "Camera.h"

namespace UT
{
    Camera::Camera(glm::vec2 viewSize, Object* trackedObject)
    {
        this->viewSize = viewSize;
        this->projectionRect = glm::vec4(0);
        this->projectionMatrix = glm::mat4(0);
        this->trackedObject = trackedObject;
    }

    void Camera::Update()
    {

    }

    // Getters
    glm::vec2 Camera::GetViewSize()
    {
        return this->viewSize;
    }

    glm::vec4 Camera::GetProjectionRect()
    {
        return this->projectionRect;
    }

    glm::mat4 Camera::GetProjectionMatrix()
    {
        return this->projectionMatrix;
    }

    Object* Camera::GetTrackedObject()
    {
        return this->trackedObject;
    }

    // Setters
    void Camera::SetProjectionMatrix(glm::mat4 projectionMatrix)
    {
        this->projectionMatrix = projectionMatrix;
    }

    void Camera::SetTrackedObject(Object* trackedObject)
    {
        this->trackedObject = trackedObject;
    }
}