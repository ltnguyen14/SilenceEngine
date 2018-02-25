#pragma once
#include "Entity.h"

class Camera {
public:
	Camera(Window* window);

	void update();
	void hookEntity(const Entity& entity);

	const glm::mat4& getViewMatrix() const;
	const glm::mat4& getProjMatrix() const;
	const glm::mat4& getProjectionViewMatrix() const;

	glm::vec3 m_position;
	glm::vec3 m_rotation;

private:
	Window * m_window;
	const Entity* m_pEntity;

	glm::mat4 m_projectionMatrix;
	glm::mat4 m_viewMatrix;
	glm::mat4 m_projViewMatrx;
};