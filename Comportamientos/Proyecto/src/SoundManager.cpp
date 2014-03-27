#include "../logic/Logic.h"


ISoundManager* m_soundManager = NULL;


ISoundManager& ISoundManager::Instance()
{
    if( !m_soundManager ) m_soundManager = NEW( SoundManager, () );

    return *m_soundManager;

}

TError SoundManager::Init()
{
    BASS_Init( -1, 44100, 0, 0, NULL );

    return OK;
}

void SoundManager::End()
{
    assert( m_soundManager == NULL );
    BASS_Free();
    DEL( m_soundManager );
}

/*void SoundManager::PlaySound()
{
}*/

void SoundManager::StopSound()
{
}

void SoundManager::PauseSound()
{
}

SoundManager::SoundManager()
{
}

SoundManager::~SoundManager()
{
}