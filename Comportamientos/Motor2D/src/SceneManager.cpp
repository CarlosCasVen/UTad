#include "../logic/logic.h"
#include "../include/u-gine.h"


#define PATH_SCENE "data/config.txt"

ISceneManager* m_sceneManager = NULL;

//-------------------------------------
//
//-------------------------------------
ISceneManager& ISceneManager::Instance()
{
    if( !m_sceneManager ) m_sceneManager = NEW( SceneManager, () );

    return *m_sceneManager;
}


//-------------------------------------
//
//-------------------------------------
TError SceneManager::Init()
{
    TError error = OK;

    String content = String::Read( PATH_SCENE );

    rapidjson::Document document;
    document.Parse<0>( (char*) content.ToCString() );

    if( document.HasParseError() ) return ERROR;
    if( !document.HasMember( "Scenes" ) ) error = ERROR;

    m_scenes = &document["Scenes"];
    m_indexCurrentScene = 0;

    CreateScene( m_scenes[m_indexCurrentScene] );

    return error;
}

//-------------------------------------
//
//-------------------------------------
void SceneManager::End()
{
	if( m_currentScene ) m_currentScene->End();
    DEL( m_currentScene );
    DEL( m_sceneManager );
}

//-------------------------------------
//
//-------------------------------------
void SceneManager::Update( double elapsedTime )
{
	if( m_previousScene ) DestroyScene();
    if( m_currentScene  ) m_currentScene->Update( elapsedTime );
}

//-------------------------------------
//
//-------------------------------------
void SceneManager::Render()
{
    if( m_currentScene ) m_currentScene->Render();
}

//-------------------------------------
//
//-------------------------------------
void SceneManager::NextScene()
{
	m_previousScene = m_currentScene;
    CreateScene( m_scenes[++m_indexCurrentScene] );
}

//-------------------------------------
//
//-------------------------------------
void SceneManager::PreviousScene()
{
	m_previousScene = m_currentScene;
    CreateScene( m_scenes[++m_indexCurrentScene] );
}

//-------------------------------------
//
//-------------------------------------
void SceneManager::SetScene( unsigned int index )
{
	m_previousScene = m_currentScene;
	m_indexCurrentScene = index;
    CreateScene( m_indexCurrentScene ); 
}

//-------------------------------------
//
//-------------------------------------
void SceneManager::CreateScene( const rapidjson::Value& infoScene )
{
    if( strcmp( infoScene["Scene"].GetString(), "BaseScene" ) == 0 )
    {
        const String info( infoScene["Param"].GetString() );
        m_currentScene = NEW( BaseScene, ( &info ) );
        m_currentScene->Init();
    }
 
}

//-------------------------------------
//
//-------------------------------------
SceneManager::SceneManager ()
{
    m_id			= IIdFactory::Instance().GetId();
	m_previousScene = NULL;
}

//-------------------------------------
//
//-------------------------------------
SceneManager::~SceneManager()
{
}

//-------------------------------------
//
//-------------------------------------
void SceneManager::ReceiveEvent ( Event& newEvent )
{
	switch( newEvent.GetType() )
	{
	case ChangeScene: 
		EventChangeScene castEvent = reinterpret_cast<EventChangeScene&>( newEvent );
		SetScene( castEvent.GetIndexNextScene() );
		break;
	}
}

//-------------------------------------
//
//-------------------------------------
unsigned long int SceneManager::GetListenerId() const
{
    return m_id;
}

//-------------------------------------
//
//-------------------------------------
void SceneManager::DestroyScene()
{
	if( m_previousScene )
	{
		m_previousScene->End();
		DEL( m_previousScene );
	}
}