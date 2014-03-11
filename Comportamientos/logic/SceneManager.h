#ifndef __SCENE_MANAGER__
#define __SCENE_MANAGER__

#include "ISceneManager.h"


class IBaseScene;


class SceneManager : public ISceneManager
{
public:
	virtual TError  Init();
	virtual void    End ();

    virtual void Update( double elapsedTime );
    virtual void Render( double elapsedTime );

    virtual void NextScene      ();
    virtual void PreviousScene  ();
    virtual void SetScene       ( IScene& scene );

private:
    IScene* m_currentScene;

};


#endif