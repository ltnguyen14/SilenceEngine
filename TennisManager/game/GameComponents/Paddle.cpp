#include "Paddle.h"

Paddle::Paddle(glm::vec2 position, glm::vec4 color, glm::vec2 dimension, std::string texture, glm::vec2 velocity)
{
	m_position = position;
	m_color = color;
	m_dimension = dimension;
	m_texture = texture;
	m_velocity = velocity;
}

void Paddle::moveUp(float amount)
{
	m_position.y += amount;
}

void Paddle::move(glm::vec2 amount)
{
	m_position += amount;
}

