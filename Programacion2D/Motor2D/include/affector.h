#ifndef UGINE_AFFECTOR_H
#define UGINE_AFFECTOR_H

#include "affector.h"
#include "particle.h"
#include "array.h"
#include "types.h"


class Affector
{
public:
	Affector(){ mode = ALL_DESACTIVE; };
	Affector( double boundx0, double boundy0, double boundx1, double boundy1 );
	void SetMinColor( uint8 r, uint8 g, uint8 b ){ this->minr = r; this->ming = g; this->minb = b; };
	void SetMaxColor( uint8 r, uint8 g, uint8 b ){ this->maxr = r; this->maxg = g; this->maxb =b; };
	void SetVelX( double minvelx, double maxvelx ){ this->minvelx = minvelx; this->maxvelx = maxvelx; };
	void SetVelY( double minvely, double maxvely ){ this->minvely = minvely; this->maxvely = maxvely; };
	void SetVelAng( double minangvel, double maxangvel ){ this->minangvel = minangvel; this->maxangvel = maxangvel; };
	void SetRegion( double bx0, double by0, double bx1, double by1 ){ this->boundx0 = bx0; this->boundy0 = by0; this->boundx1 = bx1; this->boundy1 = by1; };
	bool IsActive(){ return mode == 0; };
	void Stop(){ mode = ALL_DESACTIVE; };
	void Start( char flag = ALL_ACTIVE ){ mode = flag; };
	void SetFlag ( char flags = ALL_DESACTIVE ){ mode = flags; };
	

	void AddParticles( Particle* particles );
	void DeleteParticles( Particle* particle);

	int32 RangeRand ( int32 minRange, int32 maxRange );

private:
	void Apply( Particle* particle); 

	uint8 minr, ming, minb;
	uint8 maxr, maxg, maxb;
	double minvelx, maxvelx;
	double minvely, maxvely;
	double minangvel, maxangvel;
	double boundx0, boundx1, boundy0, boundy1;
	Array<Particle*> particlesModified;
	char mode;

};


#endif