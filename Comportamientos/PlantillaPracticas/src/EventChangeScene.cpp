#include "../logic/EventChangeScene.h"

EventChangeScene::EventChangeScene( unsigned int index ) : Event( ChangeScene )
{
	m_index = index;
}

EventChangeScene::~EventChangeScene()
{
}
    

unsigned int EventChangeScene::GetIndexNextScene() const
{
	return m_index;
}