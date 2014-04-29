#include "../include/u-gine.h"

Quat::Quat()
{
}
Quat::Quat(const Quat& q)
{
}
Quat::Quat(float x, float y, float z, float w)
{
}
Quat::Quat(const RotAxis& rotaxis)
{
}
Quat::Quat(const Vector3& euler)
{
}


Quat Quat::Normalized() const
{
}
Quat Quat::Conjugate() const
{
}

RotAxis Quat::Axis() const
{
}
void Quat::SetAxis(const RotAxis& rotaxis)
{
}

Vector3 Quat::Euler() const
{
}
void Quat::SetEuler(const Vector3& euler)
{
}

Quat Quat::Slerp(const Quat& other, float t) const
{
}

float Quat::Dot(const Quat& other) const
{
}

const float& Quat::X() const
{
}

const float& Quat::Y() const
{
}

const float& Quat::Z() const
{
}
const float& Quat::W() const
{
}
void Quat::SetX(float x)
{
}
void Quat::SetY(float y)
{
}
void Quat::SetZ(float z)
{
}
void Quat::SetW(float w)
{
}