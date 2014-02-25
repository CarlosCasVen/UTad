#ifndef __SCENE_MANAGER__
#define __SCENE_MANAGER__

#include <stdio.h>

class BaseScene;


class SceneManager
{
public:
	static SceneManager& Instance();
	void Update( double elapsedTime );

private:
	SceneManager();
	~SceneManager();

	static SceneManager* m_sceneManager;

};

#endif