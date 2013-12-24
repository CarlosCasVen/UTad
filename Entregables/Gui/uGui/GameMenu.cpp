#include "GameMenu.h"
#include "MainMenu.h"
#include "../include/glinclude.h"
#include "GUIManager.h"
#include "../include/Renderer.h"
#include "../include/screen.h"
#include "../include/emitter.h"
#include "../include/resourcemanager.h"

GameMenu* GameMenu::m_menu = NULL;

GameMenu& GameMenu::instance()
{
	if( !m_menu )
	{
		m_menu = new GameMenu();
	}
	return *m_menu;
}


void GameMenu::showScreen()
{
	if( !m_listener )
	{
		init();
	}
	m_listener->setEnabled( true );
	GUIManager::instance().setRootControl( m_listener );
}


void GameMenu::onKeyDown( Control* sender, int keyCode )
{
	if (keyCode == GLFW_KEY_ESC)
	{
		m_listener->setEnabled( false );
		MainMenu::instance().showScreen();
	}
}
	

GameMenu::GameMenu()
{
	m_listener = NULL;
}


bool GameMenu::init()
{
	m_listener = new KeyListenerControl();
	m_listener->init("ExitKey");
	m_listener->setEventListener( this );

	m_scene = Scene( ResourceManager::Instance().LoadImage( "data/background.png" ));
	m_listener->setScene( &m_scene );
	Emitter* emitter = m_scene.CreateEmitter( ResourceManager::Instance().LoadImage(  "data/star.png" ), true );
	Sprite* alien = m_scene.CreateSprite( ResourceManager::Instance().LoadImage( "data/alien.png" ) );
	emitter->SetAngularVelocity( 0, 360 );
	emitter->SetMaxColor( 0, 0, 255 );
	emitter->SetMinColor( 0, 0 , 0 );
	emitter->SetLifetime( 1, 10 );
	emitter->SetVelocityX( -300, 300 );
	m_listener->setMainCharacter( alien, emitter );
	

	return true;
}

	