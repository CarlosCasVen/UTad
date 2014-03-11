#ifndef ___ISCENEMANAGER____
#define ___ISCENEMANAGER____

#include "IScene.h"

class ISceneManager
{
public:

	static ISceneManager *get();

	virtual int  init() = 0;
	virtual void end () = 0;

	virtual void update(float fDelta) = 0;
	virtual void render(float fDelta) = 0;

	virtual void setNextScene	()											= 0;
	virtual void prevNextScene()											= 0;
	virtual void setScene			(IScene::TScene nScene) = 0;
};

#endif