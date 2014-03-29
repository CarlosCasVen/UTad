#include "../logic/Logic.h"


EntitiesFactory* EntitiesFactory::m_entitiesFactory = NULL;

EntitiesFactory& EntitiesFactory::Instance()
{
	if( !m_entitiesFactory )
	{
		m_entitiesFactory = new EntitiesFactory();
	}

	return *m_entitiesFactory;
}
	

BaseEntity* EntitiesFactory::CreateEntity( const TEntity type )
{
	BaseEntity* entity = NULL;
	switch( type )
	{
	case Hero:
		{
			//crear entidad heroe
			break;
		}
	default:
	}

	return entity;
}
	

bool EntitiesFactory::DeleteEntity ( BaseEntity* entity )
{
	if( entity != NULL )
	{
		m_entities.Remove( entity );
		return true;
	}
	else
	{
		return false;
	}
}