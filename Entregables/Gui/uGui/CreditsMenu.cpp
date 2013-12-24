#include "CreditsMenu.h"
#include "GUIManager.h"
#include "MainMenu.h"
#include "../include/screen.h"


CreditsMenu* CreditsMenu::m_menu = NULL;


CreditsMenu::CreditsMenu()
{
	m_window = NULL;
	m_author = NULL;
	m_authorName = NULL;
	m_exit = NULL;
}


CreditsMenu& CreditsMenu::instance()
{
	if( !m_menu )
	{
		m_menu = new CreditsMenu();
	}
	return *m_menu;
}


void CreditsMenu::showScreen()
{
	if( !m_window )
	{
		init();
	}

	GUIManager::instance().setRootControl( m_window );
}


bool CreditsMenu::init()
{
	Image auxImage = Image( "data/GUI/Window4.png" );
	Vector2 pos;
	pos.x = (float) Screen::Instance().GetWidth() - (float) auxImage.GetWidth();
	pos.x /= 2;
	pos.y = (float) Screen::Instance().GetHeight() - (float) auxImage.GetHeight();
	pos.y /= 2;
	
	Label* lTitle = new Label();
	lTitle->init( "labelCreditsMenu", Vector2( 40, 10 ), "data/fonts/arial16.png", "Credits Menu" );

	m_window = new Window();
	m_window->init( "CreditsMenuWindow", pos, "data/GUI/Window4.png" );
	m_window->setEventListener( this );
	m_window->setLabel( lTitle );

	m_author = new Label();
	m_author->init( "labelAuthor", pos, "data/fonts/arial16.png", "Author" );
	pos.x =  (float) auxImage.GetWidth() - (float) m_author->getSize().x;
	pos.x /= 2;
	pos.y = 100;
	m_author->setPosition( pos );
	m_author->setParent( m_window );

	m_authorName = new Label();
	m_authorName->init( "labelAuthorName", pos, "data/fonts/arial16.png", "Carlos Castillo Venegas" );
	pos.x =  auxImage.GetWidth() - m_authorName->getSize().x;
	pos.x /= 2;
	pos.y += 50;
	m_authorName->setPosition( pos );
	m_authorName->setParent( m_window );

	Label* lExit = new Label();
	lExit->init( "labelButtonExitCredits", pos, "data/fonts/arial16.png", "Back" );

	m_exit = new Button();
	m_exit->init( "ButtonConfig", Vector2( 50, 320 ), "data/GUI/Button_Normal.png", "data/GUI/Button_Push.png", "data/GUI/Button_Disabled.png" );
	m_exit->setParent( m_window );
	m_exit->setEventListener( this );
	m_exit->setLabel( lExit );

	return m_window && m_author && m_authorName && m_exit;
}



void CreditsMenu::onClick( Control* sender )
{
	if( sender == m_window )
	{
	}
	else if( sender == m_exit )
	{
		MainMenu::instance().showScreen();
	}
}