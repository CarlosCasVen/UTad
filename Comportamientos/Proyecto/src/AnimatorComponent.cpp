#include "../logic/logic.h"


AnimatorComponent::AnimatorComponent()
{
    SetType( EAnimator );
}
	
AnimatorComponent::~AnimatorComponent()
{
}

	
TError AnimatorComponent::Init()
{
    return OK;
}

void AnimatorComponent::End()
{
}

void AnimatorComponent::Update( double elapsedTime )
{
}

void AnimatorComponent::SetSprite( Sprite* sprite )
{
   // assert( m_sprite == NULL );
    m_sprite = sprite;
}

void AnimatorComponent::SetFrameRange( int firstFrame, int endFrame )
{
   // assert( m_sprite == NULL );
    m_sprite->SetFrameRange( firstFrame, endFrame );
}

void AnimatorComponent::SetFPS( int fps )
{
   // assert( m_sprite == NULL );
    m_sprite->SetFPS( fps );
}