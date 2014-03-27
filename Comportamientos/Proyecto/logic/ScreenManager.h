#ifndef __SCREEN_MANAGER__
#define __SCREEN_MANAGER__

#define DEFAULT_WIDTH 1920
#define DEFAULT_HEIGHT 1080

#include "IScreenManager.h"

enum TError;


class ScreenManager : public IScreenManager
{
public:
    virtual TError Init();
	virtual void   End ();

	virtual double TransformToScreenPointX( double x );
    virtual double TransformToScreenPointY( double y );

private:
    ScreenManager ();
    ~ScreenManager();

    double m_percentX;
    double m_percentY;

    friend class IScreenManager;
};


#endif