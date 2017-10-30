#ifndef __VEC2_H__
#define __VEC2_H__

#include <math.h>

class SVec2
{
public:
	SVec2() { m_x = m_y = 0; }
	SVec2(float x, float y) : m_x(x), m_y(y) {}

	float getX() { return m_x; }
	float getY() { return m_y; }

	void setX(float x) { m_x = x; }
	void setY(float y) { m_y = y; }

	float length() { return sqrt(m_x * m_x + m_y * m_y); }

	SVec2 operator+(const SVec2& v2) const
	{
		return SVec2(m_x + v2.m_x, m_y + v2.m_y);
	}

	friend SVec2& operator+=(SVec2& v1, const SVec2& v2)
	{
		v1.m_x += v2.m_x;
		v1.m_y += v2.m_y;

		return v1;
	}

	SVec2 operator*(float scalar)
	{
		return SVec2(m_x * scalar, m_y * scalar);
	}

	SVec2 operator*=(float scalar)
	{
		m_x *= scalar;
		m_y *= scalar;

		return *this;
	}

	SVec2 operator-(const SVec2& v2) const
	{
		return SVec2(m_x - v2.m_x, m_y - v2.m_y);
	}

	friend SVec2& operator-=(SVec2& v1, const SVec2& v2)
	{
		v1.m_x -= v2.m_x;
		v1.m_y -= v2.m_y;

		return v1;
	}

	SVec2 operator/(float scalar)
	{
		return SVec2(m_x / scalar, m_y / scalar);
	}

	SVec2& operator/=(float scalar)
	{
		m_x /= scalar;
		m_y /= scalar;

		return *this;
	}

	void normalize()
	{
		float l = length();
		if (l > 0) {
			(*this) *= 1 / 1;
		}
	}

public:
	float m_x;
	float m_y;
};

#endif //!__VEC2_H__
