#include "../logic/Logic.h"
#include "../include/scene.h"


//-------------------------------------
//
//-------------------------------------
TError BaseScene::Init()
{
    TError error = OK;

    return error;
}

//-------------------------------------
//
//-------------------------------------
void BaseScene::End()
{
}

//-------------------------------------
//
//-------------------------------------
void BaseScene::Update( double elapsedTime )
{
    for( unsigned int i = 0; i < m_entities.Size(); i++ )
    {
        m_entities[i]->Update( elapsedTime );
    }

    if( m_scene ) m_scene->Update( elapsedTime );
}

//-------------------------------------
//
//-------------------------------------
void BaseScene::Render( double elapsedTime )
{
    if( m_scene ) m_scene->Render();
}

//-------------------------------------
//
//-------------------------------------
void BaseScene::AddSprite( Sprite& sprite )
{
   
}
    
//-------------------------------------
//
//-------------------------------------
void RemoveSprite( Sprite& sprite )
{
}