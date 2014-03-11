#ifndef __ISPRITEFACTORY___
#define __ISPRITEFACTORY___

#include "include/scene.h"
#include "Utils/rapidjson/document.h"

class Sprite;

class ISpritesFactory
{
public:

	struct TSpriteInfo
	{
		Sprite *			m_pSprite;
		Image  *			m_pImage;		// Sprite image
		Scene::Layer	m_nLayer;		// Sprite layer
		TSpriteInfo()
		{
			m_pSprite = NULL;
			m_pImage	= NULL;
		}
	};

	static ISpritesFactory *get();

	virtual int  init() = 0;
	virtual void end () = 0;

	virtual int						addInfo(const rapidjson::Value *pInfo) = 0;

	virtual TSpriteInfo *	getSprite			(const char *pszName) = 0;
	virtual void					releaseSprite	(TSpriteInfo *pSprite)= 0;
};

#endif