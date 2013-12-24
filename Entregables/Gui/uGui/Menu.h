#ifndef _MENU_H_
#define _MENU_H_

#include "IEventListener.h"


class Menu : public IEventListener
{
public:
	virtual void showScreen() = 0;
	
private:
	virtual bool init() = 0;
};


#endif