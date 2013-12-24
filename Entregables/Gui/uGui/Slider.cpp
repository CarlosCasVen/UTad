#include "Slider.h"
#include "../include/Renderer.h"
#include "../include/Image.h"
#include "../include/resourcemanager.h"


Slider::Slider()
{
	m_leftButton = NULL;
	m_rightButton = NULL;
	m_pointerButton = NULL;
	m_barImage = NULL;
}


void Slider::update()
{
	if( m_leftButton->isPushed() && m_pointerPosition.x > 0 )
	{
		m_pointerPosition.x--;
	}
	else if( m_rightButton->isPushed() && m_pointerPosition.x < 100 )
	{
		m_pointerPosition.x++;
	}

	if( m_percent )
	{
		m_percent->setText( String::FromInt( (int) m_pointerPosition.x ) );
	}
}


void Slider::render()
{
	if( isVisible() )
	{
		Renderer render = Renderer::Instance();
		render.SetBlendMode( Renderer::ALPHA );
	
		Vector2 pointerPos = m_pointerButton->getPosition();
		pointerPos.x = ( m_barImage->GetWidth() - m_pointerButton->getSize().x ) / 100;
		pointerPos.x *= m_pointerPosition.x;
		m_pointerButton->setPosition( Vector2( pointerPos.x, pointerPos.y) );

		Vector2 posBar = getAbsolutePosition();
		render.DrawImage( m_barImage, posBar.x, posBar.y );

	}
}


void Slider::onInputEvent( const Message& message )
{
	if (m_enabled)
	{
		switch (message.type)
		{
		case mtPointerButtonDown:
			{
				Vector2 posSliderBall = m_pointerButton->getAbsolutePosition();
				const MessagePointerMove* messagePointer = static_cast<const MessagePointerMove*>(&message);
				if( messagePointer->x  >  posSliderBall.x && m_pointerPosition.x < 100 )
				{
					m_pointerPosition.x++;
				}
				else if( messagePointer->y  <  posSliderBall.x && m_pointerPosition.x > 0 )
				{
					m_pointerPosition.x--;
				}
			break;
			}
		}
	}
}


void Slider::destroy()
{

}


bool Slider::init( const String& name, const Vector2& position, const String barImage, const String buttonLeftNormalImage, const String buttonLeftPushedImage,
		const String buttonRightNormalImage, const String buttonRightPushedImage, const String pointerImage )
{
	Image auxImageLeft = Image( buttonLeftNormalImage );
	Image auxImageLeftPush = Image( buttonLeftPushedImage );
	Image auxImageRight = Image( buttonRightNormalImage );
	Image auxImageRightPush = Image( buttonRightPushedImage );
	Image auxImagePointer = Image( pointerImage );

	m_name = name.ToCString();
	m_position = position;
	m_barImage = ResourceManager::Instance().LoadImage( barImage.ToCString() );
	m_size = Vector2( m_barImage->GetWidth(), m_barImage->GetHeight() );
	
	Vector2 posButtons;
	posButtons.x = (float) - auxImageLeft.GetWidth();
	posButtons.y = (float) m_barImage->GetHeight() - (float) auxImageLeft.GetHeight();
	posButtons.y /= 2;

	m_leftButton = new Button();
	m_leftButton->init( "ButtonLeft", posButtons, buttonLeftNormalImage, buttonLeftPushedImage );
	m_leftButton->setEventListener( this );

	posButtons.x = m_barImage->GetWidth();
	posButtons.y = (float) m_barImage->GetHeight() - (float) auxImageRight.GetHeight();
	posButtons.y /= 2;

	m_rightButton = new Button();
	m_rightButton->init( "ButtonRight", posButtons, buttonRightNormalImage, buttonRightPushedImage );
	m_rightButton->setEventListener( this );

	m_pointerPosition.x = 50;
	m_pointerPosition.y = (float) m_barImage->GetHeight() - (float) auxImagePointer.GetHeight();
	m_pointerPosition.y /= 2;

	posButtons.x = (float) m_barImage->GetWidth() / 100;
	posButtons.x *= m_pointerPosition.x;
	posButtons.y = m_pointerPosition.y;

	m_pointerButton = new Button();
	m_pointerButton->init( "ButtonPointer", posButtons, pointerImage, pointerImage );
	m_pointerButton->setEventListener( this );

	m_leftButton->setParent( this );
	m_rightButton->setParent( this );
	m_pointerButton->setParent( this );

	return m_barImage && m_leftButton && m_rightButton && m_pointerButton;
}



void Slider::onClick( Control* sender )
{
	if( sender == m_leftButton )
	{
		if( m_pointerPosition.x > 0 && isEnabled() )
		{
			m_pointerPosition.x--;
		}
	}
	else if( sender == m_rightButton  && isEnabled() )
	{
		if( m_pointerPosition.x < 100 )
		{
			m_pointerPosition.x++;
		}
	}
	else if( sender == m_pointerButton )
	{
	}
}



void Slider::setLabel( Label* label )
{
	if( label )
	{
		m_label = label;
		label->setParent( this );
	}

}
	

void Slider::setPercentLabel( Vector2 position, const String& font )
{
	m_percent = new Label();
	m_percent->init( "percentLabel", position, font.ToCString(), String::FromInt( (int) m_pointerPosition.x ) );
	m_percent->setParent( this );
}