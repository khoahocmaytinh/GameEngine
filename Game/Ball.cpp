#include "Ball.h"


bool Ball::init()
{
	if (!SSprite::init("../../Data/sprite/spr_data.png", SRect(320, 180, 40, 40)))
	{
		return false;
	}
	
	this->setPosition(SVec2(100, 100));

	return true;
}

void Ball::update()
{

}

//void Ball::render()
//{
//	SSprite::render();
//}

void Ball::clean()
{

}