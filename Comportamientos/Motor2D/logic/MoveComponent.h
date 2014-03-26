#ifndef __MOVE_COMPONENT__
#define __MOVE_COMPONENT__

#include "BaseComponent.h"
#include "../json/rapidjson/document.h"

class MoveComponent : public BaseComponent
{
public:
    MoveComponent ();
	~MoveComponent();

	virtual TError Init();
	virtual void   End ();

	virtual void Update( double elapsedTime );

    void SetDirection( double x, double y );
    void SetSpeed    ( double speed  );

    double GetXIncrement() const;
    double GetYIncrement() const;
    double GetSpeed();

private:
    double m_xDirection, m_yDirection;
    double m_x, m_y;
    double m_speed;

};

#endif