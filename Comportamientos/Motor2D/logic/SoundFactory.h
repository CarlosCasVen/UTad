#include <stdio.h>


class SoundFactory
{
public:
	SoundFactory& Instance(){  if( m_soundFactory == NULL ) m_soundFactory = new SoundFactory(); return *m_soundFactory; }

private:
	SoundFactory(){ m_soundFactory = NULL; }

	SoundFactory* m_soundFactory;

};
