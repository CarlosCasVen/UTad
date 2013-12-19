#include "FirstMenu.h"
#include "GUIManager.h"
#include "Button.h"
#include "Window.h"
#include"ConfigScreen.h"
#include "Checkbox.h"
#include "../include/resourcemanager.h"
#include "Label.h"


ConfigScreen* ConfigScreen::configScreen = NULL;


void ConfigScreen::CreateGUI()
{

	m_window = new Window();
	m_window->init( "Pantalla Principal", Vector2( 100, 200 ), "data/GUI/Window4.png" );

	// Crea un label
	Label* l1 = new Label();
	l1->init( "ModoGore", Vector2( 0, 0 ), "Modo Gore", "data/fonts/font.png" );

	//crea checkbox
	m_gore = new Checkbox();
	m_gore->init( "ModoGore", Vector2( 0, 100 ), "data/GUI/CheckBox_enabled.png", "data/GUI/CheckBox_disabled.png", true );
	m_gore->setEventListener( this );
	m_gore->setParent( m_window );
	m_gore->setLabel( l1 );
	m_gore->setPosition( Vector2( m_window->getSize().x / 2 - m_gore->getSize().x / 2 , 50 ) );
	
	// Crea un label
	Label* l2 = new Label();
	l2->init( "Particulas", Vector2( 0, 0 ), "Particulas", "data/fonts/font.png" );

	//crea checkbox
	m_particles = new Checkbox();
	m_particles ->init( "Particulas", Vector2( 300, 170 ), "data/GUI/CheckBox_enabled.png", "data/GUI/CheckBox_disabled.png", false );
	m_particles->setEventListener( this );
	m_particles ->setParent( m_window );
	m_particles->setLabel( l2 );
	m_particles->setPosition( Vector2( m_window->getSize().x / 2 - m_particles->getSize().x / 2 , 120 ) );

	// Crea un label
	Label* l3 = new Label();
	l3->init( "Autoguardado", Vector2( 0, 0 ), "Autoguardado", "data/fonts/font.png" );

	//crea checkbox
	m_autosave = new Checkbox();
	m_autosave->init( "Autoguardado", Vector2( 300, 250 ), "data/GUI/CheckBox_enabled.png", "data/GUI/CheckBox_disabled.png", true );
	m_autosave->setEventListener( this );
	m_autosave->setParent( m_window );
	m_autosave->setLabel( l3 );
	m_autosave->setPosition( Vector2( m_window->getSize().x / 2 - m_autosave->getSize().x / 2 , 190 ) );

	// Crea un label
	Label* l4 = new Label();
	l4->init( "Volver", Vector2( 0, 0 ), "Volver", "data/fonts/font.png" );

	m_exit = new Button(); 
	m_exit->init( "Volver", Vector2( 50, 320 ), "data/GUI/Button_Normal.png", "data/GUI/Button_Push.png"  );   
	m_exit->setEventListener( this );
	m_exit->setParent( m_window );
	m_exit->setLabel( l4 );


	Label* l5 = new Label();
	l5->init( "Volumen", Vector2( 0, 0 ), "Volumen", "data/fonts/font.png" );

	// Crea un slice
	m_sound = new Slider();
	m_sound->init( "Sonido", Vector2( 100, 100 ), "data/GUI/Slider_bar.png", "data/GUI/Slider_ball.png", "data/GUI/Slider_Right_Normal.png", "data/GUI/Slider_Right_Push.png",
					"data/GUI/Slider_Left_Normal.png", "data/GUI/Slider_Left_Push.png", "data/fonts/font.png"  );
	m_sound->setEventListener( this );
	m_sound->setParent( m_window );
	m_sound->setLabel( l5 );
	m_sound->setLabelPercent();
	m_sound->setPosition( Vector2( m_window->getSize().x / 2 - m_sound->getSize().x / 2 , 300 ) );
}


void ConfigScreen::Active()
{
	if( m_window )
	{
		GUIManager::instance().setRootControl( m_window );
	}
	else
	{
		CreateGUI();
		GUIManager::instance().setRootControl( m_window );
	}
}



void ConfigScreen::onClick( Control* sender )
{
	if( sender == m_gore )
	{
		int x = 1;
	}
	else if( sender == m_particles )
	{
		int x = 1;
	}
	else if( sender == m_autosave )
	{
		int x = 1;
	}
	else if( sender == m_exit )
	{
		FirstMenu::instance().Active();
	}
}