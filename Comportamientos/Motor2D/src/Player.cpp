#include "../logic/logic.h"
#include "../include/u-gine.h"



//-------------------------------------
//
//-------------------------------------
TError Player::Init( IScene* m_scene, const rapidjson::Value& params)
{
    TError error = BaseEntity::Init( m_scene );

    if( !params.HasMember( "Image" ) )  error = NO_MEMBER;
    if( !params.HasMember( "x" ) )      error = NO_MEMBER;
    if( !params.HasMember( "y" ) )      error = NO_MEMBER;
    if( !params.HasMember( "z" ) )      error = NO_MEMBER;

    if( error == OK ) 
    {
        Image* image = ResourceManager::Instance().LoadImage( params["Image"].GetString() );
        String layer = "LAYER_BACK";

        if( params.HasMember( "Layer" ) ) String layer = params["Layer"].GetString();
            
        if( layer == "LAYER_BACK" )         SetSprite( m_scene->CreateSprite( *image, Scene::LAYER_BACK   ) );
        else if( layer == "LAYER_FRONT"  )  SetSprite( m_scene->CreateSprite( *image, Scene::LAYER_FRONT  ) );
        else if( layer == "LAYER_MIDDLE" )  SetSprite( m_scene->CreateSprite( *image, Scene::LAYER_MIDDLE ) );
        else if( layer == "LAYER_COUNT"  )  SetSprite( m_scene->CreateSprite( *image, Scene::LAYER_COUNT  ) );
        else                                error = NO_LAYER;

        GetSprite()->SetPosition( params["x"].GetDouble(), params["y"].GetDouble(), params["z"].GetDouble() );
    }

    return error;
}

//-------------------------------------
//
//-------------------------------------
void Player::End ()
{
    m_live = 0;

    BaseEntity::End();
}

//-------------------------------------
//
//-------------------------------------
void Player::Update( double ElpasedTime )
{

}

//-------------------------------------
//
//-------------------------------------
void Player::ReceiveEvent( Event& newEvent )
{

}

//-------------------------------------
//
//-------------------------------------
void Player::SubstractLive ( unsigned int damage )
{
    if( m_live < damage ) m_live = 0;
    else                  m_live -= damage;
}