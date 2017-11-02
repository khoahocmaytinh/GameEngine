#ifndef __NODE_H__
#define __NODE_H__

#include "SDL.h"
#include "SVec2.h"
#include "STexture.h"

#define ANCHOR_DEFAULT SVec2::ANCHOR_MIDDLE;
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f

enum SRendererFlip
{
	SFLIP_NONE = SDL_FLIP_NONE,
	SFLIP_HORIZONTAL = SDL_FLIP_HORIZONTAL,
	SFLIP_VERTICAL = SDL_FLIP_VERTICAL
};

class SNode
{
public:

	virtual void update();
	virtual void render();
	virtual void clean();

	/*
		rotate center = anchor point
		angle = degree
	*/
	void setRotate(double angle, SRendererFlip flip);
	virtual void setPosition(const SVec2& position);
	virtual void setAnchorPoint(const SVec2& anchor);

	SVec2 getPosition() { return m_position; }
	STexture* getTexture() { return m_texture; }
	SVec2 getAnchorPoint() { return m_anchorPoint; }
	SVec2 getDrawPosition() { return m_drawPosition; }

protected:
	STexture* m_texture;
	SVec2 m_position;
	/*

	 (0, 0)----------(1, 0)
		|               |
		|               |
		|               |
		|               |
	 (1, 0)-----------(1, 1)

	*/

	SVec2 m_anchorPoint; // default (0, 0)
	SVec2 m_drawPosition;
public:
	double m_angle; // default 0.00000f
	SRendererFlip m_flip; // default none
};

#endif // !__NODE_H__
