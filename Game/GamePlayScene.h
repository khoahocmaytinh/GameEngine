#ifndef __GAMEPLAY_SCENE_H__
#define __GAMEPLAY_SCENE_H__

#include "../Stone/Core/SScene.h"
#include "../Stone/Core/SPlatformMacro.h"
#include "Box2D.h"

#include "Player.h"
#include "Ball.h"
#include "Enemy.h"

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

	Ball* m_ball;

	b2World* m_world;
	b2Body* m_topWall;
	b2Body* m_botWall;
	b2Body* m_leftWall;
	b2Body* m_rightWall;

	float32 m_timeStep;      //the length of time passed to simulate (seconds)
	int32 m_velocityIterations;   //how strongly to correct velocity
	int32 m_positionIterations;   //how strongly to correct position
};

#endif // !__GAMEPLAY_SCENE_H__
