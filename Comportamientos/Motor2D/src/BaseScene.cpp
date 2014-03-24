#include "../logic/logic.h"
#include "../include/u-gine.h"


//-------------------------------------
//
//-------------------------------------
BaseScene::BaseScene( const String* sceneInfo )
{
    m_id        = IIdFactory::Instance().GetId();
    m_sceneInfo = sceneInfo;
}

//-------------------------------------
//
//-------------------------------------
TError BaseScene::Init()
{
    TError error = OK;

    String content = String::Read( m_sceneInfo->ToCString() );

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
        else
        {
            IEntityFactory::Instance().RemoveEntity( newEntity );
        }
    }

    return error; 
}

//-------------------------------------
//
//-------------------------------------
void BaseScene::End()
{
    for( int i = m_entities.Size() -1; i >=  0; i-- ) 
	{
		IEntity* entityToDelete = m_entities[i];
		entityToDelete->End();
		IEntityFactory::Instance().RemoveEntity( entityToDelete );
	}
    m_entities.Clear();
	DEL( m_scene );

}

//-------------------------------------
//
//-------------------------------------
void BaseScene::Update( double elapsedTime )
{
    for( unsigned int i = 0; i < m_entities.Size(); i++ ) m_entities[i]->Update( elapsedTime );
    m_scene->Update( elapsedTime );
}

//-------------------------------------
//
//-------------------------------------
void BaseScene::Render()
{
    m_scene->Render();
}

//-------------------------------------
//
//-------------------------------------
void BaseScene::AddSprite( Sprite* sprite, Scene::Layer layer )
{
    m_scene->AddSprite( sprite, layer );
}

//-------------------------------------
//
//-------------------------------------
void BaseScene::RemoveSprite( Sprite* sprite )
{
    m_scene->DeleteSprite( sprite );
}

//-------------------------------------
//
//-------------------------------------
void BaseScene::ReceiveEvent ( Event& newEvent )
{
}

//-------------------------------------
//
//-------------------------------------
unsigned long int BaseScene::GetListenerId() const
{
    return m_id;
}

