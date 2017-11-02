#include "IntroScene.h"
#include "../Stone/Graphics/SSprite.h"
#include "../Stone/UI/SButton.h"
#include "../Stone/Core/SGeometry.h"
#include "../Stone/Core/SApp.h"
#include "../Stone/Core/SSceneManager.h"

#include "GameMenuScene.h"

bool IntroScene::init()
{
	SSize windowSize = SAPP->getSize();

	auto intro = SSprite::create("../../Data/image/img_logo.png");
	intro->setAnchorPoint(SVec2::ANCHOR_MIDDLE);
	intro->setPosition(SVec2(windowSize.width / 2, windowSize.height / 2));
	this->addChild(intro);

	m_timeDelay = 0;

	//auto sprite = SSprite::create("../../Data/sprite/sin.png");
	//sprite->setAnchorPoint(SVec2::ANCHOR_MIDDLE);
	//sprite->setPosition(SVec2(400, 400));
	////sprite->setRotate(45, SFLIP_NONE);

	//auto plank = SSprite::create("../../Data/sprite/sin.png");
	//plank->setAnchorPoint(SVec2::ANCHOR_MIDDLE);
	//plank->setPosition(SVec2(200, 200));


	//auto button1 = SButton::create(
	//	"../../Data/sprite/spr_data.png", 
	//	SRect(20, 20, 280, 100), SRect(20, 140, 280, 100),
	//	std::bind(&onClick));
	//button1->setAnchorPoint(SVec2::ANCHOR_MIDDLE);
	//button1->setPosition(SVec2(200, 200));

	//this->addChild(sprite);
	//this->addChild(plank);

	return true;
}

void IntroScene::update(float dt)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	/*if (m_timeDelay < 3000)
	{
		m_timeDelay++;
	}*/
	//else
	{
		auto menuScene = GameMenuScene::create();
		SSCENEMANAGER->switchScene(menuScene);
	}
}

void IntroScene::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->render();
	}
}

void IntroScene::clean()
{

}