#ifndef __NODE_H__
#define __NODE_H__

#include "SDL.h"
#include "SVec2.h"
#include "STexture.h"

class SNode
{
public:

	virtual void update();
	virtual void render();
	virtual void clean();

	void setPosition(const SVec2& position);

protected:
	STexture* m_texture;
	SVec2 m_position;
};

#endif // !__NODE_H__
