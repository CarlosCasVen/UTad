#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "include/u-gine.h"
#include "logic/logic.h"

const float POS_INCREMENT = 0.2f;
const float PITCH_INCREMENT = 0.2f;

int	main(int	argc,	char*	argv[])	{	
    Screen::Instance().Refresh();
	Screen::Instance().Open( 800, 600, false );
    IGame::Instance().Init();

	glfwSetMousePos(400, 300);
	//glfwDisable(GLFW_MOUSE_CURSOR);

  

	while(Screen::Instance().IsOpened()	&& !Screen::Instance().KeyPressed( GLFW_KEY_ESC ))
	{	
  
		Screen::Instance().Refresh();
        IGame::Instance().Update( Screen::Instance().ElapsedTime() );
        IGame::Instance().Render();
	}

    IGame::Instance().End();
    ResourceManager::Instance().FreeResources();

	return	0;	
}

