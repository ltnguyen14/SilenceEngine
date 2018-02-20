#include "SilenceEngine.h"

SilenceEngine::SilenceEngine(int width, int height, std::string title)
	:m_window(new Window(width, height, title))
{ 
}

SilenceEngine::~SilenceEngine()
{
}