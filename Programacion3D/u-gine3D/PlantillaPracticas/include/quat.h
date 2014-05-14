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


//---------------------------------
//
//---------------------------------
inline Quat::Quat()
{
    SetX( 0.0f );
    SetY( 0.0f );
    SetZ( 0.0f );
    SetW( 1.0f );
}
//---------------------------------
//
//---------------------------------
inline Quat::Quat(const Quat& q)
{
    SetX( q.X() );
    SetY( q.Y() );
    SetZ( q.Z() );
    SetW( q.W() );
}
//---------------------------------
//
//---------------------------------
inline Quat::Quat(float x, float y, float z, float w)
{
    SetX( x );
    SetY( y );
    SetZ( z );
    SetW( w );
}
//---------------------------------
//
//---------------------------------
inline Quat::Quat(const RotAxis& rotaxis)
{
    SetAxis( rotaxis );
}
//---------------------------------
//
//---------------------------------
inline bool Quat::operator==(const Quat& other) const
{
    return X() == other.X() &&
           Y() == other.Y() &&
           Z() == other.Z() &&
           W() == other.W();
}
//---------------------------------
//
//---------------------------------
inline Quat& Quat::operator=(const Quat& other)
{
    SetX( other.X() );
    SetY( other.Y() );
    SetZ( other.Z() );
    SetW( other.W() );
    return *this;
}
//---------------------------------
//
//---------------------------------
inline Quat Quat::operator+(const Quat& other) const
{
    return Quat( X() + other.X(), Y() + other.Y(), Z() + other.Z(), W() + other.W() );
}
//---------------------------------
//
//---------------------------------
inline Quat Quat::operator*(const Quat& other) const
{
    return Quat(
                W() * other.X() + X() * other.W() + Y() * other.Z() - Z() * other.Y(),
                W() * other.Y() + Y() * other.W() + Z() * other.X() - X() * other.Z(),
                W() * other.Z() + Z() * other.W() + X() * other.Y() - Y() * other.X(),
                W() * other.W() - X() * other.X() - Y() * other.Y() - Z() * other.Z() 
               );
}
//---------------------------------
//
//---------------------------------
inline Vector3 Quat::operator*(const Vector3& vec) const
{
    Quat quatVect( vec.X(), vec.Y(), vec.Z(), 0 );
    Quat quatResult = *this * quatVect * Conjugate();

    return Vector3( 
                    quatResult.X(),
                    quatResult.Y(),
                    quatResult.W()            
                   );

}
//---------------------------------
//
//---------------------------------
inline Quat Quat::operator*(float scale) const
{
    return Quat( 
                X() * scale,
                Y() * scale,
                Z() * scale,
                W() * scale
               );
}
//---------------------------------
//
//---------------------------------
inline Quat Quat::operator/(float scale) const
{
	return Quat( 
                X() / scale,
                Y() / scale,
                Z() / scale,
                W() / scale
               );
}
//---------------------------------
//
//---------------------------------
inline Quat Quat::Conjugate() const
{
    return Quat( -X(), -Y(), -Z(), W() );
}
//---------------------------------
//
//---------------------------------
inline RotAxis Quat::Axis() const
{
	float div = sqrtf( X() * X() + Y() * Y() + Z() * Z() );

	div == 0.0 ? div = 1.0f / 0.00000000001f : div = 1.0f / div; 

    return RotAxis(
					static_cast<float>( DegACos( static_cast<double>( w ) ) * 2 ),
					Vector3(
							X() * div,
							Y() * div,
							Z() * div
							)
				  );
}
//---------------------------------
//
//---------------------------------
inline void Quat::SetAxis(const RotAxis& rotaxis)
{
   SetX( rotaxis.Axis().X() * static_cast<float>( DegSin( static_cast<double>( rotaxis.Angle() / 2.0f ) ) ) );
   SetY( rotaxis.Axis().Y() * static_cast<float>( DegSin( static_cast<double>( rotaxis.Angle() / 2.0f ) ) ) );
   SetZ( rotaxis.Axis().Z() * static_cast<float>( DegSin( static_cast<double>( rotaxis.Angle() / 2.0f ) ) ) );
   SetW( static_cast<float>( DegCos( static_cast<double>( rotaxis.Angle() / 2.0f ) ) ) ); 
}
//---------------------------------
//
//---------------------------------
inline float Quat::Dot(const Quat& other) const
{
    return X() * other.X() + Y() * other.Y() + Z() * other.Z() + W() * other.W();
}
//---------------------------------
//
//---------------------------------
inline const float& Quat::X() const
{
    return x;
}
//---------------------------------
//
//---------------------------------
inline const float& Quat::Y() const
{
    return y;
}
//---------------------------------
//
//---------------------------------
inline const float& Quat::Z() const
{
    return z;
}
//---------------------------------
//
//---------------------------------
inline const float& Quat::W() const
{
    return w;
}
//---------------------------------
//
//---------------------------------
inline void Quat::SetX(float x)
{
    this->x = x;
}
//---------------------------------
//
//---------------------------------
inline void Quat::SetY(float y)
{
    this->y = y;
}
//---------------------------------
//
//---------------------------------
inline void Quat::SetZ(float z)
{
    this->z = z;
}
//---------------------------------
//
//---------------------------------
inline void Quat::SetW(float w)
{
    this->w = w;
}
#endif // UGINE_QUAT_H
