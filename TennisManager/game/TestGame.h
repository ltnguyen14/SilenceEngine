#pragma once
#include "../engine/SilenceEngine.h"

class GameState {
public:
	GameState(unsigned int width, unsigned int height, std::string title)
		:m_engine(width, height, title)
	{
	};

	void update() {
		m_engine.update();
		m_engine.drawQuad({ 0, 0 }, 0.1, 0.2, {0.2f, 0.3f, 0.4f, 1.0f}, "gray_bg.png");
		m_engine.drawQuad({ 0.5, 0 }, 0.1, 0.2, { 0.2f, 0.3f, 0.4f, 1.0f }, "gray_bg.png");
	}

	bool isRunning() {
		return m_engine.isRunning();
	}

private:
	SilenceEngine m_engine;
};
