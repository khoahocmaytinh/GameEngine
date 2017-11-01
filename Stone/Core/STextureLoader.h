#ifndef __TEXTURELOADER_H__
#define __TEXTURELOADER_H__

//Load and save texture
#include "STexture.h"
#include "SSingleton.h"
#include "SGeometry.h"
#include <SDL_image.h>
#include <map>

class STextureLoader : public SSingleton<STextureLoader>
{
	friend class SSingleton<STextureLoader>;
public:
	STexture* load(std::string path);
	STexture* load(std::string path, SRect rect);
private:
	std::string getFileName(std::string path);

	STextureLoader()
	{
		m_count = 0;
	}
	~STextureLoader(){}

	//std::map<std::string, std::pair<SRect, STexture*>> m_textureCache;
	std::map<std::string, STexture*> m_textureCache;

	int m_count;
};

#define STEXTURELOADER STextureLoader::getInstance()

#endif // !__TEXTURELOADER_H__
