#ifndef _FIRSTMENU_H_
#define _FIRSTMENU_H_

#include "Window.h"
#include "Button.h"
#include "Label.h"

class FirstMenu : public IEventListener
{
public:
	static FirstMenu& instance(){ if( !firstMenu ) firstMenu = new FirstMenu(); return *firstMenu; }

	void Destroy(){ if( m_window ) delete m_window; if( m_start ) delete m_start; if( m_config ) delete m_config; if( m_credits ) delete m_credits; if( m_exit ) delete m_exit; }
	void Active();

	virtual void onClick( Control* sender);
	virtual void onKeyDown( Control* sender, int keyCode );

private:
	FirstMenu(){  m_window = NULL; m_start = NULL; m_config = NULL; m_credits = NULL; m_exit = NULL; m_yes = NULL; m_no = NULL; }

	void CreateGUI();

	void StartGame();

	static FirstMenu* firstMenu;

	Window* m_window;
	Button* m_start;
	Button* m_config;
	Button* m_credits;
	Button* m_exit;
	Button* m_yes;
	Button* m_no;
};


#endif