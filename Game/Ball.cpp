#include "Ball.h"

#define PIXEL_TO_MM 0.264583333
#define MM_TO_PIXEL 3.779527559

bool Ball::init()
{
	if (!SSprite::init("../../Data/sprite/spr_data.png", SRect(320, 180, 40, 40)))
	{
		return false;
	}
	this->setPosition(SVec2(400, 300));
	this->setAnchorPoint(SVec2::ANCHOR_MIDDLE);
	m_radius = 20;

	return true;
}

void Ball::update()
{
	m_ballBodyDef.position.Set(m_body->GetPosition().x + 100, m_body->GetPosition().y + 100);
	//b2Vec2 position2 = m_body->GetPosition();
	//position *= (float)MM_TO_PIXEL;
	//m_body->SetLinearVelocity(b2Vec2(position.x, 0));
	//printf("%f;%f\n", position.x, position.y);
	this->setPosition(SVec2(m_body->GetPosition().x, m_body->GetPosition().y));
}

//void Ball::render()
//{
//}

void Ball::clean()
{

}