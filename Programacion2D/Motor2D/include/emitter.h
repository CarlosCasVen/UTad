#ifndef UGINE_EMITTER_H
#define UGINE_EMITTER_H

#include "affector.h"
#include "particle.h"
#include "renderer.h"
#include "image.h"
#include "array.h"
#include "types.h"


class Emitter
{
public:
	Emitter(Image* image, bool autofade);
	virtual void SetPosition(double x, double y){ SetX( x ); SetY(y); };
	virtual void SetX(double x){ this->x = x; };
	virtual void SetY(double y){ this->y = y; };
	virtual double GetX() const{ return x; };
	virtual double GetY() const{ return y; };
	virtual void SetRate(double minrate, double maxrate){ this->minrate = minrate; this->maxrate = maxrate; };
	virtual void SetVelocityX(double minvelx, double maxvelx){ this->minvelx = minvelx; this->maxvelx = maxvelx; };
	virtual void SetVelocityY(double minvely, double maxvely){ this->minvely = minvely; this->maxvely = maxvely; };
	virtual void SetAngularVelocity(double minangvel, double maxangvel){ this->minangvel = minangvel; this->maxangvel = maxangvel; };
	virtual void SetLifetime(double minlifetime, double maxlifetime){ this->minlifetime = minlifetime; this->maxlifetime = maxlifetime; };
	virtual void SetMinColor(uint8 r, uint8 g, uint8 b){ this->minr = r; this->ming = g; this->minb = b; }; 
	virtual void SetMaxColor(uint8 r, uint8 g, uint8 b){ this->maxr = r; this->maxg = g; this->maxb = b; }; 
	virtual void SetBlendMode(Renderer::BlendMode mode){ this->blendMode = mode; };
	virtual void Start(){ this->emitting = true; }; 
	virtual void Stop(){ this->emitting = false;}; 
	virtual bool IsEmitting() const{ return emitting; };
	virtual void Update(double elapsed); 
	virtual void Render() const; 

	void AddAffector( Affector* affector );

private:
	Image* image; 
	bool autofade; 
	double x, y; 
	double minrate, maxrate;
	double minvelx, maxvelx;
	double minvely, maxvely;
	double minangvel, maxangvel;
	double minlifetime, maxlifetime;
	uint8 minr, ming, minb;
	uint8 maxr, maxg, maxb;
	Renderer::BlendMode blendMode;
	bool emitting; 
	Array<Particle*> particles;
	Array<Affector> affectors;
};



#endif