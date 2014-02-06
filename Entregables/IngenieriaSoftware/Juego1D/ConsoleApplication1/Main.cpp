// Main.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

//---------------------------------------------

//---------------------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
	World world;
	world.Init();

	if( world.GetIsOk() )
	{
		while( true )
		{
			Sleep( SLEEP_DURATION_TIME );
			world.Update();
			world.Render();
		}
	}

	return 0;
}

