#ifndef _LABEL_H_
#define _LABEL_H_

#include "Control.h"
#include "../include/font.h"

class Image;

class Label : public Control
{
public:
	Label();

	bool init( const std::string name, const Vector2& position, const std::string& text , const std::string&  font);

	virtual void update();
	virtual void render();
	virtual void onInputEvent( const Message& message );
	virtual void destroy();

	void setText( const std::string& text ){ m_text = text; }

protected:
    Font *                                    m_font;
	std::string								m_text;
	bool									m_pushed;
};


#endif // _LABEL_H_