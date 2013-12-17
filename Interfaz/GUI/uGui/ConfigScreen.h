#ifndef _CONFIGSCREEN_H_
#define _CONFIGSCREEN_H_

#include "Button.h"
#include "Window.h"
#include "Label.h"
#include "Checkbox.h"
#include "Slider.h"


class ConfigScreen : public IEventListener
{
public:
	static ConfigScreen& instance(){ if( !configScreen ) configScreen = new ConfigScreen(); return *configScreen; }

	void Destroy(){  if( m_window ) delete m_window; if( m_gore ) delete m_gore; if( m_particles ) delete m_particles; if( m_autosave ) delete m_autosave; if( m_exit ) delete m_exit; }
	void Active();

	virtual void onClick( Control* sender);

private:
	ConfigScreen(){ m_window = NULL; m_gore = NULL; m_particles = NULL; m_autosave = NULL; m_autosave = NULL; m_exit = NULL; };

	void CreateGUI();

	static ConfigScreen* configScreen;

	Window* m_window;
	Checkbox* m_gore;
	Checkbox* m_particles;
	Checkbox* m_autosave;
	Button* m_exit;
	Slider* m_sound;
};

#endif