#ifndef ___PLAYERCONTROLLERCOMPONENT___
#define ___PLAYERCONTROLLERCOMPONENT___

#include "BaseComponent.h"

class CPlayerControllerComponent : public CBaseComponent
{
public:
	// Ejecuci�n
	virtual void											update						(float fDelta);

	virtual void											activate					(bool bActivate);

	// Recepci�n de mensages
	virtual bool											manageEvent				(TBaseEvent *pMessage);

private:

	 CPlayerControllerComponent(unsigned int uId, const rapidjson::Value *pInfo);
	~CPlayerControllerComponent();

	bool m_bLeftPressed;
	bool m_bRightPressed;
	bool m_bUpPressed;
	bool m_bDownPressed;

	friend class CComponentsFactory;
};

#endif