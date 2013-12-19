#include "CreditsScreen.h"
#include "FirstMenu.h"
#include "GUIManager.h"
#include "Button.h"
#include "Window.h"
#include "../include/resourcemanager.h"


CreditsScreen* CreditsScreen::creditsScreen = NULL;


void CreditsScreen::CreateGUI()
{


	m_window = new Window();
	m_window->init( "Pantalla Principal", Vector2( 100, 200 ), "data/GUI/Window4.png" );

	// Crea un label 
	Label* l1 = new Label();
	l1->init( "Volver", Vector2( 300, 400), "Volver","data/fonts/font.png");

	// Crea un botón
	m_exit = new Button(); 
	m_exit->init( "Volver", Vector2( 250, 250 ), "data/GUI/Button_Normal.png", "data/GUI/Button_Push.png" );   
	m_exit->setEventListener( this );
	m_exit->setParent( m_window );
	m_exit->setLabel( l1 );
	


	m_credits = Array<Label*> (2);
	m_credits[0] = new Label();
	m_credits[0]->init( "Autor", Vector2( 300, 100), "Autor","data/fonts/font.png");
	m_credits[0]->setParent( m_window );
	m_credits[0]->setPosition( Vector2( m_window->getSize().x / 2 - m_credits[0]->getSize().x / 2, m_window->getSize().y / 2 - m_credits[0]->getSize().y / 2 ) );

	m_credits = Array<Label*> (2);
	m_credits[1] = new Label();
	m_credits[1]->init( "Creditos", Vector2( 300, 200), "Carlos Castillo Venegas","data/fonts/font.png");
	m_credits[1]->setParent( m_window );
	m_credits[1]->setPosition( Vector2( m_window->getSize().x / 2 - m_credits[1]->getSize().x / 2, m_window->getSize().y / 2 - m_credits[1]->getSize().y / 2 + m_credits[1]->getSize().y * 2 ) );
}



void CreditsScreen::Active()
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


void CreditsScreen::onClick( Control* sender )
{
	if( sender == m_exit )
	{
		FirstMenu::instance().Active();
	}
}