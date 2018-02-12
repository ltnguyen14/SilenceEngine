#pragma once
#include <string>

class Message {
public:
	Message(const std::string event) {
		m_event = event;
	};

	inline std::string getEvent() const { return m_event; };

private:
	std::string m_event;
};