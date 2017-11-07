#include "Enemy.h"
#include "../Stone/Core/SApp.h"

bool Enemy::init()
{
	if (!SSprite::init("../../Data/sprite/spr_data.png", SRect(380, 260, 34, 160)))
	{
		return false;
	}

	SSize windowSize = SAPP->getSize();
	this->setPosition(SVec2(windowSize.width - this->m_texture->m_width / 2, windowSize.height / 2));
	this->setAnchorPoint(SVec2::ANCHOR_MIDDLE);

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