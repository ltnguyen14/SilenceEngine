#pragma once
#include <string>
#include "../../engine/Tools/Math/glm.h"

class Paddle {
public:
	Paddle(glm::vec2 position, glm::vec4 color, glm::vec2 dimension, std::string texture);

	void setPosition(glm::vec2 position);

	inline glm::vec2 getPositions() { return m_position; };
	inline glm::vec4 getColor() { return m_color; };
	inline glm::vec2 getDimensions() { return m_dimension; };
	inline std::string getTexture() { return m_texture; };

private:
	glm::vec2 m_position;
	glm::vec4 m_color;
	glm::vec2 m_dimension;
	std::string m_texture;
};