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

    InputComponent*  input    = IComponentFactory::Instance().GetComponent<InputComponent> ( error );

    if( error != OK )
    {
        IComponentFactory::Instance().RemoveComponent( input );
        return error;
    }

    SpriteComponent* sprite   = IComponentFactory::Instance().GetComponent<SpriteComponent>( error );

    if( error != OK )
    {
        IComponentFactory::Instance().RemoveComponent( sprite );
        return error;
    }

    BoundComponent* bound   = IComponentFactory::Instance().GetComponent<BoundComponent>( error );

    if( error != OK )
    {
        IComponentFactory::Instance().RemoveComponent( bound );
        return error;
    }

    LabelComponent* label   = IComponentFactory::Instance().GetComponent<LabelComponent>( error );

    if( error != OK )
    {
        IComponentFactory::Instance().RemoveComponent( label );
        return error;
    }

    if( error != OK )
    {
        IComponentFactory::Instance().RemoveComponent( bound );
        return error;
    }

    if( GetParams().HasMember( "Image"     ) )    sprite->SetImage   ( String( GetParams()["Image"].GetString() ) );
    if( GetParams().HasMember( "X"         ) && 
        GetParams().HasMember( "Y"         ) ) 
    {		
        sprite->SetPosition( GetParams()["X"].GetDouble(), GetParams()["Y"].GetDouble() );
		bound->SetMinBound ( GetParams()["X"].GetDouble(), GetParams()["Y"].GetDouble() );
		bound->SetMaxBound ( GetParams()["X"].GetDouble() + sprite->GetImage()->GetWidth(), GetParams()["Y"].GetDouble() + sprite->GetImage()->GetHeight() );
        label->SetPosition ( GetParams()["X"].GetDouble(), GetParams()["Y"].GetDouble() );
    }
    if( GetParams().HasMember( "NextScene"  ) )    m_sceneIndex = GetParams()["NextScene"].GetInt();
    if( GetParams().HasMember( "Label"      ) )    label->SetLabel( String( GetParams()["Label"].GetString() ) ); 
    if( GetParams().HasMember( "Font"       ) )    label->SetFont ( &String( GetParams()["Font"].GetString() ) ); 
    if( GetParams().HasMember( "r"          ) &&
        GetParams().HasMember( "g"          ) &&
        GetParams().HasMember( "b"          ) )
    {
        if( GetParams().HasMember( "a"      ) )     label->SetColor( GetParams()["r"].GetInt(), GetParams()["g"].GetInt(), GetParams()["b"].GetInt(), GetParams()["a"].GetInt() );
        else                                        label->SetColor( GetParams()["r"].GetInt(), GetParams()["g"].GetInt(), GetParams()["b"].GetInt()                            );
    }

    AddComponent( bound );
    AddComponent( input );
    AddComponent( sprite );
    AddComponent( label );

    BaseEntity::Init();

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

    InputComponent* input = GetComponentByType<InputComponent>( IComponent::EInput ); 
    BoundComponent* bound = GetComponentByType<BoundComponent>( IComponent::EBound ); 

    if( bound && input ) if( input->IsMouseButtonPressed( CLICK ) ) if( bound->IsInBounds() ) SceneManager::Instance().SetScene( m_sceneIndex );

}