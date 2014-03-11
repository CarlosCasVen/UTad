#include "../logic/Logic.h"
#define PATH "path"

SceneManager* m_sceneManager = NULL;

//-------------------------------------
//
//-------------------------------------
ISceneManager& ISceneManager::Instance()
{
    if( !m_sceneManager ) m_sceneManager = NEW( SceneManager, () );

	String content = String::Read( PATH );
    rapidjson::Document document;
    document.Parse<0>( content.ToCString() );

	for( unsigned int i = 0; i < document["Scenes"].Size(); i++ )
	{
		i
	}

    return *m_sceneManager;
}

//-------------------------------------
//
//-------------------------------------
TError SceneManager::Init()  
{
    TError error = OK;

    return error;
}

//-------------------------------------
//
//-------------------------------------
void SceneManager::End()
{
    DEL( m_sceneManager );
}

//-------------------------------------
//
//-------------------------------------
void SceneManager::Update( double elapsedTime )
{
    if( m_currentScene ) m_currentScene->Update( elapsedTime );
}

//-------------------------------------
//
//-------------------------------------
void SceneManager::Render( double elapsedTime )
{
    if( m_currentScene ) m_currentScene->Render( elapsedTime );
}

//-------------------------------------
//
//-------------------------------------
void SceneManager::NextScene()
{
}

//-------------------------------------
//
//-------------------------------------
void SceneManager::PreviousScene()
{
}

//-------------------------------------
//
//-------------------------------------
void SceneManager::SetScene( IScene& scene )
{
    m_currentScene = &scene;
}