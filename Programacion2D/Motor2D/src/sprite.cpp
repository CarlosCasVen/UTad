#include "../include/sprite.h"
#include "../include/rectcollision.h"
#include "../include/image.h"
#include "../include/map.h"
#include "../include/math.h"
#include "../include/pixelcollision.h"
#include "../include/renderer.h"
#include "../include/circlecollision.h"
#include "../include/collisionPixelData.h"
#include <math.h>

Sprite::Sprite(Image* image) {
	// TAREA: Implementar
	this->image = image;
    
	this->x = 0;
	this->y = 0;
	this->z = 0;
    this->colx = 0;
	this->coly = 0;
	this->colwidth = 0;
	this->colheight = 0;
    this->angle = 0;
    this->scalex = 1;
	this->scaley = 1;
    this->radius = 0;
    this->animFPS = 0;
    this->firstFrame = 0;
	this->lastFrame = 0;
    this->currentFrame = 0;
	this->blendMode = Renderer::BlendMode::ALPHA;
    this->r = 255;
	this->g = 255;
	this->b = 255;
	this->a = 255;
    this->collision = NULL;
    this->colPixelData = NULL;
    this->colSprite = NULL;
    this->collided = false;

	this->rotating = false;
    this->toAngle = 0;
    this->rotatingSpeed = 0;
    this->anglesToRotate = 0;

	this->moving = false;
    this->toX = 0;
	this->toY = 0;
    this->movingSpeedX = 0;
	this->movingSpeedY = 0;
    this->prevX = 0;
	this->prevY = 0;

	this->scaling = false;
	this->scalingSpeedX = 0;
	this->scalingSpeedY = 0;
	this->scalePointsX = 0;
	this->scalePointsY = 0;
}

Sprite::~Sprite() {
    // TAREA: Implementar
	this->image = NULL;
    
	this->x = 0;
	this->y = 0;
	this->z = 0;
    this->colx = 0;
	this->coly = 0;
	this->colwidth = 0;
	this->colheight = 0;
    this->angle = 0;
    this->scalex = 0;
	this->scaley = 0;
    this->radius = 0;
    this->animFPS = 0;
    this->firstFrame = 0;
	this->lastFrame = 0;
    this->currentFrame = 0;
	this->blendMode = Renderer::BlendMode::SOLID;
    this->r = 0;
	this->g = 0;
	this->b = 0;
	this->a = 0;
    this->collision = NULL;
    this->colPixelData = NULL;
    this->colSprite = NULL;
    this->collided = false;

	this->rotating = false;
    this->toAngle = 0;
    this->rotatingSpeed = 0;
    this->anglesToRotate = 0;

	this->moving = false;
    this->toX = 0;
	this->toY = 0;
    this->movingSpeedX = 0;
	this->movingSpeedY = 0;
    this->prevX = 0;
	this->prevY = 0;
}

void Sprite::SetCollision(CollisionMode mode) {
	// TAREA: Implementar
	switch( mode )
	{
	case COLLISION_NONE:
		{
			delete collision;
			collision = NULL;
			break;
		}
	case COLLISION_CIRCLE:
		{
			delete collision;
			collision = NULL;
			collision = new CircleCollision( &x, &y, &radius);
			break;
		}
	case COLLISION_PIXEL:
		{
			delete collision; 
			collision = NULL;
			collision = new PixelCollision( &colx, &coly, colPixelData );
			break;
		}
	case COLLISION_RECT:
		{
			delete collision;
			collision = new RectCollision( &colx, &coly, &colwidth, &colheight );
			break;
		}
	}

}

bool Sprite::CheckCollision(Sprite* sprite) {
	// TAREA: Implementar
	if( collision  && sprite->GetCollision() )
	{
		bool isCollision = collision->DoesCollide(sprite->collision);
		if ( isCollision )
		{
			colSprite = sprite;
			collided = true;
			sprite->colSprite = this;
			sprite->collided = true;
			
			return true;
		}
		
	}

	return false;

}

bool Sprite::CheckCollision(const Map* map) {
	// TAREA: Implementar
	if ( collision  &&  map->CheckCollision(collision) ) {
		collided = true;
		return true;
	} else {
		return false;
	}
}

void Sprite::RotateTo(int32 angle, double speed) {
	// TAREA: Implementar
	toAngle = (uint16)WrapValue(angle, 360);

	if(WrapValue((toAngle - this->angle), 360) < WrapValue((this->angle - toAngle), 360))
	{
		rotatingSpeed = abs(speed);
		anglesToRotate = WrapValue((toAngle - this->angle), 360);
	}
	else
	{
		rotatingSpeed = -abs(speed);
		anglesToRotate = WrapValue((this->angle - toAngle), 360);
	}

	rotating = true;
}

