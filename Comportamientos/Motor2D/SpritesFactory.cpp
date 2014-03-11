#include "stdafx.h"
#include "SpritesFactory.h"
#include "include/image.h"
#include "include/sprite.h"

ISpritesFactory *g_SP = NULL;

ISpritesFactory * ISpritesFactory::get()
{
	if (!g_SP)
		g_SP = NEW(CSpritesFactory, ());

	return g_SP;
}

CSpritesFactory::CSpritesFactory()
{
	m_pSpritesInfo	= NULL;
	m_pImagesInfo		= NULL;
}

// **********************************************************************************
//
// **********************************************************************************
int CSpritesFactory::init()
{
	return RET_OK;
}

// **********************************************************************************
//
// **********************************************************************************
void CSpritesFactory::end()
{
	SAFE_DELETE(g_SP);
}

// **********************************************************************************
//
// **********************************************************************************
int	CSpritesFactory::addInfo(const rapidjson::Value *pInfo)
{
	if (pInfo)
	{
		m_pImagesInfo		= &(*pInfo)["images"];
		m_pSpritesInfo	= &(*pInfo)["sprites"];
	}
	return 0;
}

// **********************************************************************************
//
// **********************************************************************************
ISpritesFactory::TSpriteInfo *CSpritesFactory::getSprite(const char *pszName)
{
	ISpritesFactory::TSpriteInfo *pRet = NULL;

	if (m_pSpritesInfo && pszName)
	{
		int i						= 0;
		int iNumSprites = (*m_pSpritesInfo).Size();
		while (!pRet  && (i < iNumSprites))
		{
			const rapidjson::Value &currSpriteInfo = (*m_pSpritesInfo)[i];
			if (!strcmp(pszName, currSpriteInfo["name"].GetString()))
				pRet = createSpriteWithInfo(currSpriteInfo);
			else
				i++;
		}
	}

	return pRet;
}

// **********************************************************************************
//
// **********************************************************************************
void CSpritesFactory::releaseSprite(TSpriteInfo *pSprite)
{
	if (pSprite)
	{
		DEL(pSprite->m_pSprite);
		if (pSprite->m_pImage)
			releaseImage(pSprite->m_pImage);

		DEL(pSprite);
	}
}

// **********************************************************************************
//
// **********************************************************************************
ISpritesFactory::TSpriteInfo *CSpritesFactory::createSpriteWithInfo(const rapidjson::Value &Info)
{
	ISpritesFactory::TSpriteInfo *pRet = NULL;

	Image *pImage = getImage(Info["image"].GetString());
	

	pRet = NEW (TSpriteInfo, ());
	ASSERT(pRet);
	if (pRet)
	{
		pRet->m_pSprite = NEW(Sprite, (pImage));
		pRet->m_pImage	= pImage;
		pRet->m_nLayer	= getLayerByName(Info["layer"].GetString());
	}

	return pRet;
}

// **********************************************************************************
//
// **********************************************************************************
Scene::Layer CSpritesFactory::getLayerByName(const char *pszName)
{
	return Scene::LAYER_FRONT;
}

// **********************************************************************************
//
// **********************************************************************************
Image *CSpritesFactory::getImage(const char *pszName)
{
	Image *pRet = NULL;

	if (m_pImagesInfo && pszName)
	{
		int i						= 0;
		int iNumImages = (*m_pImagesInfo).Size();
		while (!pRet  && (i < iNumImages))
		{
			const rapidjson::Value &currImageInfo = (*m_pImagesInfo)[i];
			if (!strcmp(pszName, currImageInfo["name"].GetString()))
				pRet = createImageWithInfo(currImageInfo);
			else
				i++;
		}
	}

	return pRet;
}

// **********************************************************************************
//
// **********************************************************************************
void	CSpritesFactory::releaseImage(Image *pImage)
{
	DEL(pImage);
}

// **********************************************************************************
//
// **********************************************************************************
Image *CSpritesFactory::createImageWithInfo(const rapidjson::Value &Info)
{
	Image *pRet = NULL;

	String strFile = Info["file"].GetString();

	pRet = NEW(Image, (strFile));

	return pRet;
}