#include "Paddle.h"

Paddle::Paddle(glm::vec2 position, glm::vec4 color, glm::vec2 dimension, std::string texture)
{
	m_position = position;
	m_color = color;
	m_dimension = dimension;
	m_texture = texture;
}

void Paddle::moveUp(float amount)
{
	m_position.y += amount;
}

