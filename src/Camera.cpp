#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace UT
{
    Camera::Camera(glm::vec2 viewSize, Object* trackedObject)
    {
        this->viewSize = viewSize;
        this->projectionRect = glm::vec4(0);
        this->projectionMatrix = glm::mat4(1.0f);
        this->trackedObject = trackedObject;
    }

    void Camera::Update()
    {
        projectionMatrix = glm::ortho(0.0f, 320.0f, 240.0f, 0.0f, -9000.0f, 1000.0f);
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
    void Camera::SetTrackedObject(Object* trackedObject)
    {
        this->trackedObject = trackedObject;
    }
}