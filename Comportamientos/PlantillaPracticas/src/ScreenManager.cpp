#include "../logic/logic.h"
#include "../include/u-gine.h"

const double DEFAULT_WIDTH  = 1920;
const double DEFAULT_HEIGHT = 1080;

IScreenManager* m_screenManager = NULL;

IScreenManager& IScreenManager::Instance()
{
    if( !m_screenManager ) m_screenManager = NEW( ScreenManager, () );

    return *m_screenManager;
}


TError ScreenManager::Init()
{
    m_percentX = Screen::Instance().GetWidth () / DEFAULT_WIDTH;
    m_percentY = Screen::Instance().GetHeight() / DEFAULT_HEIGHT;

    return OK;
}

void ScreenManager::End()
{
    assert( m_screenManager == NULL );
    DEL( m_screenManager );
}

double ScreenManager::TransformToScreenPointX( double x )
{
    return x * m_percentX;
}

double ScreenManager::TransformToScreenPointY( double y )
{
    return y * m_percentY;
}

double ScreenManager::TransformToWorldPointX( double x )
{
    return x / m_percentX;
}

double ScreenManager::TransformToWorldPointY( double y ) 
{
    return y / m_percentY;
}

ScreenManager::ScreenManager()
{
    m_percentX = m_percentY = 1;
}
 
ScreenManager::~ScreenManager()
{
}