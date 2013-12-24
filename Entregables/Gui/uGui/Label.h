#ifndef _LABEL_H_
#define _LABEL_H_

#include "../include/string.h"
#include "../include/font.h"
#include "Control.h"

class Label  : public Control
{
public:
	Label();
	bool init( const std::string& name, Vector2& position, const std::string& font, const String& text );

	virtual void update();
	virtual void render();
	virtual void onInputEvent( const Message& message );
	virtual void destroy();

	void setText( const String& text );
private:
	Font* m_font;
	String m_text;

};

#endif