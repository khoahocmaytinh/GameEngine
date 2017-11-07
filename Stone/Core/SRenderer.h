#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "SDL.h"
#include "SSingleton.h"
#include "STexture.h"
#include "SVec2.h"
#include "SApp.h"
#include "SNode.h"

class SRenderer : public SSingleton<SRenderer>
{
	friend class SSingleton<SRenderer>;
	friend class SApp;
	friend class STextureLoader;
public:
	void render(STexture* texture, SVec2 position);
	/*
		angle: tinh bang degree, xoay theo chieu kim dong ho
		center: anchor point
	*/
	void render(STexture* texture, SVec2 position, double angle, SVec2 center, SRendererFlip flip);

private:
	SRenderer()
	{
		m_pRenderer = SDL_CreateRenderer(SAPP->m_pWindow, -1, SDL_RENDERER_ACCELERATED);
	}
	~SRenderer(){}

	SDL_Renderer* m_pRenderer;
};

#define SRENDERER SRenderer::getInstance()

#endif // !__RENDERER_H__
