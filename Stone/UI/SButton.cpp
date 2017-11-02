#include "SButton.h"
#include "../Core/SInput.h"
#include "../Core/STexture.h"

SButton* SButton::create(std::string path, SRect normal, SRect mouseClick, std::function<void()> func)
{
	SButton* ret = new SButton();

	ret->m_normal = SSprite::create(path, normal);
	ret->m_mouseClick = SSprite::create(path, mouseClick);

	if(!ret->m_mouseClick || !ret->m_normal)
		return nullptr;

	ret->m_current = ret->m_normal;
	ret->m_cbFunc = func;

	return ret;
}

SButton* SButton::create(std::string normal, std::string mouseClick, std::function<void()> func)
{
	SButton* ret = new SButton();
	
	ret->m_normal = SSprite::create(normal);
	ret->m_mouseClick = SSprite::create(mouseClick);

	if (!ret->m_mouseClick || !ret->m_normal)
		return nullptr;

	ret->m_current = ret->m_normal;
	ret->m_cbFunc = func;

	return ret;
}

void SButton::setPosition(const SVec2& position)
{
	m_normal->setPosition(position);
	m_mouseClick->setPosition(position);
}

void SButton::setAnchorPoint(const SVec2& anchor)
{
	m_normal->setAnchorPoint(anchor);
	m_mouseClick->setAnchorPoint(anchor);
}

void SButton::update()
{
	SVec2 mousePosition = SINPUT->getMousePosition();
	SVec2 drawPosition = m_current->getDrawPosition();
	STexture* textureOfCurrent = m_current->getTexture();

	if (SINPUT->getMouseButtonState(SBUTTON_LEFT))
	{
		if (mousePosition.m_x > drawPosition.m_x &&
			mousePosition.m_x < textureOfCurrent->m_width + drawPosition.m_x &&
			mousePosition.m_y > drawPosition.m_y &&
			mousePosition.m_y < textureOfCurrent->m_height + drawPosition.m_y)
		{
			m_current = m_mouseClick;
			m_cbFunc();
		}
	}
	else
	{
		m_current = m_normal;
	}
}

void SButton::render()
{
	m_current->render();
}

void SButton::clean()
{

}