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
    IScreenManager& manager = IScreenManager::Instance();

    if( m_sprite ) m_sprite->SetPosition( manager.TransformToScreenPointX( x ), manager.TransformToScreenPointY( y ), z );
}

//-------------------------------------
//
//-------------------------------------
void SpriteComponent::SetImage( const String& filename, unsigned int hframes, unsigned int vframes  )
{
    if( !m_sprite ) m_sprite = new Sprite(  ResourceManager::Instance().LoadImage( filename, hframes, vframes ) );
    else            m_sprite->SetImage   (  ResourceManager::Instance().LoadImage( filename, hframes, vframes ) );

    IScreenManager& manager = IScreenManager::Instance();
    SetScale( manager.TransformToScreenPointX( 1.0f ), manager.TransformToScreenPointY( 1.0f ) );
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
    IScreenManager& manager = IScreenManager::Instance();

    if( m_sprite ) return manager.TransformToWorldPointX( m_sprite->GetX() );

    return -1;
}

//-------------------------------------
//
//-------------------------------------
double SpriteComponent::GetY() const
{
    IScreenManager& manager = IScreenManager::Instance();

    if( m_sprite ) return manager.TransformToWorldPointY( m_sprite->GetY() );

    return -1;
}

//-------------------------------------
//
//-------------------------------------
double SpriteComponent::GetZ() const
{
    if( m_sprite ) return m_sprite->GetZ();

    return -1;
}

//-------------------------------------
//
//-------------------------------------
const Image* SpriteComponent::GetImage() const
{
    if( m_sprite ) return m_sprite->GetImage();

    return NULL;
}

//-------------------------------------
//
//-------------------------------------
int SpriteComponent::GetR() const
{
    if( m_sprite ) return static_cast<int>(m_sprite->GetRed());

    return -1;
}

//-------------------------------------
//
//-------------------------------------
int SpriteComponent::GetG() const
{
    if( m_sprite ) return static_cast<int>(m_sprite->GetGreen());

    return -1;
}

//-------------------------------------
//
//-------------------------------------
int SpriteComponent::GetB() const
{
    if( m_sprite ) return static_cast<int>(m_sprite->GetBlue());

    return -1;
}

//-------------------------------------
//
//-------------------------------------
int SpriteComponent::GetA() const
{
    if( m_sprite ) return static_cast<int>(m_sprite->GetAlpha());

    return -1;
}

Sprite* SpriteComponent::GetSprite()
{
    if( m_sprite ) return m_sprite;

    return NULL;
}


void SpriteComponent::SetScale( double x, double y )
{
     IScreenManager& manager = IScreenManager::Instance();
     double xTrans = manager.TransformToScreenPointX( x );
     double yTrans = manager.TransformToScreenPointY( y );

     if( m_sprite ) m_sprite->SetScale( xTrans, yTrans );
}

double SpriteComponent::GetScaleX() const
{
    IScreenManager& manager = IScreenManager::Instance();

    if( m_sprite ) return manager.TransformToWorldPointX( m_sprite->GetScaleX() );

    return -1;
}
    
double SpriteComponent::GetScaleY() const
{
    IScreenManager& manager = IScreenManager::Instance();

    if( m_sprite ) return manager.TransformToWorldPointY( m_sprite->GetScaleY() );

    return -1;
}