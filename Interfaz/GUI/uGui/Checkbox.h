#ifndef _CHECKBOX_H_
#define _CHECKBOX_H_

#include "Control.h"
#include "Label.h"
#include "../include/image.h"

class Checkbox : public Control
{
public:
	Checkbox() : Control() { m_label = NULL; m_imageDisabled = NULL; m_imageEnabled = NULL; m_pushed = false; }
	
	virtual void update();
	virtual void render();
	virtual void onInputEvent( const Message& message );
	virtual void destroy();

	bool init( const std::string& name, const Vector2& position,  const std::string& imageEnabled,  const std::string& imageDisabled, bool pushed);
	void setLabel( Label* label, bool labelInRight = true, int numberSpaces = 20 );

private:
	Image* m_imageEnabled;
	Image* m_imageDisabled;
	Label* m_label;
	bool m_pushed;
};

#endif