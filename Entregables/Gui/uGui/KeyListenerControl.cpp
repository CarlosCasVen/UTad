#include "KeyListenerControl.h"
#include "../include/renderer.h"
#include "../include/InputManager.h"
#include "../include/emitter.h"
#include "../include/glinclude.h"

KeyListenerControl::KeyListenerControl()
{
	m_scene = NULL;
	m_alien = NULL;
	m_emitter = NULL;
}


// A implementar en clases derivadas
void KeyListenerControl::update()
{
	double movementX = 0;
	double movementY = 0;
	if( m_alien )
	{
		movementX = InputManager::Instance().GetVirtualAxis( "LeftRight" );
		movementY = InputManager::Instance().GetVirtualAxis( "UpDown" );
		m_alien->SetPosition( m_alien->GetX() + 10 * movementX, m_alien->GetY() + 10 * movementY );
	}

	if( InputManager::Instance().IsVirtualButtonPressed( "Shoot" ) )
	{
		m_emitter->Start();
	}
	else if( m_emitter )
	{
		m_emitter->Stop();
	}
	
	m_scene->Update( Screen::Instance().ElapsedTime() );	
}


void KeyListenerControl::render()
{
	Renderer::Instance().SetBlendMode( Renderer::ALPHA );
	Renderer::Instance().Clear( 0, 0 ,255 );
	if( m_scene )
	{
		m_scene->Render();
	}
}


void KeyListenerControl::onInputEvent( const Message& message )
{
	const MessageKeyDown* messagePointer = static_cast<const MessageKeyDown*>(&message);
	NOTIFY_LISTENERS( onKeyDown( this, messagePointer->keyCode ));
}


void KeyListenerControl::destroy()
{
}


bool KeyListenerControl::init( const String& name )
{
	m_name = name.ToCString();
	m_position = Vector2( 0, 0 );
	m_size = Vector2( 600, 800 );

	return true;
}


void KeyListenerControl::setScene( Scene* scene )
{
	m_scene = scene;
}


void KeyListenerControl::setMainCharacter( Sprite* alien, Emitter* emitter )
{
	if( alien && emitter )
	{
		m_alien = alien;
		m_emitter = emitter;
	}
}


