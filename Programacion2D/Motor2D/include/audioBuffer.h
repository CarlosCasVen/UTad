#ifndef __H_AUDIOBUFFER__
#define __H_AUDIOBUFFER__

#include "string.h"

class AudioBuffer 
{ 
public: 
    AudioBuffer(const String& filename); 
    ~AudioBuffer(void); 
    
    bool IsValid() const { return alBuffer != 0; }
    unsigned int GetBuffer() const { return alBuffer; } 

	virtual const String& GetFilename() const { return filename; }

private: 
    unsigned int alBuffer;
	String filename;
};


#endif