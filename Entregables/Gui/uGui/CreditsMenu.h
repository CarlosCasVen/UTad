#ifndef _CREDITSMENU_H_
#define _CREDITSMENU_H_

#include "Menu.h"
#include "Button.h"
#include "Checkbox.h"
#include "Window.h"
#include "../include/array.h"


class CreditsMenu : public Menu
{
public:
	static CreditsMenu& instance();
	virtual void showScreen();
	
	virtual void onClick( Control* sender );
private:
	CreditsMenu();
	virtual bool init();

	static CreditsMenu* m_menu;
	Window* m_window;
	Label* m_author;
	Label* m_authorName;
	Button* m_exit;
};


#endif