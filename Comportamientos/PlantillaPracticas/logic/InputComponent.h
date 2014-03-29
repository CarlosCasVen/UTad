#ifndef __INPUT_COMPONENT__
#define __INPUT_COMPONENT__

#include "BaseComponent.h"
#include "../json/rapidjson/document.h"

class Event;
class String;
enum  TEvent;
enum eInputCode;

class InputComponent : public BaseComponent
{
public:
    InputComponent ();
	~InputComponent();

	virtual TError Init();
	virtual void   End ();

	virtual void Update( double elapsedTime );

    virtual bool  IsButtonPressed     ( eInputCode key ) const;
    virtual bool  IsButtonDown        ( eInputCode key ) const;
    virtual bool  IsButtonUp          ( eInputCode key ) const;
    virtual bool  IsMouseButtonPressed( eInputCode key ) const;
    virtual float GetMouseX           ()                 const;  
    virtual float GetMouseY           ()                 const;  

private:
    float m_mouseX;
    float m_mouseY;
};

#endif