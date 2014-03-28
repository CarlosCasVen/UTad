#include "../logic/logic.h"
#undef ERROR

StreamSample::StreamSample ( const String* filename, TSample type ) : BaseSample( filename, type )
{
    m_playing = false;
    String c = *GetFilename();
}
	
StreamSample::~StreamSample()
{
}

TError StreamSample::Init()
{
    if ( GetFilename() )
	{
		const char *file = GetFilename()->ToCString();
		m_stream = BASS_StreamCreateFile(FALSE, file, 0, 0 , 0);
	}
	else
	{
		return TError::ERROR;
	}

    return OK;
}

void StreamSample::End()
{
    BASS_StreamFree( m_stream );
}

void StreamSample::PlaySample ()
{
    BASS_ChannelPlay( m_stream, m_playing );
}

void StreamSample::PauseSample()
{
    BASS_Pause();
    m_playing = true;
}

void StreamSample::StopSample ()
{
    BASS_Stop();
}