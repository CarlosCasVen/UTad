#include "Slider.h"
#include "Control.h"
#include "Button.h"
#include "../include/image.h"
#include "../include/renderer.h"


bool Slider::init( const std::string name, const Vector2& position, const std::string& barImage, const std::string& pointerImage, const std::string& addImage, const std::string& addImagePushed, const std::string& substractImage, const std::string& substractImagePushed )
{
	m_name = name;
	m_position = position;
	
	m_bar = new Image( barImage.c_str() );

	m_size = Vector2( m_bar->GetHeight(), m_bar->GetWidth() );
	
	m_up = new Button();
	m_up->init( "sliderRight", Vector2( 0, 0 ), addImage.c_str(), addImagePushed.c_str() ); 
	m_up->setParent( this );

	m_down = new Button();
	m_down->init( "sliderLeft", Vector2( 50, 50 ), addImage.c_str(), addImagePushed.c_str() );
	m_down->setParent( this );

	m_posPointer = 50;
	m_pointer = new Button();
	m_pointer->init( "pointer", Vector2( 100 , 100 ), addImage.c_str(), addImagePushed.c_str() );
	m_pointer->setParent( this );

	return true;
	
}



void Slider::update()
{
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