#include "../logic/logic.h"

LoadedSample::LoadedSample ( const String* filename, TSample type ) : BaseSample( filename, type )
{
    m_sample   = 0;
    m_channel  = 0;
    m_playing  = false;
}

LoadedSample::~LoadedSample()
{
}

TError LoadedSample::Init()
{
   if( GetFilename() ) 
   {
		const char *file = GetFilename()->ToCString();
		m_sample  = BASS_SampleLoad( FALSE, file, 0, 0, 3, 0 ); 
		m_channel = BASS_ChannelPlay( m_sample, m_playing );
   }

    return OK;
}

void LoadedSample::End ()
{
    BASS_SampleFree(m_sample);
}

void LoadedSample::PlaySample ()
{
    if ( m_playing ) BASS_Start();
    else
    {
        m_channel = BASS_SampleGetChannel( m_sample, FALSE );
		BOOL ret = BASS_ChannelPlay(m_channel, FALSE); 
		int err =BASS_ErrorGetCode();

		int x = 0;
    }
}

void LoadedSample::PauseSample()
{
    BASS_Pause();
    m_playing = true;
}

void LoadedSample::StopSample ()
{
    BASS_Stop();
}
