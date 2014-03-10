#ifndef __ILISTENER__
#define __ILISTENER__


class Event;


class IListener
{
public:
    virtual void ReceiveEvent( Event& newEvent ) = 0;
    virtual unsigned long int GetId() const      = 0;
};


#endif