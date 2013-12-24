#ifndef _SLIDER_H_
#define _SLIDER_H_

#include "../include/image.h"
#include "../include/string.h"
#include "Control.h"
#include "Label.h"
#include "Button.h"
#include "IEventListener.h"

class Slider : public Control, IEventListener
{
public:
	Slider();
	virtual ~Slider(){};

	// A implementar en clases derivadas
	virtual void update();
	virtual void render();
	virtual void onInputEvent( const Message& message );
	virtual void destroy();

	bool init( const String& name, const Vector2& position, const String barImage, const String buttonLeftNormalImage, const String buttonLeftPushedImage,
		const String buttonRightNormalImage, const String buttonRightPushedImage, const String pointerImage );

	virtual void onClick( Control* sender );

	void setLabel( Label* label );
	void setPercentLabel( Vector2 position, const String& font );
private:
	Button* m_leftButton;
	Button* m_rightButton;
	Button* m_pointerButton;
	Image* m_barImage;
	Vector2 m_pointerPosition;
	Label* m_percent;
	Label* m_label;

};

#endif