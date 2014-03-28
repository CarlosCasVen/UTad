#include "../logic/logic.h"

StaticObstacleEntity::StaticObstacleEntity (  const rapidjson::Value* params ) : BaseEntity( params )
{
}
    
StaticObstacleEntity::~StaticObstacleEntity()
{
}

TError StaticObstacleEntity::Init()
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

    if( GetParams().HasMember( "Image"     ) )    sprite->SetImage( String( GetParams()["Image"].GetString() ) );
    if( GetParams().HasMember( "X"         ) && 
        GetParams().HasMember( "Y"         ) )    sprite->SetPosition( GetParams()["X"].GetDouble(), GetParams()["Y"].GetDouble() );

    collision->SetSprite( sprite->GetSprite() );

    if( GetParams().HasMember( "Collision" ) )    collision->SetCollisionMode( (Sprite::CollisionMode) GetParams()["Collision"].GetInt() );

    AddComponent( sprite    );
    AddComponent( collision );

    error = BaseEntity::Init();

    return error;
}

void StaticObstacleEntity::End()
{
    BaseEntity::End();
}

void StaticObstacleEntity::Update( double elapsedTime )
{
    BaseEntity::Update( elapsedTime );
}