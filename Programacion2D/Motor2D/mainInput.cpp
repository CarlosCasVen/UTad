#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "include/u-gine.h"

int	main(int	argc,	char*	argv[])	{	


	Screen::Instance().Open(800, 600, false);	

	Image* image = ResourceManager::Instance().LoadImage("data/alien.png");
	ParallaxScene scene( ResourceManager::Instance().LoadImage("data/backlayer.png"), ResourceManager::Instance().LoadImage("data/frontlayer.png") );
	scene.SetAutoBackSpeed( 0.5f, 0.5f);
	scene.SetAutoFrontSpeed( -0.5f, -0.5f );
	scene.SetRelativeFrontSpeed( 0.7, 0.7 );
	scene.SetRelativeBackSpeed( -0.7, -0.7 );
	Sprite* sprite = scene.CreateSprite(image);
	sprite->SetX(200);
	sprite->SetY(200);
	//scene.GetCamera().FollowSprite( sprite );

	InputManager::Instance().CreateVirtualButton("Left", eInputCode::Button_A);
	InputManager::Instance().CreateVirtualButton("Right", Button_B);

	InputManager::Instance().CreateVirtualAxis( "Axis1", Button_LY_NEG, Button_LY_POS ); 
	InputManager::Instance().CreateVirtualAxis( "Axis2", Button_LX_POS, eInputCode::Button_LX_NEG ); 

	while(Screen::Instance().IsOpened()	&& !Screen::Instance().KeyPressed(GLFW_KEY_ESC)){	
		
		InputManager::Instance().Update();

		Renderer::Instance().Clear(25,25,25);

		if( Screen::Instance().MouseButtonPressed( GLFW_MOUSE_BUTTON_1 ))
			int x = 0;


		if(InputManager::Instance().IsVirtualButtonDown("Left"))
		{
			sprite->SetY(sprite->GetX() - 100);
		}
		else if(InputManager::Instance().IsVirtualButtonUp("Left"))
		{
			sprite->SetY(sprite->GetX() + 100 );
		}

		if(InputManager::Instance().IsVirtualButtonDown("Right"))
		{
			sprite->SetY(sprite->GetY() + 100);		
		}
		else if(InputManager::Instance().IsVirtualButtonUp("Right"))
		{
			sprite->SetY(sprite->GetY() - 100 );
		}

		sprite->SetY( sprite->GetY() + InputManager::Instance().GetVirtualAxis( "Axis1" ) * 10 );
		sprite->SetX( sprite->GetX() + InputManager::Instance().GetVirtualAxis( "Axis2" ) * 10 );

		scene.Update( Screen::Instance().ElapsedTime());
		scene.Render();
		//	Refrescamos	la	pantalla		 	 
		Screen::Instance().Refresh();	
	
	}	

	 return	0;	
}