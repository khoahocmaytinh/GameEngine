#include "SInput.h"
#include "SApp.h"

void SInput::onKeyDown()
{
	m_keystates = SDL_GetKeyboardState(nullptr);
}

void SInput::onKeyUp()
{
	m_keystates = SDL_GetKeyboardState(nullptr);
}

void SInput::onButtonDown(SDL_Event& event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonStates[SBUTTON_LEFT] = true;
	}
	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonStates[SBUTTON_MIDDLE] = true;
	}
	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonStates[SBUTTON_RIGHT] = true;
	}
}

void SInput::onButtonUp(SDL_Event& event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonStates[SBUTTON_LEFT] = false;
	}
	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonStates[SBUTTON_MIDDLE] = false;
	}
	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonStates[SBUTTON_RIGHT] = false;
	}
}

void SInput::onMouseMove(SDL_Event& event)
{
	m_mousePosition.setX((float)event.motion.x);
	m_mousePosition.setY((float)event.motion.y);
}

bool SInput::getMouseButtonState(int buttonNumber) { return m_mouseButtonStates[buttonNumber]; }

SVec2 SInput::getMousePosition() { return m_mousePosition; }

bool SInput::isKeyDown(SDL_Scancode key)
{
	if (m_keystates != 0)
	{
		if (m_keystates[key] == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

void SInput::update()
{
	SDL_Event event;

	//Uint32 frameStart = SDL_GetTicks();
	//Uint32 counter = 0;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			SAPP->quit();
		}
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			onButtonDown(event);
		}
		if (event.type == SDL_MOUSEBUTTONUP)
		{
			onButtonUp(event);
		}
		if (event.type == SDL_MOUSEMOTION)
		{
			onMouseMove(event);
		}
		//counter++;
	}

	//SDL_Log("- Process time: %d - Events: %d", SDL_GetTicks() - frameStart, counter);
}