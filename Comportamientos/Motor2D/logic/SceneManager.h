#ifndef __SCENE_MANAGER__
#define __SCENE_MANAGER__

#include "ISceneManager.h"

class SceneManager : public ISceneManager
{
public:
    virtual TError Init();
    virtual void   End ();

    virtual void Update( double elapsedTime );
    virtual void Render();

private:
    SceneManager ();
    ~SceneManager();

    IScene* m_currentScene;

    friend class ISceneManager;
};

#endif