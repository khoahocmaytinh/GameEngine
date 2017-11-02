#include "Player.h"

bool Player::init()
{
	if (!SSprite::init("../../Data/sprite/spr_data.png", SRect(320, 260, 34, 160)))
	{
		return false;
	}

	this->setPosition(SVec2(400, 400));
	this->setAnchorPoint(SVec2::ANCHOR_MIDDLE);
	this->setRotate(90, SFLIP_NONE);

	return true;
}

void Player::update()
{
	//if (this->m_angle <= 360)
	//{
	//	this->m_angle++;
	//}
	//else
	//{
	//	this->m_angle = 0;
	//}
}

//void Player::render()
//{
//	SSprite::render();
//}

void Player::clean()
{

}