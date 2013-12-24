#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "include/u-gine.h"
#include "uGui/GUIManager.h"
#include "UGui/Button.h"
#include "uGui/Window.h"
#include "uGui/IEventListener.h"
#include "uGui/Label.h"
#include "uGui/Checkbox.h"
#include "uGui/Slider.h"
#include "uGui/Menu.h"
#include "uGui/MainMenu.h"
#include "uGui/ConfigMenu.h"
#include "uGui/CreditsMenu.h"
#include "uGui/GameMenu.h"
#include "include/InputManager.h"

void CreateGUI();
void MouseButtonCallback(int button, int action);
void MousePosCallback(int x, int y);
void KeyPressCallback(int key, int action);


//------------------------------------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------------------------------------
int main(int argc, char* argv[]) 
{
	Screen::Instance().Open( 1024, 768, false );
	Menu* menu = &MainMenu::instance();

	InputManager::Instance().CreateVirtualAxis( "LeftRight", Key_D, Key_A);
	InputManager::Instance().CreateVirtualAxis( "UpDown", Key_S, Key_W);
	InputManager::Instance().CreateVirtualButton( "Shoot", Mouse_Button0 );

	menu->showScreen();

	glfwSetMouseButtonCallback(MouseButtonCallback);
	glfwSetMousePosCallback(MousePosCallback);
	glfwSetKeyCallback(KeyPressCallback);


	while ( Screen::Instance().IsOpened()  ) 
	{
		GUIManager::instance().update();

		Renderer::Instance().Clear(0, 0, 0);
		GUIManager::instance().render();
		Screen::Instance().Refresh();
	}

	GUIManager::instance().end();

	return 0;
}


//------------------------------------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------------------------------------
void MouseButtonCallback(int button, int action)
{
	int x, y;
	glfwGetMousePos( &x, &y );

	if( action == GLFW_PRESS )
		GUIManager::instance().injectInput( MessagePointerButtonDown( button, (float)x, (float)y ) );
	else if( action == GLFW_RELEASE )
		GUIManager::instance().injectInput( MessagePointerButtonUp( button, (float)x, (float)y ) );
}

//------------------------------------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------------------------------------
void MousePosCallback(int x, int y)
{
	GUIManager::instance().injectInput( MessagePointerMove( (float)x, (float)y ) ); 
}



void KeyPressCallback(int key, int action)
{
    if( action == GLFW_PRESS )
        GUIManager::instance().injectInput(MessageKeyDown(key)); 
    else if( action == GLFW_RELEASE )
        GUIManager::instance().injectInput(MessageKeyUp(key));
}