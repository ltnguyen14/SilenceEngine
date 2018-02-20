#include "InputSystem.h"

void InputSystem::getMousePos(double & x, double & y)
{
	m_window->getMousePos(x, y);
}

bool InputSystem::keyPressed(unsigned int keycode) const
{
	return m_window->keyPressed(keycode);
}

bool InputSystem::mouseButtonPressed(unsigned int button) const
{
	return m_window->mouseButtonPressed(button);
}
