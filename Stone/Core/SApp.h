#ifndef __APP_H__
#define __APP_H__

#include <iostream>
#include "SDL.h"
#include "SSingleton.h"

class SApp : public SSingleton<SApp>
{
	friend class SSingleton<SApp>;
	friend class SRenderer;
public:
	bool init(std::string title, int x, int y, int width, int heigt, Uint32 flags);
	void run();
	void quit();
private:
	SApp() {}
	~SApp() {}
	void update();
	void render();
	void clean();

	bool m_bRunning;

	SDL_Window* m_pWindow;
};

#define SAPP SApp::getInstance()

#endif // !__APP_H__
