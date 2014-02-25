#include "..\include\InputManager.h"
#include "..\include\glinclude.h"
#include "..\include\screen.h"
#include "windows.h"
#include "xinput.h"

#pragma comment(lib, "XInput9_1_0.lib")


InputManager* InputManager::manager = NULL;

// Inicialición: deteccción de dispostivos, inicialización de los mismos... etc
bool InputManager::Init()
{
	 
	keys.Add(Key( Mouse_Button0 ) );
	keys.Add(Key( Mouse_Button1 ) );
	keys.Add(Key( Mouse_Button2 ) );
	keys.Add(Key( Mouse_WheelDown ) );
	keys.Add(Key( Mouse_WheelUp) );
	keys.Add(Key( Mouse_Down) );
	keys.Add(Key( Mouse_Up) );
	keys.Add(Key( Mouse_Left) );
	keys.Add(Key( Mouse_Right) );
	keys.Add(Key( JOYSTICK_1) );
	keys.Add(Key( JOYSTICK_2) );
	keys.Add(Key( JOYSTICK_3) );
	keys.Add(Key( JOYSTICK_4) );
	keys.Add(Key( JOYSTICK_5) );
	keys.Add(Key( JOYSTICK_6) );
	keys.Add(Key( JOYSTICK_7) );
	keys.Add(Key( JOYSTICK_8) );
	keys.Add(Key( JOYSTICK_9) );
	keys.Add(Key( JOYSTICK_10) );
	keys.Add(Key( JOYSTICK_11) );
	keys.Add(Key( JOYSTICK_12) );
	keys.Add(Key( JOYSTICK_13) );
	keys.Add(Key( JOYSTICK_14) );
	keys.Add(Key( JOYSTICK_15) );
	keys.Add(Key( JOYSTICK_16) );
	keys.Add(Key( Key_0) );
	keys.Add(Key( Key_1) );
	keys.Add(Key( Key_2) );
	keys.Add(Key( Key_3) );
	keys.Add(Key( Key_4) );
	keys.Add(Key( Key_5) );
	keys.Add(Key( Key_6) );
	keys.Add(Key( Key_7) );
	keys.Add(Key( Key_8) );
	keys.Add(Key( Key_9) );
	keys.Add(Key( Key_A) );
	keys.Add(Key( Key_B) );
	keys.Add(Key( Key_C) );
	keys.Add(Key( Key_D) );
	keys.Add(Key( Key_E) );
	keys.Add(Key( Key_F) );
	keys.Add(Key( Key_G) );
	keys.Add(Key( Key_H) );
	keys.Add(Key( Key_I) );
	keys.Add(Key( Key_J) );
	keys.Add(Key( Key_K) );
	keys.Add(Key( Key_L) );
	keys.Add(Key( Key_M) );
	keys.Add(Key( Key_N) );
	keys.Add(Key( Key_O) );
	keys.Add(Key( Key_P) );
	keys.Add(Key( Key_Q) );
	keys.Add(Key( Key_R) );
	keys.Add(Key( Key_S) );
	keys.Add(Key( Key_T) );
	keys.Add(Key( Key_U) );
	keys.Add(Key( Key_V) );
	keys.Add(Key( Key_W) );
	keys.Add(Key( Key_X) );
	keys.Add(Key( Key_Y) );
	keys.Add(Key( Key_Z) );
	keys.Add(Key( Key_F1) );
	keys.Add(Key( Key_F2) );
	keys.Add(Key( Key_F3) );
	keys.Add(Key( Key_F4) );
	keys.Add(Key( Key_F5) );
	keys.Add(Key( Key_F6) );
	keys.Add(Key( Key_F7) );
	keys.Add(Key( Key_F8) );
	keys.Add(Key( Key_F9) );
	keys.Add(Key( Key_F10) );
	keys.Add(Key( Key_F11) );
	keys.Add(Key( Key_F12) );
	keys.Add(Key( Key_F13) );
	keys.Add(Key( Key_F14) );
	keys.Add(Key( Key_F15) );
	keys.Add(Key( Key_UpArrow) );
	keys.Add(Key( Key_DownArrow) );
	keys.Add(Key( Key_LeftArrow) );
	keys.Add(Key( Key_RightArrow) );
	keys.Add(Key( Key_AltGr) );
	keys.Add(Key( Key_Ampersand) );
	keys.Add(Key( Key_Asterisk) );
	keys.Add(Key( Key_At) );
	keys.Add(Key( Key_BackQuote) );
	keys.Add(Key( Key_Backslash) );
	keys.Add(Key( Key_Backspace) );
	keys.Add(Key( Key_Break) );
	keys.Add(Key( Key_CapsLock) );
	keys.Add(Key( Key_Caret) );
	keys.Add(Key( Key_Clear) );
	keys.Add(Key( Key_Colon) );
	keys.Add(Key( Key_Comma) );
	keys.Add(Key( Key_Delete) );
	keys.Add(Key( Key_Dollar) );
	keys.Add(Key( Key_DoubleQuote) );
	keys.Add(Key( Key_End) );
	keys.Add(Key( Key_Equals) );
	keys.Add(Key( Key_Escape) );
	keys.Add(Key( Key_Exclaim) );
	keys.Add(Key( Key_Greater) );
	keys.Add(Key( Key_Hash) );
	keys.Add(Key( Key_Help) );
	keys.Add(Key( Key_Home) );
	keys.Add(Key( Key_Insert) );
	keys.Add(Key( Key_Keypad0) );
	keys.Add(Key( Key_Keypad1) );
	keys.Add(Key( Key_Keypad2) );
	keys.Add(Key( Key_Keypad3) );
	keys.Add(Key( Key_Keypad4) );
	keys.Add(Key( Key_Keypad5) );
	keys.Add(Key( Key_Keypad6) );
	keys.Add(Key( Key_Keypad7) );
	keys.Add(Key( Key_Keypad8) );
	keys.Add(Key( Key_Keypad9) );
	keys.Add(Key( Key_KeypadDivide) );
	keys.Add(Key( Key_KeypadEnter) );
	keys.Add(Key( Key_KeypadEquals) );
	keys.Add(Key( Key_KeypadMinus) );
	keys.Add(Key( Key_KeypadMultiply) );
	keys.Add(Key( Key_KeypadPeriod) );
	keys.Add(Key( Key_KeypadPlus) );
	keys.Add(Key( Key_LeftAlt) );
	keys.Add(Key( Key_LeftApple) );
	keys.Add(Key( Key_LeftBracket) );
	keys.Add(Key( Key_LeftControl) );
	keys.Add(Key( Key_LeftParen) );
	keys.Add(Key( Key_LeftShift) );
	keys.Add(Key( Key_LeftWindows) );
	keys.Add(Key( Key_Less) );
	keys.Add(Key( Key_Menu) );
	keys.Add(Key( Key_Minus) );
	keys.Add(Key( Key_Numlock) );
	keys.Add(Key( Key_PageDown) );
	keys.Add(Key( Key_PageUp) );
	keys.Add(Key( Key_Pause) );
	keys.Add(Key( Key_Period) );
	keys.Add(Key( Key_Plus) );
	keys.Add(Key( Key_Print) );
	keys.Add(Key( Key_Question) );
	keys.Add(Key( Key_Quote) );
	keys.Add(Key( Key_Return) );
	keys.Add(Key( Key_RightAlt) );
	keys.Add(Key( Key_RightApple) );
	keys.Add(Key( Key_RightBracket) );
	keys.Add(Key( Key_RightControl) );
	keys.Add(Key( Key_RightParen) );
	keys.Add(Key( Key_RightShift) );
	keys.Add(Key( Key_RightWindows) );
	keys.Add(Key( Key_ScrollLock) );
	keys.Add(Key( Key_Semicolon) );
	keys.Add(Key( Key_Slash) );
	keys.Add(Key( Key_Space) );
	keys.Add(Key( Key_SysReq) );
	keys.Add(Key( Key_Tab) );
	keys.Add(Key( Key_Underscore) );
	keys.Add(Key( Button_Up ) );
	keys.Add(Key( Button_Down ) );
	keys.Add(Key( Button_Left ) );
	keys.Add(Key( Button_Right ) );
	keys.Add(Key( Button_Start ) );
	keys.Add(Key( Button_Back ) );
	keys.Add(Key( Button_LB ) );
	keys.Add(Key( Button_RB ) );
	keys.Add(Key( Button_A ) );
	keys.Add(Key( Button_B ) );
	keys.Add(Key( Button_X ) );
	keys.Add(Key( Button_Y ) );
	keys.Add(Key( Button_LT ) );
	keys.Add(Key( Button_RT ) );
	keys.Add(Key( Button_LX_POS ) );
	keys.Add(Key( Button_LX_NEG ) );
	keys.Add(Key( Button_LY_POS ) );
	keys.Add(Key( Button_LY_NEG ) );
	keys.Add(Key( Button_RX_POS ) );
	keys.Add(Key( Button_RX_NEG ) );
	keys.Add(Key( Button_RY_POS ) );
	keys.Add(Key( Button_RY_NEG ) );



	xMouse = yMouse = 0;

	if( GetKeyboardType( 0 ) )
	{
		devicesOn[ Keyboard ] = true;
	}
	else
	{
		devicesOn[ Keyboard ] = false;
	}
	
	if( GetSystemMetrics( SM_MOUSEPRESENT ) )
	{
		devicesOn[ Mouse ] = true;
	}
	else
	{
		devicesOn[ XboxPad ] = false;
	}

	XINPUT_STATE state;
	ZeroMemory( &state, sizeof(state));		

	if( XInputGetState( 0, &state) == ERROR_SUCCESS )
	{
		devicesOn[ XboxPad ] = true;
	}
	else
	{
		devicesOn[ XboxPad ] = false;
	}
	return isOk = devicesOn[ Keyboard ] && devicesOn[ Mouse ] ;
}

