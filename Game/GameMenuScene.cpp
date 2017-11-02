#include "GameMenuScene.h"
#include "../Stone/UI/SButton.h"
#include "../Stone/Core/SApp.h"
#include "GamePlayScene.h"
#include "../Stone/Core/SSceneManager.h"

bool GameMenuScene::init()
{
	SSize windowSize = SAPP->getSize();

	auto playButton = SButton::create("../../Data/sprite/spr_data.png",
		SRect(20, 20, 280, 100), 
		SRect(20, 140, 280, 100), std::bind(&GameMenuScene::menuToPlay, *this));
	playButton->setAnchorPoint(SVec2::ANCHOR_MIDDLE);
	playButton->setPosition(SVec2(windowSize.width / 2, 200));

	auto exitButton = SButton::create("../../Data/sprite/spr_data.png",
		SRect(20, 260, 280, 100),
		SRect(20, 380, 280, 100), std::bind(&GameMenuScene::exit, *this));
	exitButton->setAnchorPoint(SVec2::ANCHOR_MIDDLE);
	exitButton->setPosition(SVec2(windowSize.width /2, 400));

	this->addChild(playButton);
	this->addChild(exitButton);

	return true;
}

void GameMenuScene::update(float dt)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void GameMenuScene::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->render();
	}
}

void GameMenuScene::clean()
{

}

void GameMenuScene::menuToPlay()
{
	auto playScene = GamePlayScene::create();
	SSCENEMANAGER->pushScene(playScene);
}

void GameMenuScene::exit()
{
	SAPP->quit();
}