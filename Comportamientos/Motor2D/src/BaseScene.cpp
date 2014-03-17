#include "../logic/logic.h"
#include "../include/u-gine.h"



BaseScene::BaseScene( const String* sceneInfo )
{
    m_sceneInfo = sceneInfo;
}


TError BaseScene::Init()
{
    TError error = OK;

    String content = String::Read( m_sceneInfo->ToCString() );
    
    Screen::Instance().SetTitle( *m_sceneInfo );

    rapidjson::Document document;
    document.Parse<0>( (char*) content.ToCString() );

    if( document.HasParseError() ) return ERROR;
    if( !document.HasMember( "Image" ) || !document.HasMember("Entities") ) error = ERROR;

    String pathImage = String( document["Image"].GetString() );
    Image* image = ResourceManager::Instance().LoadImage( pathImage );

    m_scene = NEW( Scene,( image ));

    const rapidjson::Value& entities = document["Entities"];
    
    for( unsigned int i = 0; i < entities.Size(); i++ )
    {
        IEntity* newEntity = IEntityFactory::Instance().GetEntity( &entities[i], error ); 
        if( error == OK )
        {
            newEntity->SetParentScene( this );
            newEntity->Init();
            m_entities.Add( newEntity );
        }
    }

    return error; 
}


void BaseScene::End()
{
    for( unsigned int i = 0; i < m_entities.Size(); i++ ) IEntityFactory::Instance().RemoveEntity( m_entities[i] );
    DEL( m_scene );

}

void BaseScene::Update( double elapsedTime )
{
    for( unsigned int i = 0; i < m_entities.Size(); i++ ) m_entities[i]->Update( elapsedTime );
    m_scene->Update( elapsedTime );
}

void BaseScene::Render( double elapsedTime )
{
    m_scene->Render();
}


void BaseScene::AddSprite( Sprite* sprite, Scene::Layer layer )
{
    m_scene->AddSprite( sprite, layer );
}


void BaseScene::RemoveSprite( Sprite* sprite )
{
    m_scene->DeleteSprite( sprite );
}


