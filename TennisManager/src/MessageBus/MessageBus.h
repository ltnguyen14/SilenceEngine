#pragma once
#include <queue>
#include <vector>
#include <functional>
#include "Message.h"

class MessageBus {
public:
	MessageBus() {};
	~MessageBus() {};

	void addReceiver(std::function<void(Message)> receiver) {
		m_receivers.push_back(receiver);
	};

	void sendMessage(Message message) {
		m_messages.push(message);
	};

	void notify() {
		while (!m_messages.empty()) {
			for (auto& receiver : m_receivers) {
				receiver(m_messages.front());
			}
		}
	}

private:
	std::vector<std::function<void(Message)>> m_receivers;
	std::queue<Message> m_messages;
};