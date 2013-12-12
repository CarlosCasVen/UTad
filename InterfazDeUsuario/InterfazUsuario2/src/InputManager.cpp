#include "..\include\InputManager.h"
#include "..\include\glinclude.h"
#include "..\include\screen.h"


InputManager* InputManager::manager = NULL;

// Inicialición: deteccción de dispostivos, inicialización de los mismos... etc
bool InputManager::Init()
{
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
