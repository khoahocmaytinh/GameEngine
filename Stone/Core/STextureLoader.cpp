#include "STextureLoader.h"
#include "SRenderer.h"

STexture* STextureLoader::load(std::string path)
{
	STexture* ret = new STexture();
	if (!ret)
		return nullptr;

	ret->m_pTexture = IMG_LoadTexture(SRENDERER->m_pRenderer, path.c_str());
	SDL_QueryTexture(ret->m_pTexture, nullptr, nullptr, &ret->m_width, &ret->m_height);

	return ret;
}

STexture* STextureLoader::load(std::string path, SRect rect)
{
	STexture* ret = new STexture();
	if (!ret)
		return nullptr;

	ret->m_pTexture = IMG_LoadTexture(SRENDERER->m_pRenderer, path.c_str());
	ret->m_x = rect.x;
	ret->m_y = rect.y;
	ret->m_width = rect.w;
	ret->m_height = rect.h;

	return ret;
}