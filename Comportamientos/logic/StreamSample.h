#ifndef __STREAM_SAMPLE__
#define __STREAM_SAMPLE__

#include "BaseSample.h"
#include "../json/rapidjson/document.h"
#include "../bass/bass.h"

enum TError;
class String;


class StreamSample : public BaseSample
{
public:
    StreamSample ( const String* filename, TSample type );
	~StreamSample();

	virtual TError Init();
	virtual void   End ();

    virtual void PlaySample ();
    virtual void PauseSample();
    virtual void StopSample ();

private:
    HSTREAM m_stream;
    bool    m_playing;
};


#endif