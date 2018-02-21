#pragma once
#include <string>
#include "../../engine/Tools/Math/glm.h"

class Paddle {
public:
	Paddle(glm::vec2 position, glm::vec4 color, glm::vec2 dimension, std::string texture, glm::vec2 velocity = {0, 0});

	void moveUp(float amount);
	void move(glm::vec2 amount);
	void setVelocity(glm::vec2 velocity) { m_velocity = velocity; };

	inline glm::vec2 getPositions() { return m_position; };
	inline glm::vec4 getColor() { return m_color; };
	inline glm::vec2 getDimensions() { return m_dimension; };
	inline std::string getTexture() { return m_texture; };
	inline glm::vec2 getVelocity() { return m_velocity; };

private:
	glm::vec2 m_position;
	glm::vec2 m_velocity;
	glm::vec4 m_color;
	glm::vec2 m_dimension;
	std::string m_texture;
};