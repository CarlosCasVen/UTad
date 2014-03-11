#ifndef ___IWORLD____
#define ___IWORLD____

// ******************************************************************************
// Interfaz que proporciona acceso a las funcionalidades del mundo donde 
// residen todas las entidades.
// ******************************************************************************
#include "ISpritesFactory.h"

class  IEntity;
struct TMessage;

class IScene
{
public:

	enum TScene
	{
		EMenuScene,
		EGameScene,
	};

	virtual TScene getType() = 0;

	virtual int  init() = 0;

	virtual bool activate(bool bActivate) = 0;

	virtual void update(float fDelta) = 0;
	virtual void render(float fDelta) = 0;

	virtual int  addSprite		(ISpritesFactory::TSpriteInfo *pSprite) = 0;
	virtual void removeSprite	(ISpritesFactory::TSpriteInfo *pSprite) = 0;

	virtual IEntity *	getEntity			(const char *pszId			) = 0;
	virtual IEntity *	getEntity			(unsigned int uId				) = 0;
	virtual void			manageMessage	(TMessage *pMessageInfo	) = 0;
};

#endif