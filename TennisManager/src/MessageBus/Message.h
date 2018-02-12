#pragma once
#include <string>

class Message {
public:
	Message(const std::string event, const std::string type) {
		m_event = event;
		m_type = type;
	};

	inline std::string getEvent() const { return m_event; };
	inline std::string getType() const { return m_type; };

private:
	std::string m_event;
	std::string m_type;
};