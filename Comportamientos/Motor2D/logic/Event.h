#ifndef __EVENT__
#define __EVENT__

#include <stdio.h>

enum TEvent;
class BaseEntity;

class Event
{
public:
	Event( TEvent tEvent );
	~Event();
	TEvent GetTEvent() const;

private:
	TEvent type;
};

#endif