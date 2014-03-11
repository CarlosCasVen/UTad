#ifndef __ICOMPONENTSFACTORY___
#define __ICOMPONENTSFACTORY___

#include "Utils/rapidjson/document.h"

class IComponent;

class IComponentsFactory
{
public:

		enum TType
	{
#define REG_COMPONENT(val, name) \
		E##val,
#include "REG_COMPONENTS.h"
#undef REG_COMPONENT

		// La última.
		EInvalid,
	};

	static IComponentsFactory *get();

	virtual int  init() = 0;
	virtual void end () = 0;

	virtual int	addClassesInfo(const rapidjson::Value *pInfo) = 0;

	virtual IComponent *	getComponent		(TType nType)										= 0;
	virtual IComponent *	getComponent		(const rapidjson::Value *pInfo)	= 0;
	virtual IComponent *	getComponent		(const char *pszClassName)			= 0;
	virtual void					releaseComponent(IComponent *pEntity)						= 0;
};

#endif