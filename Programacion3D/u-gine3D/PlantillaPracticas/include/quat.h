#ifndef UGINE_QUAT_H
#define UGINE_QUAT_H

#include "matrix4.h"
#include "rotaxis.h"
#include "vector3.h"

class Quat {
public:
	Quat();
	Quat(const Quat& q);
	Quat(float x, float y, float z, float w);
	Quat(const RotAxis& rotaxis);
	Quat(const Vector3& euler);

	bool operator==(const Quat& other) const;
	Quat& operator=(const Quat& other);
	Quat operator+(const Quat& other) const;
	Quat operator*(const Quat& other) const;
	Vector3 operator*(const Vector3& vec) const;
	Quat operator*(float scale) const;
	Quat operator/(float scale) const;

	Quat Normalized() const;
	Quat Conjugate() const;

	RotAxis Axis() const;
	void SetAxis(const RotAxis& rotaxis);

	Vector3 Euler() const;
	void SetEuler(const Vector3& euler);

	Quat Lerp(const Quat& other, float t) const { return (*this*(1-t) + other*t).Normalized(); }
	Quat Slerp(const Quat& other, float t) const;

	float Dot(const Quat& other) const;

	const float& X() const;
	const float& Y() const;
	const float& Z() const;
	const float& W() const;
	void SetX(float x);
	void SetY(float y);
	void SetZ(float z);
	void SetW(float w);
private:
	float x, y, z, w;
};

inline Quat Quat::Normalized() const {
	Quat q;
	float mag2 = x*x + y*y + z*z + w*w;
	if ( mag2 > 0.00001  &&  fabs(mag2 - 1.0) > 0.00001 ) {
		float mag = sqrt(mag2);
		q.x /= mag;
		q.y /= mag;
		q.z /= mag;
		q.w /= mag;
	}
	return q;
}

inline Vector3 Quat::Euler() const {
	float pitch = static_cast<float>( DegATan2(2 * (y*z + w*x), w*w - x*x - y*y + z*z ) );
	float yaw   = static_cast<float>( DegASin(-2 * (x*z - w*y)                        ) );
	float roll  = static_cast<float>( DegATan2(2 * (x*y + w*z), w*w + x*x - y*y - z*z ) );
	return Vector3(pitch, yaw, roll);
}

inline void Quat::SetEuler(const Vector3& euler) {
	float halfx     = euler.X() * 0.5f;
	float halfy     = euler.Y() * 0.5f;
	float halfz     = euler.Z() * 0.5f;
	float sinyaw    = static_cast<float>( DegSin( static_cast<double>( static_cast<double>( halfy ) ) ) );
	float sinpitch  = static_cast<float>( DegSin( static_cast<double>( static_cast<double>( halfx) ) ) );
	float sinroll   = static_cast<float>( DegSin( static_cast<double>( static_cast<double>( halfz) ) ) );
	float cosyaw    = static_cast<float>( DegCos( static_cast<double>( static_cast<double>( halfy) ) ) );
	float cospitch  = static_cast<float>( DegCos( static_cast<double>( static_cast<double>( halfx) ) ) );
	float cosroll   = static_cast<float>( DegCos( static_cast<double>( static_cast<double>( halfz) ) ) );

	x = sinpitch * cosyaw * cosroll - cospitch * sinyaw * sinroll;
	y = cospitch * sinyaw * cosroll + sinpitch * cosyaw * sinroll;
	z = cospitch * cosyaw * sinroll - sinpitch * sinyaw * cosroll;
	w = cospitch * cosyaw * cosroll + sinpitch * sinyaw * sinroll;
}

inline Quat Quat::Slerp(const Quat& other, float t) const {
	Quat q;
	float dot = this->Dot(other);
	if ( dot < 0 ) {
		dot *= -1;
		q = other * -1;
	} else {
		q = other;
	}

	if ( dot < 0.95f ) {
		float angle = static_cast<float>( DegACos(dot) );
		return (*this * static_cast<float>( DegSin( static_cast<double>( angle*(1-t) ) ) ) + q* static_cast<float>( DegSin( static_cast<double>( angle*t ) ) ) ) / static_cast<float>( DegSin( static_cast<double>( angle ) ) );
	} else {
		return this->Lerp(q, t);
	}
}



#endif // UGINE_QUAT_H
