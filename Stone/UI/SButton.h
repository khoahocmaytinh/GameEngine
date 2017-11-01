#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "../Core/SNode.h"
#include "../Core/SGeometry.h"
#include <string>

class SButton : public SNode
{
public:

	virtual void update();
	virtual void render();
	virtual void clean();

	static SButton* create(std::string path, SRect normal, SRect mouseClick);
	static SButton* create(std::string normal, std::string mouseClick);
private:
};


#endif // !__BUTTON_H__
