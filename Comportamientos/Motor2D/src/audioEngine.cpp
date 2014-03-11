#include "../include/audioEngine.h"
#include <AL/alc.h>

AudioEngine* AudioEngine::engine = NULL;


AudioEngine& AudioEngine::Instance()
{
    if( !engine )
    {
        engine = new AudioEngine();
    }

    return *engine;
}


void AudioEngine::Init()
{   
    device = alcOpenDevice( NULL );
    context = alcCreateContext( (ALCdevice*)device, NULL );
    alcMakeContextCurrent( (ALCcontext*)context );
}


void AudioEngine::Finish()
{
    alcDestroyContext( (ALCcontext*)context );
    alcCloseDevice( (ALCdevice*)device );
}


AudioEngine::~AudioEngine(void)
{
    delete engine;
}