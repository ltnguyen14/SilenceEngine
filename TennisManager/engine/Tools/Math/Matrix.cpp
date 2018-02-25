#include "Matrix.h"
#include "../../Framework/Entities/Camera.h"

glm::mat4 makeModelMatrix(glm::vec3 position, glm::vec3 rotation)
{
	glm::mat4 matrix(1.0f);

	matrix = glm::rotate(matrix, glm::radians(rotation.x), { 1, 0, 0 });
	matrix = glm::rotate(matrix, glm::radians(rotation.y), { 0, 1, 0 });
	matrix = glm::rotate(matrix, glm::radians(rotation.z), { 0, 0, 1 });

	matrix = glm::translate(matrix, position);

	return matrix;
}

glm::mat4 makeViewMatrix(const Camera& camera)
{
	glm::mat4 matrix(1.0f);

	matrix = glm::rotate(matrix, glm::radians(camera.m_rotation.x), { 1, 0, 0 });
	matrix = glm::rotate(matrix, glm::radians(camera.m_rotation.y), { 0, 1, 0 });
	matrix = glm::rotate(matrix, glm::radians(camera.m_rotation.z), { 0, 0, 1 });

	matrix = glm::translate(matrix, camera.m_position);


	return matrix;
}

glm::mat4 makeProjectionMatrix(float fov, Window* window)
{
	return glm::perspective(glm::radians(fov), (float)window->getWidth() / (float)window->getHeight(), 0.1f, 1000.0f);
}

glm::mat4 makeOrthoMatrix(Window* window)
{
	return glm::ortho(0.0f, (float)window->getWidth(), (float)window->getHeight(), 0.0f);
}