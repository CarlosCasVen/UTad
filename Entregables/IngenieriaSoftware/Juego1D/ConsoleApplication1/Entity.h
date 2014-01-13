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

	void End();
	void SetIsInGame( bool inGame );
	void MoveRight();
	void MoveLeft();

	bool Init( unsigned int initialPosition, bool isOk, bool inGame );
	bool GetIsOk() const;
	bool IsInGame() const;

	unsigned int GetPositionInWorld() const; 

private:
	bool m_isOk;
	bool m_inGame;

	unsigned int m_positionInWorld;

};

#endif