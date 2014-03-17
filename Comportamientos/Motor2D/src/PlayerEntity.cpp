#include "../logic/Logic.h"
#include "../include/u-gine.h"


PlayerEntity::PlayerEntity(  const rapidjson::Value& params  ) : BaseEntity( params )
{
}


PlayerEntity::~PlayerEntity()
{
}



TError PlayerEntity::Init()
{
    TError error = OK;

    Image* image = ResourceManager::Instance().LoadImage( GetParams()["Image"].GetString() );
    m_sprite = NEW( Sprite, ( image ) );

    m_sprite->SetPosition( GetParams()["x"].GetDouble(),
                           GetParams()["y"].GetDouble()
                           );
    IScene* scene = (IScene*)GetParentScene();
    scene->AddSprite( m_sprite, Scene::LAYER_BACK );

    return error;
}


void PlayerEntity::End ()
{
    DEL( m_sprite );
}


void PlayerEntity::Update( double ElpasedTime )
{
}