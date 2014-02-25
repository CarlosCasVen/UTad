#ifndef __ENTITY_FACTORY__
#define __ENTITY_FACTORY__

#include <stdio.h>

class EntitiesFactory
{
public:
	static EntitiesFactory& Instance();

private:
	EntitiesFactory();

	static EntitiesFactory* m_entitiesFactory;

};

#endif