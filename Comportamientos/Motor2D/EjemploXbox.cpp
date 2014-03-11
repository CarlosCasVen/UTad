/*#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "include/u-gine.h"
#include "Windows.h"
#include "xinput.h"

#pragma comment(lib, "XInput9_1_0.lib")

int main (int argc, char* argv[])
{

	Screen::Instance().Open(800, 600, false);	

	Sprite sprite (new Image ("data/alien.png"));

	float y = 0;
	float x = 0;

	while(Screen::Instance().IsOpened()	&& !Screen::Instance().KeyPressed(GLFW_KEY_ESC)){	

		XINPUT_STATE state;
		ZeroMemory( &state, sizeof(state));		
		XInputGetState( 0, &state);

		XINPUT_VIBRATION vibration;	
		ZeroMemory( &vibration, sizeof(XINPUT_VIBRATION));

		if( state.Gamepad.wButtons & XINPUT_GAMEPAD_A )
		{
			Beep( 5000, 100);

		}
		
		if( state.Gamepad.wButtons & XINPUT_GAMEPAD_B )
		{
			
			vibration.wLeftMotorSpeed = 65000;
			vibration.wRightMotorSpeed = 65000;
			
		}

		float xPad = (float)state.Gamepad.sThumbLX / 32768;
		float yPad = (float)state.Gamepad.sThumbLY / 32768;

		if( xPad > -0.2 && xPad < 0.2)
		{
			xPad = 0;
		}
		
		if( yPad > -0.2 && yPad < 0.2)
		{
			yPad = 0;
		}
		sprite.SetX( xPad * 10 + sprite.GetX());
		sprite.SetY( yPad * -10 + sprite.GetY());

		XInputSetState( 0, &vibration);

		Renderer::Instance().Clear(50,50,50);


		sprite.Render();
		Screen::Instance().Refresh();		
	}	

	 return	0;	

}*/