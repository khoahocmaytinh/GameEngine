#ifndef __GAMEPLAY_SCENE_H__
#define __GAMEPLAY_SCENE_H__

#include "../Stone/Core/SScene.h"
#include "../Stone/Core/SPlatformMacro.h"

class GamePlayScene : public SScene
{
public:
	virtual void update(float dt);
	virtual void render();
	virtual void clean();

	CREATE_FUNC(GamePlayScene);

private:
	bool init();

	void playToMenu();
	void playToExit();
};

#endif // !__GAMEPLAY_SCENE_H__
