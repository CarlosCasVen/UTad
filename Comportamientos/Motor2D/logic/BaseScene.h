#include <stdio.h>
#include "../include/array.h"
#include "baseEntity.h"


class BaseScene
{
public:
	virtual void LoadScene() = 0;

private:
	Array<BaseEntity*> entitiesInWorld;
};