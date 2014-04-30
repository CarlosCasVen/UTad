#ifndef UGINE_MATRIX4_H
#define UGINE_MATRIX4_H

#include "math.h"
#include "rotaxis.h"
#include "types.h"
#include "vector3.h"
#include <string.h>


#define MATRIX_SIZE 16
#define ROW_SIZE     4
#define COLUMN_SIZE  4
#define VECTOR3_SIZE 3

class Matrix4 {
public:
	Matrix4();
	Matrix4(const Matrix4& other);
	Matrix4(const float* values);

	bool operator==(const Matrix4& other) const;
	Matrix4& operator=(const Matrix4& other);
	Matrix4 operator+(const Matrix4& other) const;
	Matrix4 operator-(const Matrix4& other) const;
	Matrix4 operator*(const Matrix4& other) const;
	Vector3 operator*(const Vector3& vec) const;
	Matrix4& operator+=(const Matrix4& other);
	Matrix4& operator-=(const Matrix4& other);
	Matrix4& operator*=(const Matrix4& other);
	const float& operator[](uint32 pos) const;
	float& operator[](uint32 pos);

	void SetIdentity();
	void Set(const float* m);
	float& RC(uint32 row, uint32 column);
	const float& RC(uint32 row, uint32 column) const;
	void SetRC(uint32 row, uint32 column, float value);
	
	Vector3 Translation() const;
	
	void SetTranslation(const Vector3& trans);
	void SetRotation(const RotAxis& rot);
	void SetScale(const Vector3& scale);
	void Translate(const Vector3& trans);
	void Rotate(const RotAxis& rot);
	void Scale(const Vector3& scale);

	Matrix4 Transposed() const;
	Matrix4 Inverse() const;

	void SetOrtho(float left, float right, float bottom, float top, float near, float far);
	void SetFrustum(float left, float right, float bottom, float top, float near, float far);
	void SetPerspective(float fovy, float aspect, float near, float far);

	void LookAt(const Vector3& pos, const Vector3& look, const Vector3& up);
private:
	float m[16];
};

inline Matrix4 Matrix4::Inverse() const {
	Matrix4 mat;

	mat.m[0] = m[5] * m[10] - m[6] * m[9];
	mat.m[1] = m[2] * m[9]  - m[1] * m[10];
	mat.m[2] = m[1] * m[6]  - m[2] * m[5];
	mat.m[4] = m[6] * m[8]  - m[4] * m[10];
	mat.m[5] = m[0] * m[10] - m[2] * m[8];
	mat.m[6] = m[2] * m[4]  - m[0] * m[6];
	mat.m[8] = m[4] * m[9]  - m[5] * m[8];
	mat.m[9] = m[1] * m[8]  - m[0] * m[9];	
	mat.m[10]= m[0] * m[5]  - m[1] * m[4];

	// Calculamos determinante
	float det = m[0]*mat.m[0] + m[1]*mat.m[4] + m[2]*mat.m[8];
	if ( fabs(det) <= 0.00001f ) return Matrix4();

	// Dividimos por el determinante
	float invdet = 1.0f / det;
	mat.m[0] *= invdet;
	mat.m[1] *= invdet;
	mat.m[2] *= invdet;
	mat.m[4] *= invdet;
	mat.m[5] *= invdet;
	mat.m[6] *= invdet;
	mat.m[8] *= invdet;
	mat.m[9] *= invdet;
	mat.m[10] *= invdet;

	// Calculamos traslacion
	mat.m[12] = -(m[12] * mat.m[0] + m[13] * mat.m[4] + m[14] * mat.m[8]);
	mat.m[13] = -(m[12] * mat.m[1] + m[13] * mat.m[5] + m[14] * mat.m[9]);
	mat.m[14] = -(m[12] * mat.m[2] + m[13] * mat.m[6] + m[14] * mat.m[10]);

	// Ultima fila
	mat.m[3] = mat.m[7] = mat.m[11] = 0.0f;
	mat.m[15] = 1.0f;
	
	return mat;
}

