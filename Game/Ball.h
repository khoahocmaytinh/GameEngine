#ifndef __BALL_H__
#define __BALL_H__

#include "../Stone/Graphics/SSprite.h"
#include "../Stone/Core/SPlatformMacro.h"

#include "Box2D.h"

class Ball : public SSprite
{
public:
	virtual void update();
	//virtual void render();
	virtual void clean();
	CREATE_FUNC(Ball);
private:
	bool init();

};

#endif // !__BALL_H__
