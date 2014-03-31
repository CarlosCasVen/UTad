#ifndef __WAVE_MOVEMENT_COMPONENT__
#define __WAVE_MOVEMENT_COMPONENT__

#include "BaseComponent.h"
#include "../json/rapidjson/document.h"

class WaveMovementComponent : public BaseComponent
{
public:
    WaveMovementComponent ();
	~WaveMovementComponent();

	virtual TError Init();
	virtual void   End ();

	virtual void Update( double elapsedTime );

    void SetSpeed     ( double speedX   , double speedY    );
    void SetInitialPos( double x        , double y         );
    void SetDistance  ( double distanceX, double distanceY );

    double GetDistanceX() const;
    double GetDistanceY() const;
    double GetSpeedX   () const;
    double GetSpeedY   () const;
    double GetX        () const;
    double GetY        () const;

private:
    double m_x, m_y;
    double m_speedX, m_speedY;
    double m_distanceX, m_distanceY;
    double m_incrementX, m_incrementY;

};

#endif