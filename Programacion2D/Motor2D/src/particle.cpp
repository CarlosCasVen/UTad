#include "../include/particle.h"
#include "../include/image.h"



Particle::Particle() : Sprite( NULL )
{
	velocityx = velocityy = angularVelocity = 0;
	lifetime = 0;
	autofade = false;
}


Particle::Particle(Image* image, double velx, double vely, double angularVel, double lifetime, bool autofade) : Sprite( image )
{
	this->velocityx = velx;
	this->velocityy = vely;
	this-> angularVelocity = angularVel;
	this->initialLifetime = this->lifetime = lifetime;
	this->autofade = autofade;
	SetBlendMode( Renderer::BlendMode::ADDITIVE );
}


void Particle::Update(double elapsed)
{
	SetX( GetX() + velocityx * elapsed );
	SetY( GetY() + velocityy * elapsed );

	SetAngle( GetAngle() + angularVelocity * elapsed );

	if( autofade)
	{
		lifetime -= elapsed;

		if( lifetime < 0 ) 
		{
			lifetime = 0;
		}

		uint8 alpha = (lifetime * 255) / initialLifetime; 
		SetColor( GetRed(), GetGreen(), GetBlue(), alpha );
	}
}


bool Particle::operator== ( const Particle& particle)
{
	return velocityx == particle.velocityx && velocityy == particle.velocityy && angularVelocity == particle.angularVelocity && lifetime == particle.lifetime && autofade == autofade;
}