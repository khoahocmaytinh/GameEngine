#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "SDL.h"
#include "SSingleton.h"
#include "STexture.h"

class SRenderer : public SSingleton<SRenderer>
{
	friend class SSingleton<SRenderer>;
	friend class SApp;
public:
	void render()
private:
	SRenderer(){}
	~SRenderer(){}

	SDL_Renderer* m_pRenderer;
};

#define SRENDERER SRenderer::getInstance()

#endif // !__RENDERER_H__
