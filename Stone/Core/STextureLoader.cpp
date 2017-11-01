#include "STextureLoader.h"
#include "SRenderer.h"

STexture* STextureLoader::load(std::string path)
{
	std::string name = getFileName(path);
	if (m_textureCache[name])
	{
		return m_textureCache[name];
	}

	STexture* ret = new STexture();
	if (!ret)
		return nullptr;

	ret->m_pTexture = IMG_LoadTexture(SRENDERER->m_pRenderer, path.c_str());
	m_count++;
	printf("%d\n", m_count);
	SDL_QueryTexture(ret->m_pTexture, nullptr, nullptr, &ret->m_width, &ret->m_height);

	m_textureCache[name] = ret;

	return ret;
}

STexture* STextureLoader::load(std::string path, SRect rect)
{
	STexture* ret = new STexture();
	if (!ret)
		return nullptr;

	ret->m_x = rect.x;
	ret->m_y = rect.y;
	ret->m_width = rect.w;
	ret->m_height = rect.h;

	std::string name = getFileName(path);
	if (m_textureCache[name])
	{
		ret->m_pTexture = m_textureCache[name]->m_pTexture;
		return ret;
	}

	ret->m_pTexture = IMG_LoadTexture(SRENDERER->m_pRenderer, path.c_str());
	m_count++;
	printf("%d\n", m_count);

	m_textureCache[name] = ret;

	return ret;
}

std::string STextureLoader::getFileName(std::string path)
{
	std::string name;
	int index = path.length();

	while(path[index - 1] != '/')
		index--;

	while (index < path.length())
	{
		name.push_back(path[index]);
		index++;
	}
		
	return name;
}