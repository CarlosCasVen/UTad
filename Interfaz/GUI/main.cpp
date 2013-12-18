#include "include/u-gine.h"

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "include/u-gine.h"
#include "uGui/GUIManager.h"
#include "UGui/Button.h"
#include "uGui/Window.h"
#include "uGui/IEventListener.h"
#include "uGui/FirstMenu.h"
#include "uGui/ConfigScreen.h"
#include "uGui/CreditsScreen.h"
#include "uGui/Slider.h"

void MouseButtonCallback(int button, int action);
void MousePosCallback(int x, int y);


//------------------------------------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------------------------------------
int main(int argc, char* argv[]) 
{
	Screen::Instance().Open( 1024, 768, false );
	
	GUIManager::instance().init();
	
	FirstMenu menu = FirstMenu::instance();
	menu.Active();
	
/*	Label* l1 = new Label(); 
	l1->init( "Label1", Vector2( 200, 300 ), "Prueba", "data/fonts/font.png" );   
	
	Button* m_exit = new Button(); 
	m_exit->init( "Volver", Vector2( 250, 250 ), "data/GUI/Button_Normal.png", "data/GUI/Button_Push.png" );   
	m_exit->setLabel(l1);
	m_exit->setParent( GUIManager::instance().getRootControl() );
	*/
	glfwSetMouseButtonCallback(MouseButtonCallback);
	glfwSetMousePosCallback(MousePosCallback);

	while ( Screen::Instance().IsOpened()  &&  !Screen::Instance().KeyPressed(GLFW_KEY_ESC) ) 
	{
		GUIManager::instance().update();

		Screen::Instance().SetTitle( String( "X: ") + String::FromFloat( Screen::Instance().GetMouseX()) + String( " Y: ") + String::FromFloat( Screen::Instance().GetMouseY()) );

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