#include "../logic/Logic.h"


SceneManager* m_sceneManager = NULL;

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