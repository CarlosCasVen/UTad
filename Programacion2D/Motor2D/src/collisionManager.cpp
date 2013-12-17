#include "../include/collisionManager.h"
#include "../include/math.h"
#include <math.h>

bool CollisionManager::CircleToCircle(double x1, double y1, double r1, double x2, double y2, double r2) const
{
	double distanceC1C2 = pow( Distance( x1, y1, x2, y2 ), 2 );
	double distanceBetweenRadious = pow( r1 + r2, 2 );

	return distanceC1C2 <= distanceBetweenRadious; 
}


//bool CircleToPixels(double cx, double cy, double cr, const CollisionPixelData* pixels, double px, double py) const;


bool  CollisionManager::CircleToRect(double cx, double cy, double cr, double rx, double ry, double rw, double rh) const
{
	double magnitude = Distance( cx, cy, rx, ry );
	double xVector = ( rx - cx) / magnitude;
	double yVector = ry - cy / magnitude;
	
	xVector = xVector * cr + cx;
	yVector = yVector * cr + cy;

	return PointInRect( cx, cy, rx, ry, rw, rh );
}


//bool PixelsToPixels(const CollisionPixelData* p1, double x1, double y1, const CollisionPixelData* p2, double x2, double y2) const;


//bool PixelsToRect(const CollisionPixelData* pixels, double px, double py, double rx, double ry, double rw, double rh) const; 


bool CollisionManager::RectToRect(double x1, double y1, double w1, double h1, double x2, double y2, double w2, double h2) const
{
	return RectsOverlap( x1, y1, w1, h1, x2, y2, w2, h2 );
}