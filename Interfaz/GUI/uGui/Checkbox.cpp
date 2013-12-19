#include "Checkbox.h"
#include "../include/image.h"
#include "../include/renderer.h"



bool Checkbox::init( const std::string& name, const Vector2& position, const std::string& imageEnabled,  const std::string& imageDisabled, bool pushed)
{
	m_name = name;
	m_position = position;
	m_imageDisabled = new Image( imageDisabled.c_str() );
	m_imageEnabled = new Image( imageEnabled.c_str() );
	m_pushed = pushed;
	m_size = Vector2( (float)m_imageEnabled->GetWidth(), (float)m_imageEnabled->GetHeight() );

	return m_imageEnabled && m_imageDisabled;
}



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
	const MessagePointerButtonDown* messagePointer = static_cast<const MessagePointerButtonDown*>(&message);
	if( isPointInside(  Vector2(messagePointer->x, messagePointer->y ) ) )
	{
		switch( message.type )
		{
		case mtPointerButtonDown:
			m_pushed = !m_pushed;
			break;
		}
	}
}


void Checkbox::destroy()
{
	if( m_imageDisabled )
	{
		delete m_imageDisabled;
		m_imageDisabled = NULL;
	}

	if( m_imageEnabled )
	{
		delete m_imageEnabled;
		m_imageEnabled = NULL;
	}
}


void Checkbox::setLabel( Label* label, bool labelInRight, int numberSpaces )
{
	if( labelInRight && label )
	{
		m_label = label;
		m_label->setParent( this );
		m_label->setPosition( Vector2( m_size.x + numberSpaces , m_size.y / 2 - label->getSize().y / 2) );		
	}
	else
	{
		m_label = label;
		m_label->setParent( this );
		m_label->setPosition( Vector2(  - ( label->getSize().x + numberSpaces ), label->getSize().y / 2) );
	}
}