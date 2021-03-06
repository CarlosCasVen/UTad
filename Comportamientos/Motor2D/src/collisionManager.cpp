#include "../include/collisionManager.h"
#include "../include/math.h"
#include "../include/collisionPixelData.h"
#include <math.h>


CollisionManager* CollisionManager::manager; 


bool CollisionManager::CircleToCircle(double x1, double y1, double r1, double x2, double y2, double r2) const
{
	double distanceC1C2 = PowDistance( x1, y1, x2, y2 );
	double distanceBetweenRadious = r1 + r2;
	distanceBetweenRadious *= distanceBetweenRadious;
	
	return distanceC1C2 <= distanceBetweenRadious; 
}


bool CollisionManager::CircleToPixels(double cx, double cy, double cr, const CollisionPixelData* pixels, double px, double py) const
{
	
	bool isCollision = false;

	if( CircleToRect( cx, cy, cr, px, py, pixels->GetWidth(), pixels->GetHeight() ) )
	{
	
		double outx = 0.0, outy = 0.0, outw = 0.0, outh = 0.0;
		OverlappingRect( cx - cr, cy - cr, 2 * cr, 2 * cr, px, py, pixels->GetWidth(), pixels->GetHeight(), &outx, &outy, &outw, &outh );
		double xP1 = outx - px;
		double yP1 = outy - py;		

		for( unsigned int i = 0; i < outh && !isCollision; i++ )
		{
			for( unsigned int a = 0; a < outw && !isCollision; a++ )
			{
				if( pixels->GetData( (uint32) ( xP1 + a ), (uint32) ( yP1 + i ) ) )
				{
					isCollision = PowDistance( outx + a, outy + i, cx, cy ) <= ( cr * cr );
				}
			}
		}
	}

	return isCollision;
}


bool  CollisionManager::CircleToRect(double cx, double cy, double cr, double rx, double ry, double rw, double rh) const
{
	double outx = 0;
	double outy = 0;

	ClosestPointToRect( cx, cy, rx, ry, rw, rh, &outx, &outy );

	double distance = PowDistance( cx, cy, outx, outy );
	return ( cr * cr ) >= distance;
}


bool CollisionManager::PixelsToPixels(const CollisionPixelData* p1, double x1, double y1, const CollisionPixelData* p2, double x2, double y2) const
{
	bool isCollision = false;

	if( RectToRect( x1, y1, p1->GetWidth(), p1->GetHeight(), x2, y2, p2->GetWidth(), p2->GetHeight() ) )
	{
	
		double outx = 0.0, outy = 0.0, outw = 0.0, outh = 0.0;

		 OverlappingRect( x1, y1, p1->GetWidth(), p1->GetHeight(), x2, y2, p2->GetWidth(), p2->GetHeight(), &outx, &outy, &outw, &outh);

		double xP1 = outx - x1;
		double yP1 = outy - y1;
		double xP2 = outx - x2;
		double yP2 = outy - y2;
		

		for( unsigned int i = 0; i < outh && !isCollision; i++ )
		{
			for( unsigned int a = 0; a < outw && !isCollision; a++ )
			{
				if( p1->GetData( (uint32) ( xP1 + a ), (uint32) ( yP1 + i ) ) && p2->GetData( (uint32) ( xP2 + a ), (uint32) ( yP2 + i ) ) )
				{
					isCollision = true;
				}
			}
		}
	}

	return isCollision;
}


bool CollisionManager::PixelsToRect(const CollisionPixelData* pixels, double px, double py, double rx, double ry, double rw, double rh) const
{

	bool isCollision = false;

	if( RectToRect( px, py, pixels->GetWidth(), pixels->GetHeight(), rx, ry, rw, rh ) )
	{
	
		double outx = 0.0, outy = 0.0, outw = 0.0, outh = 0.0;

		 OverlappingRect( px, py, pixels->GetWidth(), pixels->GetHeight(), rx, ry, rw, rh, &outx, &outy, &outw, &outh);

		double xP1 = outx - px;
		double yP1 = outy - py;		

		for( unsigned int i = 0; i < outh && !isCollision; i++ )
		{
			for( unsigned int a = 0; a < outw && !isCollision; a++ )
			{
				if( pixels->GetData( (uint32) ( xP1 + a ), ( uint32) ( yP1 + i ) ) )
				{
					isCollision = true;
				}
			}
		}
	}

	return isCollision;
}

bool CollisionManager::RectToRect(double x1, double y1, double w1, double h1, double x2, double y2, double w2, double h2) const
{

	return RectsOverlap( x1, y1, w1, h1, x2, y2, w2, h2 );

}