#include "../logic/logic.h"
#include "../include/u-gine.h"
#include "../json/rapidjson/document.h"
#undef ERROR
#define PATH_BULLET "data/bullet.txt"

String ParseBullet( TError& error, rapidjson::Document& document );

//-------------------------------------
//
//-------------------------------------
BulletEntity::BulletEntity(  const rapidjson::Value* params ) : BaseEntity( params )
{
}

//-------------------------------------
//
//-------------------------------------
BulletEntity::~BulletEntity()
{
}

//-------------------------------------
//
//-------------------------------------
TError BulletEntity::Init()
{
    TError error = OK;

    SpriteComponent* sprite = IComponentFactory::Instance().GetComponent<SpriteComponent>( error );

    if( error != OK )
    {
        IComponentFactory::Instance().RemoveComponent( sprite );
        return error;
    }

    MoveComponent* movement = IComponentFactory::Instance().GetComponent<MoveComponent>( error );

    if( error != OK )
    {
        IComponentFactory::Instance().RemoveComponent( movement );
        return error;
    }  

    CollisionComponent*   collision = IComponentFactory::Instance().GetComponent<CollisionComponent>  ( error );
    
    if( error != OK )
    {
        IComponentFactory::Instance().RemoveComponent( collision );
        return error;
    }

    String content = String::Read( PATH_BULLET );
    rapidjson::Document document;
    document.Parse<0>( (char*) content.ToCString() );

    String p = ParseBullet( error, document );
    sprite->SetImage( p );

    collision->SetSprite( sprite->GetSprite() );

    if( document.HasMember( "Collision" ) )   collision->SetCollisionMode( (Sprite::CollisionMode)document["Collision"].GetInt() );    
    
    AddComponent( sprite );
    AddComponent( movement );
    AddComponent( collision );

    ICollisionManager::Instance().RegisterCollider( (ICollisionListener*)collision );

    BaseEntity::Init();

    return error;
}


String ParseBullet( TError& error, rapidjson::Document& document )
{
    

    if( document.HasParseError() )
    {
        error = ERROR;
        return NULL;
    }
    
    if( document.HasMember( "Image" ) ) 
    {
        return String( document["Image"].GetString() );
    }
    else
    {
        error = ERROR;
        return NULL;
    }
}

//-------------------------------------
//
//-------------------------------------
void BulletEntity::End()
{
    BaseEntity::End();
}

//-------------------------------------
//
//-------------------------------------
void BulletEntity::Update( double elapsedTime )
{
    BaseEntity::Update( elapsedTime );

    MoveComponent*      movement = NULL;
    SpriteComponent*    sprite   = NULL;
    CollisionComponent* collision   = NULL;

    movement  = GetComponentByType<MoveComponent>     ( IComponent::EMove      );
    sprite    = GetComponentByType<SpriteComponent>   ( IComponent::ESprite    );
    collision = GetComponentByType<CollisionComponent>( IComponent::ECollision );

    if( sprite && movement )
    {
        sprite->SetPosition( sprite->GetX() + movement->GetXIncrement(), sprite->GetY() + movement->GetYIncrement() );
    }
    
    if( collision && collision->GetCollisionsCollisioning().Size() > 0 ) 
    {
        GetParentScene()->RemoveEntity( this );
    }
}

//-------------------------------------
//
//-------------------------------------
void BulletEntity::SetDirection( double x, double y )
{
    MoveComponent* movement = NULL;

    movement = GetComponentByType<MoveComponent>( IComponent::EMove );
    
    if( movement ) movement->SetDirection( x, y );
}

//-------------------------------------
//
//-------------------------------------
void BulletEntity::SetSpeed( double speed )
{
    MoveComponent* movement = NULL;

    movement = GetComponentByType<MoveComponent>( IComponent::EMove );
    
    if( movement ) movement->SetSpeed( speed );
}

//-------------------------------------
//
//-------------------------------------
void BulletEntity::SetPosition ( double x, double y, double z )
{
    SpriteComponent* sprite = NULL;

    sprite = GetComponentByType<SpriteComponent>( IComponent::ESprite );
    
    if( sprite ) sprite->SetPosition( x, y, z );
}