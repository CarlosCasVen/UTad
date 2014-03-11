#ifndef ___BASEENTITY___
#define ___BASEENTITY___

#include "../IEntity.h"
#include "../Utils/rapidjson/document.h"
#include "../ISpritesFactory.h"

class Sprite;
class CBaseScene;
class CBaseEntity : public IEntity
{
public:
	// Carga de los recursos
	virtual int init();

	virtual IEntitiesFactory::TType				getType	();
	virtual unsigned int								  getId		();
	virtual const char *									getName ();

	// Se añde o se quita de la escena
	virtual int  addedToScene			(CBaseScene *pScene);
	virtual void removedFromScene	();

	// Ejecución
	virtual void update(float fDelta);

	virtual int getPosX();
	virtual int getPosY();
	virtual int getPosZ();
	virtual void setPos(int x, int y, int z);

	virtual bool manageEvent(TBaseEvent *pMessage);

protected:
	CBaseEntity(IEntitiesFactory::TType nType, unsigned int uId, const rapidjson::Value *pInfo);
	virtual ~CBaseEntity();

	ISpritesFactory::TSpriteInfo	*	getDefaultSprite();
	const rapidjson::Value *				getInfo					();

private:
	void freeResources();

	const rapidjson::Value *m_pInfo;

	CBaseScene *m_pScene;

	ISpritesFactory::TSpriteInfo	*m_pSpriteInfo;
	IEntitiesFactory::TType				 m_nType;
	unsigned int									 m_uId;
	const char *									 m_pszName;

	int														 m_iPosX;
	int														 m_iPosY;
	int														 m_iPosZ;

	friend class CEntitiesFactory;
};

#endif