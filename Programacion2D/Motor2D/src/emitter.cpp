#include "../include/emitter.h"
#include "../include/types.h"
#include "../include/affector.h"

Emitter::Emitter(Image* image, bool autofade) : image( image ), autofade( autofade )
{

	x = y = 0; 
	minrate = maxrate = 0;
	minvelx = maxvelx = 0;
	minvely = maxvely = 0;
	minangvel = maxangvel = 0;
	minlifetime = maxlifetime = 0;
	minr = ming = minb = 0;
	maxr = maxg = maxb = 255;
	blendMode = Renderer::BlendMode::ADDITIVE;
	emitting = false; 
}


void Emitter::Update(double elapsed)
{

	Array <int> particlesToRemove ( 0 );
	//eliminacion de particulas

	for( unsigned int i = 0; i < particles.Size(); i++ )
	{
		particles[i].Update( elapsed );

		if( particles[i].GetLifetime() <= 0 )
		{
			particlesToRemove.Add( i );
		}
	}

	if( affectors.Size() > 0 )
	{
		for( unsigned int i = 0; i < affectors.Size(); i++ )
		{
			affectors[i].ApplyAffector( &particles );
		
			affectors[i].DeleteParticles();
		}	
	}


	for( int i = particlesToRemove.Size() - 1; i >= 0 ; i-- )
	{
		particles.RemoveAt( particlesToRemove[i] );
	}

	//fin eliminacion particulas


	//creacion de particulas

	int32 nParticles;
	double velX, velY, velAng, life;
	uint8 r, g, b;

	IsEmitting() ? nParticles = (int32)MaxMinRand ( minrate, maxrate ) * elapsed : nParticles = 0;

	for( uint32 i = 0; i < nParticles; i++ )
	{
		velX = (double)MaxMinRand( minvelx, maxvelx );
		velY = (double)MaxMinRand( minvely, maxvely ); 
		velAng = (double)MaxMinRand( minangvel, maxangvel ); 
		life = (double)MaxMinRand( minlifetime, maxlifetime) ;
		r = (uint8)MaxMinRand( minr, maxr );
		g = (uint8)MaxMinRand( ming, maxg );
		b = (uint8)MaxMinRand( minb, maxb );

		Particle particle ( image, velX, velY, velAng, life, autofade );

		particle.SetPosition( x, y );
		particle.SetColor( r, g, b, 255 );
		particle.SetBlendMode( blendMode );

		particles.Add( particle );
	}
	//fin creacion particulas
}


void Emitter::Render() const
{

	for( unsigned int i = 0; i < particles.Size(); i++ )
	{
		particles[i].Render();
	}
}


int32 Emitter::MaxMinRand ( int32 minRange, int32 maxRange )
{
	int32 range = maxRange - minRange;
	int32 randomValue = 0;
	if( range != 0 )
	{
		randomValue = rand() % range;
	}
	
	randomValue += minRange;

	return randomValue;
}


void Emitter::AddAffector( Affector* affector )
{ 
	if( affector != NULL ) 
		affectors.Add( *affector ); 
}