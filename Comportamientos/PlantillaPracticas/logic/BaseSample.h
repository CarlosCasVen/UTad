#ifndef __BASE_SAMPLE__
#define __BASE_SAMPLE__

#include "ISample.h"
#include "../json/rapidjson/document.h"

enum TError;
class String;


class BaseSample : public ISample
{
public:
    BaseSample ( const String* filename, TSample type );
	~BaseSample();

	virtual TError Init() = 0;
	virtual void   End () = 0;

	virtual unsigned long int GetId  () const;
    virtual TSample           GetType() const;

    virtual void PlaySample ()            = 0;
    virtual void PauseSample()            = 0;
    virtual void StopSample ()            = 0;

protected:
    const String* GetFilename() const;

private:
	unsigned int            m_id;
	TSample 		        m_type;
    const String*           m_filename;

};


#endif