// Cierre
void InputManager::End()
{
}

// Función de actualización, actualización de estados entre frames
void InputManager::Update()
{

	for( unsigned int i = 0; i < virtualButtons.Size(); i++ )
	{
		if( virtualButtons[i].buttonsAssigned > Mouse_Right && virtualButtons[i].buttonsAssigned < Button_Up )
		{
			virtualButtons[i].isDown = !virtualButtons[i].pressed && IsKeyPressed( virtualButtons[i].buttonsAssigned );
			virtualButtons[i].isUp = virtualButtons[i].pressed && !IsKeyPressed( virtualButtons[i].buttonsAssigned );
			virtualButtons[i].pressed = IsKeyPressed( virtualButtons[i].buttonsAssigned );
		}
		else if( virtualButtons[i].buttonsAssigned <= Mouse_Right ) 
		{
			virtualButtons[i].isDown = !virtualButtons[i].pressed && IsMouseButtonPressed( virtualButtons[i].buttonsAssigned );
			virtualButtons[i].isUp = virtualButtons[i].pressed && !IsMouseButtonPressed( virtualButtons[i].buttonsAssigned );
			virtualButtons[i].pressed = IsMouseButtonPressed( virtualButtons[i].buttonsAssigned );
		}
		else
		{
			virtualButtons[i].isDown = !virtualButtons[i].pressed && IsXboxDown( virtualButtons[i].buttonsAssigned );
			virtualButtons[i].isUp = virtualButtons[i].pressed && !IsXboxPressed( virtualButtons[i].buttonsAssigned );
			virtualButtons[i].pressed = IsXboxPressed( virtualButtons[i].buttonsAssigned );
		}
	}

	for( unsigned int i = 0; i < virtualAxis.Size(); i++ )
	{
	
		if( virtualAxis[i].positiveAxis > Mouse_Right && virtualAxis[i].positiveAxis < Button_Up )
		{
			IsKeyPressed( virtualAxis[i].positiveAxis ) ? 	virtualAxis[i].movement = 1.0 : virtualAxis[i].movement = 0;
		}
		else if( virtualAxis[i].positiveAxis <= Mouse_Right )
		{
			IsMouseButtonPressed( virtualAxis[i].positiveAxis ) ? 	virtualAxis[i].movement = 1.0 : virtualAxis[i].movement = 0;
		}
		else
		{
			IsXboxPressed( virtualAxis[i].positiveAxis ) ? 	virtualAxis[i].movement = 1.0 : virtualAxis[i].movement = 0;
		}

		if( virtualAxis[i].negativeAxis > Mouse_Right && virtualAxis[i].negativeAxis < Button_Up )
		{
			IsKeyPressed( virtualAxis[i].negativeAxis ) ? 	virtualAxis[i].movement += -1.0 : virtualAxis[i].movement += 0;
		}
		else if( virtualAxis[i].negativeAxis <= Mouse_Right )
		{
			IsMouseButtonPressed( virtualAxis[i].negativeAxis ) ? 	virtualAxis[i].movement += -1.0 : virtualAxis[i].movement += 0;
		}
		else
		{
			IsXboxPressed( virtualAxis[i].negativeAxis ) ? 	virtualAxis[i].movement += -1.0 : virtualAxis[i].movement += 0;
		}
	}


	for( unsigned int i = 0; i < keys.Size(); i++ )
	{
		if( keys[i].device == Keyboard )
		{
			keys[i].wasPushed = IsKeyPressed( keys[i].key );
		}
		else if( keys[i].key == Mouse )
		{
			keys[i].wasPushed = IsMouseButtonPressed( keys[i].key );		
		}
		else if( keys[i].key == XboxPad )
		{
			keys[i].wasPushed = IsXboxPressed( keys[i].key );
		}
	}

	xMouse = Screen::Instance().GetMouseX();
	yMouse = Screen::Instance().GetMouseY();
}
    
