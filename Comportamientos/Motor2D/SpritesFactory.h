#ifndef ___SPRITEFACTORY___
#define ___SPRITEFACTORY___

#include "ISpritesFactory.h"
#include "Utils/rapidjson/document.h"

class CSpritesFactory : public ISpritesFactory
{
public:
	virtual int  init();
	virtual void end ();

	virtual int						addInfo(const rapidjson::Value *pInfo);

	virtual TSpriteInfo *	getSprite			(const char *pszName);
	virtual void					releaseSprite	(TSpriteInfo *pSprite);

	virtual Image *				getImage			(const char *pszName);
	virtual void					releaseImage	(Image *pSprite);

private:

	CSpritesFactory();
	~CSpritesFactory();

	TSpriteInfo *createSpriteWithInfo	(const rapidjson::Value &Info);
	Scene::Layer getLayerByName				(const char *pszName);
	Image *			 createImageWithInfo	(const rapidjson::Value &Info);

	const rapidjson::Value *m_pSpritesInfo;
	const rapidjson::Value *m_pImagesInfo;

	friend class ISpritesFactory;
};

#endif