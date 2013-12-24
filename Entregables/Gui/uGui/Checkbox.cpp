#include "Checkbox.h"
#include "../include/Renderer.h"
#include "../include/Image.h"
#include "../include/resourcemanager.h"


Checkbox::Checkbox()
{
	m_enabledImage = m_disabledImage = NULL;
}


void Checkbox::update()
{
}


void Checkbox::render()
{
	if( isVisible() )
	{
		Vector2 pos = getAbsolutePosition();
		Renderer render = Renderer::Instance();
		render.SetBlendMode( Renderer::ALPHA );
		m_pushed ? render.DrawImage( m_enabledImage, pos.x, pos.y ) : render.DrawImage( m_disabledImage, pos.x, pos.y ); 
	}
}


void Checkbox::onInputEvent( const Message& message )
{
	if (m_enabled)
	{
		switch (message.type)
		{
		case mtPointerButtonDown:
			m_pushed = !m_pushed;
			break;

		}
	}
}


void Checkbox::destroy()
{
}


bool Checkbox::init( const String& name, const Vector2& position, const String& enableImage, const String& disabledImage )
{
	m_name = name.ToCString();
	m_position = position;
	m_enabledImage = ResourceManager::Instance().LoadImage( enableImage.ToCString() );
	m_disabledImage = ResourceManager::Instance().LoadImage( disabledImage.ToCString() );
	m_size = Vector2( (float)m_enabledImage->GetWidth(), (float)m_enabledImage->GetHeight() );

	return m_enabledImage && m_disabledImage;
}


void Checkbox::setLabel( Label* checkboxLabel )
{
	if( checkboxLabel )
	{
		m_label = checkboxLabel;
		m_label->setParent( this );
	}
}


void Checkbox::setPush( bool pushed )
{
	m_pushed = pushed;
}