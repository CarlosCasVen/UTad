#include "Label.h"
#include "Message.h"
#include "../include/renderer.h"
#include "../include/resourcemanager.h"

Label::Label()
{
	m_font = NULL;
}


bool Label::init( const std::string& name, Vector2& position, const std::string& font, const String&  text )
{
	m_name = name.c_str();
	m_position = position;
	m_font = ResourceManager::Instance().LoadFont( font.c_str() );
	m_text = text;
	m_size = Vector2( (float)m_font->GetTextWidth( text.ToCString() ), (float)m_font->GetTextHeight( m_text.ToCString() ) );

	if( !m_font )
	{
		return false;
	}
	return true;
}


void Label::update()
{
}


void Label::render()
{
	if( m_parent )
	{
		if( isVisible() && m_parent->isVisible() )
		{
			Renderer::Instance().SetBlendMode( Renderer::ALPHA );
			Vector2 pos = getAbsolutePosition();
			m_font->Render( m_text.ToCString(), pos.x, pos.y );
		}
	}
}


void Label::onInputEvent( const Message& message )
{
	if( m_parent )
	{
		m_parent->onInputEvent( message );
	}
}


void Label::destroy()
{
}


void Label::setText( const String& text )
{
	m_text = text;
}