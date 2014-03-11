#ifndef __IENTITIESFACTORY___
#define __IENTITIESFACTORY___

#include "Utils/rapidjson/document.h"

class IEntity;

class IEntitiesFactory
{
public:

		enum TType
	{
#define REG_ENTITY(val, name) \
		E##val,
#include "REG_ENTITIES.h"
#undef REG_ENTITY

		// La �ltima.
		EInvalid,
	};

	static IEntitiesFactory *get();

	virtual int  init() = 0;
	virtual void end () = 0;

	// A�ade informaci�n sobre las clases de entidades disponibles
	virtual int	addClassesInfo(const rapidjson::Value *pInfo)		= 0;

	// Crea una entidad del tipo indicado
	virtual IEntity *	getEntity			(TType nType)										= 0;

	// Crea una entidad de la clase indicada
	virtual IEntity *	getEntity			(const char *pszClassName)			= 0;


	// Crea una entidad a partir de la informaci�n en JSON pasada
	virtual IEntity *	getEntity			(const rapidjson::Value *pInfo)	= 0;

	// Da por finializada la utilizaci�n de una entidad.
	virtual void			releaseEntity (IEntity *pEntity)							= 0;
};

#endif