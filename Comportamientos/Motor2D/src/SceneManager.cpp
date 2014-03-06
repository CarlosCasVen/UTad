#include "../logic/Logic.h"


SceneManager* SceneManager::m_sceneManager = NULL;


SceneManager& SceneManager::Instance()
{
	if( !m_sceneManager )
	{
		m_sceneManager = NEW( SceneManager );
	}

	return *m_sceneManager;
}


virtual void SceneManager::Update( double elapsedTime )
{
	m_activeScene->Update( elapsedTime );
}


void SceneManager::SetActiveScene( BaseScene* scene )
{
	m_activeScene = scene;
}


SceneManager::SceneManager()
{
	m_activeScene = NULL;
}


SceneManager::~SceneManager()
{
}

