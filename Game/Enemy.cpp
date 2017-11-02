#include "Enemy.h"

bool Enemy::init()
{
	if (!SSprite::init("../../Data/sprite/spr_data.png", SRect(380, 260, 34, 160)))
	{
		return false;
	}

	this->setPosition(SVec2(400, 200));
	this->setAnchorPoint(SVec2::ANCHOR_MIDDLE);
	this->setRotate(90, SFLIP_NONE);

	return true;
}

void Enemy::update()
{
	//if (this->m_angle <= 360)
	//{
	//	this->m_angle += 20;
	//}
	//else
	//{
	//	this->m_angle = 0;
	//}
}

//void Enemy::render()
//{
//	SSprite::render();
//}

void Enemy::clean()
{

}