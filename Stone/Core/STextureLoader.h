#ifndef __TEXTURELOADER_H__
#define __TEXTURELOADER_H__

//Load and save texture
#include "STexture.h"
#include "SSingleton.h"
#include "SGeometry.h"
#include <map>

class STextureLoader : public SSingleton<STextureLoader>
{
	friend class SSingleton<STextureLoader>;
public:
	STexture* load(std::string path);
	STexture* load(std::string path, SRect rect);
private:
	STextureLoader(){}
	~STextureLoader(){}

	std::map<std::string,STexture*> m_textureCache;
};

#define STEXTURELOADER STextureLoader::getInstance()

#endif // !__TEXTURELOADER_H__
