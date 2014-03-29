#include "../logic/logic.h"


//-------------------------------------
//
//-------------------------------------
ShootComponent::ShootComponent( const rapidjson::Value& params ) : BaseComponent( params )
{
}

//-------------------------------------
//
//-------------------------------------
ShootComponent::~ShootComponent()
{
}

//-------------------------------------
//
//-------------------------------------
TError ShootComponent::Init()
{
}

//-------------------------------------
//
//-------------------------------------
void ShootComponent::End()
{
}

//-------------------------------------
//
//-------------------------------------
void ShootComponent::Update( double elapsedTime )
{
}

//-------------------------------------
//
//-------------------------------------
bool ShootComponent::newBullet()
{
    if( !m_newBullet ) return false;

    m_newBullet = false;
    return true;
}