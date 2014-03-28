#ifndef __DAMAGE_COMPONENT__
#define __DAMAGE_COMPONENT__

#include "BaseComponent.h"
#include "../json/rapidjson/document.h"


class DamageComponent : public BaseComponent
{
public:
    DamageComponent ();
	~DamageComponent();

	virtual TError Init();
	virtual void   End ();

	virtual void Update( double elapsedTime );

    void         SetDamage( unsigned int damage );
    unsigned int GetDamage();

private:
    unsigned int m_damage;

};

#endif