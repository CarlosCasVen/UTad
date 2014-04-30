#include "../include/u-gine.h"

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
    return 0.0f;
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
    if( x >= 0 && x <= 1 ) this->x = x;
}
//---------------------------------
//
//---------------------------------
void Quat::SetY(float y)
{
    if( y >= 0 && y <= 1 ) this->y = y;
}
//---------------------------------
//
//---------------------------------
void Quat::SetZ(float z)
{
    if( z >= 0 && z <= 1 ) this->z = z;
}
//---------------------------------
//
//---------------------------------
void Quat::SetW(float w)
{
    if( w >= 0 && w <= 1 ) this->w = w;
}