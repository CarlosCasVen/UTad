#ifndef _GAMEMENU_H_
#define _GAMEMENU_H_

#include "KeyListenerControl.h"
#include "Control.h"
#include "Menu.h"
#include "../include/scene.h"

class GameMenu : public Menu
{
public:
	static GameMenu& instance();
	virtual void showScreen();

	virtual void onKeyDown( Control* sender, int keyCode );
	
private:
	GameMenu();
	virtual bool init();

	static GameMenu* m_menu;


	KeyListenerControl* m_listener;
	Scene m_scene;

};


#endif