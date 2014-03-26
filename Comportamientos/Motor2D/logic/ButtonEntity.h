#ifndef __BUTTON_ENTITY__
#define __BUTTON_ENTITY__

#include "BaseEntity.h"
#include "../json/rapidjson/document.h"



class ButtonEntity : public BaseEntity
{
public:
    ButtonEntity (  const rapidjson::Value* params );
    ~ButtonEntity();

    virtual TError Init();
    virtual void   End ();

    virtual void Update( double elapsedTime );

private:
    unsigned int m_sceneIndex;
};


#endif