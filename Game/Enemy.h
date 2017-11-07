#ifndef __ENEMY_H__
#define  __ENEMY_H__

#include "../Stone/Graphics/SSprite.h"
#include "../Stone/Core/SPlatformMacro.h"
#include "Box2D.h"

class Enemy : public SSprite
{
	friend class GamePlayScene;
public:
	virtual void update();
	//virtual void render();
	virtual void clean();

	CREATE_FUNC(Enemy);

private:
	bool init();

	b2Body* m_body;
};

#endif // !__ENEMY_H__
