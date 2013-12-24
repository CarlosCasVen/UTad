#ifndef _WINDOW_H_
#define _WINDOW_H_

#include "Control.h"
#include "Label.h"
#include "../include/Image.h"


class Window : public Control
{
public:
	Window();

	bool Window::init( const std::string name );
	bool init( const std::string name, const Vector2& position, const std::string& backgroungImage );

	void update();
	void render();
	void onInputEvent( const Message& message );
	void destroy();

	void setLabel( Label* label );
protected:

	// SDL
	Image*								m_canvas;
	Vector2								m_lastPos;
	bool								m_avaiableToDrag;
	Label*								m_label;
};


#endif // _WINDOW_H_