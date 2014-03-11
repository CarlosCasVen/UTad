#ifndef ___SCENEMANAGER____
#define ___SCENEMANAGER____

#include "ISceneManager.h"
#include "Utils/rapidjson/document.h"
class CBaseScene;

class CSceneManager : public ISceneManager
{
public:

	virtual int  init();
	virtual void end ();

	virtual void update(float fDelta);
	virtual void render(float fDelta);

	virtual void setNextScene	();
	virtual void prevNextScene();
	virtual void setScene			(IScene::TScene nScene);

private:
	CSceneManager();
	~CSceneManager();

	CBaseScene *				m_pCurrScene;
	char *							m_pszJSON;
	rapidjson::Document m_docJSON;

	friend class ISceneManager;
};

#endif