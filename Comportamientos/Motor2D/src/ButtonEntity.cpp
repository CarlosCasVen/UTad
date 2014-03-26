#include "../logic/logic.h"
#include "../include/u-gine.h"

#define CLICK eInputCode::Mouse_Button0

//-------------------------------------
//
//-------------------------------------
ButtonEntity::ButtonEntity(  const rapidjson::Value* params ) : BaseEntity( params )
{
   
}

//-------------------------------------
//
//-------------------------------------
ButtonEntity::~ButtonEntity()
{
}


//-------------------------------------
//
//-------------------------------------
TError ButtonEntity::Init()
{
    TError error = OK;

    

    return error;
}
  
//-------------------------------------
//
//-------------------------------------
void ButtonEntity::End()
{
    BaseEntity::End();
}

//-------------------------------------
//
//-------------------------------------
void ButtonEntity::Update( double elapsedTime )
{
    BaseEntity::Update( elapsedTime );

    InputComponent* input = NULL;
    BoundComponent* bound = NULL;

    input = GetComponentByType<InputComponent>( IComponent::EInput ); 
    bound = GetComponentByType<BoundComponent>( IComponent::EBound ); 

    if( bound && input ) if( input->IsMouseButtonPressed( CLICK ) && bound->IsInBounds() ) SceneManager::Instance().SetScene( m_sceneIndex );

}