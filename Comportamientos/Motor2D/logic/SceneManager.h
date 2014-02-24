#include <stdio.h>
#include "BaseScene.h"


class SceneManager
{
public:
	SceneManager& Instance(){  if( m_sceneManager == NULL ) m_sceneManager = new SceneManager(); return *m_sceneManager; }

private:
	SceneManager(){ m_sceneManager = NULL; }

	SceneManager* m_sceneManager;

};
