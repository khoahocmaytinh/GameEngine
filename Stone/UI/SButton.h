#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "../Core/SNode.h"
#include "../Core/SGeometry.h"
#include "../Graphics/SSprite.h"
#include <string>
#include <iostream>
#include <functional>

class SButton : public SNode
{
public:

	virtual void update();
	virtual void render();
	virtual void clean();
	
	static SButton* create(std::string path, SRect normal, SRect mouseClick, std::function<void()> func);
	static SButton* create(std::string normal, std::string mouseClick, std::function<void()> func);
	
	virtual void setPosition(const SVec2& position);
	virtual void setAnchorPoint(const SVec2& anchor);

private:

	SSprite* m_normal;
	SSprite* m_mouseClick;
	SSprite* m_current;
	
	std::function<void()> m_cbFunc; // callback
	bool m_release;
};


#endif // !__BUTTON_H__
