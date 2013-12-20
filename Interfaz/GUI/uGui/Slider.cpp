#include "Slider.h"
#include "Control.h"
#include "Button.h"
#include "../include/image.h"
#include "../include/renderer.h"
#include "Vector2.h"
#include "../include/math.h"
#include "../include/screen.h"


bool Slider::init( const std::string name, const Vector2& position, const std::string& barImage, const std::string& pointerImage, const std::string& addImage,
				  const std::string& addImagePushed, const std::string& substractImage, const std::string& substractImagePushed, const std::string& font )
{
	Vector2 posChildrens( 0 , 0 );

	m_name = name;
	m_position = position;

	m_bar = new Image( barImage.c_str() );

	m_size = Vector2( m_bar->GetWidth(), m_bar->GetHeight() );

	m_up = new Button();
	m_up->init( "sliderUp", posChildrens , addImage.c_str(), addImagePushed.c_str() ); 
	m_up->setEventListener( this );
	m_up->setParent( this );
	posChildrens = Vector2( m_size.x, m_size.y / 2 - m_up->getSize().y  / 2  );
	m_up->setPosition( posChildrens );

	
	m_down = new Button();
	m_down->init( "sliderDown", posChildrens, substractImage.c_str(), substractImagePushed.c_str() );
	m_down->setEventListener( this );
	m_down->setParent( this );
	posChildrens = Vector2( - m_down->getSize().x , m_size.y / 2 - m_down->getSize().y  / 2  );
	m_down->setPosition( posChildrens );
	
	
	m_pointer = new Button();
	m_pointer->init( "pointer", posChildrens, pointerImage.c_str(), pointerImage.c_str() );
	m_pointer->setEventListener( this );
	m_pointer->setParent( this );
	m_posPointer = Vector2( 50,  m_size.y - Image( pointerImage.c_str() ).GetHeight() / 2 );
	posChildrens = Vector2( ( m_posPointer.x * m_bar->GetWidth() / 100 ) - Image( pointerImage.c_str() ).GetHeight() / 2, m_size.y / 2 - m_pointer->getSize().y  / 2  );
	m_pointer->setPosition( posChildrens );


	m_labelPercent = new Label();
	m_labelPercent->init( "Porcentaje", Vector2( 0, 0 ), String::FromInt( (int)m_posPointer.x ).ToCString(), font.c_str() );
	m_labelPercent->setParent( this );
	m_labelPercent->setVisible( false );

	return m_bar && m_up && m_down && m_pointer && m_labelPercent;
	
}



void Slider::update()
{
	if( !m_enabled )
		int x = 1;

	if( m_up->getIsPushed() && m_posPointer.x < 100 )
	{
		m_posPointer.x++;
	}

	if( m_down->getIsPushed() && m_posPointer.x > 0 )
	{
		m_posPointer.x--;
	}

	if( m_labelPercent )
	{
		m_labelPercent->setText( String::FromInt( (int)m_posPointer.x ).ToCString() );
	
	}

	Vector2 pos( ( m_posPointer.x * m_bar->GetWidth() / 100 ) - m_pointer->getSize().x / 2, m_posPointer.y );
	m_pointer->setPosition( pos );
	xMouse = Screen::Instance().GetMouseX();
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
	if( m_bar )
	{
		delete m_bar;
	}

}


 void Slider::onClick( Control* sender )
 {
	 if( sender == m_down )
	 {
		if( m_posPointer.x > 0 )
		{
				m_posPointer.x--;
		}
	 }
	 else if( sender == m_up )
	 {
		if( m_posPointer.x < 100 )
		{
				m_posPointer.x++;
		}
	 }
	 else if( sender == m_pointer )
	 {
		 
	 }
 }


 void Slider::setLabel( Label* label, bool right, unsigned int numberSpaces )
 {
	 if( right && label )
	{
		m_label = label;
		m_label->setParent( this );
		m_label->setPosition( Vector2( m_size.x + m_up->getSize().x + numberSpaces, m_bar->GetHeight() / 2 - label->getSize().y / 2) );		
	}
	else
	{
		m_label = label;
		m_label->setParent( this );
		m_label->setPosition( Vector2( - ( label->getSize().x + numberSpaces ), label->getSize().y / 2) );
	}
 }


void Slider::setLabelPercent( bool up, unsigned int numberSpaces )
{
	if( m_labelPercent )
	{
		if( up )
		{
			m_labelPercent->setVisible( true );
			m_labelPercent->setParent( this );
			m_labelPercent->setPosition( Vector2 ( ( m_size.x / 2 ) - ( m_labelPercent->getSize().x / 2 ), - ( m_labelPercent->getSize().y + numberSpaces  ) ) );
		}
		else
		{
			m_labelPercent->setVisible( true );
			m_labelPercent->setParent( this );
			m_labelPercent->setPosition( Vector2 ( ( m_size.x / 2 ) - ( m_labelPercent->getSize().x / 2 ), m_labelPercent->getSize().y + numberSpaces + m_size.y ) );
		}
	}
}