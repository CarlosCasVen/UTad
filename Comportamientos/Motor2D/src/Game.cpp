#include "../logic/logic.h"
#include "../include/screen.h"


IGame* m_game = NULL;

//-------------------------------------
//
//-------------------------------------
IGame& IGame::Instance()
{
    if( m_game == NULL )
    {
        m_game = NEW( Game, () );
    }

    return *m_game;
}

//-------------------------------------
//
//-------------------------------------
TError Game::Init()
{
    TError error = OK; 

    if( error == OK ) error = IEventManager::Instance().Init();
    if( error == OK ) error = ISceneManager::Instance().Init();

    return error;
}

//-------------------------------------
//
//-------------------------------------
void Game::End()
{
    DEL( m_game );
}

//-------------------------------------
//
//-------------------------------------
void Game::Update( double elapsedTime )
{
    IEventManager::Instance().Update();
    ISceneManager::Instance().Update( Screen::Instance().ElapsedTime() );
}

//-------------------------------------
//
//-------------------------------------
void Game::Render( double elapsedTime )
{
    ISceneManager::Instance().Render( Screen::Instance().ElapsedTime() );
}