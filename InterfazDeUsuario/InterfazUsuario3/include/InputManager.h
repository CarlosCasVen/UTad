/************************************************************************************************************/
//
//
/************************************************************************************************************/

#ifndef _INPUT_MANAGER_H_
#define _INPUT_MANAGER_H_

#include "array.h"
#include "string.h"

/*
enum eInputCode2
{


KEY_UNKNOWN = -1,
KEY_SPACE = 32,
KEY_SPECIAL = 256,
KEY_ESC,
KEY_F1,
KEY_F2,
KEY_F3,
KEY_F4,
KEY_F5,
KEY_F6,
KEY_F7,
KEY_F8,
KEY_F9,
KEY_F1,
KEY_F11,
KEY_F12,
KEY_F13,
KEY_F14,
KEY_F15,
KEY_F17,
KEY_F18,
KEY_F19,
KEY_F20,
KEY_F21,
KEY_F22,
KEY_F23,
KEY_F24,
KEY_F25,
KEY_UP,
KEY_DOWN,
KEY_LEFT,
KEY_RIGHT,
KEY_LSHIFT,
KEY_RSHIFT,
KEY_LCTRL,
KEY_RCTRL,
KEY_LALT,
KEY_RALT,
KEY_TAB,
KEY_ENTER,
KEY_BACKSPACE,
KEY_INSERT,
KEY_DEL,
KEY_PAGEUP,
KEY_PAGEDOWN,
KEY_HOME,
KEY_END,
KEY_KP_0,
KEY_KP_1,
KEY_KP_2,
KEY_KP_3,
KEY_KP_4,
KEY_KP_5,
KEY_KP_6,
KEY_KP_7,
KEY_KP_8,
KEY_KP_9,
KEY_KP_DIVIDE,
KEY_KP_MULTIPLY,
_KEY_KP_SUBTRACT,
_KEY_KP_ADD,
KEY_KP_DECIMAL,
KEY_KP_EQUAL,
KEY_KP_ENTER,
KEY_KP_NUM_LOCK,
KEY_CAPS_LOCK,
KEY_SCROLL_LOCK,
KEY_PAUSE,
KEY_LSUPER,
KEY_RSUPER,
KEY_MENU,
//KEY_LAST GLFW_KEY_MENU,


GLFW_MOUSE_BUTTON_1 = 0,
MOUSE_BUTTON_2,
MOUSE_BUTTON_3,
MOUSE_BUTTON_4,
MOUSE_BUTTON_5,
MOUSE_BUTTON_6,
MOUSE_BUTTON_7,
MOUSE_BUTTON_8,
//MOUSE_BUTTON_LAST   GLFW_MOUSE_BUTTON_8,



MOUSE_BUTTON_LEFT   GLFW_MOUSE_BUTTON_1,
MOUSE_BUTTON_RIGHT  GLFW_MOUSE_BUTTON_2,
MOUSE_BUTTON_MIDDLE GLFW_MOUSE_BUTTON_3,





JOYSTICK_1 = 0,
JOYSTICK_2          1,
JOYSTICK_3          2,
JOYSTICK_4          3,
JOYSTICK_5          4,
JOYSTICK_6          5,
JOYSTICK_7          6,
JOYSTICK_8          7,
JOYSTICK_9          8,
JOYSTICK_10         9,
JOYSTICK_11         10,
JOYSTICK_12         11,
JOYSTICK_13         12,
JOYSTICK_14         13,
JOYSTICK_15         14,
JOYSTICK_16         15,
JOYSTICK_LAST       GLFW_JOYSTICK_16
}*/



// códigos que representan los distintos tipos de inputs posibles
enum eInputCode
{
  // Ratón
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
};

struct Button 
{
	eInputCode buttonsAssigned;
	String action;
	bool wasPreesedLastFrame;
};

struct VirtualAxis 
{
	eInputCode positiveAxis;
	eInputCode negativeAxis;
	String nameAxis;
	int movement;
	double lastX;
	double lastY;
};


class InputManager
{
  public:
	  static InputManager& Instance() {if ( !manager ) manager = new InputManager(); return *manager; }

	  InputManager(){ isOk = Init(); }
	  ~InputManager(){}

	// Inicialición: deteccción de dispostivos, inicialización de los mismos... etc
    bool            Init();

	// Cierre
    void            End();

	// Devuelve true si el manager ha sido inicializado correctamente
	bool IsOk(){ return isOk; }


	// Función de actualización, actualización de estados entre frames
    void            Update();
    

    // Crea un botón virtual
    void            CreateVirtualButton( const String& name, eInputCode button );
	// Crea un eje virtual
    void            CreateVirtualAxis( const String& name, eInputCode positiveAxis, eInputCode negativeAxis );

    // Está el botón pulsado en este momento?
    bool            IsVirtualButtonPressed( const String& name ) const;
	// Devuelve true durante el frame que que el usuario ha comenzaco la pulsación de un botón
    bool            IsVirtualButtonDown( const String& name ) const;
	// Devuelve true durante el frame que que el usuario ha dejado de pulsar un botón
    bool            IsVirtualButtonUp( const String& name ) const;

    // Estado de ejes virtuales normalizado de -1 a +1
    float           GetVirtualAxis( String name ) const;

    // Está el la tecla pulsada en este momento?
    bool            IsKeyPressed( eInputCode vkCode );
	// Devuelve true durante el frame que que el usuario ha comenzaco la pulsación de una tecla (***OPCIONAL***)
    bool            IsKeyDown( eInputCode vkCode );
	// Devuelve true durante el frame que que el usuario ha dejado de pulsar una tecla (***OPCIONAL***)
    bool            IsKeyUp( eInputCode vkCode );

	// Está el la el botón del ratón tecla pulsado en este momento?
    bool            IsMouseButtonPressed( eInputCode button );
	// Devuelve true durante el frame que que el usuario ha comenzaco la pulsación del botón del ratón dado
    bool            GetMouseButtonDown( eInputCode button );
	// Devuelve true durante el frame que que el usuario ha dejado de pulsar el botón del ratón dado
    bool            GetMouseButtonUp( eInputCode button );

private:
	Array<Button> actions;
	Array<VirtualAxis> virtualAxis;
	Array<eInputCode> buttonsPressed;
	bool isOk;
	static InputManager* manager;
};


#endif