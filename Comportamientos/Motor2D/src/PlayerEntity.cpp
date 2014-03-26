#include "../logic/Logic.h"
#include "../include/u-gine.h"
#include <time.h>

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
    int x = 0;
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


    if( GetParams().HasMember( "Image" ) )    sprite->SetImage   ( String( GetParams()["Image"].GetString() ) );
    if( GetParams().HasMember( "X"     ) && 
        GetParams().HasMember( "Y"     ) )    sprite->SetPosition( GetParams()["X"].GetDouble(), GetParams()["Y"].GetDouble() );
    if( GetParams().HasMember( "Speed" ) )    movement->SetSpeed ( GetParams()["Speed"].GetDouble() );
    if( GetParams().HasMember( "Up"    ) )    m_up    = (eInputCode)GetParams()["Up"].GetInt();
    if( GetParams().HasMember( "Down"  ) )    m_down  = (eInputCode)GetParams()["Down"].GetInt();
    if( GetParams().HasMember( "Shoot" ) )    m_shoot = (eInputCode)GetParams()["Shoot"].GetInt();


    
    input->SetParent( this );
    sprite->SetParent( this );
    movement->SetParent( this );
    
    input->Init();
    sprite->Init();
    movement->Init();

    AddComponent( input    );
    AddComponent( sprite   );
    AddComponent( movement );

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

	if( input->IsButtonPressed( m_up    ) ) 
	{
		movement->SetDirection( 0, 1 );
		y += movement->GetYIncrement();
	}
	if( input->IsButtonPressed( m_down  ) ) 
	{
		movement->SetDirection( 0, -1 );
		y += movement->GetYIncrement();
	}
	if( input->IsButtonPressed( m_shoot ) ) 
		CreateBullet( sprite->GetX(), y, movement->GetXIncrement(), movement->GetYIncrement() );

	sprite->SetPosition( sprite->GetX(), y );

}

//-------------------------------------
//
//-------------------------------------
void PlayerEntity::CreateBullet( double x, double y, double xDir, double yDir )
{
    TError error = OK;
    
    BulletEntity* bullet = IEntityFactory::Instance().GetTemporalEntity<BulletEntity>(error);

    if( error != OK ) IEntityFactory::Instance().RemoveEntity( bullet );

    bullet->Init();
    bullet->SetDirection( xDir, yDir );
    bullet->SetPosition( x, y, 0 );
    bullet->SetSpeed( m_bulletSpeed );
    GetParentScene()->AddEntity( bullet );
    
}