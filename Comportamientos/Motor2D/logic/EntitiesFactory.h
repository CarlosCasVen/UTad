#include <stdio.h>


class EntitiesFactory
{
public:
	EntitiesFactory& Instance(){  if( m_entitiesFactory == NULL ) m_entitiesFactory = new EntitiesFactory(); return *m_entitiesFactory; }

private:
	EntitiesFactory(){ m_entitiesFactory = NULL; }

	EntitiesFactory* m_entitiesFactory;

};
