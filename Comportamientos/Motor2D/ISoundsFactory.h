#ifndef __ISOUNDSFACTORY___
#define __ISOUNDSFACTORY___

#include "Utils/rapidjson/document.h"

class ISound;

class ISoundsFactory
{
public:
	static ISoundsFactory *get();

	virtual int  init() = 0;
	virtual void end () = 0;

	virtual int			addInfo(const rapidjson::Value *pInfo) = 0;

	virtual ISound *getSound		(const char *pszName)	= 0;
	virtual void		releaseSound(ISound *pSprite)			= 0;
};

#endif