#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include "SDL.h"

class STexture
{
	friend class SRenderer;
	friend class STextureLoader;
public:

private:
	SDL_Texture* m_pTexture;
public:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
};

#endif // !__TEXTURE_H__
