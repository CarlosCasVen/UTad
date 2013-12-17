#include "CreditsScreen.h"
#include "FirstMenu.h"
#include "GUIManager.h"
#include "Button.h"
#include "Window.h"
#include "../include/resourcemanager.h"


CreditsScreen* creditsScreen = NULL;


void CreditsScreen::CreateGUI()
{


	m_window = new Window();
	m_window->init( "Pantalla Principal", Vector2( 100, 200 ), "data/GUI/Window4.png" );

	// Crea un botón
	m_exit = new Button(); 
	m_exit->init( "Volver", Vector2( 250, 250 ), "data/GUI/Button_Normal.png", "data/GUI/Button_Push.png" );   
	m_exit->setEventListener( this );
	m_exit->setParent( m_window );

	m_credits = new Label();
	m_credits->init( "Creditos", Vector2( 300, 400), "Carlos Castillo Venegas","../data/fonts/font.png");
	m_credits->setParent( m_window );

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