#include "MainMenu.h"
#include "Button.h"
#include "Window.h"
#include "Label.h"
#include "GUIManager.h"
#include "ConfigMenu.h"
#include "CreditsMenu.h"
#include "GameMenu.h"
#include "../include/screen.h"

MainMenu* MainMenu::m_menu = NULL;

MainMenu::MainMenu()
{
	m_window = NULL;
	m_start = NULL;
	m_config = NULL;
	m_credits = NULL;
	m_exit = NULL;
	m_yes = NULL;
	m_no = NULL;
}

MainMenu& MainMenu::instance()
{
	if( !m_menu )
	{
		m_menu = new MainMenu();
	}

	return *m_menu;
}

void MainMenu::showScreen()
{
	if( !m_window )
	{
		init();

	}
	
	GUIManager::instance().setRootControl( m_window );
}
	

bool MainMenu::init()
{
	Image auxImage = Image( "data/GUI/Window4.png" );
	Vector2 pos;
	pos.x = (float) Screen::Instance().GetWidth() - (float) auxImage.GetWidth();
	pos.x /= 2;
	pos.y = (float) Screen::Instance().GetHeight() - (float) auxImage.GetHeight();
	pos.y /= 2;
	
	Label* lTitle = new Label();
	lTitle->init( "labelMainMenu", Vector2( 40, 10 ), "data/fonts/arial16.png", "Main Menu" );

	m_window = new Window();
	m_window->init( "MainMenuWindow", pos, "data/GUI/Window4.png" );
	m_window->setEventListener( this );
	m_window->setLabel( lTitle );

	Image auxButtonImage = Image( "data/GUI/Button_Normal.png" );
	pos.x = m_window->getSize().x - auxButtonImage.GetWidth();
	pos.x /= 2;	
	pos.y = 50;

	Label* lStart = new Label();
	lStart->init( "labelButtonStart", pos, "data/fonts/arial16.png", "Start" );
	m_window->setEventListener( this );

	m_start = new Button();
	m_start->init( "ButtonStart", pos, "data/GUI/Button_Normal.png", "data/GUI/Button_Push.png", "data/GUI/Button_Disabled.png" );
	m_start->setParent( m_window );
	m_start->setEventListener( this );
	m_start->setLabel( lStart );

	pos.y += 50;
	
	Label* lConfig = new Label();
	lConfig->init( "labelButtonConfiguration", pos, "data/fonts/arial16.png", "Configuration" );

	m_config = new Button();
	m_config->init( "ButtonConfig", pos, "data/GUI/Button_Normal.png", "data/GUI/Button_Push.png", "data/GUI/Button_Disabled.png" );
	m_config->setParent( m_window );
	m_config->setEventListener( this );
	m_config->setLabel( lConfig );

	pos.y += 50;

	Label* lCredits = new Label();
	lCredits->init( "labelButtonCredits", pos, "data/fonts/arial16.png", "Credits" );

	m_credits = new Button();
	m_credits->init( "ButtonCredits", pos, "data/GUI/Button_Normal.png", "data/GUI/Button_Push.png", "data/GUI/Button_Disabled.png" );
	m_credits->setParent( m_window );
	m_credits->setEventListener( this );
	m_credits->setLabel( lCredits );

	pos.y += 50;

	Label* lExit = new Label();
	lExit->init( "labelButtonExit", pos, "data/fonts/arial16.png", "Exit" );

	m_exit = new Button();
	m_exit->init( "ButtonConfig", pos, "data/GUI/Button_Normal.png", "data/GUI/Button_Push.png", "data/GUI/Button_Disabled.png" );
	m_exit->setParent( m_window );
	m_exit->setEventListener( this );
	m_exit->setLabel( lExit );


	pos.x = m_window->getSize().x - auxButtonImage.GetWidth();
	pos.x /= 3;
	pos.y = m_window->getSize().y - auxButtonImage.GetHeight();
	pos.y /= 2;

	Label* lYes = new Label();
	lYes->init( "labelButtonYes", pos, "data/fonts/arial16.png", "Yes" );

	m_yes =  new Button();
	m_yes->init( "ButtonYes", pos, "data/GUI/Button_Normal.png", "data/GUI/Button_Push.png", "data/GUI/Button_Disabled.png" );
	m_yes->setParent( m_window );
	m_yes->setEventListener( this );
	m_yes->setLabel( lYes );
	m_yes->setEnabled( false );
	m_yes->setVisible( false );

	pos.x = m_window->getSize().x - auxButtonImage.GetWidth();
	pos.x /= 3;
	pos.x *= 2;

	Label* lNo = new Label();
	lNo->init( "labelButtonNo", pos, "data/fonts/arial16.png", "No" );

	m_no =  new Button();
	m_no->init( "ButtonNo", pos, "data/GUI/Button_Normal.png", "data/GUI/Button_Push.png", "data/GUI/Button_Disabled.png" );
	m_no->setParent( m_window );
	m_no->setEventListener( this );
	m_no->setLabel( lNo );
	m_no->setEnabled( false );
	m_no->setVisible( false );
	
	return m_window && m_start && m_config && m_credits && m_exit;
	return true;
}


void MainMenu::onClick( Control* sender )
{
	if( sender == m_window )
	{
	
	}
	else if( sender == m_start )
	{
		GameMenu::instance().showScreen();
	}
	else if( sender == m_config )
	{
		ConfigMenu::instance().showScreen();
	}
	else if( sender == m_credits )
	{
		CreditsMenu::instance().showScreen();
	}
	else if( sender == m_exit )
	{
		m_start->setEnabled( false );
		m_start->setVisible( false );
		m_config->setEnabled( false );
		m_config->setVisible( false );
		m_credits->setEnabled( false );
		m_credits->setVisible( false );
		m_exit->setEnabled( false );
		m_exit->setVisible( false );
		m_yes->setEnabled( true );
		m_yes->setVisible( true );
		m_no->setEnabled( true );
		m_no->setVisible( true );

	}
	else if( sender == m_yes )
	{
		exit(0);
	}
	else if( sender == m_no )
	{
		m_start->setEnabled( true );
		m_start->setVisible( true );
		m_config->setEnabled( true );
		m_config->setVisible( true );
		m_credits->setEnabled( true );
		m_credits->setVisible( true );
		m_exit->setEnabled( true );
		m_exit->setVisible( true );
		m_yes->setEnabled( false );
		m_yes->setVisible( false );
		m_no->setEnabled( false );
		m_no->setVisible( false );
	}
}