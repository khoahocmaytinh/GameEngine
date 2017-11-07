#include "Ball.h"


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
	b2Vec2 position = m_body->GetPosition();
	printf("%f;%f\n", position.x, position.y);
	this->setPosition(SVec2(position.x, position.y));
}

//void Ball::render()
//{
//}

void Ball::clean()
{

}