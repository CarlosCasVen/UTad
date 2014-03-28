#include "../logic/logic.h"

//-------------------------------------
//
//-------------------------------------
BaseSample::BaseSample ( const String* filename, TSample type )
{
    m_id       = IIdFactory::Instance().GetId();
    m_filename = filename;
    m_type     = type;
}
	
//-------------------------------------
//
//-------------------------------------
BaseSample::~BaseSample()
{
}

//-------------------------------------
//
//-------------------------------------
unsigned long int BaseSample::GetId() const
{
    return m_id;
}

//-------------------------------------
//
//-------------------------------------
ISample::TSample BaseSample::GetType() const
{
    return m_type;
}

//-------------------------------------
//
//-------------------------------------
const String* BaseSample::GetFilename() const
{
    return m_filename;
}