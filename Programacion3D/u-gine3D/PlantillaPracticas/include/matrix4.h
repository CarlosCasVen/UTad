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
	Matrix4 inv;
	inv[ 0] =  m[5] * m[10] * m[15] - m[5] * m[11] * m[14] - m[9] * m[6] * m[15] + m[9] * m[7] * m[14] + m[13] * m[6] * m[11] - m[13] * m[7] * m[10];
	inv[ 4] = -m[4] * m[10] * m[15] + m[4] * m[11] * m[14] + m[8] * m[6] * m[15] - m[8] * m[7] * m[14] - m[12] * m[6] * m[11] + m[12] * m[7] * m[10];
	inv[ 8] =  m[4] * m[ 9] * m[15] - m[4] * m[11] * m[13] - m[8] * m[5] * m[15] + m[8] * m[7] * m[13] + m[12] * m[5] * m[11] - m[12] * m[7] * m[ 9];
	inv[12] = -m[4] * m[ 9] * m[14] + m[4] * m[10] * m[13] + m[8] * m[5] * m[14] - m[8] * m[6] * m[13] - m[12] * m[5] * m[10] + m[12] * m[6] * m[ 9];
	inv[ 1] = -m[1] * m[10] * m[15] + m[1] * m[11] * m[14] + m[9] * m[2] * m[15] - m[9] * m[3] * m[14] - m[13] * m[2] * m[11] + m[13] * m[3] * m[10];
	inv[ 5] =  m[0] * m[10] * m[15] - m[0] * m[11] * m[14] - m[8] * m[2] * m[15] + m[8] * m[3] * m[14] + m[12] * m[2] * m[11] - m[12] * m[3] * m[10];
	inv[ 9] = -m[0] * m[ 9] * m[15] + m[0] * m[11] * m[13] + m[8] * m[1] * m[15] - m[8] * m[3] * m[13] - m[12] * m[1] * m[11] + m[12] * m[3] * m[ 9];
	inv[13] =  m[0] * m[ 9] * m[14] - m[0] * m[10] * m[13] - m[8] * m[1] * m[14] + m[8] * m[2] * m[13] + m[12] * m[1] * m[10] - m[12] * m[2] * m[ 9];
	inv[ 2] =  m[1] * m[ 6] * m[15] - m[1] * m[ 7] * m[14] - m[5] * m[2] * m[15] + m[5] * m[3] * m[14] + m[13] * m[2] * m[ 7] - m[13] * m[3] * m[ 6];
	inv[ 6] = -m[0] * m[ 6] * m[15] + m[0] * m[ 7] * m[14] + m[4] * m[2] * m[15] - m[4] * m[3] * m[14] - m[12] * m[2] * m[ 7] + m[12] * m[3] * m[ 6];
	inv[10] =  m[0] * m[ 5] * m[15] - m[0] * m[ 7] * m[13] - m[4] * m[1] * m[15] + m[4] * m[3] * m[13] + m[12] * m[1] * m[ 7] - m[12] * m[3] * m[ 5];
	inv[14] = -m[0] * m[ 5] * m[14] + m[0] * m[ 6] * m[13] + m[4] * m[1] * m[14] - m[4] * m[2] * m[13] - m[12] * m[1] * m[ 6] + m[12] * m[2] * m[ 5];
	inv[ 3] = -m[1] * m[ 6] * m[11] + m[1] * m[ 7] * m[10] + m[5] * m[2] * m[11] - m[5] * m[3] * m[10] - m[ 9] * m[2] * m[ 7] + m[ 9] * m[3] * m[ 6];
	inv[ 7] =  m[0] * m[ 6] * m[11] - m[0] * m[ 7] * m[10] - m[4] * m[2] * m[11] + m[4] * m[3] * m[10] + m[ 8] * m[2] * m[ 7] - m[ 8] * m[3] * m[ 6];
	inv[11] = -m[0] * m[ 5] * m[11] + m[0] * m[ 7] * m[ 9] + m[4] * m[1] * m[11] - m[4] * m[3] * m[ 9] - m[ 8] * m[1] * m[ 7] + m[ 8] * m[3] * m[ 5];
	inv[15] =  m[0] * m[ 5] * m[10] - m[0] * m[ 6] * m[ 9] - m[4] * m[1] * m[10] + m[4] * m[2] * m[ 9] + m[ 8] * m[1] * m[ 6] - m[ 8] * m[2] * m[ 5];
 
	float det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];
	if ( fabs(det) <= 0.00001f ) return Matrix4();
 
	float invdet = 1.0f / det;
	for ( uint32 i = 0; i < 16; i++ ) inv[i] *= invdet;
	
	return inv;
}



