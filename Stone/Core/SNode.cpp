#include "SNode.h"
#include "SRenderer.h"

void SNode::update()
{

}

void SNode::render()
{
	SRENDERER->render(this->m_texture, this->m_drawPosition, m_angle, m_anchorPoint, m_flip);
}

void SNode::clean()
{

}

void SNode::setPosition(const SVec2& position)
{
	m_position.m_x = position.m_x;
	m_position.m_y = position.m_y;

	m_drawPosition.m_x = m_position.m_x - m_anchorPoint.m_x * m_texture->m_width;
	m_drawPosition.m_y = m_position.m_y - m_anchorPoint.m_y * m_texture->m_height;
}

void SNode::setAnchorPoint(const SVec2& anchor)
{
	m_anchorPoint.m_x = anchor.m_x;
	m_anchorPoint.m_y = anchor.m_y;

	m_drawPosition.m_x = m_position.m_x - m_anchorPoint.m_x * m_texture->m_width;
	m_drawPosition.m_y = m_position.m_y - m_anchorPoint.m_y * m_texture->m_height;
}

void SNode::setRotate(double angle, SRendererFlip flip)
{
	m_angle = angle;
	m_flip = flip;
}