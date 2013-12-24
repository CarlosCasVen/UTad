#include "ConfigMenu.h"
#include "GUIManager.h"
#include "Slider.h"
#include "MainMenu.h"
#include "../include/screen.h"
#include "../include/font.h"

ConfigMenu* ConfigMenu::m_menu = NULL;


ConfigMenu& ConfigMenu::instance()
{
	if( !m_menu )
	{
		m_menu = new ConfigMenu();
	}

	return *m_menu;
}


void ConfigMenu::showScreen()
{
	if( !m_window )
	{
		init();
	}

	GUIManager::instance().setRootControl( m_window );
}
	

ConfigMenu::ConfigMenu()
{
	m_window = NULL;
	m_gore = NULL;
	m_particles = NULL;
	m_autosave = NULL;
	m_exit = NULL;

}



bool ConfigMenu::init()
{
	Image auxImage = Image( "data/GUI/Window4.png" );
	Image auxCheckboxImage = Image( "data/GUI/CheckBox_enabled.png" );
	Image auxButtonImage = Image( "data/GUI/Button_Normal.png" );


	Vector2 pos;
	pos.x = (float) Screen::Instance().GetWidth() - (float) auxImage.GetWidth();
	pos.x /= 2;
	pos.y = (float) Screen::Instance().GetHeight() - (float) auxImage.GetHeight();
	pos.y /= 2;
	

	Vector2 labelsPos = Vector2( -20, 0);

	Label* lTitle = new Label();
	lTitle->init( "labelConfigMenu", Vector2( 40, 10 ), "data/fonts/arial16.png", "Configuration Menu" );


	m_window = new Window();
	m_window->init( "ConfigMenuWindow", pos, "data/GUI/Window4.png" );
	m_window->setEventListener( this );
	m_window->setLabel( lTitle );


	pos.x = m_window->getSize().x - auxCheckboxImage.GetWidth();
	pos.x /= 2;	
	pos.y = 70;

	Label* lGore = new Label();
	lGore->init( "labelCheckGore", labelsPos, "data/fonts/arial16.png", "Gore" );
	labelsPos.x = - (20 + lGore->getSize().x );
	labelsPos.y = auxCheckboxImage.GetHeight() - lGore->getSize().y;
	labelsPos.y /= 2;
	lGore->setPosition( labelsPos );

	m_gore = new Checkbox();
	m_gore->init( "CheckGore", pos, "data/GUI/CheckBox_enabled.png", "data/GUI/CheckBox_disabled.png" );
	m_gore->setParent( m_window );
	m_gore->setEventListener( this );
	m_gore->setLabel( lGore );
	
	pos.y += 70;

	Label* lParticles = new Label();
	lParticles->init( "labelCheckParticles", labelsPos, "data/fonts/arial16.png", "Particles" );

	m_particles = new Checkbox();
	m_particles->init( "CheckParticles", pos, "data/GUI/CheckBox_enabled.png", "data/GUI/CheckBox_disabled.png" );
	m_particles->setParent( m_window );
	m_particles->setEventListener( this );
	m_particles->setPush( false );
	labelsPos.x = - (20 + lParticles->getSize().x );
	lParticles->setPosition( labelsPos );
	m_particles->setLabel( lParticles );

	pos.y += 70;

	Label* lAutosave = new Label();
	lAutosave->init( "labelCheckAutosave", labelsPos, "data/fonts/arial16.png", "Autosave" );

	m_autosave = new Checkbox();
	m_autosave->init( "CheckAutosave", pos, "data/GUI/CheckBox_enabled.png", "data/GUI/CheckBox_disabled.png" );
	m_autosave->setParent( m_window );
	m_autosave->setEventListener( this );
	m_autosave->setEventListener( this );
	labelsPos.x = - (20 + lAutosave->getSize().x );
	lAutosave->setPosition( labelsPos );
	m_autosave->setLabel( lAutosave );
	
	 pos.y += 70;

	Font fontAux = Font("data/fonts/arial16.png");

	Label* lSound = new Label();
	lSound->init( "labelCheckSound", labelsPos, "data/fonts/arial16.png", "Volume" );

	m_sound = new Slider();
	m_sound->init( "SoundSlider", pos, "data/GUI/Slider_bar.png", "data/GUI/Slider_Left_Normal.png", "data/GUI/Slider_Left_Push.png"
		, "data/GUI/Slider_Right_Normal.png", "data/GUI/Slider_Right_Push.png", "data/GUI/Slider_ball.png" );
	m_sound->setEventListener( this );
	m_sound->setParent( m_window );

	labelsPos.y =  m_sound->getSize().y - lSound->getSize().y;
	labelsPos.y /= 2;
	lSound->setPosition( labelsPos );
	
	pos.x = m_window->getSize().x - m_sound->getSize().x;
	pos.x /= 2;
	
	labelsPos.x = m_sound->getSize().x - fontAux.GetTextWidth( "00" );
	labelsPos.x /= 2;
	labelsPos.y = 25;

	m_sound->setLabel( lSound );
	m_sound->setPosition( pos );
	m_sound->setPercentLabel( labelsPos, "data/fonts/arial16.png" );

	pos.x = 50;
	pos.y = 320;

	Label* lExit = new Label();
	lExit->init( "labelButtonExitConfig", pos, "data/fonts/arial16.png", "Back" );

	m_exit = new Button();
	m_exit->init( "ButtonConfig", pos, "data/GUI/Button_Normal.png", "data/GUI/Button_Push.png", "data/GUI/Button_Disabled.png" );
	m_exit->setParent( m_window );
	m_exit->setEventListener( this );
	m_exit->setLabel( lExit );
	

	return true;
}


void ConfigMenu::onClick( Control* sender )
{
	if( sender == m_window )
	{
	}
	else if( sender == m_gore )
	{
	}
	else if( sender == m_particles )
	{
	}
	else if( sender == m_autosave )
	{
	}
	else if( sender == m_exit )
	{
		MainMenu::instance().showScreen();
	}
}