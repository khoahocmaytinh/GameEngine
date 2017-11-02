#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../Stone/Graphics/SSprite.h"
#include "../Stone/Core/SPlatformMacro.h"

class Player : public SSprite
{
public:

	virtual void update();
	//virtual void render();
	virtual void clean();

	CREATE_FUNC(Player);

private:
	bool init();
};

#endif // !__PLAYER_H__
