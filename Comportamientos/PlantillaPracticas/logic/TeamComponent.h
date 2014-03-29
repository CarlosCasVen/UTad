#ifndef __TEAM_COMPONENT__
#define __TEAM_COMPONENT__

#include "BaseComponent.h"
#include "../json/rapidjson/document.h"


class TeamComponent : public BaseComponent
{
public:
    TeamComponent ();
    ~TeamComponent();

    virtual TError Init();
    virtual void   End ();

    virtual void Update( double elapsedTime );

    void         SetTeam  ( unsigned int teamId );
    unsigned int GetTeamId()                const;

private:
    unsigned int m_teamId;

};


#endif