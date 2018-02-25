#pragma once
#include "glm.h"
#include "../../Framework/Window/Window.h"

class Camera;
glm::mat4 makeModelMatrix(glm::vec3 position, glm::vec3 rotation);
glm::mat4 makeProjectionMatrix(float fov, Window* window);
glm::mat4 makeViewMatrix(const Camera& camera);
glm::mat4 makeOrthoMatrix(Window* window);