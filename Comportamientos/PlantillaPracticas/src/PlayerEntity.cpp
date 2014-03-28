#include "../logic/Logic.h"
#include "../include/u-gine.h"
#include <time.h>

bool  push = false;
//-------------------------------------
//
//-------------------------------------
PlayerEntity::PlayerEntity(  const rapidjson::Value* params  ) : BaseEntity( params )
{
}

//-------------------------------------
//
//-------------------------------------
PlayerEntity::~PlayerEntity()
{
}

//-------------------------------------
//
//-------------------------------------
TError PlayerEntity::Init()
{
    TError error = OK;

    InputComponent*  input    = IComponentFactory::Instance().GetComponent<InputComponent> ( error );

    if( error != OK )
    {
        IComponentFactory::Instance().RemoveComponent( input );
        return error;
    }

    SpriteComponent* sprite   = IComponentFactory::Instance().GetComponent<SpriteComponent>( error );

    if( error != OK )
    {
        IComponentFactory::Instance().RemoveComponent( sprite );
        return error;
    }

    MoveComponent*   movement = IComponentFactory::Instance().GetComponent<MoveComponent>  ( error );
    
    if( error != OK )
    {
        IComponentFactory::Instance().RemoveComponent( movement );
        return error;
    }

    AnimatorComponent*   animator = IComponentFactory::Instance().GetComponent<AnimatorComponent>  ( error );
    
    if( error != OK )
    {
        IComponentFactory::Instance().RemoveComponent( animator );
        return error;
    }

    CollisionComponent*   collision = IComponentFactory::Instance().GetComponent<CollisionComponent>  ( error );
    
    if( error != OK )
    {
        IComponentFactory::Instance().RemoveComponent( collision );
        return error;
    }

    LiveComponent*   live = IComponentFactory::Instance().GetComponent<LiveComponent>  ( error );
    
    if( error != OK )
    {
        IComponentFactory::Instance().RemoveComponent( live );
        return error;
    }

    if( GetParams().HasMember( "Image"     ) )    sprite->SetImage   ( String( GetParams()["Image"].GetString() ) );
    if( GetParams().HasMember( "X"         ) && 
        GetParams().HasMember( "Y"         ) )    sprite->SetPosition( GetParams()["X"].GetDouble(), GetParams()["Y"].GetDouble() );
    if( GetParams().HasMember( "Speed"     ) )    movement->SetSpeed ( GetParams()["Speed"].GetDouble() );
    if( GetParams().HasMember( "Right"     ) )    m_right    = (eInputCode)GetParams()["Right"].GetInt();
    if( GetParams().HasMember( "Left"      ) )    m_left  = (eInputCode)GetParams()["Left"].GetInt();
    if( GetParams().HasMember( "Shoot"     ) )    m_shoot = (eInputCode)GetParams()["Shoot"].GetInt();
    if( GetParams().HasMember( "Shoot"     ) )    m_shoot = (eInputCode)GetParams()["Shoot"].GetInt();
	if( GetParams().HasMember( "Direction" ) )    m_yDirection    = GetParams()["Direction"].GetInt();
	if( GetParams().HasMember( "BSpeed"    ) )    m_bulletSpeed    = GetParams()["BSpeed"].GetDouble();

    animator->SetSprite ( sprite->GetSprite() );
    collision->SetSprite( sprite->GetSprite() );

    if( GetParams().HasMember( "FirstFps"  ) &&
        GetParams().HasMember( "LastFps"   ) )    animator->SetFrameRange( GetParams()["FirstFps"].GetInt(), GetParams()["LastFps"].GetInt() );
    if( GetParams().HasMember( "FirstFps"  ) )    animator->SetFPS( GetParams()["FPS"].GetInt() );
    if( GetParams().HasMember( "Collision" ) )    collision->SetCollisionMode( (Sprite::CollisionMode) GetParams()["Collision"].GetInt() );
    if( GetParams().HasMember( "Live"      ) )    live->SetLive( GetParams()["Live"].GetInt() );
 
    AddComponent( input     );
    AddComponent( sprite    );
    AddComponent( movement  );
    AddComponent( collision );
    AddComponent( animator  );
    AddComponent( live      );

    error = BaseEntity::Init();

    return error;
}

//-------------------------------------
//
//-------------------------------------
void PlayerEntity::End ()
{
    BaseEntity::End();
}

//-------------------------------------
//
//-------------------------------------
void PlayerEntity::Update( double elapsedTime )
{
    BaseEntity::Update( elapsedTime );

    InputComponent*  input    = NULL;
    SpriteComponent* sprite   = NULL;
    MoveComponent*   movement = NULL;

    input    = GetComponentByType<InputComponent> ( IComponent::EInput  ); 
    sprite   = GetComponentByType<SpriteComponent>( IComponent::ESprite ); 
    movement = GetComponentByType<MoveComponent>  ( IComponent::EMove   );

	double y = sprite->GetY();
    double x = sprite->GetX();

    if( input->IsButtonPressed( m_right  ) ) 
	{
		movement->SetDirection( 1, 0 );
		x += movement->GetXIncrement();
	}
	if( input->IsButtonPressed( m_left  ) ) 
	{
		movement->SetDirection( -1, 0 );
		x += movement->GetXIncrement();
	}
/*	if( input->IsButtonDown( m_shoot ) && !push ) 
    {
		push = true;
        CreateBullet( sprite->GetX(), y );
    }*/
	sprite->SetPosition( x, y ); 
}

//-------------------------------------
//
//-------------------------------------
/*void PlayerEntity::CreateBullet( double x, double y )
{
    TError error = OK;
    
    BulletEntity* bullet = IEntityFactory::Instance().GetTemporalEntity<BulletEntity>(error);

    if( error != OK ) 
		IEntityFactory::Instance().RemoveEntity( bullet );

    bullet->SetParentScene( GetParentScene() );
	bullet->SetEntityCreator( this );
    bullet->Init();
	bullet->SetDirection( 0, m_yDirection );
    bullet->SetPosition( x, y, 0 );
    bullet->SetSpeed( m_bulletSpeed );
    GetParentScene()->AddEntity( bullet );
    
}*/