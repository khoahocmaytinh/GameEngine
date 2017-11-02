#include "GamePlayScene.h"
#include "../Stone/Core/SApp.h"
#include "GameMenuScene.h"
#include "../Stone/Core/SSceneManager.h"

#include "Player.h"
#include "Ball.h"
#include "Enemy.h"

bool GamePlayScene::init()
{
	auto ball = Ball::create();
	auto player = Player::create();
	auto enemy = Enemy::create();

	this->addChild(ball);
	this->addChild(player);
	this->addChild(enemy);

	return true;
}

void GamePlayScene::update(float dt)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void GamePlayScene::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->render();
	}
}

void GamePlayScene::clean()
{

}

void GamePlayScene::playToMenu()
{
	auto menuScene = GameMenuScene::create();
	SSCENEMANAGER->pushScene(menuScene);
}

void GamePlayScene::playToExit()
{
	SAPP->quit();
}