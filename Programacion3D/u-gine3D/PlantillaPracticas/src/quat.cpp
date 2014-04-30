#include "../include/quat.h"

//---------------------------------
//
//---------------------------------
Quat::Quat()
{
    SetX( 0.0f );
    SetY( 0.0f );
    SetZ( 0.0f );
    SetW( 1.0f );
}
//---------------------------------
//
//---------------------------------
Quat::Quat(const Quat& q)
{
    SetX( q.X() );
    SetY( q.Y() );
    SetZ( q.Z() );
    SetW( q.W() );
}
//---------------------------------
//
//---------------------------------
Quat::Quat(float x, float y, float z, float w)
{
    SetX( x );
    SetY( y );
    SetZ( z );
    SetW( w );
}
//---------------------------------
//
//---------------------------------
Quat::Quat(const RotAxis& rotaxis)
{
    SetAxis( rotaxis );
}
//---------------------------------
//
//---------------------------------
bool Quat::operator==(const Quat& other) const
{
    return X() == other.X() &&
           Y() == other.Y() &&
           Z() == other.Z() &&
           W() == other.W();
}
//---------------------------------
//
//---------------------------------
Quat& Quat::operator=(const Quat& other)
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
Quat Quat::operator+(const Quat& other) const
{
    return Quat( X() + other.X(), Y() + other.Y(), Z() + other.Z(), W() + other.W() );
}
//---------------------------------
//
//---------------------------------
Quat Quat::operator*(const Quat& other) const
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
Vector3 Quat::operator*(const Vector3& vec) const
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
Quat Quat::operator*(float scale) const
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
Quat Quat::operator/(float scale) const
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
Quat Quat::Conjugate() const
{
    return Quat( -X(), -Y(), -Z(), W() );
}
//---------------------------------
//
//---------------------------------
RotAxis Quat::Axis() const
{
    return RotAxis();
}
//---------------------------------
//
//---------------------------------
void Quat::SetAxis(const RotAxis& rotaxis)
{
   SetX( rotaxis.Axis().X() * static_cast<float>( DegSin( static_cast<double>( rotaxis.Angle() / 2.0f ) ) ) );
   SetY( rotaxis.Axis().Y() * static_cast<float>( DegSin( static_cast<double>( rotaxis.Angle() / 2.0f ) ) ) );
   SetZ( rotaxis.Axis().Z() * static_cast<float>( DegSin( static_cast<double>( rotaxis.Angle() / 2.0f ) ) ) );
   SetW( static_cast<float>( DegCos( static_cast<double>( rotaxis.Angle() / 2.0f ) ) ) ); 
}
//---------------------------------
//
//---------------------------------
float Quat::Dot(const Quat& other) const
{
    return X() * other.X() + Y() * other.Y() + Z() * other.Z() + W() * other.W();
}
//---------------------------------
//
//---------------------------------
const float& Quat::X() const
{
    return x;
}
//---------------------------------
//
//---------------------------------
const float& Quat::Y() const
{
    return y;
}
//---------------------------------
//
//---------------------------------
const float& Quat::Z() const
{
    return z;
}
//---------------------------------
//
//---------------------------------
const float& Quat::W() const
{
    return w;
}
//---------------------------------
//
//---------------------------------
void Quat::SetX(float x)
{
    this->x = x;
}
//---------------------------------
//
//---------------------------------
void Quat::SetY(float y)
{
    this->y = y;
}
//---------------------------------
//
//---------------------------------
void Quat::SetZ(float z)
{
    this->z = z;
}
//---------------------------------
//
//---------------------------------
void Quat::SetW(float w)
{
    this->w = w;
}