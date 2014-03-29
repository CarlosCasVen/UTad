#include "../include/array.h"


class BaseEntity;


class EntityEliminator
{
public:
	static EntityEliminator& Instance();
	bool RegistrerEntity( BaseEntity* entity );
	void Update();

private:
	EntityEliminator();

	static EntityEliminator* m_entityEliminator;
	Array<BaseEntity*> m_entitiesToDelete;
};