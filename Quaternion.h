//#pragma once
//#include "Vector3.h"
//class Quaternion
//{
//public:
//	Quaternion(): Quaternion(0, 0, 0, 0) {}
//	Quaternion(Float x, Float y, Float z, Float w):
//		x(x), y(y), z(z), w(w) {}
//	Quaternion(Vector3 v, Float w)
//		:v(v), w(w) {}
//	Quaternion(const Quaternion& q)
//	{
//		v = q.v;
//		w = q.w;
//	}
//
//	~Quaternion() {}
//
//	union
//	{
//		struct
//		{
//			Float x;
//			Float y;
//			Float z;
//		};
//		Vector3 v;
//	};
//	Float w;
//
//	Quaternion Conjugate() const
//	{
//		return Quaternion(-v, w);
//	}
//
//	Float Norm() const
//	{
//		return ::sqrtf(x * x + y * y + z * z + w * w);
//	}
//
//	Quaternion operator+(const Quaternion& q) const
//	{
//		return Quaternion(v + q.v, w + q.w);
//	}
//
//	Quaternion operator*(const Quaternion& q) const
//	{
//		Quaternion ret;
//		ret.v = Vector3::Cross(v, q.v) + v * q.w + q.v * w;
//		ret.w = w * q.w - Vector3::Dot(v, q.v);
//		return ret;
//	}
//};
//
