#include "Button.h"
#include "GUIManager.h"
#include <iostream>
#include <sstream>
#include "../include/Renderer.h"
#include "../include/ResourceManager.h"
#include "../include/Image.h"
#include "Label.h"
#include "../include/math.h"

//------------------------------------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------------------------------------
Button::Button()
{
	m_normalImage = NULL;
	m_pushImage	= NULL;
	m_disabledImage = NULL;
	m_pushed = false;
	m_label = NULL;
}

//------------------------------------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------------------------------------
bool Button::init( const std::string name, const Vector2& position, const std::string& normalImage, const std::string& pushImage, const std::string& disabledImage )
{
	m_name				= name;
	m_position			= position;
	m_normalImage		= new Image( normalImage.c_str() );
	m_pushImage			= new Image( pushImage.c_str() );
	m_size					= Vector2( (float)m_normalImage->GetWidth(), (float)m_normalImage->GetHeight() );

	if( disabledImage != " " )
	{
		m_disabledImage =  new Image( disabledImage.c_str() );
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

	if( ( !isVisible() || !isEnabled() ) && m_label )
	{
		m_label->setVisible( false );
	}
	else if ( m_label )
	{
		m_label->setVisible( true );
	}
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
		
		if( !isEnabled() && m_disabledImage )
		{
			Renderer::Instance().DrawImage( m_disabledImage, pos.x, pos.y );
		}
		else
		{
			if( m_pushed )
			{
				Renderer::Instance().DrawImage( m_pushImage, pos.x, pos.y );
			}
			else
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
	switch( message.type )
	{
	case mtPointerButtonDown:
		m_pushed = true;
		break;

	case mtPointerButtonUp:
		if( m_pushed )
			NOTIFY_LISTENERS( onClick( this ) );
		m_pushed = false;
		break;
	}
}

//------------------------------------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------------------------------------
void Button::destroy()
{
	if( m_normalImage )
	{
		delete m_normalImage;
		m_normalImage = NULL;
	}
	if( m_pushImage )
	{
		delete m_pushImage;
		m_pushImage = NULL;
	}
	if( m_disabledImage )
	{
		delete m_disabledImage;
		m_disabledImage = NULL;
	}
}


void Button::setLabel( Label* label )
{ 
	m_label = label; 

	Vector2 textSize = label->getSize();
	Vector2 posInButton = Vector2( ( m_size.x - textSize.x ) / 2 , ( m_size.y - textSize.y ) / 2 );

	label->setPosition( posInButton ); 
	label->setParent( this ); 

} 