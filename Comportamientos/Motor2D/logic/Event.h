#ifndef __EVENT__
#define __EVENT__



class IEntity;

enum TEvent
{
    ChangeScene,
};

class Event
{
public:
    Event( TEvent tEvent );

    TEvent GetType() const;

private:
	enum TEvent m_type;

};

#endif