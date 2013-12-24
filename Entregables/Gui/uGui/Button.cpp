#include "Button.h"
#include "GUIManager.h"
#include <iostream>
#include <sstream>
#include "../include/Renderer.h"
#include "../include/Image.h"
#include "../include/resourcemanager.h"

//------------------------------------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------------------------------------
Button::Button()
{
	m_pushed = false;
	m_normalImage = NULL;
	m_pushImage = NULL;
}

//------------------------------------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------------------------------------
bool Button::init( const String name, const Vector2& position, const String& normalImage, const String& pushImage, const String& disableImage )
{
	m_name				= name.ToCString();
	m_position			= position;
	m_normalImage		= ResourceManager::Instance().LoadImage( normalImage.ToCString() );
	m_pushImage			= ResourceManager::Instance().LoadImage( pushImage.ToCString() );
	m_size					= Vector2( (float)m_normalImage->GetWidth(), (float)m_normalImage->GetHeight() );

	if( disableImage != "" )
	{
		m_disableImage = ResourceManager::Instance().LoadImage( disableImage.ToCString() );
	}
	return m_normalImage && m_pushImage;
}

//------------------------------------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------------------------------------
void Button::update()
{
	if( !m_pointerIsOver )
		m_pushed = false;
}

//------------------------------------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------------------------------------
void Button::render()
{
	if( m_visible )
	{
		Vector2 pos = getAbsolutePosition();

		Renderer::Instance().SetBlendMode( Renderer::ALPHA );
		if( !isEnabled() && m_disableImage )
		{
			Renderer::Instance().DrawImage( m_pushImage, pos.x, pos.y );
		}
		else
		{
			if( m_pushed )
			{
				Renderer::Instance().DrawImage( m_pushImage, pos.x, pos.y );
			}
			else if( !m_pushed )
			{
				Renderer::Instance().DrawImage( m_normalImage, pos.x, pos.y );
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------------------------------------
void Button::onInputEvent( const Message& message )
{
	if (m_enabled)
	{
		switch (message.type)
		{
		case mtPointerButtonDown:
			m_pushed = true;
			break;

		case mtPointerButtonUp:
			if (m_pushed) {
				NOTIFY_LISTENERS(onClick(this));
			}
			m_pushed = false;
			break;
		}
	}
}

//------------------------------------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------------------------------------
void Button::destroy()
{
}

//------------------------------------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------------------------------------
void Button::setLabel ( Label* buttonLabel )
{
	if( buttonLabel )
	{
		float posX = m_size.x - buttonLabel->getSize().x;
		posX /= 2;
		float posY = m_size.y - buttonLabel->getSize().y;
		posY /= 2;
		
		m_label = buttonLabel;
		m_label->setPosition( Vector2( posX, posY ) );
		m_label->setParent( this );
	}
}



bool Button::isPushed()
{
	return m_pushed;
}
