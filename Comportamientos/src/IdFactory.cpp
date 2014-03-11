#include "../logic/logic.h"


IdFactory* m_factory = NULL;
unsigned long int m_id = 0;


//-------------------------------------
//
//-------------------------------------
IIdFactory& IIdFactory::Instance()
{
    if( !m_factory ) m_factory = NEW( IdFactory, () );

    return *m_factory;
}


//-------------------------------------
//
//-------------------------------------
TError IdFactory::Init()
{
    TError error = OK;

    return error;
}
    

//-------------------------------------
//
//-------------------------------------
void IdFactory::End()
{
    DEL( m_factory );
}


//-------------------------------------
//
//-------------------------------------
unsigned long int IdFactory::GetId()
{
    return GenerateId();
}
    

//-------------------------------------
//
//-------------------------------------
unsigned long int IdFactory::GenerateId()
{
    m_id++;
}