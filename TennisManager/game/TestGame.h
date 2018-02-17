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
	}

	bool isRunning() {
		return m_engine.isRunning();
	}

private:
	SilenceEngine m_engine;
};
