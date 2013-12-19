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

	InputManager::Instance().CreateVirtualAxis( "Axis1", eInputCode::Key_S, eInputCode::Key_W ); 
	InputManager::Instance().CreateVirtualAxis( "Axis2", eInputCode::Key_D, eInputCode::Key_A ); 

	while(Screen::Instance().IsOpened()	&& !Screen::Instance().KeyPressed(GLFW_KEY_ESC)){	
		
		InputManager::Instance().Update();

		Renderer::Instance().Clear(25,25,25);

		if( Screen::Instance().MouseButtonPressed( GLFW_MOUSE_BUTTON_1 ))
			int x = 0;


		if(InputManager::Instance().IsVirtualButtonDown("Left"))
		{
			sprite.SetY(sprite.GetX() - 100);
		}
		else if(InputManager::Instance().IsVirtualButtonUp("Left"))
		{
			sprite.SetY(sprite.GetX() + 100 );
		}

		if(InputManager::Instance().IsVirtualButtonDown("Right"))
		{
			sprite.SetY(sprite.GetY() + 100);		
		}
		else if(InputManager::Instance().IsVirtualButtonUp("Right"))
		{
			sprite.SetY(sprite.GetY() - 100 );
		}

		sprite.SetY( sprite.GetY() + InputManager::Instance().GetVirtualAxis( "Axis1" ) * 10 );
		sprite.SetX( sprite.GetX() + InputManager::Instance().GetVirtualAxis( "Axis2" ) * 10 );

		sprite.Render();
		//	Refrescamos	la	pantalla		 	 
		Screen::Instance().Refresh();	
	
	}	

	 return	0;	
}

