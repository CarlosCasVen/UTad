#ifndef _CONFIGMENU_H_
#define _CONFIGMENU_H_

#include "Menu.h"
#include "Slider.h"
#include "Button.h"
#include "Checkbox.h"
#include "Window.h"
#include "../include/array.h"


class ConfigMenu : public Menu
{
public:
	static ConfigMenu& instance();
	virtual void showScreen();

	virtual void onClick( Control* sender );
	
private:
	ConfigMenu();
	virtual bool init();

	static ConfigMenu* m_menu;
	Window* m_window;
	Checkbox* m_gore;
	Checkbox* m_particles;
	Checkbox* m_autosave;
	Slider* m_sound;
	Button* m_exit;
};


#endif