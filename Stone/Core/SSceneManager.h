#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__

#include "SScene.h"
#include "SSingleton.h"
#include <vector>

class SSceneManager : public SSingleton<SSceneManager>
{
	friend class SSingleton<SSceneManager>;
public:
	void update(float dt);
	void render();
	void clean();

	void runWithScene(SScene* scene);
	void switchScene(SScene* scene);
	void pushScene(SScene* scene);
	void popScene(SScene* scene);
private:
	SScene* m_currentScene;
	SScene* m_nextScene;

	std::vector<SScene*> m_scenes;
};

#define SSCENEMANAGER SSceneManager::getInstance()

#endif // !__SCENE_MANAGER_H__
