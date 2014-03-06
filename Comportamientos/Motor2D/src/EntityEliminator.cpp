#include "../logic/Logic.h"


EntityEliminator* EntityEliminator::m_entityEliminator = NULL;


EntityEliminator& EntityEliminator::Instance()
{
	if( !m_entityEliminator )
	{
		m_entityEliminator = NEW( EntityEliminator, );
	}
	return *m_entityEliminator;
}
	

bool EntityEliminator::RegistrerEntity( BaseEntity* entity )
{
}
	

void EntityEliminator::Update()
{
}

	
EntityEliminator::EntityEliminator()
{
}