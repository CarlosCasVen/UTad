#include "../logic/logic.h"
#include "../include/u-gine.h"
#undef ERROR

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

    InputManager::Instance().Init() ? error = OK : error = ERROR;
    if( error == OK ) error = ISoundFactory::Instance().Init();
    if( error == OK ) error = IComponentFactory::Instance().Init();
    if( error == OK ) error = IEntityFactory::Instance().Init();
    if( error == OK ) error = IIdFactory::Instance().Init();
    if( error == OK ) error = IScreenManager::Instance().Init();
    if( error == OK ) error = ISoundManager::Instance().Init();
    if( error == OK ) error = IEventManager::Instance().Init();
    if( error == OK ) error = ISceneManager::Instance().Init();
    if( error == OK ) error = ICollisionManager::Instance().Init();

    return error;
}

//-------------------------------------
//
//-------------------------------------
void Game::End()
{
	ISceneManager::Instance().End();    
    InputManager::Instance().End();
	IScreenManager::Instance().End();
    ISoundManager::Instance().End();
    ICollisionManager::Instance().End();
	IEventManager::Instance().End();
	IIdFactory::Instance().End();
	IEntityFactory::Instance().End();
    IComponentFactory::Instance().End();
    ISoundFactory::Instance().End();

    DEL( m_game );
}

//-------------------------------------
//
//-------------------------------------
void Game::Update( double elapsedTime )
{
    IEventManager::Instance().Update();
	InputManager::Instance().Update();
    ISceneManager::Instance().Update( Screen::Instance().ElapsedTime() );
}

//-------------------------------------
//
//-------------------------------------
void Game::Render()
{
    ISceneManager::Instance().Render();
}

//-------------------------------------
//
//-------------------------------------
bool Game::IsFinish() const
{
    return ISceneManager::Instance().IsFinish();
}