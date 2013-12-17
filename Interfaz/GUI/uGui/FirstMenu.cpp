#include "FirstMenu.h"
#include "CreditsScreen.h"
#include "ConfigScreen.h"
#include "GUIManager.h"
#include "Button.h"
#include "Window.h"
#include "Label.h"
#include "../include/font.h"
#include "../include/resourceManager.h"


FirstMenu* FirstMenu::firstMenu = NULL;


void FirstMenu::CreateGUI()
{
	m_window = new Window();
	m_window->init( "Pantalla Principal", Vector2( 100, 200 ), "data/GUI/Window4.png" );

	// Crea un bot�n
	m_start = new Button();
	m_start->init( "Comenzar Partida", Vector2( 250, 100 ), "data/GUI/Button_Normal.png", "data/GUI/Button_Push.png", "data/GUI/Button_Disabled" );
	m_start->setEventListener( this );
	m_start->setParent( m_window );

	// Crea un bot�n
	m_config = new Button(); 
	m_config->init( "Configuracion", Vector2( 250, 150 ), "data/GUI/Button_Normal.png", "data/GUI/Button_Push.png", "data/GUI/Button_Disabled" );   
	m_config->setEventListener( this );
	m_config->setParent( m_window );

	// Crea un bot�n
	m_credits = new Button(); 
	m_credits->init( "Creditos", Vector2( 250, 200 ), "data/GUI/Button_Normal.png", "data/GUI/Button_Push.png", "data/GUI/Button_Disabled" );   
	m_credits->setEventListener( this );
	m_credits->setParent( m_window );

	// Crea un bot�n
	m_exit = new Button(); 
	m_exit->init( "Salir", Vector2( 250, 250 ), "data/GUI/Button_Normal.png", "data/GUI/Button_Push.png", "data/GUI/Button_Disabled" );   
	m_exit->setEventListener( this );
	m_exit->setParent( m_window );

	// Crea un bot�n
	m_yes = new Button(); 
	m_yes->init( "Si", Vector2( 150, 250 ), "data/GUI/Button_Normal.png", "data/GUI/Button_Push.png", "data/GUI/Button_Disabled" );   
	m_yes->setEventListener( this );
	m_yes->setParent( m_window );
	m_yes->setVisible( false );

	// Crea un bot�n
	m_no = new Button(); 
	m_no->init( "No", Vector2( 350, 250 ), "data/GUI/Button_Normal.png", "data/GUI/Button_Push.png", "data/GUI/Button_Disabled" );   
	m_no->setEventListener( this );
	m_no->setParent( m_window );
	m_no->setVisible( false );

}


void FirstMenu::Active()
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


void FirstMenu::onClick( Control* sender )
{
	if( sender == m_start )
	{
	}
	else if( sender == m_config )
	{
		ConfigScreen::instance().Active();
	}
	else if( sender == m_credits )
	{
		//CreditsScreen::instance()->Active();
	}
	else if( sender == m_exit )
	{
		m_window->setEnabled( false );
		m_start->setEnabled( false );
		m_config->setEnabled( false );
		m_credits->setEnabled( false );
		m_exit->setEnabled( false );
		m_yes->setVisible( true );
		m_no->setVisible( true );
	}
	else if( sender == m_yes )
	{
		return;
	}
	else if( sender == m_no )
	{
		m_window->setEnabled( true );
		m_start->setEnabled( true );
		m_config->setEnabled( true );
		m_credits->setEnabled( true );
		m_exit->setEnabled( true );
		m_yes->setVisible( false );
		m_no->setVisible( false );
	}

}