#include "..\include\InputManager.h"
#include "..\include\glinclude.h"
#include "..\include\screen.h"


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




	return actions.Size() == 0;
}

// Cierre
void InputManager::End()
{
}

// Función de actualización, actualización de estados entre frames
void InputManager::Update()
{
	bool returned = false;

	for(unsigned int i = 0; i < actions.Size(); i++)
	{
		returned = actions[i].wasPreesedLastFrame = IsVirtualButtonPressed(actions[i].action);
	}

	for(unsigned int i = 0; i < virtualAxis.Size(); i++)
	{
		int posRange;
		Screen::Instance().KeyPressed( virtualAxis[i].positiveAxis) ? posRange = 1 : posRange = 0;
		
		int negRange;
		Screen::Instance().KeyPressed( virtualAxis[i].negativeAxis) ? negRange = -1 : negRange = 0;

		virtualAxis[i].movement = negRange + posRange;
	}
}
    
// Crea un botón virtual
void InputManager::CreateVirtualButton( const String& name, eInputCode button )
{
	bool found = false;

	for(unsigned int i = 0; i < actions.Size() && !found; i++)
	{
		if(actions[i].action == name)
		{
			found = true;
		}
	}

	if(!found)
	{
		Button newButton;
		newButton.action = name;
		newButton.buttonsAssigned = button;
		newButton.wasPreesedLastFrame = false;

		actions.Add(newButton);
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
	}

}

// Está el botón pulsado en este momento?
bool InputManager::IsVirtualButtonPressed( const String& name ) const
{
	bool pressed = false;
	bool found = false;

	for(unsigned int i = 0; i < actions.Size() && !found; i++)
	{
		if(actions[i].action == name && actions[i].buttonsAssigned >  Mouse_Right)
		{
			found = true;
			pressed = Screen::Instance().KeyPressed(actions[i].buttonsAssigned);
		}
		else if(actions[i].action == name && actions[i].buttonsAssigned <=  Mouse_Right)
		{
			found = true;
			pressed = Screen::Instance().MouseButtonPressed(actions[i].buttonsAssigned);
		}
	}

	return pressed;
}

// Devuelve true durante el frame que que el usuario ha comenzaco la pulsación de un botón
bool InputManager::IsVirtualButtonDown( const String& name ) const
{
	bool pressed = false;
	bool found = false;

	for(unsigned int i = 0; i < actions.Size() && !found; i++)
	{
		if(actions[i].action == name && actions[i].buttonsAssigned >  Mouse_Right)
		{
			found = true;
			pressed = Screen::Instance().KeyPressed(actions[i].buttonsAssigned) && !actions[i].wasPreesedLastFrame;
			
		}
		else if(actions[i].action == name && actions[i].buttonsAssigned <=  Mouse_Right)
		{
			found = true;
			pressed = Screen::Instance().MouseButtonPressed(actions[i].buttonsAssigned) && !actions[i].wasPreesedLastFrame;
		}
	}

	return pressed;
}

// Devuelve true durante el frame que que el usuario ha dejado de pulsar un botón
bool InputManager::IsVirtualButtonUp( const String& name ) const
{
	bool found = false;
	bool pressed = false;

	for(unsigned int i = 0; i < actions.Size() && !found; i++)
	{
		if(actions[i].action == name && actions[i].buttonsAssigned >  Mouse_Right)
		{
			found = true;
			pressed = !Screen::Instance().KeyPressed(actions[i].buttonsAssigned) && actions[i].wasPreesedLastFrame;
		}
		else if(actions[i].action == name && actions[i].buttonsAssigned <=  Mouse_Right)
		{
			found = true;
			pressed = !Screen::Instance().MouseButtonPressed(actions[i].buttonsAssigned) && actions[i].wasPreesedLastFrame;
		}

	}

	return pressed;
}

// Estado de ejes virtuales normalizado de -1 a +1
float InputManager::GetVirtualAxis( String name ) const
{
	bool found = false;
	unsigned int i = 0;

	for( i; i < virtualAxis.Size() && !found; i++)
	{
		if( virtualAxis[i].nameAxis == name)
		{
			found = true;
		}
	}

	if(found)
	{
		return virtualAxis[i].movement;
	}
	else
	{
		return 0;
	}
}



bool InputManager::IsKeyPressed( eInputCode vkCode )
{
	return Screen::Instance().KeyPressed( vkCode );
}


bool InputManager::IsKeyDown( eInputCode vkCode )
{
	bool found = false;
	unsigned int i = 0;

	while( i < buttonsPressed.Size() && !found)
	{
		if( buttonsPressed[i] == vkCode )
		{
			found = true;
		}
	}

	if( !found )
	{
		return false;
	}
	else
	{
		return IsKeyPressed( vkCode );
	}
	
}


bool InputManager::IsKeyUp( eInputCode vkCode )
{
	bool found = false;
	unsigned int i = 0;

	while( i < buttonsPressed.Size() && !found)
	{
		if( buttonsPressed[i] == vkCode )
		{
			found = true;
		}
	}

	if( !found )
	{
		return false;
	}
	else
	{
		return !IsKeyPressed( vkCode );
	}	
}


bool InputManager::IsMouseButtonPressed( eInputCode button )
{
	return Screen::Instance().MouseButtonPressed(button);
}


bool InputManager::GetMouseButtonDown( eInputCode button )
{
	bool found = false;
	unsigned int i = 0;

	while( i < buttonsPressed.Size() && !found)
	{
		if( buttonsPressed[i] == button )
		{
			found = true;
		}
	}

	if( !found )
	{
		return false;
	}
	else
	{
		return IsMouseButtonPressed( button );
	}	
}


bool InputManager::GetMouseButtonUp( eInputCode button )
{
	bool found = false;
	unsigned int i = 0;

	while( i < buttonsPressed.Size() && !found)
	{
		if( buttonsPressed[i] == button )
		{
			found = true;
		}
	}

	if( !found )
	{
		return false;
	}
	else
	{
		return !IsMouseButtonPressed( button );
	}	
}
