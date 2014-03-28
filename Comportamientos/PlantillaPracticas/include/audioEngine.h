#ifndef __H_AUDIOENGINE__
#define __H_AUDIOENGINE__

#include <stdio.h>


class AudioEngine
{
public:
    static AudioEngine& Instance(); 
    
    void Init(); 
    void Finish();

protected:
    AudioEngine(void) : device(NULL), context(NULL){}
    ~AudioEngine(void); 

private: 
    static AudioEngine* engine; 
    void* device; 
    void* context;
};

#endif