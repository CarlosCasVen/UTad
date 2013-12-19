#include "../include/camera.h"
#include "../include/sprite.h"
#include "../include/screen.h"


void Camera::SetPosition(double x, double y)
{ 	
	SetX(x);
	SetY(y);
}



void Camera::SetX(double x)
{
	if(HasBounds())
	{
		if( x < boundx0)
		{
			x = boundx0;
		}
		else if( x > boundx1)
		{
			x = boundx1;
		}
	}

	this->x = x;
}


void Camera::SetY(double y)
{ 
	if(HasBounds())
	{
		if( y < boundy0)
		{
			y = boundy0;
		}
		else if( y > boundy1)
		{
			y = boundy1;
		}
	}

	this->y = y;
}


void Camera::SetBounds(double bx0, double by0, double bx1, double by1)
{
	boundx0 = bx0; 
	boundy0 = by0; 
	boundx1 = bx1 - Screen::Instance().GetWidth(); 
	boundy1 = by1 - Screen::Instance().GetHeight();
}


void Camera::Update()
{
	if(followingSprite)
	{
		SetPosition( followingSprite->GetX() - Screen::Instance().GetWidth() / 2, followingSprite->GetY() - Screen::Instance().GetHeight() / 2);
	}
}


void Camera::FollowSprite(Sprite* sprite)
{ 
	followingSprite = sprite; 
};