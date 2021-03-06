#ifndef _INPUT_MANAGER_H_
#define _INPUT_MANAGER_H_

#include "array.h"
#include "string.h"

#define NUM_DEVICES 3

enum DeviceType{
	Keyboard,
	Mouse,
	XboxPad
};

// c�digos que representan los distintos tipos de inputs posibles
enum eInputCode
{
  // Rat�n
  Mouse_Button0 = 0,
  Mouse_Button1,
  Mouse_Button2,
  Mouse_WheelDown,
  Mouse_WheelUp,
  Mouse_Down,
  Mouse_Up,
  Mouse_Left,
  Mouse_Right,

   //JOYSTICK
  JOYSTICK_1,
  JOYSTICK_2,
  JOYSTICK_3,
  JOYSTICK_4,
  JOYSTICK_5,
  JOYSTICK_6,
  JOYSTICK_7,
  JOYSTICK_8,
  JOYSTICK_9,
  JOYSTICK_10,
  JOYSTICK_11,
  JOYSTICK_12,
  JOYSTICK_13,
  JOYSTICK_14,
  JOYSTICK_15,
  JOYSTICK_16,

  // Teclado
  Key_0,
  Key_1,
  Key_2,
  Key_3,
  Key_4,
  Key_5,
  Key_6,
  Key_7,
  Key_8,
  Key_9,
  Key_A = 65,
  Key_B,
  Key_C,
  Key_D,
  Key_E,
  Key_F,
  Key_G,
  Key_H,
  Key_I,
  Key_J,
  Key_K,
  Key_L,
  Key_M,
  Key_N,
  Key_O,
  Key_P,
  Key_Q,
  Key_R,
  Key_S,
  Key_T,
  Key_U,
  Key_V,
  Key_W,
  Key_X,
  Key_Y,
  Key_Z,   
  Key_F1 = 258,
  Key_F2,
  Key_F3,
  Key_F4,
  Key_F5,
  Key_F6,
  Key_F7,
  Key_F8,
  Key_F9,
  Key_F10,
  Key_F11,
  Key_F12,
  Key_F13,
  Key_F14,
  Key_F15,
  Key_UpArrow = 283,
  Key_DownArrow,
  Key_LeftArrow,
  Key_RightArrow, 
  Key_AltGr,
  Key_Ampersand,
  Key_Asterisk,
  Key_At,
  Key_BackQuote,
  Key_Backslash,
  Key_Backspace,
  Key_Break,
  Key_CapsLock,
  Key_Caret,
  Key_Clear,
  Key_Colon,
  Key_Comma,
  Key_Delete,
  Key_Dollar,
  Key_DoubleQuote,
  Key_End,
  Key_Equals,
  Key_Escape,
  Key_Exclaim,
  Key_Greater,
  Key_Hash,
  Key_Help,
  Key_Home,
  Key_Insert,
  Key_Keypad0,
  Key_Keypad1,
  Key_Keypad2,
  Key_Keypad3,
  Key_Keypad4,
  Key_Keypad5,
  Key_Keypad6,
  Key_Keypad7,
  Key_Keypad8,
  Key_Keypad9,
  Key_KeypadDivide,
  Key_KeypadEnter,
  Key_KeypadEquals,
  Key_KeypadMinus,
  Key_KeypadMultiply,
  Key_KeypadPeriod,
  Key_KeypadPlus,
  Key_LeftAlt,
  Key_LeftApple,
  Key_LeftBracket,
  Key_LeftControl,
  Key_LeftParen,
  Key_LeftShift,
  Key_LeftWindows,
  Key_Less,
  Key_Menu,
  Key_Minus,
  Key_Numlock,
  Key_PageDown,
  Key_PageUp,
  Key_Pause,
  Key_Period,
  Key_Plus,
  Key_Print,
  Key_Question,
  Key_Quote,
  Key_Return,
  Key_RightAlt,
  Key_RightApple,
  Key_RightBracket,
  Key_RightControl,
  Key_RightParen,
  Key_RightShift,
  Key_RightWindows,
  Key_ScrollLock,
  Key_Semicolon,
  Key_Slash,
  Key_Space,
  Key_SysReq,
  Key_Tab,
  Key_Underscore, 

