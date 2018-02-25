#pragma once
#include "../Entity.h"
#include "../Camera.h"

class Player : public Entity{
public:
	Player(Window* window);

	void handleInput();

	void update(float dt);

private:
	Window * m_window;
	void keyboardInput();
	void mouseInput();
	double old_x, old_y;

	glm::vec3 m_velocity = { 0, 0, 0 };
};