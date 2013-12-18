#include "Slider.h"
#include "Control.h"
#include "Button.h"
#include "../include/image.h"
#include "../include/renderer.h"
#include "Vector2.h"

bool Slider::init( const std::string name, const Vector2& position, const std::string& barImage, const std::string& pointerImage, const std::string& addImage, const std::string& addImagePushed, const std::string& substractImage, const std::string& substractImagePushed )
{
	m_name = name;
	m_position = position;
	
	m_bar = new Image( barImage.c_str() );

	m_size = Vector2( m_bar->GetWidth(), m_bar->GetWidth() );
	
	m_up = new Button();
	m_up->init( "sliderUp", Vector2( m_size.x  , -Image( addImagePushed.c_str() ).GetHeight() / 2 ) , addImage.c_str(), addImagePushed.c_str() ); 
	m_up->setParent( this );

	m_down = new Button();
	m_down->init( "sliderDown", Vector2( -Image( substractImage.c_str() ).GetWidth(), -Image( substractImage.c_str() ).GetHeight() / 2 ) , substractImage.c_str(), substractImagePushed.c_str() );
	m_down->setParent( this );

	m_posPointer = Vector2( 50, -Image( pointerImage.c_str() ).GetHeight() / 2 );
	m_pointer = new Button();
	m_pointer->init( "pointer", m_posPointer , pointerImage.c_str(), pointerImage.c_str() );
	m_pointer->setParent( this );

	return true;
	
}



void Slider::update()
{
	if( !m_enabled )
		int x = 1;
}

void Slider::render()
{
	if( isVisible() )
	{
		if( !isEnabled() )
		{
			int x =1;
		}
		else
		{
			Vector2 pos = getAbsolutePosition();

			Renderer::Instance().SetBlendMode( Renderer::BlendMode::ALPHA );
			Renderer::Instance().DrawImage( m_bar, pos.x, pos.y );

		}
	}
}


void Slider::onInputEvent( const Message& message )
{
}


void Slider::destroy()
{
}