// Crea un botón virtual
void InputManager::CreateVirtualButton( const String& name, eInputCode button )
{
	bool found = false;

	for(unsigned int i = 0; i < virtualButtons.Size() && !found; i++)
	{
		if(virtualButtons[i].action == name)
		{
			found = true;
		}
	}

	if(!found)
	{
		VirtualButton newButton;
		newButton.action = name;
		newButton.buttonsAssigned = button;
		newButton.pressed = newButton.isDown = newButton.isUp = false;

		virtualButtons.Add(newButton);
	}
}

// Crea un eje virtual
void InputManager::CreateVirtualAxis( const String& name, eInputCode positiveAxis, eInputCode negativeAxis )
{
	bool found = false;

	for(unsigned int i = 0; i < virtualAxis.Size() && !found; i++)
	{
		if( virtualAxis[i].nameAxis == name)
		{
			found = true;
		}
	}

	if(!found)
	{
		VirtualAxis newAxis;
		newAxis.nameAxis = name;
		newAxis.positiveAxis = positiveAxis;
		newAxis.negativeAxis = negativeAxis;
		newAxis.movement = 0;

		virtualAxis.Add( newAxis );
	}

}

// Está el botón pulsado en este momento?
bool InputManager::IsVirtualButtonPressed( const String& name ) const
{
	bool pressed = false;
	bool found = false;

	for(unsigned int i = 0; i < virtualButtons.Size() && !found; i++)
	{
		if( virtualButtons[i].action == name )
		{
			found = true;
			pressed = virtualButtons[i].pressed;
		}	
	}

	return pressed;
}

