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

	//crea checkbox
	m_gore = new Checkbox();
	m_gore->init( "ModoGore", Vector2( 400, 320 ), "data/GUI/CheckBox_enabled.png", "data/GUI/CheckBox_disabled.png", true );
	m_gore->setEventListener( this );
	m_gore->setParent( m_window );
	
	//crea checkbox
	m_particles = new Checkbox();
	m_particles ->init( "Particulas", Vector2( 400, 350 ), "data/GUI/CheckBox_enabled.png", "data/GUI/CheckBox_disabled.png", false );
	m_particles->setEventListener( this );
	m_particles ->setParent( m_window );
	
	//crea checkbox
	m_autosave = new Checkbox();
	m_autosave->init( "Autoguardado", Vector2( 400, 420 ), "data/GUI/CheckBox_enabled.png", "data/GUI/CheckBox_disabled.png", true );
	m_autosave->setEventListener( this );
	m_autosave->setParent( m_window );

	// Crea un botón
	Label* l1 = new Label();
	l1->init( "Volver", Vector2( 0, 0 ), "Volver", "data/fonts/font.png" );

	m_exit = new Button(); 
	m_exit->init( "Volver", Vector2( 50, 320 ), "data/GUI/Button_Normal.png", "data/GUI/Button_Push.png"  );   
	m_exit->setEventListener( this );
	m_exit->setParent( m_window );
	m_exit->setLabel( l1 );

	// Crea un slice
	m_sound = new Slider();
	m_sound->init( "Sonido", Vector2( 100, 100 ), "data/GUI/Slider_bar.png", "data/GUI/Slider_ball.png", "data/GUI/Slider_Right_PushNormal.png", "data/GUI/Slider_Right_Push.png",
					"data/GUI/Slider_Left_Normal.png", "data/GUI/Slider_Left_Push.png" );
	m_sound->setEventListener( this );
	m_sound->setParent( m_window );
	
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