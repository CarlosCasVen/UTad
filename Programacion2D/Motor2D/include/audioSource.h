#include "audioBuffer.h"

class AudioSource 
{ 
public: 
   AudioSource(AudioBuffer* buffer); 
   ~AudioSource(); 
   
   void SetPitch(float pitch); 
   void SetGain(float gain); 
   void SetLooping(bool loop); 
   void SetPosition(float x, float y, float z); 
   void SetVelocity(float x, float y, float z); 
   
   void Play(); 
   void Stop(); 
   void Pause(); 
 
   bool IsPlaying() const; 

private: 
    unsigned int source; 
    AudioBuffer* buffer;
};