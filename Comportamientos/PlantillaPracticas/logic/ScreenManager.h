#ifndef __SCREEN_MANAGER__
#define __SCREEN_MANAGER__

#include "IScreenManager.h"

enum TError;


class ScreenManager : public IScreenManager
{
public:
    virtual TError Init();
	virtual void   End ();

	virtual double TransformToScreenPointX( double x );
    virtual double TransformToScreenPointY( double y );

    virtual double TransformToWorldPointX( double x );
    virtual double TransformToWorldPointY( double y );

private:
    ScreenManager ();
    ~ScreenManager();

    double m_percentX;
    double m_percentY;

    friend class IScreenManager;
};


#endif