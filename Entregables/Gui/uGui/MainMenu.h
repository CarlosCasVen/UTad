#ifndef _MAINMENU_H_
#define _MAINMENU_H_

#include "Menu.h"
#include "Button.h"
#include "Window.h"
#include "../include/array.h"


class MainMenu : public Menu
{
public:
	static MainMenu& instance();
	virtual void showScreen();
	
	virtual void onClick( Control* sender );

private:
	MainMenu();
	virtual bool init();

	static MainMenu* m_menu;
	Window* m_window;
	Button* m_start;
	Button* m_config;
	Button* m_credits;
	Button* m_exit;
	Button* m_yes;
	Button* m_no;
};


#endif