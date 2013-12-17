#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "Control.h"
#include "Label.h"

class Image;

class Button : public Control
{
public:
	Button();

	bool init( const std::string name, const Vector2& position, const std::string& normalImage, const std::string& pushImage, const std::string& disabledImage = " " );

	virtual void update();
	virtual void render();
	virtual void onInputEvent( const Message& message );
	virtual void destroy();

	void setLabel( Label* label );

protected:
	Image*								m_normalImage;
	Image*								m_pushImage;
	Image*								m_disabledImage;
	Label*								m_label;
	bool									m_pushed;
};


#endif // _BUTTON_H_