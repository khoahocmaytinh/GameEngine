#ifndef __GAMEMENU_SCENE_H__
#define __GAMEMENU_SCENE_H__

#include "../Stone/Core/SScene.h"
#include "../Stone/Core/SPlatformMacro.h"

class GameMenuScene : public SScene
{
public:
	virtual void update(float dt);
	virtual void render();
	virtual void clean();

	CREATE_FUNC(GameMenuScene);

private:
	bool init();
	void menuToPlay();
	void exit();
};

#endif // !__GAMEMENU_SCENE_H__
