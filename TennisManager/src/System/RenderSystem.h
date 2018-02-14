#pragma once
#include "System.h"

class RenderSystem : public System
{
public:
	RenderSystem(MessageBus* messageBus) : System(messageBus) {}

	void update()
	{
		Message* message = new Message("Hello", CHAT);
		m_messageBus->sendMessage(*message);
		delete(message);
	}

private:
	void onNotify(Message message)
	{
	}
};