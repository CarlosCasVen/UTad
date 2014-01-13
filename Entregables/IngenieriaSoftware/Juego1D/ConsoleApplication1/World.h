#ifndef __WORLD__
#define __WORLD__

#include "stdafx.h"


class World
{
public:
	World();
	~World();

	bool Init();
	
	void End();
	void CreateNewEntities();
	void Update();
	void Render();
	void NewEnemy();
	void NewRainDrop();
	void DetectCollisionAndDestroy();

	unsigned int GetScore();

private:
	Array<EntRainDrop*> m_rainDrops;
	Array<EntEnemy*> m_enemies;
	Array<EntBullet*> m_bullets;

	EntHero* m_hero;

	bool m_isOk;

	unsigned int m_nBullets;
	unsigned int m_nEnemies;
	unsigned int m_nRainDrops;
	unsigned int m_timeToNextEnemy;
	unsigned int m_timeToNextRainDrop;
	unsigned int m_score;
	unsigned int m_nBulletsShooted;

};

#endif