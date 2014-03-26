#include "../logic/logic.h"
#define PATH_BULLET ""


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

    SpriteComponent* component = IComponentFactory::Instance().GetComponent<SpriteComponent>( error );

    if( error != OK )
    {
        IComponentFactory::Instance().RemoveComponent( component );
        return error;
    }

    MoveComponent* movement = IComponentFactory::Instance().GetComponent<MoveComponent>( error );

    if( error != OK )
    {
        IComponentFactory::Instance().RemoveComponent( component );
        return error;
    }  

    if( GetParams().HasMember( "Image" ) )                                    component->SetImage   ( String( GetParams()["Image"].GetString() ) );
    if( GetParams().HasMember( "X"     ) && GetParams().HasMember( "Y"    ) ) component->SetPosition( GetParams()["X"].GetDouble(), GetParams()["Y"].GetDouble() );
    if( GetParams().HasMember( "DirX"  ) && GetParams().HasMember( "DirY" ) ) movement->SetDirection( GetParams()["DirX"].GetDouble(), GetParams()["DirY"].GetDouble() );   
    if( GetParams().HasMember( "Speed" ) )                                    movement->SetSpeed    ( GetParams()["Speed"].GetDouble() );

    component->Init();
    movement->Init();
    
    AddComponent( component );
    AddComponent( movement );

    return error;
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

    MoveComponent*   movement = NULL;
    SpriteComponent* sprite   = NULL;

    movement = GetComponentByType<MoveComponent>  ( IComponent::EMove );
    sprite   = GetComponentByType<SpriteComponent>( IComponent::EMove );


  // #define TYPE ESpriteComponent \
  // sprite = GetComponent<SpriteComponent>( TYPE );
  // #undef TYPE

    if( sprite && movement )
    {
        sprite->SetPosition( sprite->GetX() + movement->GetXIncrement(), sprite->GetY() + movement->GetYIncrement() );
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