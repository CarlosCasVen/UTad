#ifndef UGINE_PIXELCOLLISION_H
#define UGINE_PIXELCOLLISION_H

#include "collision.h"
#include "collisionPixelData.h"
#include "../include/collisionmanager.h"


class PixelCollision : public Collision {
public:
	PixelCollision( double* x, double* y, const CollisionPixelData* pixels ) : x( x ), y( y ), pixels( pixels ) { }

	virtual bool DoesCollide(const Collision* other) const { return other->DoesCollide( pixels, *x, *y); }
	virtual bool DoesCollide(double cx, double cy, double cradius) const { return CollisionManager::Instance().CircleToPixels( cx, cy, cradius, pixels, *x, *y ); }
	virtual bool DoesCollide(double rx, double ry, double rwidth, double rheight) const { return CollisionManager::Instance().PixelsToRect( pixels, *x, *y, rx, ry, rwidth, rheight ); }

	virtual bool DoesCollide(const CollisionPixelData* pixels, double px, double py) const { return CollisionManager::Instance().PixelsToPixels( pixels, px, py, pixels, *x, *y ); }

private:
    double* x;
    double* y;
	const CollisionPixelData* pixels;
};

#endif