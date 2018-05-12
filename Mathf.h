#pragma once

#include "stdafx.h"

namespace math
{
	static const double small_double = 9.99999943962493E-06;
	static const double sqr_small_double = 9.99999943962493E-11;
	static const float pi = 3.14159265359f;
	static const float degree_to_radians = pi / 180.0f;
	static const float radians_to_degree = 180.0f / pi;

	inline float lerp(float a, float b, float t)
	{
		return a + (b - a) * t;
	}

	template <class T>
	inline T clamp(T value, T min, T max)
	{
		if (value < min)
			value = min;
		else if (value > max)
			value = max;
		return value;
	}

	template <class T>
	inline T nclamp(T value)
	{
		return clamp(value, (T)0, (T)1);
	}

	inline float to_radian(float angle)
	{
		return angle * degree_to_radians;
	}

	inline float to_degree(float radian)
	{
		return radian * radians_to_degree;
	}

}
