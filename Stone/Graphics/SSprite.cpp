#include "SSprite.h"
#include "../Core/STextureLoader.h"
#include "../Core/SRenderer.h"

bool SSprite::init(std::string path, SRect rect)
{
	m_texture = STEXTURELOADER->load(path, rect);
	if (!m_texture)
		return false;
	return true;
}

bool SSprite::init(std::string path)
{
	m_texture = STEXTURELOADER->load(path);
	if (!m_texture)
		return false;
	return true;
}

SSprite* SSprite::create(std::string path)
{
	SSprite* ret = new SSprite();
	if (ret && ret->init(path))
		return ret;
	return nullptr;
}

SSprite* SSprite::create(std::string path, SRect rect)
{
	SSprite* ret = new SSprite();
	if (ret && ret->init(path, rect))
		return ret;
	return nullptr;
}

void SSprite::update()
{
	m_angle++;
}

void SSprite::render()
{
	SNode::render();
}

void SSprite::clean()
{

}