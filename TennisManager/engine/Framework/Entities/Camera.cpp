#include "Camera.h"


Camera::Camera(Window* window)
{
	m_projectionMatrix = makeProjectionMatrix(45, window);

	m_position = { 0, 0, -1 };
	m_window = window;
}

void Camera::update()
{
	m_position = m_pEntity->position;
	m_rotation = m_pEntity->rotation;

	m_viewMatrix = makeViewMatrix(*this);
	m_projViewMatrx = m_projectionMatrix * m_viewMatrix;
}

void Camera::hookEntity(const Entity& entity)
{
	m_pEntity = &entity;
}

const glm::mat4& Camera::getViewMatrix() const
{
	return m_viewMatrix;
}

const glm::mat4& Camera::getProjMatrix() const
{
	return m_projectionMatrix;
}

const glm::mat4& Camera::getProjectionViewMatrix() const
{
	return m_projViewMatrx;
}
