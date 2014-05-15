#include "../logic/logic.h"
#include "../include/u-gine.h"

//-------------------------------------
//
//-------------------------------------
LabelComponent::LabelComponent ()
{ 
    m_font = NULL;
    SetType( ELabel );
}

//-------------------------------------
//
//-------------------------------------
LabelComponent::~LabelComponent()
{
}

//-------------------------------------
//
//-------------------------------------
TError LabelComponent::Init()
{
    GetParent()->GetParentScene()->AddFont( this );

    return TError::OK;
}

//-------------------------------------
//
//-------------------------------------
void LabelComponent::End()
{
    GetParent()->GetParentScene()->RemoveFont( this );
    DEL( m_font );
    m_font = NULL;
}

//-------------------------------------
//
//-------------------------------------
void LabelComponent::Update( double elapsedTime )
{
}

//-------------------------------------
//
//-------------------------------------
void LabelComponent::Render()
{
    if( m_font )
    {
        IScreenManager& manager = IScreenManager::Instance();

        Renderer::Instance().SetColor( m_red, m_green, m_blue, m_alpha );
        m_font->Render( m_label,  manager.TransformToScreenPointX( m_x ),  manager.TransformToScreenPointY( m_y ) );
        Renderer::Instance().SetColor( 255, 255, 255, 255 );
    }
}

//-------------------------------------
//
//-------------------------------------
void LabelComponent::SetLabel( String& label )
{
    m_label = label;
}

//-------------------------------------
//
//-------------------------------------
void LabelComponent::SetX( double x )
{
    m_x = x;
}

//-------------------------------------
//
//-------------------------------------
void LabelComponent::SetY( double y )
{
    m_y = y;
}

//-------------------------------------
//
//-------------------------------------
void LabelComponent::SetPosition( double x, double y  )
{
    m_x = x;
    m_y = y;
}

//-------------------------------------
//
//-------------------------------------
void LabelComponent::SetColor( uint8 r, uint8 g, uint8 b, uint8 a )
{
    m_red   = r;
    m_green = g;
    m_blue  = b;
    m_alpha = a;
}

void LabelComponent::SetFont( const String* font )
{
    if( font )
    {
        m_font = NEW( Font, ( *font ) );
    }
}

//-------------------------------------
//
//-------------------------------------
String LabelComponent::GetLabel() const
{
    return m_label;
}

//-------------------------------------
//
//-------------------------------------
double LabelComponent::GetX() const
{
    return m_x;
}

//-------------------------------------
//
//-------------------------------------
double LabelComponent::GetY()   const
{
    return m_y;
}

//-------------------------------------
//
//-------------------------------------
void LabelComponent::GetColor( uint8& r, uint8& g, uint8& b, uint8 a ) const
{
    r = m_red;
    g = m_green;
    b = m_blue;
    a = m_alpha;
}
