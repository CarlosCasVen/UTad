#include "../logic/logic.h"


//-------------------------------------
//
//-------------------------------------
DynamicObstacleEntity::DynamicObstacleEntity (  const rapidjson::Value* params ) : BaseEntity( params )
{
}
   
//-------------------------------------
//
//-------------------------------------
DynamicObstacleEntity::~DynamicObstacleEntity()
{
}

//-------------------------------------
//
//-------------------------------------
TError DynamicObstacleEntity::Init()
{
    TError error = OK;

    SpriteComponent* sprite = IComponentFactory::Instance().GetComponent<SpriteComponent>( error );

    if( error != OK )
    {
        IComponentFactory::Instance().RemoveComponent( sprite );
        return error;
    }

    CollisionComponent* collision = IComponentFactory::Instance().GetComponent<CollisionComponent>( error );
    
    if( error != OK )
    {
        IComponentFactory::Instance().RemoveComponent( collision );
        return error;
    }

    TeamComponent*   team = IComponentFactory::Instance().GetComponent<TeamComponent>  ( error );
    
    if( error != OK )
    {
        IComponentFactory::Instance().RemoveComponent( team );
        return error;
    }

    WaveMovementComponent*   wave = IComponentFactory::Instance().GetComponent<WaveMovementComponent>  ( error );
    
    if( error != OK )
    {
        IComponentFactory::Instance().RemoveComponent( wave );
        return error;
    }

    if( GetParams().HasMember( "Image"     ) )    sprite->SetImage( String( GetParams()["Image"].GetString() ) );
    if( GetParams().HasMember( "X"         ) && 
        GetParams().HasMember( "Y"         ) )    
    {
        sprite->SetPosition( GetParams()["X"].GetDouble(), GetParams()["Y"].GetDouble() );
        wave->SetInitialPos( GetParams()["X"].GetDouble(), GetParams()["Y"].GetDouble() );
    }
    collision->SetSprite( sprite->GetSprite() );

    if( GetParams().HasMember( "Collision" ) )    collision->SetCollisionMode( (Sprite::CollisionMode) GetParams()["Collision"].GetInt() );
    if( GetParams().HasMember( "DistanceX" ) && 
        GetParams().HasMember( "DistanceY" ) )    wave->SetDistance( GetParams()["DistanceX"].GetDouble(), GetParams()["DistanceY"].GetDouble() );
    if( GetParams().HasMember( "SpeedX"    ) &&    
        GetParams().HasMember( "SpeedY"    ) )    wave->SetSpeed( GetParams()["SpeedX"].GetDouble(), GetParams()["SpeedY"].GetDouble() );

    AddComponent( sprite    );
    AddComponent( collision );
    AddComponent( team      );
    AddComponent( wave      );

    team->SetTeam( 10 );
    error = BaseEntity::Init();

    return error;
}

//-------------------------------------
//
//-------------------------------------
void DynamicObstacleEntity::End()
{
    BaseEntity::End();
}

//-------------------------------------
//
//-------------------------------------
void DynamicObstacleEntity::Update( double elapsedTime )
{
    BaseEntity::Update( elapsedTime );

    WaveMovementComponent* wave      = GetComponentByType<WaveMovementComponent>     ( IComponent::EWaveMovement      );
    SpriteComponent*       sprite    = GetComponentByType<SpriteComponent>           ( IComponent::ESprite            );

    sprite->SetPosition( wave->GetX(), wave->GetY() );
}