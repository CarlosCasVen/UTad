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
    if( error == OK ) error = IEntityFactory::Instance().Init();
    if( error == OK ) error = IIdFactory::Instance().Init();

    return error;
}

//-------------------------------------
//
//-------------------------------------
void Game::End()
{
    IIdFactory::Instance().End();
    IEntityFactory::Instance().End();
    ISceneManager::Instance().End();
    IEventManager::Instance().End();

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