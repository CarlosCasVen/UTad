#ifndef __GAME__
#define __GAME__

#include "IGame.h"


enum TError;


class Game : public IGame
{
public:
    virtual TError  Init();
    virtual void    End ();

    virtual void Update( double elapsedTime );
    virtual void Render();

    virtual bool IsFinish() const;

};


#endif