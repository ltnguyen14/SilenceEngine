#pragma once
#include <iostream>
#include <functional>
#include "../MessageBus/MessageBus.h"

class System {

public:
	System(MessageBus* messageBus) {
		this->m_messageBus = messageBus;
		this->m_messageBus->addReceiver(this->getNotifyFunc());
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

};