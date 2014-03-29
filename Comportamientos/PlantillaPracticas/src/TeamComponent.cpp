#include "../logic/logic.h"


TeamComponent::TeamComponent()
{
    m_teamId = 0xFFFFFFFF;
    SetType( ETeam );
}
    
TeamComponent::~TeamComponent()
{
}

TError TeamComponent::Init()
{
    return OK;
}

void TeamComponent::End ()
{
    m_teamId = 0xFFFFFFFF;
}

void TeamComponent::Update( double elapsedTime )
{
}

void TeamComponent::SetTeam( unsigned int teamId )
{
    m_teamId = teamId;
}

unsigned int TeamComponent::GetTeamId() const
{
    return m_teamId;
}