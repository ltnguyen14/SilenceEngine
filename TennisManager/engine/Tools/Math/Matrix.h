#pragma once
#include "glm.h"
#include "../../Framework/Window/Window.h"

glm::mat4 makeProjectionMatrix(float fov);
glm::mat4 makeOrthoMatrix(Window* window);