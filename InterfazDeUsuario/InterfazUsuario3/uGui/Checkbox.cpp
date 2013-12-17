#include "Checkbox.h"
#include "../include/image.h"
#include "../include/renderer.h"


void Checkbox::update()
{
	
}


void Checkbox::render()
{
	if( isVisible() )
	{
		Vector2 pos = getAbsolutePosition();

		if( m_pushed )
		{
			Renderer::Instance().DrawImage( m_imageEnabled, pos.x, pos.y );
		}
		else
		{
			Renderer::Instance().DrawImage( m_imageDisabled, pos.x, pos.y );
		}

		if( m_label )
		{
			m_label->render();
		}
	}
}


void Checkbox::onInputEvent( const Message& message )
{
	switch( message.type )
	{
	case mtPointerButtonDown:
		m_pushed = !m_pushed;
		break;

	}
}


void Checkbox::destroy()
{
	delete m_imageDisabled;
	delete m_imageEnabled;
}


bool Checkbox::init( const std::string& name, const Vector2& position, const std::string& imageEnabled,  const std::string& imageDisabled, bool pushed)
{
	m_name = name;
	m_position = position;
	m_imageDisabled = new Image( imageDisabled.c_str() );
	m_imageEnabled = new Image( imageEnabled.c_str() );
	m_pushed = pushed;
	m_size = Vector2( (float)m_imageEnabled->GetWidth(), (float)m_imageEnabled->GetHeight() );

	return true;
}

/*
void Checkbox::setLabel( Label* label, bool labelInRight = true, int numberSpaces = 20 )
{
	m_label = label;
}*/