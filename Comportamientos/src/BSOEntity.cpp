#include "../logic/logic.h"


BSOEntity::BSOEntity(  const rapidjson::Value* params ) : BaseEntity( params )
{
    m_sample = NULL;
}

BSOEntity::~BSOEntity()
{
}

TError BSOEntity::Init()
{
    TError error = OK;

     if( GetParams().HasMember( "Sample" ) )
     {    
         String c = GetParams()["Sample"].GetString();
         const String* path = &c;
         m_sample = ISoundFactory::Instance().CreateSample( ISample::ELoaded, path ,error );
         m_sample->Init();
     }

     ISoundManager::Instance().PlaySample( m_sample );

     return error;
}

void BSOEntity::End ()
{
//    assert( m_sample == NULL );
	ISoundManager::Instance().StopSample( m_sample );
    ISoundFactory::Instance().RemoveSample( m_sample );
}

void BSOEntity::Update( double elapsedTime )
{
}