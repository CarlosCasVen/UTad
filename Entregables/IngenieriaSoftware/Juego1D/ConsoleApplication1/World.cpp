#include "stdafx.h"

//---------------------------------------------

//---------------------------------------------
World::World()
{
	m_isOk = false;
}
//---------------------------------------------

//---------------------------------------------
World::~World()
{
	End();
}
//---------------------------------------------

//---------------------------------------------
bool World::Init()
{
	m_hero = new EntHero();
	m_hero->Init( WORLD_WIDTH / 2, true );
	m_nBullets = 0;
	m_nEnemies = 0;
	m_nRainDrops = 0;
	m_timeToNextEnemy = 0;
	m_timeToNextRainDrop = 0;
	m_score = 0;
	m_nBulletsShooted = 0;

	if( m_hero )
	{
		m_isOk = true;
	}

	return m_isOk;
}
//---------------------------------------------

//---------------------------------------------
void World::End()
{
	m_isOk = false;
	delete m_hero;
	
	for( unsigned int i = 0; i < m_rainDrops.Size(); i++ )
	{
		delete m_rainDrops[i];
	}

	for( unsigned int i = 0; i < m_enemies.Size(); i++ )
	{
		delete m_enemies[i];
	}

	for( unsigned int i = 0; i < m_bullets.Size(); i++ )
	{
		delete m_bullets[i];
	}

	m_rainDrops.Clear();
	m_enemies.Clear();
	m_bullets.Clear();
}
//---------------------------------------------

//---------------------------------------------
void World::CreateNewEntities()
{
	if(_kbhit())
	{
		switch( InputManager::ProcessInput() )
		{
		case HeroMoveLeft:
			{
				m_hero->SetMovementDirection( LeftDirection );
				break;
			}
		case HeroMoveRight:	
			{
				m_hero->SetMovementDirection( RightDirection );
				break;
			}
		case HeroShootLeft:
			{
				if( m_nBullets < MAX_NUM_BULLETS && m_hero->IsAlive() )
				{
					EntBullet* bullet = new EntBullet();
					bullet->Init( m_hero, LeftDirection, true );
					m_bullets.Add( bullet );
					m_hero->SetMovementDirection( NoDirection );
					m_nBullets++;
					m_nBulletsShooted++;
				}
				
				break;
			}
		case HeroShootRight:
			{
				if( m_nBullets < MAX_NUM_BULLETS && m_hero->IsAlive() )
				{
					EntBullet* bullet = new EntBullet();
					bullet->Init( m_hero, RightDirection, true );
					m_bullets.Add( bullet );
					m_hero->SetMovementDirection( NoDirection );
					m_nBullets++;
					m_nBulletsShooted++;
				}
				
				break;
			}
		case EndGame:
			{
				End();
				exit(0);
				break;
			}
		default:
			{
				m_hero->SetMovementDirection( NoDirection );
				break;
			}
		}
	}
	else
	{
		m_hero->SetMovementDirection( NoDirection );
	}
}
//---------------------------------------------

//---------------------------------------------
void World::Update()
{
	CreateNewEntities();
	NewEnemy();
	NewRainDrop();

	for( unsigned int i = 0; i < m_enemies.Size(); i++ )
	{
		m_enemies[i]->Update();
	}

	DetectCollisionAndDestroy();

	for( unsigned int i = 0; i < m_bullets.Size(); i++ )
	{
		m_bullets[i]->Update();
	}

	for( unsigned int i = 0; i < m_rainDrops.Size(); i++ )
	{
		m_rainDrops[i]->Update();
	}

	
	m_hero->Update();
	DetectCollisionAndDestroy();
	
}
//---------------------------------------------

//---------------------------------------------
void World::Render()
{
	DrawFunction::Clear();

	if( m_hero->IsAlive() )
	{
		DrawFunction::PrintWorld();
	
		for( unsigned int i = 0; i < m_rainDrops.Size(); i++ )
		{
			m_rainDrops[i]->Render();
		}

		for( unsigned int i = 0; i < m_enemies.Size(); i++ )
		{
			m_enemies[i]->Render();
		}
		
		for( unsigned int i = 0; i < m_bullets.Size(); i++ )
		{
			m_bullets[i]->Render();
		}

		m_hero->Render();
	}
	else
	{
		DrawFunction::GameOver( m_score, m_nBulletsShooted );
	}
}
//---------------------------------------------

//---------------------------------------------
void World::NewEnemy()
{
	if( m_nEnemies < MAX_NUM_ENEMIES )
	{
		if( m_timeToNextEnemy <= 0 )
		{
			m_timeToNextEnemy = rand() % MAX_TIME_BETWEEN_ENEMIES;
			m_nEnemies++;
			EntEnemy* enemy = new EntEnemy();
			enemy->Init( m_hero, true );
			m_enemies.Add( enemy );
		}
	}
	m_timeToNextEnemy--;
}
//---------------------------------------------

//---------------------------------------------
void World::NewRainDrop()
{
	if( m_nRainDrops < MAX_NUM_RAIN_DROPS )
	{
		if( m_timeToNextRainDrop <= 0 )
		{
			m_timeToNextRainDrop = rand() % MAX_TIME_BETWEEN_RAIN_DROPS;
			m_nRainDrops++;
			EntRainDrop* drop = new EntRainDrop();
			drop->Init( true );
			m_rainDrops.Add( drop );
		}
	}

	m_timeToNextRainDrop--;
}
//---------------------------------------------

//---------------------------------------------
void World::DetectCollisionAndDestroy()
{
	for( unsigned int i = 0; i < m_enemies.Size(); i++ )
	{
		if( m_enemies[i]->GetPositionInWorld() == m_hero->GetPositionInWorld() )
		{
			m_hero->SetIsAlive( false );
			m_enemies[i]->SetIsInGame( false );
		}
		
		for( unsigned int k = 0; k < m_bullets.Size(); k++ )
		{
			if( m_enemies[i]->GetPositionInWorld() == m_bullets[k]->GetPositionInWorld() )
			{
				m_enemies[i]->SetIsInGame( false );
				m_bullets[k]->SetIsInGame( false );	
				m_score++;
			}
		}
	}

	for( int i = m_enemies.Size() - 1; i >= 0; i-- )
	{
		if( !m_enemies[i]->IsInGame() )
		{
			delete m_enemies[i];
			m_enemies.RemoveAt( i );
			m_nEnemies--;
		}
	}

	for( int i = m_bullets.Size() - 1; i >= 0; i-- )
	{
		if( !m_bullets[i]->IsInGame() )
		{
			delete m_bullets[i];
			m_bullets.RemoveAt( i );
			m_nBullets--;
		}
	}

	for( int i = m_rainDrops.Size() - 1; i >= 0; i-- )
	{
		if( !m_rainDrops[i]->IsInGame() )
		{
			delete m_rainDrops[i];
			m_rainDrops.RemoveAt( i );
			m_nRainDrops--;
		}
	}
}