// Devuelve true durante el frame que que el usuario ha comenzaco la pulsación de un botón
bool InputManager::IsVirtualButtonDown( const String& name ) const
{
	bool pressed = false;
	bool found = false;

	for(unsigned int i = 0; i < virtualButtons.Size() && !found; i++)
	{
		if( virtualButtons[i].action == name )
		{
			found = true;
			pressed = virtualButtons[i].isDown;
		}
	}

	return pressed;
}

// Devuelve true durante el frame que que el usuario ha dejado de pulsar un botón
bool InputManager::IsVirtualButtonUp( const String& name ) const
{
	bool result = false;
	bool found = false;

	for(unsigned int i = 0; i < virtualButtons.Size() && !found; i++)
	{
		if( virtualButtons[i].action == name )
		{
			found = true;
			result = virtualButtons[i].isUp;
		}
	}

	return result;
}

// Estado de ejes virtuales normalizado de -1 a +1
float InputManager::GetVirtualAxis( String name ) const
{
	bool found = false;
	unsigned int i = 0;

	while( !found && i < virtualAxis.Size() )
	{
		if( virtualAxis[i].nameAxis == name )
		{
			found = true;
		}
		else
		{
			i++;
		}
	}

	return found ? virtualAxis[i].movement : 0.0f;
}



bool InputManager::IsKeyPressed( eInputCode vkCode )
{
	return Screen::Instance().KeyPressed( vkCode );
}


bool InputManager::IsKeyDown( eInputCode vkCode )
{
	bool found = false;
	bool isDown = false;

	for( unsigned int i = 0; i < keys.Size() && !found; i++ )
	{
		if( keys[i].key == vkCode )
		{
			found = true;
			isDown = !keys[i].wasPushed && IsKeyPressed( vkCode ); 
		}
	}
	
	return isDown;
}


bool InputManager::IsKeyUp( eInputCode vkCode )
{
	bool found = false;
	bool isUp = false;

	if( vkCode > Mouse_Right )
	{
		for( unsigned int i = 0; i < keys.Size() && !found; i++ )
		{
			if( keys[i].key == vkCode )
			{
				found = true;
				isUp = keys[i].wasPushed && !IsKeyPressed( vkCode ); 
			}
		}
	}

	return isUp;
}


bool InputManager::IsMouseButtonPressed( eInputCode button )
{
	bool result = false;
	switch( button )
	{
		case Mouse_Down:
		{
			result = Screen::Instance().GetMouseY() > yMouse;
			break;
		}
		case Mouse_Up:
		{
			result = Screen::Instance().GetMouseY() < yMouse;
			break;
		}
		case Mouse_Left:
		{
			result = Screen::Instance().GetMouseX() < xMouse;
			break;
		}
		case Mouse_Right:
		{
			result = Screen::Instance().GetMouseX() > xMouse;
			break;
		}
		default:
		{
			result = Screen::Instance().MouseButtonPressed(button);
		}
	}
	return result;
}


