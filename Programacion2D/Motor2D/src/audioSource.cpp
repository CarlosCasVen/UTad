#include <AL\al.h>
#include "../include/audioSource.h"


AudioSource::AudioSource(AudioBuffer* buffer)
{
    this->buffer = buffer;
    alGenSources( 1, &source );
}


AudioSource::~AudioSource()
{
    alDeleteSources( 1,	&source );	
}


void AudioSource::SetPitch(float pitch)
{
    alSourcef( source, AL_PITCH, pitch );
}


void AudioSource::SetGain(float gain)
{
    alSourcef( source, AL_GAIN, gain );
}


void AudioSource::SetLooping(bool loop)
{
    alSourcei( source, AL_LOOPING, loop );	
}


void AudioSource::SetPosition(float x, float y, float z)
{
    alSource3f( source, AL_POSITION, x, y, z );
}


void AudioSource::SetVelocity(float x, float y, float z)
{
    alSource3f( source, AL_VELOCITY, x, y, z );
}


void AudioSource::Play()
{
    alSourcePlay( source );
}


void AudioSource::Stop()
{
    alSourceStop( source );
}


void AudioSource::Pause()
{
    alSourcePause( source );
}
 

bool AudioSource::IsPlaying() const
{
    ALint isPlaying = false;
    alGetSourcei( source, AL_PLAYING, &isPlaying );

}