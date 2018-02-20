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
		m_engine.m_renderSystem->drawQuad({ 0, 0 }, 0.2, 0.5, { 0.1f, 0.4f, 0.7f, 1.0f }, "gray_bg.png");
	}

	bool isRunning() {
		return m_engine.isRunning();
	}

private:
	SilenceEngine m_engine;
};
