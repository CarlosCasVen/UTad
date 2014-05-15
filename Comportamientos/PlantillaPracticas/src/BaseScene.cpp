#include "../logic/logic.h"
#include "../include/u-gine.h"
#undef ERROR

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
    if( !document.HasMember("Image") || !document.HasMember("Entities") ) error = ERROR;

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
		m_entities.Remove( m_entities[i] );
		IEntityFactory::Instance().RemoveEntity( entityToDelete );
	}

    m_labels.Clear();
    m_labelsToDelete.Clear();

	DEL( m_scene );
}

//-------------------------------------
//
//-------------------------------------
void BaseScene::Update( double elapsedTime )
{
	DestroyEntities();
    DestroySprites ();
    DestroyLabels  ();
    AddEntities    ();

    for( unsigned int i = 0; i < m_entities.Size(); i++ ) m_entities[i]->Update( elapsedTime );
    
	if( m_scene )m_scene->Update( elapsedTime );

}

//-------------------------------------
//
//-------------------------------------
void BaseScene::Render()
{
    m_scene->Render();
    for( unsigned int i = 0; i < m_labels.Size(); i++ ) m_labels[ i ]->Render();
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
    m_spriteToDelete.Add( sprite );
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

//-------------------------------------
//
//-------------------------------------
void BaseScene::RemoveEntity( IEntity* entity )
{
	m_entitiesToDelete.Add( entity );
}

//-------------------------------------
//
//-------------------------------------
void BaseScene::DestroyEntities ()
{
	for( int i = m_entitiesToDelete.Size() - 1 ; i >= 0; i-- )
	{
		m_entitiesToDelete[i]->End();
		m_entities.Remove( m_entitiesToDelete[i] );
		IEntityFactory::Instance().RemoveEntity( m_entitiesToDelete[i] );
	}
	m_entitiesToDelete.Clear();
}

//-------------------------------------
//
//-------------------------------------
void BaseScene::AddEntity ( IEntity* entity )
{
    m_entitiesToAdd.Add( entity );
}

//-------------------------------------
//
//-------------------------------------
void BaseScene::AddEntities()
{
    for( unsigned int i = 0; i < m_entitiesToAdd.Size(); i++ ) m_entities.Add( m_entitiesToAdd[i] );
    m_entitiesToAdd.Clear();
}

//-------------------------------------
//
//-------------------------------------
void BaseScene::DestroySprites()
{
    for( unsigned int i = 0 ; i < m_spriteToDelete.Size(); i++ ) m_scene->DeleteSprite( m_spriteToDelete[i] );
    m_spriteToDelete.Clear();
}

//-------------------------------------
//
//-------------------------------------
void BaseScene::AddFont( LabelComponent* labelComponent )
{
    m_labels.Add( labelComponent );
}

//-------------------------------------
//
//-------------------------------------
void BaseScene::RemoveFont( LabelComponent* labelComponent )
{
    m_labelsToDelete.Add( labelComponent );
}

//-------------------------------------
//
//-------------------------------------
void BaseScene::DestroyLabels()
{
    for( unsigned int i = 0 ; i <  m_labelsToDelete.Size(); i++ ) m_labels.Remove( m_labelsToDelete[ i] );
    m_labelsToDelete.Clear();
}