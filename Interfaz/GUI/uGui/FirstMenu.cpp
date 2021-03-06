#include "FirstMenu.h"
#include "CreditsScreen.h"
#include "ConfigScreen.h"
#include "GUIManager.h"
#include "Button.h"
#include "Window.h"
#include "Label.h"
#include "../include/scene.h"
#include "../include/sprite.h"
#include "../include/emitter.h"
#include "../include/font.h"
#include "../include/resourceManager.h"
#include "../include/glinclude.h"


FirstMenu* FirstMenu::firstMenu = NULL;


void FirstMenu::CreateGUI()
{
	m_window = new Window();
	m_window->init( "Pantalla Principal", Vector2( 100, 200 ), "data/GUI/Window4.png" );
	m_window->setEventListener( this );

	// Crea un label 
	Label* l1 = new Label();
	l1->init( "Comenzer Partida", Vector2( 300, 400), "Comentar Partida","data/fonts/font.png");

	// Crea un bot�n
	m_start = new Button();
	m_start->init( "Comenzar Partida", Vector2( 250, 100 ), "data/GUI/Button_Normal.png", "data/GUI/Button_Push.png", "data/GUI/Button_Disabled" );
	m_start->setEventListener( this );
	m_start->setParent( m_window );
	m_start->setLabel( l1 );
	m_start->setPosition( Vector2( m_window->getSize().x / 2 - m_start->getSize().x / 2 , 100 ) );

	// Crea un label 
	Label* l2 = new Label();
	l2->init( "Configuracion", Vector2( 300, 400), "Configuracion","data/fonts/font.png");

	// Crea un bot�n
	m_config = new Button(); 
	m_config->init( "Configuracion", Vector2( 250, 150 ), "data/GUI/Button_Normal.png", "data/GUI/Button_Push.png", "data/GUI/Button_Disabled" );   
	m_config->setEventListener( this );
	m_config->setParent( m_window );
	m_config->setLabel( l2 );
	m_config->setPosition( Vector2( m_window->getSize().x / 2 - m_config->getSize().x / 2 , 150 ) );

	// Crea un label 
	Label* l3 = new Label();
	l3->init( "Creditos", Vector2( 300, 400), "Creditos","data/fonts/font.png");

	// Crea un bot�n
	m_credits = new Button(); 
	m_credits->init( "Creditos", Vector2( 250, 200 ), "data/GUI/Button_Normal.png", "data/GUI/Button_Push.png", "data/GUI/Button_Disabled" );   
	m_credits->setEventListener( this );
	m_credits->setParent( m_window );
	m_credits->setLabel( l3 );
	m_credits->setPosition( Vector2( m_window->getSize().x / 2 - m_credits->getSize().x / 2 , 200 ) );

	// Crea un label 
	Label* l4 = new Label();
	l4->init( "Salir", Vector2( 300, 400), "Salir","data/fonts/font.png");

	// Crea un bot�n
	m_exit = new Button(); 
	m_exit->init( "Salir", Vector2( 250, 250 ), "data/GUI/Button_Normal.png", "data/GUI/Button_Push.png", "data/GUI/Button_Disabled" );   
	m_exit->setEventListener( this );
	m_exit->setParent( m_window );
	m_exit->setLabel( l4 );
	m_exit->setPosition( Vector2( m_window->getSize().x / 2 - m_exit->getSize().x / 2 , 250 ) );

	// Crea un label 
	Label* l5 = new Label();
	l5->init( "Si", Vector2( 300, 400), "Si","data/fonts/font.png");

	// Crea un bot�n
	m_yes = new Button(); 
	m_yes->init( "Si", Vector2( 150, 250 ), "data/GUI/Button_Normal.png", "data/GUI/Button_Push.png", "data/GUI/Button_Disabled" );   
	m_yes->setEventListener( this );
	m_yes->setParent( m_window );
	m_yes->setVisible( false );
	m_yes->setLabel( l5 );
	m_yes->setPosition( Vector2( m_window->getSize().x / 4 - m_yes->getSize().x / 2 , m_window->getSize().y / 2 - m_yes->getSize().y / 2 ) );

	// Crea un label 
	Label* l6 = new Label();
	l6->init( "No", Vector2( 300, 400), "No","data/fonts/font.png");

	// Crea un bot�n
	m_no = new Button(); 
	m_no->init( "No", Vector2( 350, 250 ), "data/GUI/Button_Normal.png", "data/GUI/Button_Push.png", "data/GUI/Button_Disabled" );   
	m_no->setEventListener( this );
	m_no->setParent( m_window );
	m_no->setVisible( false );
	m_no->setLabel( l6 );
	m_no->setPosition( Vector2( 3 * m_window->getSize().x / 4 - m_no->getSize().x / 2 , m_window->getSize().y / 2 - m_no->getSize().y / 2 ) );
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
		m_window->setVisible( false );
		m_start->setEnabled( false );
		m_config->setEnabled( false );
		m_credits->setEnabled( false );
		m_exit->setEnabled( false );
		m_yes->setVisible( false );
		m_no->setVisible( false );
		StartGame();
	}
	else if( sender == m_config )
	{
		ConfigScreen::instance().Active();
	}
	else if( sender == m_credits )
	{
		CreditsScreen::instance().Active();
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
		exit(0);
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


void FirstMenu::onKeyDown( Control* sender, int keyCode )
{
	if( sender == m_window && keyCode == 27)
	{
		m_window->setVisible( true );
		m_start->setVisible( true );
		m_config->setVisible( true );
		m_credits->setVisible( true );
		m_exit->setVisible( true );
		m_yes->setVisible( true );
		m_no->setVisible( true );
	}
}


void FirstMenu::StartGame()
{

	
}