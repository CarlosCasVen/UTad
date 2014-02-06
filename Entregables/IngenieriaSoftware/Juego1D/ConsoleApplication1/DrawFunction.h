#ifndef __DRAW_FUNCTION__
#define __DRAW_FUNCTION__

#include "stdafx.h"


namespace DrawFunction
{
	void Gotoxy( int x, int y );
	void Hidecursor( void );
	void Clear();
	void GameOver( unsigned int score, unsigned int nBullets );
	void PrintWorld();
	void PrintSimbolInWorld( char simbol );
}

#endif