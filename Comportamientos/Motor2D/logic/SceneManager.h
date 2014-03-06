#ifndef __SCENE_MANAGER__
#define __SCENE_MANAGER__

#include <stdio.h>

class BaseScene;


class SceneManager
{
public:
	static SceneManager& Instance();
	virtual void Update( double elapsedTime );
	void SetActiveScene( BaseScene* scene );
	bool CreateScene( const String& filename );

private:
	SceneManager();
	~SceneManager();

	static SceneManager* m_sceneManager;
	BaseScene* m_activeScene;

};

#endif