//---------------------------------
//
//---------------------------------
bool Matrix4::operator==(const Matrix4& other) const	
{
    bool equals = true;

    for( unsigned int index = 0; index < MATRIX_SIZE && equals; index++ )
    {
        if( m[index] != other[index] )
        {
            equals = false;
        }
    }

    return equals;
}
//---------------------------------
//
//---------------------------------
Matrix4& Matrix4::operator=(const Matrix4& other)
{
    for( unsigned int index = 0; index < MATRIX_SIZE; index++ ) m[index] = other[index];

    return *this;
}
//---------------------------------
//
//---------------------------------
Matrix4 Matrix4::operator+(const Matrix4& other) const
{
    float newMatrix[MATRIX_SIZE];

    for( unsigned int index = 0; index < MATRIX_SIZE; index++ )
	{
		newMatrix[index] = m[index] + other[index];
	}

	return Matrix4( newMatrix );
}
//---------------------------------
//
//---------------------------------
Matrix4 Matrix4::operator-(const Matrix4& other) const
{
    float newMatrix[MATRIX_SIZE];

    for( unsigned int index = 0; index < MATRIX_SIZE; index++ )
	{
		newMatrix[index] = m[index] - other[index];
	}

	return Matrix4( newMatrix );
}
//---------------------------------
//
//---------------------------------
Matrix4 Matrix4::operator*(const Matrix4& other) const
{
    float newMatrix[MATRIX_SIZE];

    for( unsigned int x = 0; x < ROW_SIZE; x++ )
    {
        for( unsigned int y = 0; y < COLUMN_SIZE; y++ )
        {
            newMatrix[ ( x * COLUMN_SIZE ) + y ] = 0;

            for( unsigned int i = 0; i < ROW_SIZE; i++ )
            {
                newMatrix[ ( x * COLUMN_SIZE ) + y ] += m[ y + i ] * other[ ( x + i ) * COLUMN_SIZE ];
            }
        }
    }
    
    return Matrix4( newMatrix );
}
//---------------------------------
//
//---------------------------------
Vector3 Matrix4::operator*(const Vector3& vec) const
{
    float newVec[VECTOR3_SIZE] = { 0, 0, 0 };

   for( unsigned int indexVec = 0; indexVec < VECTOR3_SIZE; indexVec++ )
   {
       for( unsigned int i = 0; i < ROW_SIZE; i++ )
       {
           newVec[ indexVec ] += newVec[ indexVec ] * m[ indexVec + ( i * COLUMN_SIZE ) ];
       }
   }

   return Vector3();
}
//---------------------------------
//
//---------------------------------
Matrix4& Matrix4::operator+=(const Matrix4& other)
{
	for( unsigned int index = 0; index < MATRIX_SIZE; index++ )
	{
		m[index] += other[index];
	}

	return *this;
}
//---------------------------------
//
//---------------------------------
Matrix4& Matrix4::operator-=(const Matrix4& other)
{
	for( unsigned int index = 0; index < MATRIX_SIZE; index++ )
	{
		m[index] -= other[index];
	}

	return *this;
}
//---------------------------------
//
//---------------------------------
Matrix4& Matrix4::operator*=(const Matrix4& other)
{
    float newMatrix[MATRIX_SIZE];

    for( unsigned int x = 0; x < ROW_SIZE; x++ )
    {
        for( unsigned int y = 0; y < COLUMN_SIZE; y++ )
        {
            newMatrix[ ( x * COLUMN_SIZE ) + y ] = 0;

            for( unsigned int i = 0; i < ROW_SIZE; i++ )
            {
                newMatrix[ ( x * COLUMN_SIZE ) + y ] += m[ y + i ] * other[ ( x + i ) * COLUMN_SIZE ];
            }
        }
    }
    
    for( unsigned int index = 0; index < MATRIX_SIZE; index++ ) m[ index ] = newMatrix[ index ];
   
    return *this;
}
//---------------------------------
//
//---------------------------------
const float& Matrix4::operator[](uint32 pos) const
{
	return m[pos];
}
//---------------------------------
//
//---------------------------------
float& Matrix4::operator[](uint32 pos)
{
	return m[pos];
}

#endif // UGINE_MATRIX4_H