bool InputManager::GetMouseButtonDown( eInputCode button )
{
	bool found = false;
	bool isDown = false;

	for( unsigned int i = 0; i < keys.Size() && !found; i++ )
	{
		if( keys[i].key == button )
		{
			found = true;
			isDown = !keys[i].wasPushed && IsMouseButtonPressed( button ); 
		}	
	}
	
	return isDown;	
	
}


bool InputManager::GetMouseButtonUp( eInputCode button )
{
	bool found = false;
	bool isUp = false;

	for( unsigned int i = 0; i < keys.Size() && !found; i++ )
	{
		if( keys[i].key == button )
		{
			found = true;
			isUp = keys[i].wasPushed && !IsMouseButtonPressed( button ); 
		}	
	}
	
	return isUp;	
}


bool InputManager::IsXboxPressed( eInputCode vkCode )
{
	XINPUT_STATE state;
	ZeroMemory( &state, sizeof(state));		
	XInputGetState( 0, &state);

	if( vkCode <= Button_Y )
	{
		return ( state.Gamepad.wButtons & FromKeyToXboxStruct( vkCode ) ) > 0;
	}
	else
	{
		switch( vkCode)
		{
		case  Button_LT:
			{
				float ltPad = ( float ) state.Gamepad.bLeftTrigger / 255;
				return ltPad > 0.1f;
			}
		case   Button_RT:
			{
				float rtPad = ( float ) state.Gamepad.bRightTrigger / 255;
				return rtPad > 0.1f;

			}
		case Button_LX_POS:
			{
				float lxPad = ( float ) state.Gamepad.sThumbLX / 32768;
				return lxPad > 0.2f;
			}
		case Button_LX_NEG:
			{
				float lxPad = ( float ) state.Gamepad.sThumbLX / 32768;
				return lxPad < -0.2f;
			}
		case Button_LY_POS:
			{
				float lyPad = ( float ) state.Gamepad.sThumbLY / 32768;
				return lyPad > 0.2f;
			}
		case Button_LY_NEG:
			{
				float lyPad = ( float ) state.Gamepad.sThumbLY / 32768;
				return lyPad < -0.2f;
			}
		case Button_RX_POS:
			{
				float rxPad = ( float ) state.Gamepad.sThumbRX / 32768;
				return rxPad > 0.2f;
			}
		case Button_RX_NEG:
			{
				float rxPad = ( float ) state.Gamepad.sThumbRX / 32768;
				return rxPad < -0.2f;
			}
		case Button_RY_POS:
			{
				float ryPad = ( float ) state.Gamepad.sThumbRY / 32768;
				return ryPad > 0.2f;
			}
		case Button_RY_NEG:
			{
				float ryPad = ( float ) state.Gamepad.sThumbRY / 32768;
				return ryPad < -0.2f;
			}
		default:
			return false;
		}
	}

}


bool InputManager::IsXboxDown( eInputCode vkCode )
{
	bool found = false;
	unsigned int i = 0;

	while( i < keys.Size() && !found )
	{
		if( vkCode == keys[i].key )
		{
			found = true;
		}
		i++;
	}
	return !keys[i].wasPushed && IsXboxPressed( vkCode );
}


bool InputManager::IsXboxUp( eInputCode vkCode )
{
	bool found = false;
	unsigned int i = 0;

	while( i < keys.Size() && !found )
	{
		if( vkCode == keys[i].key )
		{
			found = true;
		}
		i++;
	}
	return keys[i].wasPushed && !IsXboxPressed( vkCode );
}


int InputManager::FromKeyToXboxStruct ( eInputCode key )
{
	switch( key )
	{
	case Button_A:
		return XINPUT_GAMEPAD_A;
	case Button_B:
		return XINPUT_GAMEPAD_B;
	case Button_Y:
		return XINPUT_GAMEPAD_Y;
	case Button_X:
		return XINPUT_GAMEPAD_X;
	case Button_RB:
		return XINPUT_GAMEPAD_RIGHT_SHOULDER;
	case Button_LB:
		return XINPUT_GAMEPAD_RIGHT_SHOULDER;
	case Button_Start:
		return XINPUT_GAMEPAD_START;
	case Button_Back:
		return XINPUT_GAMEPAD_BACK;
	case Button_Right:
		return XINPUT_GAMEPAD_DPAD_RIGHT;
	case Button_Left:
		return XINPUT_GAMEPAD_DPAD_LEFT;
	case Button_Up:
		return XINPUT_GAMEPAD_DPAD_UP;
	case Button_Down:
		return XINPUT_GAMEPAD_DPAD_DOWN;
	default:
		return -1;
	}
}