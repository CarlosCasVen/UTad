#ifndef __ISCREEN_MANAGER__
#define __ISCREEN_MANAGER__

enum TError;


class IScreenManager
{
public:
    static IScreenManager& Instance();

	virtual TError  Init()  = 0;
	virtual void    End ()  = 0;

	virtual double TransformToScreenPointX( double x ) = 0;
    virtual double TransformToScreenPointY( double y ) = 0;

    virtual double TransformToWorldPointX( double x ) = 0;
    virtual double TransformToWorldPointY( double y ) = 0;
};  


#endif