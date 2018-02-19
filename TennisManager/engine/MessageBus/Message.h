#pragma once
#include <string>

enum MessageType {
	CHAT,
	MOUSE_INPUT
};

class Message {
public:
	Message(const std::string event, MessageType type) {
		m_event = event;
		m_type = type;
	};

	inline std::string getEvent() const { return m_event; };
	inline MessageType getType() const { return m_type; };

private:
	std::string m_event;
	MessageType m_type;
};