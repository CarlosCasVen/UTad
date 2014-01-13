#include "stdafx.h"

//---------------------------------------------

//---------------------------------------------
NextAction InputManager::ProcessInput()
{
	NextAction action;

	switch( _getch() )
	{
	case KEY_TO_MOVE_LEFT:
		action = HeroMoveLeft;
		break;
	case KEY_TO_MPVE_RIGHT:
		action = HeroMoveRight;
		break;
	case KEY_TO_SHOOT_LEFT:
		action = HeroShootLeft;
		break;
	case KEY_TO_SHOOT_RIGHT:
		action = HeroShootRight;
		break;
	case KEY_TO_EXIT:
		action = EndGame;
		break;
	default:
		action = HeroNoMovement;
	}

	return action;
}