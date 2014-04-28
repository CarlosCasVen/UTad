#include "../include/u-gine.h"

Matrix4::Matrix4()
{
}

Matrix4::Matrix4(const Matrix4& other)
{
}

Matrix4::Matrix4(const float* values)
{
}



void Matrix4::SetIdentity()
{
}
void Matrix4::Set(const float* m)
{
}
float& Matrix4::RC(uint32 row, uint32 column)
{
}
const float& Matrix4::RC(uint32 row, uint32 column) const
{
}
void Matrix4::SetRC(uint32 row, uint32 column, float value)
{
}

Vector3 Matrix4::Translation() const
{
}

void Matrix4::SetTranslation(const Vector3& trans)
{
}
void Matrix4::SetRotation(const RotAxis& rot)	
{
}
void Matrix4::SetScale(const Vector3& scale)
{
}
void Matrix4::Translate(const Vector3& trans)
{
}
void Matrix4::Rotate(const RotAxis& rot)
{
}
void Matrix4::Scale(const Vector3& scale)
{
}

Matrix4 Matrix4::Transposed() const
{
}
Matrix4 Matrix4::Inverse() const
{
}

void Matrix4::SetOrtho(float left, float right, float bottom, float top, float near, float far)
{
}
void Matrix4::SetFrustum(float left, float right, float bottom, float top, float near, float far)
{
}
void Matrix4::SetPerspective(float fovy, float aspect, float near, float far)
{
}

void Matrix4::LookAt(const Vector3& pos, const Vector3& look, const Vector3& up)
{
}