void Sprite::MoveTo(double x, double y, double speedX, double speedY) {
	// TAREA: Implementar
	moving = true;
	
	if(speedY != 0)
	{
		x - this->x >= 0 ? movingSpeedX = abs(speedX) : movingSpeedX = -abs(speedX);
		y - this->y >= 0 ? movingSpeedY = abs(speedY) : movingSpeedY = -abs(speedY);
	}
	else
	{
		double timeToArrive = 0;
		double totalDistance = Distance( this->x, this->y, x, y);
		double xDistance = x - this->x;
		double yDistance = y - this->y;

		if(totalDistance != 0)
		{
			timeToArrive = totalDistance / speedX;
		}

		xDistance != 0 ? movingSpeedX = xDistance / timeToArrive : movingSpeedX = 0;
		yDistance != 0 ? movingSpeedY = yDistance / timeToArrive : movingSpeedY = 0;

	}
	
	toX = x;
	toY = y;
	moving = true;
}

void Sprite::Update(double elapsed, const Map* map) {
	// Informacion inicial de colision
	colSprite = NULL;
	collided = false;

	// TAREA: Actualizar animacion
	currentFrame += animFPS * elapsed;
	//if( currentFrame >= lastFrame )
	//{
	//	currentFrame = firstFrame;
	//}

	if (lastFrame < currentFrame)
		currentFrame = firstFrame;
	if (currentFrame < firstFrame)
		currentFrame = lastFrame;


	// TAREA: Actualizar rotacion animada
	if(rotating)
	{
		prevAngle = angle;
		double rotationToApply = rotatingSpeed * elapsed;
		angle = WrapValue(angle + rotationToApply, 360);
		anglesToRotate = anglesToRotate - abs(rotationToApply);

		if(anglesToRotate <= 0)
		{
			angle = WrapValue(toAngle, 360);
			rotating = false;
		}

		UpdateCollisionBox();
		if( CheckCollision( map ) )
		{
			angle = prevAngle;
			rotating = false;
		}
	}

	// TAREA: Actualizar movimiento animado
	if(moving)
	{
		prevX = x;
		prevY = y;
	
		x += movingSpeedX * elapsed;
		
		if(movingSpeedX >= 0 && x >= toX)
		{
			x = toX;
		}
		else if(movingSpeedX < 0 && x <= toX)
		{
			x = toX;
		}

		UpdateCollisionBox(); 

		if( CheckCollision( map ) )
		{
			x = prevX;
		}

		y += movingSpeedY * elapsed;

		if(movingSpeedY >= 0 && y >= toY)
		{
			y = toY;
		}
		else if(movingSpeedY < 0 && y <= toY)
		{
			y = toY;
		}

		UpdateCollisionBox(); 

		if( CheckCollision( map ) )
		{
			y = prevY;
		}

		if( ( x == toX && y == toY ) || ( x == prevX && y == prevY ) )
		{
			moving = false;
		}
	}


	if(scaling)
	{
		scalex += scalingSpeedX * elapsed;
		scaley += scalingSpeedY * elapsed;

		scalePointsX -= abs(scalingSpeedX * elapsed);
		scalePointsY -= abs(scalingSpeedY * elapsed);

		if(scalePointsX <= 0 && scalePointsY <= 0)
		{					
			scaling = false;
		}

		if(scalePointsX <= 0)
		{
			scalex = toScaleX;
		}

		if(scalePointsY <= 0)
		{
			scaley = toScaleY;
		}
	}

	// Informacion final de colision
	UpdateCollisionBox();
}

void Sprite::Render() const {
    // TAREA: Implementar
	Renderer::Instance().SetBlendMode(blendMode);
	Renderer::Instance().SetColor(r, g, b, a);
	Renderer::Instance().DrawImage(image, x, y, (uint32)currentFrame, image->GetWidth() * scalex, image->GetHeight() * scaley, angle);
}

void Sprite::UpdateCollisionBox() {
	// TAREA: Implementar
	double cx = x - image->GetHandleX() * fabs( scalex );
	double cy = y - image->GetHandleY() * fabs( scaley );
	double cw = image->GetWidth() * fabs( scalex );
	double ch = image->GetHeight() * fabs( scaley );

	UpdateCollisionBox( cx, cy, cw, ch );

}

void Sprite::UpdateCollisionBox(double x, double y, double w, double h) {
	// TAREA: Implementar
	colx = x;
	coly = y;
	colwidth = w;
	colheight = h;

}

void Sprite::ScaleTo(double scaleX, double scaleY, double scalingSpeedX, double scalingSpeedY)
{
	scaling = true;

	scalePointsX = abs(scaleX - this->scalex);
	scalePointsY = abs(scaleY - this->scaley);

	this->toScaleX = scaleX;
	this->toScaleY = scaleY;

	this->scalex < toScaleX ? this->scalingSpeedX = abs(scalingSpeedX) : this->scalingSpeedX = -abs(scalingSpeedX);
	this->scaley < toScaleY ? this->scalingSpeedY = abs(scalingSpeedY) : this->scalingSpeedY = -abs(scalingSpeedY);
}
