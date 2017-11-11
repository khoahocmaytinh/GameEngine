#include "GamePlayScene.h"
#include "../Stone/Core/SApp.h"
#include "GameMenuScene.h"
#include "../Stone/Core/SSceneManager.h"

#include "../Stone/Core/SRenderer.h"

bool GamePlayScene::init()
{
	m_ball = Ball::create();
	//auto ball = Ball::create();
	auto player = Player::create();
	auto enemy = Enemy::create();

	//-------------------------------World------------------------------------------------

	b2Vec2 gravity(0, 0);
	m_world = new b2World(gravity);

	m_timeStep = 1.0f / SAPP->FPS;      //the length of time passed to simulate (seconds)
	m_velocityIterations = 8;   //how strongly to correct velocity
	m_positionIterations = 3;   //how strongly to correct position

	//-------------------------Wall------------------------------------------------------
	auto size = SAPP->getSize();

	//Top
	b2BodyDef wallBodyDef;
	wallBodyDef.type = b2_staticBody;
	//wallBodyDef.position.Set(0, 0);
	m_topWall = m_world->CreateBody(&wallBodyDef);
	b2EdgeShape edge;
	edge.Set(b2Vec2(0, 0), b2Vec2(size.width, 0));
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &edge;
	m_topWall->CreateFixture(&fixtureDef);

	//Left
	m_leftWall = m_world->CreateBody(&wallBodyDef);
	edge.Set(b2Vec2(0, 0), b2Vec2(0, size.height));
	fixtureDef.shape = &edge;
	m_leftWall->CreateFixture(&fixtureDef);

	//Bot
	//wallBodyDef.position.Set(size.width, size.height);
	m_botWall = m_world->CreateBody(&wallBodyDef);
	edge.Set(b2Vec2(0, size.height), b2Vec2(size.width, size.height));
	fixtureDef.shape = &edge;
	m_botWall->CreateFixture(&fixtureDef);

	//Right
	m_rightWall = m_world->CreateBody(&wallBodyDef);
	edge.Set(b2Vec2(size.width, 0), b2Vec2(size.width, size.height));
	fixtureDef.shape = &edge;
	m_rightWall->CreateFixture(&fixtureDef);

	//--------------------Ball Physic----------------------------------------------------
	
	m_ball->m_ballBodyDef.type = b2_dynamicBody;
	m_ball->m_ballBodyDef.position.Set(m_ball->getPosition().m_x / 32.0f, m_ball->getPosition().m_y / 32.0f);
	m_ball->m_body = m_world->CreateBody(&m_ball->m_ballBodyDef);
	m_ball->m_body->SetUserData(m_ball);

	b2CircleShape circleShape;
	circleShape.m_p.Set(0, 0);
	circleShape.m_radius = m_ball->m_radius;
	b2FixtureDef ballFixtureDef;
	ballFixtureDef.shape = &circleShape;
	ballFixtureDef.density = 1;
	ballFixtureDef.restitution = 1;
	m_ball->m_body->CreateFixture(&ballFixtureDef);
	m_ball->m_body->SetLinearVelocity(b2Vec2(50, 35));

	//---------------------Player Physic---------------------------------------------------
	b2BodyDef playerBodyDef;
	playerBodyDef.type = b2_kinematicBody;
	playerBodyDef.position.Set(player->getPosition().m_x, player->getPosition().m_y);
	player->m_body = m_world->CreateBody(&playerBodyDef);
	//player->m_body->SetUserData(player);

	b2PolygonShape polygonShape;
	polygonShape.SetAsBox(player->m_texture->m_width / 2, player->m_texture->m_height / 2);
	b2FixtureDef playerFixtureDef;
	playerFixtureDef.shape = &polygonShape;
	player->m_body->CreateFixture(&playerFixtureDef);
	
	//----------------------Enemy Physic---------------------------------------------------
	b2BodyDef enemyBodyDef;
	enemyBodyDef.type = b2_kinematicBody;
	enemyBodyDef.position.Set(enemy->getPosition().m_x, enemy->getPosition().m_y);
	enemy->m_body = m_world->CreateBody(&enemyBodyDef);
	//enemy->m_body->SetUserData(enemy);

	polygonShape.SetAsBox(enemy->m_texture->m_width / 2, enemy->m_texture->m_height / 2);
	b2FixtureDef enemyFixtureDef;
	enemyFixtureDef.shape = &polygonShape;
	enemy->m_body->CreateFixture(&enemyFixtureDef);

	this->addChild(m_ball);
	this->addChild(player);
	this->addChild(enemy);

	return true;
}

void GamePlayScene::update(float dt)
{
	m_world->Step(m_timeStep, m_velocityIterations, m_positionIterations);
	//for (b2Body* b = m_world->GetBodyList(); b != nullptr; b = b->GetNext())
	//{
	//	m_ball->m_body = (b2Body*)b->GetUserData();
	//	m_ball->setPosition(SVec2(b->GetPosition().x * 32, b->GetPosition().y * 32));
	//}
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