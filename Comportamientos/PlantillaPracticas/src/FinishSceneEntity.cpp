#include "../logic/logic.h"
#undef ERROR

FinishSceneEntity::FinishSceneEntity (  const rapidjson::Value* params ) : BaseEntity( params )
{
    m_nextScene = 0xFFFFFFFF;
}

FinishSceneEntity::~FinishSceneEntity()
{
}

TError FinishSceneEntity::Init()
{
    if( GetParams().HasMember( "NextScene" ) ) 
    {
        m_nextScene = GetParams()["NextScene"].GetInt();
    }
    else
    {
        return ERROR;
    }

    IEventManager::Instance().RegistreToEvent( *this, TEvent::ChangeScene );

    return OK;
}

void FinishSceneEntity::End ()
{
    IEventManager::Instance().UnregistredToEvent( TEvent::ChangeScene, *this );
    BaseEntity::End();
}

void FinishSceneEntity::Update( double elapsedTime )
{
    
}

void FinishSceneEntity::ReceiveEvent ( Event& newEvent )
{
    switch( newEvent.GetType() )
    {
    case TEvent::ChangeScene: SceneManager::Instance().SetScene( m_nextScene ); break;
    default: break;
    }
}

unsigned long int FinishSceneEntity::GetListenerId() const
{
    return GetId();
}