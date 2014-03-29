#ifndef __BOUND_COMPONENT__
#define __BOUND_COMPONENT__

#include "BaseComponent.h"
#include "../json/rapidjson/document.h"

class BoundComponent : public BaseComponent
{
public:
    BoundComponent ();
	~BoundComponent();

	virtual TError Init();
	virtual void   End ();

	virtual void Update( double elapsedTime );

    void SetMinBound( double x, double y );
    void SetMaxBound( double x, double y );

    bool IsInBounds();

private:
    double m_xMin, m_xMax;
    double m_yMin, m_yMax;

};

#endif