#include "../logic/logic.h"


DamageComponent::DamageComponent()
{
    SetType( EDamage );
    m_damage = 0xFFFFFFFF;
}

DamageComponent::~DamageComponent()
{
}

TError DamageComponent::Init()
{
    return OK;
}

void DamageComponent::End()
{
    m_damage = 0xFFFFFFFF;
}

void DamageComponent::Update( double elapsedTime )
{
}

void DamageComponent::SetDamage( unsigned int damage )
{
    m_damage = damage;
}

unsigned int DamageComponent::GetDamage()
{
    return m_damage;
}
