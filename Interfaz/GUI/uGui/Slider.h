#ifndef _SLIDER_H_
#define _SLIDER_H_

#include "Control.h"
#include "Button.h"
#include "../include/image.h"
#include "Vector2.h"

class Slider : public Control, public IEventListener
{
public:
	Slider() : Control(){ m_bar = NULL; m_pointer = m_up = m_down = NULL; m_posPointer = Vector2( 0, 0); }

	virtual void update();
	virtual void render();
	virtual void onInputEvent( const Message& message );
	virtual void destroy();


	bool init( const std::string name, const Vector2& position, const std::string& barImage, const std::string& pointerImage, const std::string& addImage, const std::string& addImagePushed, const std::string& substractImage, const std::string& substractImagePushed, const std::string& font );
	void setButtonRight( Button* button );
	void setButtonLeft( Button* button );
	void setLabel( Label* label, bool right = true, unsigned int numberSpaces = 20 );
	void setLabelPercent( bool up = true, unsigned int numberSpaces = 20 );

	void onClick( Control* sender );

private:
	Image* m_bar;
	Button* m_pointer;
	Button* m_up;
	Button* m_down;
	Vector2 m_posPointer;
	Label* m_label;
	Label* m_labelPercent;
	
};



#endif;