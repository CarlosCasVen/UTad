#ifndef __BOUND_ELIMINATOR_COMPONENT__
#define __BOUND_ELIMINATOR_COMPONENT__

#include "BaseComponent.h"
#include "../json/rapidjson/document.h"

class BoundEliminatorComponent : public BaseComponent
{
public:
    BoundEliminatorComponent ();
	~BoundEliminatorComponent();

	virtual TError Init();
	virtual void   End ();

	virtual void Update( double elapsedTime );

    void SetMinBound( double x, double y );
    void SetMaxBound( double x, double y );

    bool IsInBounds();

    void SetSprite( Sprite* sprite );

private:
    double        m_xMin, m_xMax;
    double        m_yMin, m_yMax;
    Sprite*       m_sprite;

};

#endif