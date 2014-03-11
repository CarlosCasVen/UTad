#ifndef __EVENT__
#define __EVENT__


enum TEvent;
class IEntity;


class Event
{
public:
    Event( TEvent tEvent );

    TEvent GetType() const;

private:
	enum TEvent m_type;

};

#endif