  //XBOX
  Button_Up,
  Button_Down,
  Button_Left,
  Button_Right,
  Button_Start,
  Button_Back,
  Button_LB,
  Button_RB, 
  Button_A,
  Button_B,
  Button_X,
  Button_Y,
  Button_LT,
  Button_RT,
  Button_LX_POS,
  Button_LX_NEG,
  Button_LY_POS,
  Button_LY_NEG,
  Button_RX_POS,
  Button_RX_NEG,
  Button_RY_POS,
  Button_RY_NEG,
};

struct VirtualButton 
{
	eInputCode buttonsAssigned;
	String action;
	bool pressed;
	bool isUp;
	bool isDown;
};

struct VirtualAxis 
{
	eInputCode positiveAxis;
	eInputCode negativeAxis;
	String nameAxis;
	float movement;
};


struct Key
{
	eInputCode key;
	DeviceType device;
	bool wasPushed;

public:
	Key(){};
	Key( eInputCode k )
	{ 
		key = k; wasPushed = false;

		if( k <= Mouse_Right ) 
		{
			device = Mouse;
		}
		else if( k > Mouse_Right  && k <=  Key_Underscore )
		{
			device = Keyboard;
		}
		else
		{
			device = XboxPad;
		}
	}
};



class InputManager
{
  public:
	  static InputManager& Instance() {if ( !manager ) manager = new InputManager(); return *manager; }

	  
      ~InputManager(){ keys.Clear(); virtualAxis.Clear(); virtualButtons.Clear(); pressed.Clear();}

	// Inicialici�n: deteccci�n de dispostivos, inicializaci�n de los mismos... etc
    bool            Init();

	// Cierre
    void            End();

	// Devuelve true si el manager ha sido inicializado correctamente
	bool IsOk(){ return isOk; }


	// Funci�n de actualizaci�n, actualizaci�n de estados entre frames
    void            Update();
    

    // Crea un bot�n virtual
    void            CreateVirtualButton( const String& name, eInputCode button );
	// Crea un eje virtual
    void            CreateVirtualAxis( const String& name, eInputCode positiveAxis, eInputCode negativeAxis );

    // Est� el bot�n pulsado en este momento?
    bool            IsVirtualButtonPressed( const String& name ) const;
	// Devuelve true durante el frame que que el usuario ha comenzaco la pulsaci�n de un bot�n
    bool            IsVirtualButtonDown( const String& name ) const;
	// Devuelve true durante el frame que que el usuario ha dejado de pulsar un bot�n
    bool            IsVirtualButtonUp( const String& name ) const;

    // Estado de ejes virtuales normalizado de -1 a +1
    float           GetVirtualAxis( String name ) const;

    // Est� el la tecla pulsada en este momento?
    bool            IsKeyPressed( eInputCode vkCode );
	// Devuelve true durante el frame que que el usuario ha comenzaco la pulsaci�n de una tecla (***OPCIONAL***)
    bool            IsKeyDown( eInputCode vkCode );
	// Devuelve true durante el frame que que el usuario ha dejado de pulsar una tecla (***OPCIONAL***)
    bool            IsKeyUp( eInputCode vkCode );

	// Est� el la el bot�n del rat�n tecla pulsado en este momento?
    bool            IsMouseButtonPressed( eInputCode button );
	// Devuelve true durante el frame que que el usuario ha comenzaco la pulsaci�n del bot�n del rat�n dado
    bool            GetMouseButtonDown( eInputCode button );
	// Devuelve true durante el frame que que el usuario ha dejado de pulsar el bot�n del rat�n dado
    bool            GetMouseButtonUp( eInputCode button );

    // Est� el boton del GamePAd pulsada en este momento?
    bool            IsXboxPressed( eInputCode vkCode );
	// Devuelve true durante el frame que que el usuario ha comenzaco la pulsaci�n boton del GamePAd (***OPCIONAL***)
    bool            IsXboxDown( eInputCode vkCode );
	// Devuelve true durante el frame que que el usuario ha dejado de pulsar boton del GamePAd  (***OPCIONAL***)
    bool            IsXboxUp( eInputCode vkCode );

private:
	InputManager(){ isOk = Init(); }
	int FromKeyToXboxStruct ( eInputCode key );

	Array<VirtualButton> virtualButtons;
	Array<VirtualAxis> virtualAxis;
	Array<eInputCode> pressed;
	Array<Key> keys;
	bool devicesOn[ NUM_DEVICES ];
	bool isOk;
	static InputManager* manager;
	double xMouse, yMouse;
};


#endif