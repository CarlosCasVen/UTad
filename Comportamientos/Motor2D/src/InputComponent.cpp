#include "../logic/logic.h"
#include "../include/u-gine.h"

//-------------------------------------
//
//-------------------------------------
InputComponent::InputComponent() :BaseComponent()
{
    SetType( EInput );
}

//-------------------------------------
//
//-------------------------------------
InputComponent::~InputComponent()
{
}

//-------------------------------------
//
//-------------------------------------
TError InputComponent::Init()
{
    TError error = OK;

    #define TYPE EInputComponent \
    SetType( TYPE );
    #undef TYPE
    
    return error;
}

//-------------------------------------
//
//-------------------------------------
void InputComponent::End()
{
}

//-------------------------------------
//
//-------------------------------------
void InputComponent::Update( double elapsedTime )
{
}

//-------------------------------------
//
//-------------------------------------
bool InputComponent::IsButtonPressed( eInputCode key ) const
{
    return InputManager::Instance().IsKeyPressed( key );
}

//-------------------------------------
//
//-------------------------------------
bool InputComponent::IsButtonDown( eInputCode key ) const
{
    return InputManager::Instance().IsKeyDown( key );
}

//-------------------------------------
//
//-------------------------------------
bool InputComponent::IsButtonUp( eInputCode key ) const
{
    return InputManager::Instance().IsKeyUp( key );
}

//-------------------------------------
//
//-------------------------------------
bool InputComponent::IsMouseButtonPressed( eInputCode key ) const
{
    return InputManager::Instance().IsMouseButtonPressed( key );
}

//-------------------------------------
//
//-------------------------------------
float InputComponent::GetMouseX() const
{
    return static_cast<float>(Screen::Instance().GetMouseX());
}

//-------------------------------------
//
//-------------------------------------
float InputComponent::GetMouseY() const
{
    return static_cast<float>(Screen::Instance().GetMouseY());
}