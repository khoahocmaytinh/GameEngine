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
		m_mouseButtonStates[LEFT] = true;
	}
	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonStates[MIDDLE] = true;
	}
	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonStates[RIGHT] = true;
	}
}

void SInput::onButtonUp(SDL_Event& event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonStates[LEFT] = false;
	}
	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonStates[MIDDLE] = false;
	}
	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonStates[RIGHT] = false;
	}
}

void SInput::onMouseMove(SDL_Event& event)
{
	m_mousePosition->setX((float)event.motion.x);
	m_mousePosition->setY((float)event.motion.y);
}

void SInput::update()
{
	SDL_Event event;

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
	}
}