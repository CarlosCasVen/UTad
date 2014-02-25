#ifndef __SOUND_MANAGER__
#define __SOUND_MANAGER__

#include <stdio.h>


class SoundManager
{
public:
	static SoundManager& Instance();//{  if( m_soundManager == NULL ) m_soundManager = new SoundManager(); return *m_soundManager; }

private:
	SoundManager();//{ m_soundManager = NULL; }

	static SoundManager* m_soundManager;

};

#endif
