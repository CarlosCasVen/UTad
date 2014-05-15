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

    TeamComponent*   team = IComponentFactory::Instance().GetComponent<TeamComponent>  ( error );
    
    if( error != OK )
    {
        IComponentFactory::Instance().RemoveComponent( team );
        return error;
    }

    LabelComponent* label   = IComponentFactory::Instance().GetComponent<LabelComponent>( error );

    if( error != OK )
    {
        IComponentFactory::Instance().RemoveComponent( label );
        return error;
    }

    int hFrames = 1;
    int vFrames = 1;

    if( GetParams().HasMember( "HFrames"     ) )  hFrames = GetParams()["HFrames"].GetInt();
    if( GetParams().HasMember( "VFrames"     ) )  vFrames = GetParams()["VFrames"].GetInt();

    if( GetParams().HasMember( "Image"     ) )    sprite->SetImage   ( String( GetParams()["Image"].GetString() ), hFrames, vFrames );
    if( GetParams().HasMember( "X"         ) && 
        GetParams().HasMember( "Y"         ) )    sprite->SetPosition( GetParams()["X"].GetDouble(), GetParams()["Y"].GetDouble() );
    if( GetParams().HasMember( "ScaleX"    ) && 
        GetParams().HasMember( "ScaleY"    ) )    sprite->SetScale( GetParams()["ScaleX"].GetDouble(), GetParams()["ScaleY"].GetDouble() );
    if( GetParams().HasMember( "Speed"     ) )    movement->SetSpeed ( GetParams()["Speed"].GetDouble() );
    if( GetParams().HasMember( "Right"     ) )    m_right    = (eInputCode)GetParams()["Right"].GetInt();
    if( GetParams().HasMember( "Left"      ) )    m_left  = (eInputCode)GetParams()["Left"].GetInt();
    if( GetParams().HasMember( "Shoot"     ) )    m_shoot = (eInputCode)GetParams()["Shoot"].GetInt();
    if( GetParams().HasMember( "Shoot"     ) )    m_shoot = (eInputCode)GetParams()["Shoot"].GetInt();
    if( GetParams().HasMember( "Direction" ) )    m_paramsBullet.m_yDirection = GetParams()["Direction"].GetInt();
	if( GetParams().HasMember( "BSpeed"    ) )    m_paramsBullet.m_bulletSpeed = GetParams()["BSpeed"].GetDouble();

    animator->SetSprite ( sprite->GetSprite() );
    collision->SetSprite( sprite->GetSprite() );

    if( GetParams().HasMember( "FirstFps"  ) &&
        GetParams().HasMember( "LastFps"   ) )    animator->SetFrameRange( GetParams()["FirstFps"].GetInt(), GetParams()["LastFps"].GetInt() );
    if( GetParams().HasMember( "FirstFps"  ) )    animator->SetFPS( GetParams()["FPS"].GetInt() );
    if( GetParams().HasMember( "Collision" ) )    collision->SetCollisionMode( (Sprite::CollisionMode) GetParams()["Collision"].GetInt() );
    if( GetParams().HasMember( "Live"      ) )    live->SetLive( GetParams()["Live"].GetInt() );
    if( GetParams().HasMember( "Team"      ) )    team->SetTeam( m_paramsBullet.m_teamId = GetParams()["Team"].GetInt() );
 

    if( GetParams().HasMember( "Label"      ) )    m_label = String( GetParams()["Label"].GetString() ); 
    if( GetParams().HasMember( "Font"       ) )    label->SetFont ( &String( GetParams()["Font"].GetString() ) ); 
    if( GetParams().HasMember( "XLabel"     ) && 
        GetParams().HasMember( "YLabel"     ) )    label->SetPosition( GetParams()["XLabel"].GetDouble(), GetParams()["YLabel"].GetDouble() );
    if( GetParams().HasMember( "r"          ) &&
        GetParams().HasMember( "g"          ) &&
        GetParams().HasMember( "b"          ) )
    {
        sprite->SetColor( GetParams()["r"].GetInt(), GetParams()["g"].GetInt(), GetParams()["b"].GetInt() );
        label->SetColor ( GetParams()["r"].GetInt(), GetParams()["g"].GetInt(), GetParams()["b"].GetInt() );
    }

    AddComponent( input     );
    AddComponent( sprite    );
    AddComponent( movement  );
    AddComponent( collision );
    AddComponent( animator  );
    AddComponent( live      );
    AddComponent( team      );
    AddComponent( label     );

    error = BaseEntity::Init();
    label->SetLabel( m_label + String::FromInt( live->GetLive() ) );

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

    InputComponent*  input    = GetComponentByType<InputComponent> ( IComponent::EInput  );  
    SpriteComponent* sprite   = GetComponentByType<SpriteComponent>( IComponent::ESprite );
    MoveComponent*   movement = GetComponentByType<MoveComponent>  ( IComponent::EMove   );
    LiveComponent*   live     = GetComponentByType<LiveComponent>  ( IComponent::ELive   );
    LabelComponent*  label    = GetComponentByType<LabelComponent> ( IComponent::ELabel  );
    BoundComponent*  bound    = GetComponentByType<BoundComponent> ( IComponent::EBound  );

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
	if( input->IsButtonDown( m_shoot ) ) 
    {
        m_paramsBullet.m_x = x;
        m_paramsBullet.m_y = y;
        CreateBullet( m_paramsBullet );
    }
	sprite->SetPosition( x, y ); 

    if( live->GetLive() == 0 )
        IEventManager::Instance().AddEvent( NEW( EventChangeScene, ( 0 ) ) );

    label->SetLabel( m_label + String::FromInt( live->GetLive() ) );

    double xMin = 0;
    double xMax = IScreenManager::Instance().TransformToScreenPointX( IScreenManager::Instance().GetWidth() ) -  IScreenManager::Instance().TransformToScreenPointX( sprite->GetImage()->GetWidth() );

    if( sprite->GetX() < 0    ) sprite->SetPosition( 0   , sprite->GetY() );
    if( sprite->GetX() > xMax ) sprite->SetPosition( xMax, sprite->GetY() );
}

//-------------------------------------
//
//-------------------------------------
void PlayerEntity::CreateBullet( BulletParams params )
{
    TError error = OK;
    
    BulletEntity* bullet = IEntityFactory::Instance().GetTemporalEntity<BulletEntity>(error);

    if( error != OK ) 
		IEntityFactory::Instance().RemoveEntity( bullet );
    
    bullet->SetParentScene  ( GetParentScene() );
    bullet->SetEntityCreator( this );
    bullet->Init();
    bullet->SetDirection    ( 0, params.m_yDirection );
    bullet->SetPosition     ( params.m_x, params.m_y );
    bullet->SetSpeed        ( params.m_bulletSpeed );
    bullet->SetTeam         ( params.m_teamId );
    
}