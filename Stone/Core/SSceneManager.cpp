#include "SSceneManager.h"

void SSceneManager::update(float dt)
{
	m_currentScene->update(dt);
}

void SSceneManager::render()
{
	m_currentScene->render();
}

void SSceneManager::clean()
{
	m_currentScene->clean();
}

void SSceneManager::runWithScene(SScene* scene)
{
	m_currentScene = scene;
	m_scenes.push_back(scene);
}

void SSceneManager::switchScene(SScene* scene)
{
	if (m_currentScene)
	{
		m_currentScene->clean();
		delete m_currentScene;
		m_scenes.pop_back();
		m_currentScene = scene;
		m_scenes.push_back(m_currentScene);
	}
}

void SSceneManager::pushScene(SScene* scene)
{
	m_scenes.push_back(scene);
	m_currentScene = scene;
}

void SSceneManager::popScene(SScene* scene)
{
	if (m_currentScene)
	{

	}
}