#ifndef __LABEL_COMPONENT__
#define __LABEL_COMPONENT__

#include "BaseComponent.h"
#include "../json/rapidjson/document.h"

class String;
enum  TEvent;

class LabelComponent : public BaseComponent
{
public:
    LabelComponent ();
	~LabelComponent();

	virtual TError Init();
	virtual void   End ();

	virtual void Update( double elapsedTime );

    virtual void SetLabel ( const String* label ); 
    virtual void SetSprite( Sprite* sprite      );

private:
    const String* m_label;
    Sprite*       m_sprite;
    
};

#endif