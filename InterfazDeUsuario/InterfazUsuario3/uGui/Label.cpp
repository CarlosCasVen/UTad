#include "Label.h"
#include "GUIManager.h"
#include <iostream>
#include <sstream>
#include "../include/Renderer.h"
#include "../include/Image.h"
#include "../include/resourcemanager.h"


//------------------------------------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------------------------------------
Label::Label()
{
	m_pushed = false;
}

//------------------------------------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------------------------------------
bool Label::init( const std::string name, const Vector2& position, const std::string& text, const std::string&  font)
{
	m_font              = ResourceManager::Instance().LoadFont( font.c_str() );
	m_name				= name;
	m_position			= position;
	m_text		= text;
	m_size					= Vector2( m_font->GetTextWidth( text.c_str() ), m_font->GetHeight() );

	return true;
}

//------------------------------------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------------------------------------
void Label::update()
{
	if( !m_pointerIsOver )
		m_pushed = false;
}

//------------------------------------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------------------------------------
void Label::render()
{
	if( m_visible )
	{
		Vector2 pos = getAbsolutePosition();

		Renderer::Instance().SetBlendMode( Renderer::BlendMode::ALPHA );
		Renderer::Instance().SetBlendMode( Renderer::ALPHA );
		
        m_font->Render(m_text.c_str(), pos.x, pos.y);
	}
}

//------------------------------------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------------------------------------
void Label::onInputEvent( const Message& message )
{
}

//------------------------------------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------------------------------------
void Label::destroy()
{
}