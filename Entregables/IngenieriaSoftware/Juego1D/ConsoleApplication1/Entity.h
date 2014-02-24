#ifndef __ENTITY__
#define __ENTITY__

#include "stdafx.h"


class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual void Update() = 0;
	virtual void Render() = 0;

    bool Init( unsigned int initialPosition, bool isOk, bool inGame );
	void End();

	void SetIsInGame( bool inGame );

	bool IsInGame() const;
	bool GetIsOk() const;
	unsigned int GetPositionInWorld() const; 

	void MoveRight();
	void MoveLeft();	

private:
	bool m_isOk;
	bool m_inGame;

	unsigned int m_positionInWorld;
};

#endif