//---------------------------------
//
//---------------------------------
inline bool Matrix4::operator==(const Matrix4& other) const	
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
inline Matrix4& Matrix4::operator=(const Matrix4& other)
{
    for( unsigned int index = 0; index < MATRIX_SIZE; index++ ) m[ index ] = other[ index ]; 
    return *this;
}
//---------------------------------
//
//---------------------------------
inline Matrix4 Matrix4::operator+(const Matrix4& other) const
{
    float newMatrix[MATRIX_SIZE];

    for( unsigned int index = 0; index < MATRIX_SIZE; index++ )
	{
		newMatrix[ index ] = m[ index ] + other[ index ];
	}

	return Matrix4( newMatrix );
}
//---------------------------------
//
//---------------------------------
inline Matrix4 Matrix4::operator-(const Matrix4& other) const
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
inline Matrix4 Matrix4::operator*(const Matrix4& other) const
{
    float newMatrix[MATRIX_SIZE];

    for( unsigned int x = 0; x < ROW_SIZE; x++ )
    {
        for( unsigned int y = 0; y < COLUMN_SIZE; y++ )
        {
            newMatrix[ ( x * COLUMN_SIZE ) + y ] = 0;

            for( unsigned int i = 0; i < ROW_SIZE; i++ )
            {
				float prim =  m[ i * COLUMN_SIZE  + y ];
				float sec  =  other[ x * COLUMN_SIZE + i] ;
				float op = newMatrix[ ( x * COLUMN_SIZE + i ) + y ] + prim * sec;

                newMatrix[ ( x * COLUMN_SIZE ) + y  ] += m[  i * COLUMN_SIZE  + y  ] * other[ ( x ) * COLUMN_SIZE + i ];
            }
        }
    }
    
    return Matrix4( newMatrix );
}
//---------------------------------
//
//---------------------------------
inline Vector3 Matrix4::operator*(const Vector3& vec) const
{
    Vector3 newVec;
    return Vector3(
                    vec.X() * m[ 0 ] + vec.Y() * m[ ROW_SIZE     ] + vec.Z() * m[ ROW_SIZE * 2     ],
                    vec.X() * m[ 1 ] + vec.Y() * m[ ROW_SIZE + 1 ] + vec.Z() * m[ ROW_SIZE * 2 + 1 ],
                    vec.X() * m[ 2 ] + vec.Y() * m[ ROW_SIZE + 2 ] + vec.Z() * m[ ROW_SIZE * 2 + 2 ]
                  );
}
//---------------------------------
//
//---------------------------------
inline Matrix4& Matrix4::operator+=(const Matrix4& other)
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
inline Matrix4& Matrix4::operator-=(const Matrix4& other)
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
inline Matrix4& Matrix4::operator*=(const Matrix4& other)
{
    *this = *this * other;
    return *this;
}
//---------------------------------
//
//---------------------------------
inline const float& Matrix4::operator[](uint32 pos) const
{
	return m[pos];
}
//---------------------------------
//
//---------------------------------
inline float& Matrix4::operator[](uint32 pos)
{
	return m[pos];
}
//---------------------------------
//
//---------------------------------
inline Matrix4::Matrix4()
{
	SetIdentity();
}
//---------------------------------
//
//---------------------------------
inline Matrix4::Matrix4(const Matrix4& other)
{
    *this = other;
}
//---------------------------------
//
//---------------------------------
inline Matrix4::Matrix4(const float* values)
{
    for( unsigned int index = 0; index < MATRIX_SIZE; index++ ) m[ index ] = values[ index ];
}
//---------------------------------
//
//---------------------------------
inline void Matrix4::SetIdentity()
{
    for( unsigned int index = 0; index < MATRIX_SIZE; index++ )
    {
        switch( index )
        {
        case  0:     m[ index ] = 1.0f; break;
        case  5:     m[ index ] = 1.0f; break;       
        case 10:     m[ index ] = 1.0f; break;
        case 15:     m[ index ] = 1.0f; break;
        default:     m[ index ]=  0.0f; break;
        }
    }
}
//---------------------------------
//
//---------------------------------
inline void Matrix4::Set(const float* m)
{
    for( unsigned int index = 0; index < MATRIX_SIZE; index++ ) this->m[ index ] = m[ index ];
}
//---------------------------------
//
//---------------------------------
inline float& Matrix4::RC(uint32 row, uint32 column)
{
    return m[ column * COLUMN_SIZE + row ];
}
//---------------------------------
//
//---------------------------------
inline const float& Matrix4::RC(uint32 row, uint32 column) const
{
    return m[ column * COLUMN_SIZE + row ];
}
//---------------------------------
//
//---------------------------------
inline void Matrix4::SetRC(uint32 row, uint32 column, float value)
{
    m[ column * COLUMN_SIZE + row ] = value;
}
//---------------------------------
//
//---------------------------------
inline Vector3 Matrix4::Translation() const
{
    return Vector3( m[ 12 ], m[ 13 ], m[ 14 ] );
}
//---------------------------------
//
//---------------------------------
inline void Matrix4::SetTranslation(const Vector3& trans)
{
	SetIdentity();
    m[ 12 ] = trans.X();
    m[ 13 ] = trans.Y();
    m[ 14 ] = trans.Z();
}
//---------------------------------
//
//---------------------------------
inline void Matrix4::SetRotation(const RotAxis& rot)	
{
	float c = static_cast<float>( DegCos( static_cast<float>( rot.Angle() ) ) );
	float s = static_cast<float>( DegSin( static_cast<float>( rot.Angle() ) ) );

    m[0]  = rot.Axis().X() * rot.Axis().X() * ( 1 - c ) + c;	
    m[1]  = rot.Axis().X() * rot.Axis().Y() * ( 1 - c ) + rot.Axis().Z() * s;	
    m[2]  = rot.Axis().X() * rot.Axis().Z() * ( 1 - c ) - rot.Axis().Y() * s;	
    m[3]  = 0;		        

    m[4]  = rot.Axis().X() * rot.Axis().Y() * ( 1 - c ) - rot.Axis().Z() * s;	
    m[5]  = rot.Axis().Y() * rot.Axis().Y() * ( 1 - c ) + c;	
    m[6]  = rot.Axis().Y() * rot.Axis().Z() * ( 1 - c ) + rot.Axis().X() * s;	
    m[7]  = 0;		        

    m[8]  = rot.Axis().X() * rot.Axis().Z() * ( 1 - c ) + rot.Axis().Y() * s;	
    m[9]  = rot.Axis().Y() * rot.Axis().Z() * ( 1 - c ) - rot.Axis().X() * s;	
    m[10] = rot.Axis().Z() * rot.Axis().Z() * ( 1 - c ) + c;	
    m[11] = 0;		        

    m[12] = 0;
    m[13] = 0;
    m[14] = 0;
    m[15] = 1;
}
//---------------------------------
//
//---------------------------------
inline void Matrix4::SetScale(const Vector3& scale)
{
	SetIdentity();
    m[  0 ] *= scale.X();
    m[  5 ] *= scale.Y();
    m[ 10 ] *= scale.Z();
}
//---------------------------------
//
//---------------------------------
inline void Matrix4::Translate(const Vector3& trans)
{
	Matrix4 translation;
	translation.SetTranslation( trans );
	*this *= translation;
}
//---------------------------------
//
//---------------------------------
inline void Matrix4::Rotate(const RotAxis& rot)
{
	Matrix4 rotation;
	rotation.SetRotation( rot );
	*this *= rotation;
}
//---------------------------------
//
//---------------------------------
inline void Matrix4::Scale(const Vector3& scale)
{
	Matrix4 scaleMatrix;
	scaleMatrix.SetScale( scale );
	*this *= scaleMatrix;
}
//---------------------------------
//
//---------------------------------
inline Matrix4 Matrix4::Transposed() const
{
	float values[ MATRIX_SIZE ];

	values[  0 ] = m[  0 ];
	values[  1 ] = m[  4 ];
    values[  2 ] = m[  8 ];
	values[  3 ] = m[ 12 ];
	values[  4 ] = m[  1 ];
	values[  5 ] = m[  5 ];
	values[  6 ] = m[  9 ];
	values[  7 ] = m[ 13 ];
	values[  8 ] = m[  2 ];
	values[  9 ] = m[  6 ];
	values[ 10 ] = m[ 10 ];
	values[ 11 ] = m[ 14 ];
	values[ 12 ] = m[  3 ];
	values[ 13 ] = m[  7 ];
	values[ 14 ] = m[ 11 ];
	values[ 15 ] = m[ 15 ];

	return Matrix4( values );
}
//---------------------------------
//
//---------------------------------
inline void Matrix4::SetOrtho(float left, float right, float bottom, float top, float near, float far)
{
     m[  0 ] =      2.0f             / ( right - left   );
     m[  5 ] =      2.0f             / ( top   - bottom );
     m[ 10 ] =  -   2.0f             / ( far   - near   );
     m[ 12 ] =  - ( right + left   ) / ( right - left   );
     m[ 13 ] =  - ( top   + bottom ) / ( top   - bottom );
     m[ 14 ] =  - ( far   + near   ) / ( far   - near   );
     m[ 15 ] =      1.0f;                                 
}
//---------------------------------
//
//---------------------------------
inline void Matrix4::SetFrustum(float left, float right, float bottom, float top, float near, float far)
{
    m[  0 ] =     near * 2.0f         / ( right - left   );
    m[  5 ] =     near * 2.0f         / ( top   - bottom );
    m[  8 ] =   ( right + left      ) / ( right - left   );
    m[  9 ] =   ( top   + bottom    ) / ( top   - bottom );
    m[ 10 ] = - ( far   + near      ) / ( far   - near   );
    m[ 11 ] = -   1.0f;                                    
    m[ 14 ] = - ( 2.0f * far * near ) / ( far   - near   );

}
//---------------------------------
//
//---------------------------------
inline void Matrix4::SetPerspective(float fovy, float aspect, float near, float far)
{
	float height = near   * static_cast<float>( DegTan( fovy / 2 ) );
	float width  = height * aspect;
	SetFrustum( -width, width, -height, height, near, far );
}
//---------------------------------
//
//---------------------------------
inline void Matrix4::LookAt(const Vector3& pos, const Vector3& look, const Vector3& up)
{
    Vector3 zVector = pos - look;
    
    zVector = zVector.Normalized();

    Vector3 xVector = up.Cross( zVector );
    Vector3 yVector = zVector.Cross( xVector );

    xVector = xVector.Normalized();
    yVector = yVector.Normalized();

    m[0]  = xVector.X();	m[4]  = xVector.Y();	m[8]  = xVector.Z();	m[12] = 0;
    m[1]  = yVector.X();	m[5]  = yVector.Y();	m[9]  = yVector.Z();	m[13] = 0;
    m[2]  = zVector.X();	m[6]  = zVector.Y();	m[10] = zVector.Z();	m[14] = 0;
    m[3]  = 0;		        m[7]  = 0;		        m[11] = 0;		        m[15] = 1;
    
    this->Translate( Vector3(-pos.X(), -pos.Y(), -pos.Z()) );
}

#endif // UGINE_MATRIX4_H
