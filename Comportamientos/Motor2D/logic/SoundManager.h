#include <stdio.h>


class SoundManager
{
public:
	SoundManager& Instance(){  if( m_soundManager == NULL ) m_soundManager = new SoundManager(); return *m_soundManager; }

private:
	SoundManager(){ m_soundManager = NULL; }

	SoundManager* m_soundManager;

};
