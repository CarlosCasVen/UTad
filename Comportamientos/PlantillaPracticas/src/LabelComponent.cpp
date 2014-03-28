#include "../logic/logic.h"
#include "../include/u-gine.h"


LabelComponent::LabelComponent()
{
    m_label  = NULL;
    m_sprite = NULL;
}
	
LabelComponent::~LabelComponent()
{
}

TError LabelComponent::Init()
{
    return OK;
}

void LabelComponent::End()
{
}

void LabelComponent::Update( double elapsedTime )
{
}

void LabelComponent::SetLabel( const String* label )
{
    m_label = label;
}

void LabelComponent::SetSprite( Sprite* sprite )
{
    m_sprite = sprite;
}