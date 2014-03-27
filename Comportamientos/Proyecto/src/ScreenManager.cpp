#include "../logic/logic.h"
#include "../include/u-gine.h"


IScreenManager* m_screenManager = NULL;

IScreenManager& IScreenManager::Instance()
{
    if( !m_screenManager ) m_screenManager = NEW( ScreenManager, () );

    return *m_screenManager;
}


TError ScreenManager::Init()
{
    m_percentX = Screen::Instance().GetWidth () / DEFAULT_WIDTH;
    m_percentX = Screen::Instance().GetHeight() / DEFAULT_HEIGHT;

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

ScreenManager::ScreenManager()
{
    m_percentX = m_percentY = 1;
}
 
ScreenManager::~ScreenManager()
{
}