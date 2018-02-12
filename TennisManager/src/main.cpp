#include "System/System.h"

// This class will receive a message from ComponentB.
class ComponentA : public System
{
public:
	ComponentA(MessageBus* messageBus) : System(messageBus) {}

private:
	void onNotify(Message message)
	{
		std::cout << "A: I received: " << message.getEvent() << std::endl;
	}
};

// This class will send a message to ComponentA.
class ComponentB : public System
{
public:
	ComponentB(MessageBus* messageBus) : System(messageBus) {}

	void update()
	{
		Message greeting("Hi!");
		sendMessage(greeting);
	}

private:
	void onNotify(Message message)
	{
		std::cout << "I received: " << message.getEvent() << std::endl;
	}
};


int main() {
	MessageBus messageBus;
	ComponentA compA(&messageBus);
	ComponentB compB(&messageBus);

	// This is supposed to act like a game loop.
	for (int ctr = 0; ctr < 2; ctr++) {
		compA.update();
		compB.update();
		messageBus.notify();
	}

	return 0;
}