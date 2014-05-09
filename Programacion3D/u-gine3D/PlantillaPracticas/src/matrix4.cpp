#include "../include/matrix4.h"

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
//---------------------------------
//
//---------------------------------
Matrix4::Matrix4()
{
	SetIdentity();
}
//---------------------------------
//
//---------------------------------
Matrix4::Matrix4(const Matrix4& other)
{
    for( unsigned int index = 0; index < MATRIX_SIZE; index++ ) m[ index ] = other[ index ];
}
//---------------------------------
//
//---------------------------------
Matrix4::Matrix4(const float* values)
{
    for( unsigned int index = 0; index < MATRIX_SIZE; index++ ) m[ index ] = values[ index ];
}
//---------------------------------
//
//---------------------------------
void Matrix4::SetIdentity()
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
void Matrix4::Set(const float* m)
{
    for( unsigned int index = 0; index < MATRIX_SIZE; index++ ) this->m[ index ] = m[ index ];
}
//---------------------------------
//
//---------------------------------
float& Matrix4::RC(uint32 row, uint32 column)
{
    return m[ column * COLUMN_SIZE + row ];
}
//---------------------------------
//
//---------------------------------
const float& Matrix4::RC(uint32 row, uint32 column) const
{
    return m[ column * COLUMN_SIZE + row ];
}
//---------------------------------
//
//---------------------------------
void Matrix4::SetRC(uint32 row, uint32 column, float value)
{
    m[ column * COLUMN_SIZE + row ] = value;
}
//---------------------------------
//
//---------------------------------
Vector3 Matrix4::Translation() const
{
    return Vector3( 11, 12, 13 );
}
//---------------------------------
//
//---------------------------------
void Matrix4::SetTranslation(const Vector3& trans)
{
	SetIdentity();
    m[ 12 ] = trans.X();
    m[ 13 ] = trans.Y();
    m[ 14 ] = trans.Z();
}
//---------------------------------
//
//---------------------------------
void Matrix4::SetRotation(const RotAxis& rot)	
{
	float c = static_cast<float>( DegCos( static_cast<float>( rot.Angle() ) ) );
	float s = static_cast<float>( DegSin( static_cast<float>( rot.Angle() ) ) );

    float values[16] = {
						rot.Axis().X() * rot.Axis().X() * ( 1 - c ) + c,
						rot.Axis().X() * rot.Axis().Y() * ( 1 - c ) + rot.Axis().Z() * s,
						rot.Axis().X() * rot.Axis().Z() * ( 1 - c ) - rot.Axis().Y() * s,
						0,

						rot.Axis().X() * rot.Axis().Y() * ( 1 - c ) - rot.Axis().Z() * s,
						rot.Axis().Y() * rot.Axis().Y() * ( 1 - c ) + c,
						rot.Axis().Y() * rot.Axis().Z() * ( 1 - c ) + rot.Axis().X() * s,
						0,

						rot.Axis().X() * rot.Axis().Z() * ( 1 - c ) + rot.Axis().Y() * s,
						rot.Axis().Y() * rot.Axis().Z() * ( 1 - c ) - rot.Axis().X() * s,
						rot.Axis().Z() * rot.Axis().Z() * ( 1 - c ) + c,
						0,

						0,
						0,
						0,
						1
				    };
	Set( values );

}
//---------------------------------
//
//---------------------------------
void Matrix4::SetScale(const Vector3& scale)
{
	SetIdentity();
    m[  0 ] *= scale.X();
    m[  5 ] *= scale.Y();
    m[ 10 ] *= scale.Z();
}
//---------------------------------
//
//---------------------------------
void Matrix4::Translate(const Vector3& trans)
{
	Matrix4 translation;
	translation.SetTranslation( trans );
	*this *= translation;
}
//---------------------------------
//
//---------------------------------
void Matrix4::Rotate(const RotAxis& rot)
{
	Matrix4 rotation;
	rotation.SetRotation( rot );
	*this *= rotation;
}
//---------------------------------
//
//---------------------------------
void Matrix4::Scale(const Vector3& scale)
{
	Matrix4 scaleMatrix;
	scaleMatrix.SetScale( scale );
	*this *= scaleMatrix;
}
//---------------------------------
//
//---------------------------------
Matrix4 Matrix4::Transposed() const
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
void Matrix4::SetOrtho(float left, float right, float bottom, float top, float near, float far)
{

    for( unsigned int index = 0; index < MATRIX_SIZE; index++ )
    {
        switch( index )
        {
        case  0:     m[ index ] =      2.0f             / ( right - left   );    break;
        case  5:     m[ index ] =      2.0f             / ( top   - bottom );    break;
        case 10:     m[ index ] =  -   2.0f             / ( far   - near   );    break;
        case 12:     m[ index ] =  - ( right + left   ) / ( right - left   );    break;
        case 13:     m[ index ] =  - ( top   + bottom ) / ( top   - bottom );    break;
        case 14:     m[ index ] =  - ( far   + near   ) / ( far   - near   );    break;
        case 15:     m[ index ] =      1.0f;                                     break;
        default:     m[ index ] =      0.0f;                                     break;
        }
    }
}
//---------------------------------
//
//---------------------------------
void Matrix4::SetFrustum(float left, float right, float bottom, float top, float near, float far)
{
    for( unsigned int index = 0; index < MATRIX_SIZE; index++ )
    {
        switch( index )
        {
        case  0:     m[ index ] =     near * 2.0f         / ( right - left   );    break;
        case  5:     m[ index ] =     near * 2.0f         / ( top   - bottom );    break;
        case  8:     m[ index ] =   ( right + left      ) / ( right - left   );    break;
        case  9:     m[ index ] =   ( top   + bottom    ) / ( top   - bottom );    break;
        case 10:     m[ index ] = - ( far   + near      ) / ( far   - near   );    break;
        case 11:     m[ index ] = -   1.0f;                                        break;
        case 14:     m[ index ] = - ( 2.0f * far * near ) / ( far   - near   );    break;
        default:     m[ index ] =     0.0f;                                        break;
        }
    }

}
//---------------------------------
//
//---------------------------------
void Matrix4::SetPerspective(float fovy, float aspect, float near, float far)
{
	float height = near   * static_cast<float>( DegTan( fovy / 2 ) );
	float width  = height * aspect;
	SetFrustum( -width, width, -height, height, near, far );
}
//---------------------------------
//
//---------------------------------
void Matrix4::LookAt(const Vector3& pos, const Vector3& look, const Vector3& up)
{
    Vector3 zVector = pos - look;
    
    zVector.Normalized();

    Vector3 xVector = zVector.Cross( up		);
    Vector3 yVector = xVector.Cross( zVector );

    xVector.Normalized();
    yVector.Normalized();

    float values[ MATRIX_SIZE ] = { 
                                    xVector.X(), yVector.X(), zVector.X(), 0,
                                    xVector.Y(), yVector.Y(), zVector.Y(), 0,
                                    xVector.Z(), yVector.Z(), zVector.Z(), 0,
                                              0,           0,           0, 1
                                   };
    Matrix4 lookMatrix( values );

    lookMatrix.Translate( Vector3( -pos.X(), -pos.Y(), -pos.Z() ) );
}