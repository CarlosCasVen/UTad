#include "Window.h"
#include "GUIManager.h"
#include "../include/Renderer.h"
#include "../include/Image.h"

Window::Window()
{
	m_canvas					= NULL;
	m_avaiableToDrag = false;
	m_label = NULL;
}

//------------------------------------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------------------------------------
bool Window::init( const std::string name, const Vector2& position, const std::string& backgroungImage )
{
	m_name					= name;
	m_position			= position;
	m_canvas				= new Image( backgroungImage.c_str() );
	m_size					= Vector2( (float)m_canvas->GetWidth(), (float)m_canvas->GetHeight() );

	return true;
}

//------------------------------------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------------------------------------
bool Window::init( const std::string name )
{
	m_name					= name;
	m_position			= Vector2( 0, 0 );
	m_size					= GUIManager::instance().getScreenSize();

	return true;
}

//------------------------------------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------------------------------------
void Window::update()
{

}

//------------------------------------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------------------------------------
void Window::render()
{
	if( m_canvas && m_visible )
	{
		Vector2 pos = getAbsolutePosition();

		Renderer::Instance().SetBlendMode( Renderer::ALPHA );
		Renderer::Instance().DrawImage( m_canvas, pos.x, pos.y );
	}
}

//------------------------------------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------------------------------------
void Window::onInputEvent( const Message& message )
{
	switch( message.type )
	{
	  case mtPointerMove:
        if (m_avaiableToDrag) {
            const MessagePointerMove* messagePointer = static_cast<const MessagePointerMove*>(&message);
			m_position = Vector2(messagePointer->x + m_lastPos.x, messagePointer->y + m_lastPos.y);
        }
        break;
	  case mtPointerButtonDown: 
        {
		    const MessagePointerButtonDown* messagePointer = static_cast<const MessagePointerButtonDown*>(&message);
            if( messagePointer->y - m_position.y < 30 )
				m_avaiableToDrag = true;
			m_lastPos = Vector2( m_position.x - messagePointer->x, m_position.y - messagePointer->y );

		}
        break;
	case mtPointerButtonUp:
		m_avaiableToDrag = false;
		NOTIFY_LISTENERS( onClick( this ) );
		break;
	}	
}

//------------------------------------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------------------------------------
void Window::destroy()
{
	if( m_canvas )
	{
		delete m_canvas;
		m_canvas = NULL;
	}
}



void Window::setLabel( Label* label )
{
	if( label )
	{
		m_label = label;
		m_label->setParent( this );
	}
}