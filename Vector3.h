#pragma once

#include "stdafx.h"
#include "Mathf.h"

namespace math
{

class Vector3
{
public:
	float x = 0;
	float y = 0;
	float z = 0;

	Vector3() {}
	explicit Vector3(float v): Vector3(v, v, v) {}
	Vector3(float x, float y, float z): x(x), y(y), z(z) {}
	Vector3(const Vector3& v): Vector3(v.x, v.y, v.z) {}
	Vector3(Vector3&& v): Vector3(v.x, v.y, v.z) {}
	~Vector3() {}
	Vector3& operator=(const Vector3& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}


	static const Vector3 forward;
	static const Vector3 back;
	static const Vector3 up;
	static const Vector3 down;
	static const Vector3 left;
	static const Vector3 right;

	static const Vector3 negativeInfinity;
	static const Vector3 positiveInfinity;
	static const Vector3 zero;
	static const Vector3 one;

	static float dot(Vector3 a, Vector3 b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}
	inline static Vector3 lerp(Vector3 a, Vector3 b, float t)
	{
		t = nclamp(t);
		return lerp_unclamped(a, b, t);
	}

	inline static Vector3 lerp_unclamped(Vector3 a, Vector3 b, float t)
	{
		return Vector3(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t);
	}

	static Vector3 slerp(Vector3 a, Vector3 b, float t, bool normalized=false)
	{
		float magnitude = normalized ? 1.0f : math::lerp(a.magnitude(), b.magnitude(), t);
		if (!normalized)
		{
			a.normalize();
			b.normalize();
		}
		float radian = Vector3::angle(a, b, true);
		
		t = ((cos(radian * t) + cos(radian * ( 1.0f - t)))) / (a + b).sqr_magnitude();
		return Vector3(a + b) * t;
	}

	static float angle(Vector3 from, Vector3 to, bool normalized=false)
	{
		if (!normalized)
		{
			from.normalize();
			to.normalize();
		}
		float dot = Vector3::dot(from, to);
		dot = nclamp(dot);
		return acos(dot);
	}
	inline static Vector3 cross(Vector3 a, Vector3 b)
	{
		return Vector3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
	}
	inline static float distance(Vector3 a, Vector3 b)
	{
		return (a - b).magnitude();
	}

	inline Vector3 operator+(const Vector3& v) const
	{
		return Vector3(x + v.x, y + v.y, z + v.z);
	}
	inline Vector3 operator-(const Vector3& v) const
	{
		return Vector3(x - v.x, y - v.y, z - v.z);
	}
	inline bool operator==(const Vector3& v) const
	{
		return (*this - v).is_zero();
	}
	inline bool operator!=(const Vector3& v) const
	{
		return !(*this == v);
	}
	inline Vector3 operator*(float d) const
	{
		return Vector3(x * d, y * d, z * d);
	}
	inline Vector3& operator*=(float d)
	{
		x *= d;
		y *= d;
		z *= d;
		return *this;
	}
	inline Vector3 operator/(float d) const
	{
		return *this * (1.0f / d);
	}
	inline Vector3& operator/=(float d)
	{
		*this *= (1.0f / d);
		return *this;
	}
	inline Vector3 operator*(const Vector3& v) const
	{
		return Vector3(x * v.x, y * v.y, z * v.z);
	}
	inline Vector3 operator-() const
	{
		return Vector3(-x, -y, -z);
	}

	inline bool is_zero()
	{
		return sqr_magnitude() < sqr_small_double;
	}

	inline float magnitude()
	{
		return sqrtf(sqr_magnitude());
	}
	inline float sqr_magnitude()
	{
		return Vector3::dot(*this, *this);
	}

	inline Vector3 normalized() const
	{
		Vector3 result(*this);
		result.normalize();
		return result;
	}

	inline float normalize()
	{
		float num = magnitude();
		if ((double)num > small_double)
		{
			*this /= num;
		}
		return num;
	}

	inline Vector3& reset()
	{
		x = y = z = 0.0f;
		return *this;
	}
	inline Vector3& set(float value)
	{
		x = y = z = value;
		return *this;
	}
	inline Vector3& set(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		return *this;
	}
};

} // namespace math
