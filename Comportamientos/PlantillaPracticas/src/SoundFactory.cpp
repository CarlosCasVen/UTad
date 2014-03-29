#include "../logic/Logic.h"
#undef ERROR

ISoundFactory* m_soundFactory = NULL;

//-------------------------------------
//
//-------------------------------------
ISoundFactory& ISoundFactory::Instance()
{
    if( !m_soundFactory ) m_soundFactory = NEW( SoundFactory, () );

    return *m_soundFactory;
}

//-------------------------------------
//
//-------------------------------------
TError SoundFactory::Init()
{
    return OK;
}


void SoundFactory::End()
{
    DEL( m_soundFactory );
}

//-------------------------------------
//
//-------------------------------------
ISample* SoundFactory::CreateSample( ISample::TSample type, const String* sample, TError& error )
{
    ISample* newSample = NULL;

    switch( type)
    {
    case ISample::EStream: newSample = NEW( StreamSample, ( sample, type ) ); break;       
    case ISample::ELoaded: newSample = NEW( LoadedSample, ( sample, type ) ); break;
    default:               error = TError::NO_MEMBER;
    }

    if( !newSample ) error = TError::ERROR;
    return newSample;
}

//-------------------------------------
//
//-------------------------------------
void SoundFactory::RemoveSample( ISample* sample)
{
    if( sample ) DEL( sample );
}

//-------------------------------------
//
//-------------------------------------
SoundFactory::SoundFactory()
{
}
 
//-------------------------------------
//
//-------------------------------------
SoundFactory::~SoundFactory()
{
}