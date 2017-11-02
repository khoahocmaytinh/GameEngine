#include "SApp.h"
#include "SRenderer.h"
#include "SInput.h"
#include <functional>

#include "SSceneManager.h"
#include "../../Game/IntroScene.h"

int SApp::FPS = 60;
const double DELAY_TIME = 1000.0f / SApp::FPS;

bool SApp::init(std::string title, int x, int y, int width, int heigt, Uint32 flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		this->m_pWindow = SDL_CreateWindow(title.c_str(), x, y, width, heigt, flags);

		if (this->m_pWindow)
		{
			this->m_bRunning = true;
			this->m_size.width = width;
			this->m_size.height = heigt;

			// --------------YOU CAN CHANGE BACKGROUNG GAME HERE--------------------
			setBackgroundColor(255, 255, 255, 0);
			//----------------------------------------------------------------------

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

	//------------------RUN YOUR STARTSCENE HERE-----------------------
	auto introScene = IntroScene::create();
	SSCENEMANAGER->runWithScene(introScene);

	//------------------------------------------------------------------

	return true;
}

void SApp::run()
{
	double frameStart;
	double frameTime;

	while (m_bRunning)
	{
		frameStart = SDL_GetTicks();

		this->update();
		this->render();

		frameTime = SDL_GetTicks() - frameStart;
		//SDL_Log("- ft: %d", (int) frameTime);
		if (frameTime < DELAY_TIME)
		{
			SDL_Delay(DELAY_TIME - frameTime);
		}
	}
	this->clean();
}

void SApp::update()
{
	SINPUT->update();
	SSCENEMANAGER->update(0);
}

void SApp::render()
{
	SDL_RenderClear(SRENDERER->m_pRenderer);
	///////////////////////////////////////
	
	SSCENEMANAGER->render();

	///////////////////////////////////////
	SDL_RenderPresent(SRENDERER->m_pRenderer);
}

void SApp::clean()
{
	SSCENEMANAGER->clean();
}

void SApp::quit()
{
	this->m_bRunning = false;
}

void SApp::setBackgroundColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(SRENDERER->m_pRenderer, r, g, b, a);
}