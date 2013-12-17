#ifndef _CREDITSSCREEN_H_
#define _CREDITSSCREEN_H_

#include "Label.h"
#include "Button.h"
#include "Window.h"

class CreditsScreen : public IEventListener
{
public:
	static CreditsScreen& instance(){ if( !creditsScreen ) creditsScreen = new CreditsScreen(); return *creditsScreen; }

	void Destroy(){ if( m_window ) delete m_window; if( m_credits ) delete m_credits; if( m_exit ) delete m_exit; }	
	void Active();

	virtual void onClick( Control* sender);

private:
	CreditsScreen(){ m_window = NULL; m_credits = NULL; m_exit = NULL; }

	void CreateGUI();

	static CreditsScreen* creditsScreen;

	Window* m_window;
	Label* m_credits;
	Button* m_exit;
};

#endif