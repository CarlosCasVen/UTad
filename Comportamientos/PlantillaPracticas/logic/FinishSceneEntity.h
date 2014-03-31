#ifndef __FINISH_SCENE_ENTITY__
#define __FINISH_SCENE_ENTITY__

#include "IListener.h"
#include "BaseEntity.h"
#include "../json/rapidjson/document.h"

class ISample;
enum TError;

class FinishSceneEntity : public BaseEntity, IListener
{
public:
    FinishSceneEntity (  const rapidjson::Value* params );
    ~FinishSceneEntity();

    virtual TError Init();
    virtual void   End ();

    virtual void Update( double elapsedTime );

    virtual void              ReceiveEvent ( Event& newEvent );
    virtual unsigned long int GetListenerId()            const;

private:
    unsigned int m_nextScene;
};


#endif