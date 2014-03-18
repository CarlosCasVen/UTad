#include "../logic/Logic.h"
#include "../include/u-gine.h"
#include <time.h>


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
    m_sprite = new Sprite( image );

    m_sprite->SetPosition( GetParams()["x"].GetDouble(),
                           GetParams()["y"].GetDouble()
                           );
    IScene* scene = (IScene*)GetParentScene();
    scene->AddSprite( m_sprite, Scene::LAYER_BACK );

    return error;
}


void PlayerEntity::End ()
{
    //DEL( m_sprite );
}


void PlayerEntity::Update( double ElpasedTime )
{
	if( m_sprite )
	{
		float x = (float)m_sprite->GetX();
		float y = (float)m_sprite->GetY();

		x += (sinf( (float)time(0) ) * 50 ) * Screen::Instance().ElapsedTime();
//		y += cosf( time(0) ) / 10;

		m_sprite->SetPosition( (float)x, (float)y ,0);
	}
}