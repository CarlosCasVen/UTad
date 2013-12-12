#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "include/u-gine.h"

int	main(int	argc,	char*	argv[])	{	


	Screen::Instance().Open(800, 600, false);	

	Image* image = ResourceManager::Instance().LoadImage("data/alien.png");
	Sprite sprite = Sprite(image);
	sprite.SetX(200);
	sprite.SetY(200);

	InputManager::Instance().CreateVirtualButton("Left", eInputCode::Mouse_Button0);
	InputManager::Instance().CreateVirtualButton("Right", eInputCode::Mouse_Button1);

	while(Screen::Instance().IsOpened()	&& !Screen::Instance().KeyPressed(GLFW_KEY_ESC)){	
		
		InputManager::Instance().Update();

		Renderer::Instance().Clear(25,25,25);

		if( Screen::Instance().MouseButtonPressed( GLFW_MOUSE_BUTTON_1 ))
			int x = 0;


		if(InputManager::Instance().IsVirtualButtonPressed("Left"))
		{
			sprite.SetX(sprite.GetX() - 10);
		}

		if(InputManager::Instance().IsVirtualButtonPressed("Right"))
		{
			sprite.SetX(sprite.GetX() + 10);		
		}


		sprite.Render();
		//	Refrescamos	la	pantalla		 	 
		Screen::Instance().Refresh();	
	
	}	

	 return	0;	
}

