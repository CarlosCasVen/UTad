#include "../include/affector.h"
#include "../include/particle.h"	


Affector::Affector( double boundx0, double boundy0, double boundx1, double boundy1, bool active ) : boundx0( boundx0 ), boundy0( boundy0 ), boundx1( boundx1 ), boundy1( boundy1 ), active( active )
{
	minr = ming = minb = 0;
	maxr = maxg = maxb = 0;
	minvelx = maxvelx = 0;
	minvely = maxvely = 0;
	minangvel = maxangvel = 0;
}
	

	
void Affector::AddParticles( Particle* particles )
{
	bool insideBounding = false;

	if( particles->GetX() >= boundx0 && particles->GetX() <=  boundx1 &&
	particles->GetY() >= boundy0 && particles->GetY() <=  boundy1 )
	{
		insideBounding = true;
	}


	for( unsigned int i = 0; i < particlesModified.Size() && insideBounding; i++ )
	{
		if( particles == particlesModified[i] )
		{
			insideBounding = false;
		}
	}

	if( insideBounding )
	{
		//particlesModified.Add( particles );
		Apply( particles );
	}
}
	
void Affector::ApplyAffector( Array<Particle>* particles )
{
	for( unsigned int i = 0; i < particles->Size(); i++ )
	{
		AddParticles( &particles[0][i] );
	}
}


void Affector::Apply( Particle* particle)
{
	
	particle->SetVelocityX( RangeRand(minvelx, maxvelx ) );
	particle->SetVelocityY( RangeRand(minvely, maxvely ) );
	particle->SetVelocityAngle( RangeRand(minangvel, maxangvel ) );
	particle->SetColor( RangeRand(minr, maxr ), RangeRand(ming, maxg ), RangeRand(minb, maxb ), particle->GetAlpha() );
}



void Affector::DeleteParticles()
{
	Array<int> index;

	for( int i = 0; i < particlesModified.Size(); i++ )
	{
		Particle* part =  particlesModified[i];
		if( particlesModified[i]->GetLifetime() <= 0 )
		{
			index.Add(i);
		}
	}

	for( int i = index.Size() - 1; i >= 0; i-- )
	{
		particlesModified.RemoveAt( index[i] );
	}
}


int32 Affector::RangeRand ( int32 minRange, int32 maxRange )
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