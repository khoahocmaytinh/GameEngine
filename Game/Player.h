#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../Stone/Graphics/SSprite.h"
#include "../Stone/Core/SPlatformMacro.h"
#include "Box2D.h"

class Player : public SSprite
{
	friend class GamePlayScene;
public:
	virtual void update();
	//virtual void render();
	virtual void clean();

	CREATE_FUNC(Player);

private:
	bool init();

	b2Body* m_body;
};

#endif // !__PLAYER_H__
