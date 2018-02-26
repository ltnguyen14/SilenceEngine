#include "Player.h"
#define SPEED_DEC 0.75

Player::Player(Window* window)
	:m_window(window)
{
	position = { 0, 0, -2 };

	old_x = static_cast<int>(m_window->getWidth() / 2);
	old_y = static_cast<int>(m_window->getHeight() / 2);
}

void Player::handleInput()
{
	keyboardInput();
	mouseInput();
}

void Player::update(float dt)
{
	position += m_velocity * dt;
	m_velocity *= 0.75;
}

void Player::keyboardInput()
{
	glm::vec3 change = {0, 0, 0};
	float speed = 0.05;

	if (m_window->keyPressed(GLFW_KEY_W))
	{
		change.x = glm::cos(glm::radians(rotation.y + 90)) * speed;
		change.z = glm::sin(glm::radians(rotation.y + 90)) * speed;
	}
	if (m_window->keyPressed(GLFW_KEY_S))
	{
		change.x = -glm::cos(glm::radians(rotation.y + 90)) * speed;
		change.z = -glm::sin(glm::radians(rotation.y + 90)) * speed;
	}
	if (m_window->keyPressed(GLFW_KEY_A))
	{
		change.x = glm::cos(glm::radians(rotation.y)) * speed;
		change.z = glm::sin(glm::radians(rotation.y)) * speed;
	}
	if (m_window->keyPressed(GLFW_KEY_D))
	{
		change.x = -glm::cos(glm::radians(rotation.y)) * speed;
		change.z = -glm::sin(glm::radians(rotation.y)) * speed;
	}
	if (m_window->keyPressed(GLFW_KEY_Q))
	{
		change.y = -0.05f;
	}	
	if (m_window->keyPressed(GLFW_KEY_E))
	{
		change.y = 0.05f;
	}
	m_velocity += change;
}

void Player::mouseInput()
{
	static auto const BOUND = 80;
	double change_x, change_y, new_x, new_y;
	m_window->getMousePos(new_x, new_y);

	change_x = new_x - old_x;
	change_y = new_y - old_y;

	std::cout << change_x << std::endl;

	rotation.y += change_x * 0.001;
	rotation.x += change_y * 0.001;

	if (rotation.x >  BOUND) rotation.x = BOUND;
	else if (rotation.x < -BOUND) rotation.x = -BOUND;

	if (rotation.y >  360) rotation.y = 0;
	else if (rotation.y < 0)    rotation.y = 360;

	//m_window->setPosition(m_window->getWidth() / 2, m_window->getHeight() / 2);
}

