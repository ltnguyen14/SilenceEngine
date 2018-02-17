#pragma once
#include <iostream>
#include <functional>
#include "../MessageBus/MessageBus.h"
#include "../Framework/Framework.h"

class System {
	// Base class for all systems
public:
	System(MessageBus* messageBus, Window& window) 
		:m_graphics(window)
	{
		m_messageBus = messageBus;
		m_messageBus->addReceiver(this->getNotifyFunc());
	}

	virtual void update() {};

protected:
	std::function<void(Message)> getNotifyFunc() {
		auto messageListener = [=](Message message)-> void {
			this->onNotify(message);
		};
		return messageListener;
	};

	void sendMessage(Message message) {
		m_messageBus->sendMessage(message);
	};

	virtual void onNotify(Message message) {

	}

	MessageBus * m_messageBus;
	Graphics m_graphics;

};