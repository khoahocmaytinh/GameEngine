#include "SApp.h"
#include "SRenderer.h"
#include "SInput.h"

#include "../Graphics/SSprite.h"
#include "SDL_image.h"

bool SApp::init(std::string title, int x, int y, int width, int heigt, Uint32 flags)
{

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		this->m_pWindow = SDL_CreateWindow(title.c_str(), x, y, width, heigt, flags);

		if (this->m_pWindow)
		{
			this->m_bRunning = true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

	auto sprite = SSprite::create("../../Data/sprite/spr_data.png", SRect(20, 20, 280, 100));
	m_gameObjects.push_back(sprite);

	return true;
}

void SApp::run()
{
	while (m_bRunning)
	{
		this->update();
		this->render();
	}
	this->clean();
}

void SApp::update()
{
	SINPUT->update();
	///////////////////////////////
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void SApp::render()
{
	SDL_RenderClear(SRENDERER->m_pRenderer);
	///////////////////////////////////////

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->render();
	}

	///////////////////////////////////////
	SDL_RenderPresent(SRENDERER->m_pRenderer);
}

void SApp::clean()
{

}

void SApp::quit()
{
	this->m_bRunning = false;
}