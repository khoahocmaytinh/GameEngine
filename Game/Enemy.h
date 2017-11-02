#ifndef __ENEMY_H__
#define  __ENEMY_H__

#include "../Stone/Graphics/SSprite.h"
#include "../Stone/Core/SPlatformMacro.h"

class Enemy : public SSprite
{
public:
	virtual void update();
	//virtual void render();
	virtual void clean();

	CREATE_FUNC(Enemy);

private:
	bool init();
};

#endif // !__ENEMY_H__
