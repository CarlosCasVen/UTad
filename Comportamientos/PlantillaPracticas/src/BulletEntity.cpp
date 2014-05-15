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

    TeamComponent*   team = IComponentFactory::Instance().GetComponent<TeamComponent>  ( error );
    
    if( error != OK )
    {
        IComponentFactory::Instance().RemoveComponent( team );
        return error;
    }

    DamageComponent* damage = IComponentFactory::Instance().GetComponent<DamageComponent>  ( error );
    
    if( error != OK )
    {
        IComponentFactory::Instance().RemoveComponent( damage );
        return error;
    }

    BoundEliminatorComponent* eliminator = IComponentFactory::Instance().GetComponent<BoundEliminatorComponent>  ( error );
    
    if( error != OK )
    {
        IComponentFactory::Instance().RemoveComponent( eliminator );
        return error;
    }

    String content = String::Read( PATH_BULLET );
    rapidjson::Document document;
    document.Parse<0>( (char*) content.ToCString() );

    String p = ParseBullet( error, document );
    sprite->SetImage( p );

    collision->SetSprite( sprite->GetSprite() );

    if( document.HasMember( "ScaleX"    ) && 
        document.HasMember( "ScaleY"    ) )    sprite->SetScale( document["ScaleX"].GetDouble(), document["ScaleY"].GetDouble() );

    if( document.HasMember( "Collision" ) )   collision->SetCollisionMode( (Sprite::CollisionMode)document["Collision"].GetInt() );  
    if( document.HasMember( "Damage"    ) )   damage->SetDamage          ( document["Damage"].GetInt()                           );  
        
    eliminator->SetSprite( sprite->GetSprite() );
    eliminator->SetMinBound( 0, 0 );
    eliminator->SetMaxBound( 
                             ScreenManager::Instance().GetWidth () - sprite->GetImage()->GetWidth () * sprite->GetScaleX(),
                             ScreenManager::Instance().GetHeight() - sprite->GetImage()->GetHeight() * sprite->GetScaleY() 
                            );


    team->SetTeam( 2 );
    AddComponent( sprite );
    AddComponent( movement );
    GetParentScene()->AddEntity( this );
    AddComponent( collision );
    AddComponent( team );
    AddComponent( damage );
    AddComponent( eliminator );

    ICollisionManager::Instance().RegisterCollider( (ICollisionListener*)collision );

    BaseEntity::Init();

    if( document.HasMember( "ShootSound"      ) ) 
    {
        String c = document["ShootSound"].GetString();
        const String* path = &c;
        m_shoot = ISoundFactory::Instance().CreateSample( ISample::ELoaded, path, error );
        m_shoot->Init();
    }
    if( document.HasMember( "ExplosionSound"  ) ) 
    {
        String c = document["ExplosionSound"].GetString();
        const String* path = &c;
        m_explosion =  ISoundFactory::Instance().CreateSample( ISample::ELoaded, path, error );
        m_explosion->Init();
    }

    ISoundManager::Instance().PlaySample( m_shoot );
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
    ISoundFactory::Instance().RemoveSample( m_shoot      );
    ISoundFactory::Instance().RemoveSample( m_explosion );
}

//-------------------------------------
//
//-------------------------------------
void BulletEntity::Update( double elapsedTime )
{
    BaseEntity::Update( elapsedTime );

    MoveComponent*      movement  = GetComponentByType<MoveComponent>     ( IComponent::EMove      );
    SpriteComponent*    sprite    = GetComponentByType<SpriteComponent>   ( IComponent::ESprite    );
    CollisionComponent* collision = GetComponentByType<CollisionComponent>( IComponent::ECollision );
    TeamComponent*      team      = GetComponentByType<TeamComponent>     ( IComponent::ETeam      );

    if( sprite && movement )
    {
        sprite->SetPosition( sprite->GetX() + movement->GetXIncrement(), sprite->GetY() + movement->GetYIncrement() );
    }
    
    Array<CollisionComponent*> arrayCollisions = collision->GetCollisionsCollisioning();

    if( !collision ) return; 
    
    bool destroyed = false;

    for( unsigned int i = 0; i < arrayCollisions.Size() && !destroyed; i++ )
    {
        BaseEntity* entity = dynamic_cast<BaseEntity*>( arrayCollisions[i]->GetParent() );
        TeamComponent* collisionTeam = entity->GetComponentByType<TeamComponent>( IComponent::ETeam );

        if( collisionTeam )
        {
            if( team->GetTeamId() != collisionTeam->GetTeamId() )
            {
                DoDamage( entity );

                GetParentScene()->RemoveSprite( sprite->GetSprite() );
                GetParentScene()->RemoveEntity( this );
                destroyed = true;
                ISoundManager::Instance().PlaySample( m_explosion );
            }
        }
    }
}

//-------------------------------------
//
//-------------------------------------
void BulletEntity::SetDirection( double x, double y )
{
    MoveComponent* movement = GetComponentByType<MoveComponent>( IComponent::EMove );
    
    if( movement ) movement->SetDirection( x, y );
}

//-------------------------------------
//
//-------------------------------------
void BulletEntity::SetSpeed( double speed )
{
    MoveComponent* movement = GetComponentByType<MoveComponent>( IComponent::EMove );
    
    if( movement ) movement->SetSpeed( speed );
}

//-------------------------------------
//
//-------------------------------------
void BulletEntity::SetPosition ( double x, double y, double z )
{
    SpriteComponent* sprite = GetComponentByType<SpriteComponent>( IComponent::ESprite );
    
    if( sprite ) sprite->SetPosition( x, y, z );
}

//-------------------------------------
//
//-------------------------------------
void BulletEntity::SetEntityCreator( const IEntity* entity )
{
    if( entity ) m_creator = entity;
}

//-------------------------------------
//
//-------------------------------------
void BulletEntity::SetTeam( unsigned int team )
{
    TeamComponent* teamComponent = GetComponentByType<TeamComponent>( IComponent::ETeam );

    if( team ) teamComponent->SetTeam( team );
}

//-------------------------------------
//
//-------------------------------------
void BulletEntity::DoDamage( BaseEntity* entityToDamage )
{
    DamageComponent* damage = GetComponentByType<DamageComponent>( IComponent::EDamage );
    LiveComponent*   live   = entityToDamage->GetComponentByType<LiveComponent>( IComponent::ELive );

    if( damage && live )
    {
        live->SubstractLive( damage->GetDamage() );
    }

}