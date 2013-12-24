#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "../include/string.h"
#include "Control.h"
#include "Label.h"

class Image;

class Button : public Control
{
public:
	Button();

	bool init( const String name, const Vector2& position, const String& normalImage, const String& pushImage, const String& disableImage = "" );

	virtual void update();
	virtual void render();
	virtual void onInputEvent( const Message& message );
	virtual void destroy();

	void setLabel ( Label* buttonLabel );
	bool isPushed();
protected:
	Image*								m_normalImage;
	Image*								m_pushImage;
	Image*								m_disableImage;
	bool									m_pushed;
	Label*								m_label;
};


#endif // _BUTTON_H_