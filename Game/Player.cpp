#include "Player.h"
#include "../Stone/Core/SApp.h"

bool Player::init()
{
	if (!SSprite::init("../../Data/sprite/spr_data.png", SRect(320, 260, 34, 160)))
	{
		return false;
	}

	SSize windowSize = SAPP->getSize();
	
	this->setPosition(SVec2(this->m_texture->m_width / 2, windowSize.height / 2));
	this->setAnchorPoint(SVec2::ANCHOR_MIDDLE);
	//this->setRotate(90, SFLIP_NONE);

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