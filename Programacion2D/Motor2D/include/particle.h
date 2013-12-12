#ifndef UGINE_PARTICLE_H
#define UGINE_PARTICLE_H

#include "sprite.h"
#include "types.h"

class Particle : public Sprite
{
public:
	Particle();
	Particle(Image* image, double velx, double vely, double angularVel, double lifetime, bool autofade); 
	virtual double GetLifetime() const{ return lifetime; };  
	virtual void Update(double elapsed);
	bool operator== ( const Particle& particle);

	void SetVelocityX( double velX ){ this->velocityx = velX; };
	void SetVelocityY ( double velY ){ this->velocityy = velY; };
	void SetVelocityAngle ( double velAngle){ this->angularVelocity = velAngle; };
	void SetLifetTime ( double lifetime ){ this->lifetime = lifetime; };
	void SetAutoFade ( double autofade ){ this->autofade = autofade; };

private: 
	double velocityx, velocityy;
	double angularVelocity; 
	double lifetime; 
	double initialLifetime; 
	bool autofade;
};

#endif