#ifndef ___BASESCENE____
#define ___BASESCENE____

#include "../IScene.h"
#include "../Utils/rapidjson/document.h"
#include "../ISpritesFactory.h"
#include <vector>

class Scene;
class IEntity;
// ***********************************************************************************
//
// ***********************************************************************************
class CBaseScene : public IScene
{
public:

	virtual ~CBaseScene	();

	// FROM IScene
	virtual TScene getType();

	virtual int  init();

	virtual bool activate(bool bActivate);

	virtual void update(float fDelta);
	virtual void render(float fDelta);

	virtual int	 addSprite		(ISpritesFactory::TSpriteInfo *pSprite);
	virtual void removeSprite	(ISpritesFactory::TSpriteInfo *pSprite);

	virtual IEntity *	getEntity			(const char *pszId			);
	virtual IEntity *	getEntity			(unsigned int uId				);
	virtual void			manageMessage	(TMessage *pMessageInfo	);

protected:

	Scene *getRenderer();

	// Implementada en las heredadas para crear la escena adecuada
	virtual Scene *createRenderer() = 0;

	CBaseScene(TScene nType, rapidjson::Document *pinfo);

	void setRenderer(Scene *pScene);

private:

	void CBaseScene::createEntity(const rapidjson::Value &info);

	Scene *									m_pRenderer;
	rapidjson::Document*		m_pinfo;

	std::vector<IEntity *> m_aEntities;

	TScene m_nType;
};

#endif