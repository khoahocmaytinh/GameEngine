#ifndef __SCENE_H__
#define __SCENE_H__

#include "SNode.h"
#include <vector>

class SScene
{
public:
	virtual void update(float dt) = 0;
	virtual void render() = 0;
	virtual void clean() = 0;
protected:
	void addChild(SNode* node, int index = 0)
	{
		m_gameObjects.push_back(node);
	}

	std::vector<SNode*> m_gameObjects;
};

#endif // !__SCENE_H__
