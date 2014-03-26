#include "../logic/logic.h"
#include "../include/u-gine.h"


//-------------------------------------
//
//-------------------------------------
SpriteComponent::SpriteComponent() : BaseComponent()
{
    m_sprite = NULL;
    SetType( ESprite );
}

//-------------------------------------
//
//-------------------------------------
SpriteComponent::~SpriteComponent()
{
    int x = 0;
}

//-------------------------------------
//
//-------------------------------------
TError SpriteComponent::Init()
{
    TError error = OK;

    if( !m_sprite ) 
        m_sprite = new Sprite( NULL );

    GetParent()->GetParentScene()->AddSprite( m_sprite, Scene::LAYER_FRONT );

    return error;
}

//-------------------------------------
//
//-------------------------------------
void SpriteComponent::End()
{
}

//-------------------------------------
//
//-------------------------------------
void SpriteComponent::Update( double elapsedTime )
{
}

//-------------------------------------
//
//-------------------------------------
void SpriteComponent::SetPosition( double x, double y, double z )
{
    if( m_sprite ) m_sprite->SetPosition( x, y, z );
}

//-------------------------------------
//
//-------------------------------------
void SpriteComponent::SetImage( const String& filename )
{
    if( !m_sprite ) m_sprite = new Sprite(  ResourceManager::Instance().LoadImage( filename ) );
    else            m_sprite->SetImage( ResourceManager::Instance().LoadImage( filename ) );
}

//-------------------------------------
//
//-------------------------------------
void SpriteComponent::SetColor( int r, int g, int b, int a )
{
    if( m_sprite ) m_sprite->SetColor( r, g, b );
}

//-------------------------------------
//
//-------------------------------------
double SpriteComponent::GetX() const
{
    if( m_sprite ) return m_sprite->GetX();
}

//-------------------------------------
//
//-------------------------------------
double SpriteComponent::GetY() const
{
    if( m_sprite ) return m_sprite->GetY();
}

//-------------------------------------
//
//-------------------------------------
double SpriteComponent::GetZ() const
{
    if( m_sprite ) return m_sprite->GetZ();
}

//-------------------------------------
//
//-------------------------------------
const Image* SpriteComponent::GetImage() const
{
    if( m_sprite ) return m_sprite->GetImage();
}

//-------------------------------------
//
//-------------------------------------
int SpriteComponent::GetR() const
{
    if( m_sprite ) return static_cast<int>(m_sprite->GetRed());
}

//-------------------------------------
//
//-------------------------------------
int SpriteComponent::GetG() const
{
    if( m_sprite ) return static_cast<int>(m_sprite->GetGreen());
}

//-------------------------------------
//
//-------------------------------------
int SpriteComponent::GetB() const
{
    if( m_sprite ) return static_cast<int>(m_sprite->GetBlue());
}

//-------------------------------------
//
//-------------------------------------
int SpriteComponent::GetA() const
{
    if( m_sprite ) return static_cast<int>(m_sprite->GetAlpha());
}