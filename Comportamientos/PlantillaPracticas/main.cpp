#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#pragma warning( disable : 4065  05 )

#include "include/u-gine.h"
#include "logic/logic.h"
#include "bass\bass.h"

const float POS_INCREMENT = 0.2f;
const float PITCH_INCREMENT = 0.2f;

int	main(int	argc,	char*	argv[])	{	
    Screen::Instance().Refresh();
	Screen::Instance().Open( 1800, 800, false );
    IGame::Instance().Init();

	glfwSetMousePos(400, 300);

	while(Screen::Instance().IsOpened()	&& !Screen::Instance().KeyPressed( GLFW_KEY_ESC ))
	{	
  
		Screen::Instance().Refresh();
        IGame::Instance().Update( Screen::Instance().ElapsedTime() );
        IGame::Instance().Render();
	}

    IGame::Instance().End();
    ResourceManager::Instance().FreeResources();

    DUMP_LEAKS

	return	0;	
}

