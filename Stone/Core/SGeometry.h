#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

struct SRect
{
	SRect()
	{
		x = y = w = h = 0;
	}
	SRect(float _x, float _y, float _w, float _h)
	{
		x = _x; y = _y; w = _w; h = _h;
	}

	bool operator==(const SRect& rect)
	{
		return (this->x == rect.x && this->x == rect.y && this->w == rect.w && this->h == rect.h);
	}

	float x;
	float y;
	float w;
	float h;
};

struct SSize
{
	SSize()
	{
		width = height = 0;
	}

	int width;
	int height;
};

#endif // !__GEOMETRY_H__
