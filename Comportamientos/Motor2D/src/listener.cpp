#include <stdio.h>
#include "../include/listener.h"
#include <AL/al.h>


Listener* Listener::listener = NULL;

Listener& Listener::Instance()
{
    if( !listener )
        listener = new Listener();

    return *listener;
}
    

void Listener::SetPosition(float x, float y, float z)
{
    alListener3f( AL_POSITION, x, y, z );
}


void Listener::SetVelocity(float x, float y, float z)
{
    alListener3f( AL_VELOCITY, x, y, z );
}


void Listener::SetOrientation(float x, float y, float z)
{
    alListener3f( AL_ORIENTATION, x, y, z );
}


Listener::Listener()
{
    alListener3f( AL_POSITION, 0, 0, 0 );
    alListener3f( AL_VELOCITY, 0, 0, 0 );
    alListener3f( AL_ORIENTATION, 0, 0, 0 );
}