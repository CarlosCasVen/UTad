// JuegoIngSoft.cpp: define el punto de entrada de la aplicaci�n de consola.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	World world;
	world.Init();

	while( true )
	{
		Sleep( 10 );
		world.Update();
		world.Render();
	}
	return 0;
}

