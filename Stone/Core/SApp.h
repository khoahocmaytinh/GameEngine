#ifndef __APP_H__
#define __APP_H__

#include <iostream>
#include <vector>
#include "SDL.h"
#include "SSingleton.h"
#include "SGeometry.h"

class SApp : public SSingleton<SApp>
{
	friend class SSingleton<SApp>;
	friend class SRenderer;
public:
	bool init(std::string title, int x, int y, int width, int heigt, Uint32 flags);
	void run();
	void quit();
	SSize getSize() { return m_size; }

	static int FPS;
private:
	SApp() {}
	~SApp() {}

	void setBackgroundColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void update();
	void render();
	void clean();

	bool m_bRunning;
	SDL_Window* m_pWindow;
	SSize m_size;
};

#define SAPP SApp::getInstance()

#endif // !__APP_H__
