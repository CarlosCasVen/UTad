#ifndef _CHECKBOX_H_
#define _CHECKBOX_H_

#include "../include/image.h"
#include "../include/string.h"
#include "Control.h"
#include "Label.h"

class Checkbox: public Control
{
public:
	Checkbox();
	virtual ~Checkbox(){};

	// A implementar en clases derivadas
	virtual void update();
	virtual void render();
	virtual void onInputEvent( const Message& message );
	virtual void destroy();

	bool init( const String& name, const Vector2& position, const String& enableImage, const String& disabledImage );
	void setLabel( Label* checkboxLabel );
	void setPush( bool pushed );
private:
	Image* m_enabledImage;
	Image* m_disabledImage;
	Label* m_label;
	bool m_pushed;
};



#endif