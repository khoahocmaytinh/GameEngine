#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "../Core/SNode.h"
#include "../Core/SGeometry.h"
#include <string>

class SSprite : public SNode
{
public:

	virtual void update();
	virtual void render();
	virtual void clean();

	static SSprite* create(std::string path);
	static SSprite* create(std::string path, SRect rect);

private:

	bool init(std::string path);
	bool init(std::string path, SRect rect);
};

#endif // !__SPRITE_H__
