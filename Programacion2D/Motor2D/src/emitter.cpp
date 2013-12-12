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

	Array <int> particlesToRemove;
	//eliminacion de particulas

	for( unsigned int i = 0; i < particles.Size(); i++ )
	{
		particles[i]->Update( elapsed );
		
		for( unsigned int a = 0; a < affectors.Size(); a++ ) affectors[a].AddParticles( particles[i] );
			
		if( particles[i]->GetLifetime() <= 0 )
		{
			particlesToRemove.Add( i );
			delete particles[i];
		
			for( unsigned int a = 0; a < affectors.Size(); a++ ) affectors[a].DeleteParticles( particles[i] );			
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

	IsEmitting() ? nParticles = (int32)(MaxMinRand ((int32)minrate, (int32)maxrate ) * elapsed) : (int32)nParticles = 0;

	for( uint32 i = 0; i < (uint32)nParticles; i++ )
	{
		velX = (double)MaxMinRand( (int32)minvelx, (int32)maxvelx );
		velY = (double)MaxMinRand( (int32)minvely, (int32)maxvely ); 
		velAng = (double)MaxMinRand( (int32)minangvel, (int32)maxangvel ); 
		life = (double)MaxMinRand( (int32)minlifetime, (int32)maxlifetime) ;
		r = (uint8)MaxMinRand( (int32)minr, (int32)maxr );
		g = (uint8)MaxMinRand( (int32)ming, (int32)maxg );
		b = (uint8)MaxMinRand( (int32)minb, (int32)maxb );

		Particle *particle = new Particle( image, velX, velY, velAng, life, autofade );

		particle->SetPosition( x, y );
		particle->SetColor( r, g, b, 255 );
		particle->SetBlendMode( blendMode );

		particles.Add( particle );
	}
	//fin creacion particulas
}


void Emitter::Render() const
{

	for( unsigned int i = 0; i < particles.Size(); i++ )
	{
		particles[i]->Render();
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