#include "SRenderer.h"
#include "SGeometry.h"

void SRenderer::render(STexture* texture, SVec2 position)
{
	SDL_Rect src;
	SDL_Rect des;

	src.x = texture->m_x;
	src.y = texture->m_y;
	src.w = texture->m_width;
	src.h = texture->m_height;

	des.x = position.m_x;
	des.y = position.m_y;
	des.w = src.w;
	des.h = src.h;

	SDL_RenderCopy(this->m_pRenderer, texture->m_pTexture, &src, &des);
}

void SRenderer::render(STexture* texture, SVec2 position, double angle, SVec2 center, SRendererFlip flip)
{
	SDL_Rect src;
	SDL_Rect des;

	src.x = texture->m_x;
	src.y = texture->m_y;
	src.w = texture->m_width;
	src.h = texture->m_height;

	des.x = position.m_x;
	des.y = position.m_y;
	des.w = src.w;
	des.h = src.h;

	SDL_Point pointCenter; // pointcenter tren texture
	pointCenter.x = center.m_x * texture->m_width;
	pointCenter.y = center.m_y * texture->m_height;

	SDL_RenderCopyEx(SRENDERER->m_pRenderer, texture->m_pTexture, &src, &des, angle, 
		&pointCenter, (SDL_RendererFlip)flip);
}