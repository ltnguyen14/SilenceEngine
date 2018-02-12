#pragma once
#include "System.h"

class RenderSystem : public System
{
public:
	RenderSystem(MessageBus* messageBus) : System(messageBus) {}

	void update()
	{
	}

private:
	void onNotify(Message message)
	{
	}
};