#ifndef _KEYLISTENERCONTROL_H_
#define _KEYLISTENERCONTROL_H_

#include "../include/string.h"
#include "Control.h"
#include "../include/scene.h"

class KeyListenerControl : public Control
{
public:
	KeyListenerControl();
	virtual ~KeyListenerControl(){};

	// A implementar en clases derivadas
	virtual void update();
	virtual void render();
	virtual void onInputEvent( const Message& message );
	virtual void destroy();

	bool init( const String& name );

	void setScene( Scene* scene );
	void setMainCharacter( Sprite* alien, Emitter* emitter );

private:
	Scene* m_scene;
	Sprite* m_alien;
	Emitter* m_emitter;
};


#endif