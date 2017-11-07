#ifndef __BALL_H__
#define __BALL_H__

#include "../Stone/Graphics/SSprite.h"
#include "../Stone/Core/SPlatformMacro.h"

#include "Box2D.h"

class Ball : public SSprite
{
	friend class GamePlayScene;
public:
	virtual void update();
	//virtual void render();
	virtual void clean();
	CREATE_FUNC(Ball);
private:
	bool init();
	b2Vec2 m_linearVelocity;

	b2Body* m_body;
	float m_radius;
};

#endif // !__BALL_H__
