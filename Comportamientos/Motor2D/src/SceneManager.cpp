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

    String* prueba = new String( PATH_SCENE );

    m_currentScene = NEW( BaseScene, ( prueba ) ); 

    if( !m_currentScene ) error = ERROR;
    else                  m_currentScene->Init();
    
    delete prueba;

    return error;
}

//-------------------------------------
//
//-------------------------------------
void SceneManager::End()
{
    DEL( m_currentScene );
    DEL( m_sceneManager );
}

//-------------------------------------
//
//-------------------------------------
void SceneManager::Update( double elapsedTime )
{
    m_currentScene->Update( elapsedTime );

}

void SceneManager::Render( double elapsedTime )
{
    m_currentScene->Render( elapsedTime );
}

//-------------------------------------
//
//-------------------------------------
SceneManager::SceneManager ()
{

}

//-------------------------------------
//
//-------------------------------------
SceneManager::~SceneManager()
{
}