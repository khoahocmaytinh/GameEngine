#ifndef __INTRO_SCENE_H__
#define __INTRO_SCENE_H__

#include "../Stone/Core/SScene.h"
#include "../Stone/Core/SPlatformMacro.h"

class IntroScene : public SScene
{
public:
	virtual void update(float dt);
	virtual void render();
	virtual void clean();

	CREATE_FUNC(IntroScene);

private:
	bool init();
	int m_timeDelay;
};

#endif // !__INTRO_SCENE_H__
