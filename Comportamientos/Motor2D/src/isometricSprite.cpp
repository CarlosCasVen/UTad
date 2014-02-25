#include "../include/isometricSprite.h"
#include "../include/math.h"
#include "../include/image.h"
#include <math.h>

IsometricSprite::IsometricSprite(Image* image) : Sprite( image )
{
	screenX = 0;
	screenY = 0;
}


void IsometricSprite::SetCollision(CollisionMode mode)
{
	if( mode == COLLISION_PIXEL )
	{
		Sprite::SetCollision( COLLISION_RECT );
	}
	else
	{
		Sprite::SetCollision( mode );
	}
}


void IsometricSprite::Update(double elapsed, const Map* map )
{
	Sprite::Update( elapsed, map );
	TransformIsoCoords( GetX(), GetY(), GetZ(), &screenX, &screenY );
	
}


void IsometricSprite::UpdateCollisionBox()
{
	const Image* image = GetImage();
	double x = GetX() - image->GetHandleX() *  fabs( GetScaleX() ); 
	double y = GetY() - image->GetHandleX() *  fabs( GetScaleX() ); 
	double w = image->GetWidth() * fabs( GetScaleX() ); 
	double h = image->GetHeight() * fabs( GetScaleX() );

	Sprite::UpdateCollisionBox( x, y, w, h);
}