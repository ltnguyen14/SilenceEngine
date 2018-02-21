#include "Matrix.h"

glm::mat4 makeProjectionMatrix(float fov)
{
	return glm::perspective(glm::radians(fov), 1280.0f / 720.0f, 0.1f, 1000.0f);
}

glm::mat4 makeOrthoMatrix(Window* window)
{
	return glm::ortho(0.0f, (float)window->getWidth(), 0.0f, (float)window->getHeight());
}