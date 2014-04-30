#include "../include/u-gine.h"

//---------------------------------
//
//---------------------------------
Matrix4::Matrix4()
{
    for( unsigned int index = 0; index < MATRIX_SIZE; index++ ) m[ index ] = 0;
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
        case 0:     m[ index ] = 1; break;
        case 4:     m[ index ] = 1; break;       
        case 9:     m[ index ] = 1; break;
        case 14:    m[ index ] = 1; break;
        default:    m[ index ]=  0; break;
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
    m[ 11 ] = trans.X();
    m[ 12 ] = trans.Y();
    m[ 13 ] = trans.Z();
}
//---------------------------------
//
//---------------------------------
void Matrix4::SetRotation(const RotAxis& rot)	
{
    
}
//---------------------------------
//
//---------------------------------
void Matrix4::SetScale(const Vector3& scale)
{
    m[ 0 ] = scale.X();
    m[ 4 ] = scale.Y();
    m[ 9 ] = scale.Z();
}
//---------------------------------
//
//---------------------------------
void Matrix4::Translate(const Vector3& trans)
{
}
//---------------------------------
//
//---------------------------------
void Matrix4::Rotate(const RotAxis& rot)
{
}
//---------------------------------
//
//---------------------------------
void Matrix4::Scale(const Vector3& scale)
{
}
//---------------------------------
//
//---------------------------------
Matrix4 Matrix4::Transposed() const
{
    return Matrix4();
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
        case  8:     m[ index ] = - ( right + left      ) / ( right - left   );    break;
        case  9:     m[ index ] = - ( top   + bottom    ) / ( top   - bottom );    break;
        case 10:     m[ index ] = - ( far   + near      ) / ( far   - near   );    break;
        case 11:     m[ index ] =     1.0f;                                        break;
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
}
//---------------------------------
//
//---------------------------------
void Matrix4::LookAt(const Vector3& pos, const Vector3& look, const Vector3& up)
{
    Vector3 zVector = pos - look;
    
    zVector.Normalized();

    Vector3 xVector = zVector.Cross( up );
    Vector3 yVector = xVector.Cross( up );

    xVector.Normalized();
    yVector.Normalized();

    float values[ MATRIX_SIZE ] = { 
                                    xVector.X(), yVector.X(), zVector.X(), 0,
                                    xVector.Y(), yVector.Y(), zVector.Y(), 0,
                                    xVector.Z(), yVector.Z(), zVector.Z(), 0,
                                              0,           0,           0, 0
                                   };
    Matrix4 lookMatrix( values );

    lookMatrix.Translate( Vector3( -pos.X(), -pos.Y(), -pos.Z() ) );
}