#ifndef __SCENE_MANAGER__
#define __SCENE_MANAGER__

#include "ISceneManager.h"
#include "../json/rapidjson/document.h"


class SceneManager : public ISceneManager
{
public:
    virtual TError Init();
    virtual void   End ();

    virtual void Update( double elapsedTime );
    virtual void Render();

    virtual void NextScene    ();
    virtual void PreviousScene();
    virtual void SetScene     ( unsigned int index );

private:
    SceneManager ();
    ~SceneManager();

    void CreateScene( const rapidjson::Value& infoScene );
	void DestroyScene();

    IScene*                   m_currentScene;
	IScene*                   m_previousScene;
    unsigned int              m_indexCurrentScene;
    const rapidjson::Value*   m_scenes;
    unsigned long int         m_id;

    friend class ISceneManager;
};

#endif