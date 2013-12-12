#ifndef UGINE_SPRITE_H
#define UGINE_SPRITE_H

#include "renderer.h"
#include "types.h"

class Collision;
class CollisionPixelData;
class Image;
class Map;

class Sprite {
public:
	enum CollisionMode {
		COLLISION_NONE,
		COLLISION_CIRCLE,
		COLLISION_PIXEL,
		COLLISION_RECT
	};

	Sprite(Image* image);
	virtual ~Sprite();

	virtual void SetImage(Image* image) { /* TAREA: Implementar */ this->image = image; }
	virtual const Image* GetImage() const { /* TAREA: Implementar */ return this->image; }

    virtual void SetPosition(double x, double y, double z = 0) { /* TAREA: Implementar */ this->x = x; this->y = y; this->z = z; }
    virtual void SetX(double x) { /* TAREA: Implementar */ this->x = x; }
	virtual void SetY(double y) { /* TAREA: Implementar */ this->y = y; }
    virtual void SetZ(double z) { /* TAREA: Implementar */ this->z = z;}
    virtual double GetX() const { /* TAREA: Implementar */ return this->x; }
	virtual double GetY() const { /* TAREA: Implementar */ return this->y; }
    virtual double GetZ() const { /* TAREA: Implementar */ return this->y; }
	virtual double GetScreenX() const { /* TAREA: Implementar */ return this->x; }
    virtual double GetScreenY() const { /* TAREA: Implementar */ return this->y; }

	virtual void SetAngle(double angle) { /* TAREA: Implementar */ this->angle = angle; }
    virtual double GetAngle() const { /* TAREA: Implementar */ return this->angle; }

	virtual void SetScale(double sx, double sy) { /* TAREA: Implementar */ this->scalex = sx; this->scaley = sy; }
	virtual void SetScaleX(double sx) { /* TAREA: Implementar */ this->scalex = sx; }
	virtual void SetScaleY(double sy) { /* TAREA: Implementar */ this->scaley = sy; }
	virtual double GetScaleX() const { /* TAREA: Implementar */ return this->scalex; }
	virtual double GetScaleY() const { /* TAREA: Implementar */ return this->scaley; }

	virtual void SetFPS(int16 fps) { /* TAREA: Implementar */ this->animFPS = fps; }
	virtual int16 GetFPS() const { /* TAREA: Implementar */ return this->animFPS; }
	virtual void SetFrameRange(uint16 firstFrame, uint16 lastFrame) { /* TAREA: Implementar */ this->firstFrame = firstFrame; this->lastFrame = lastFrame; }
	virtual uint16 GetFirstFrame() const { /* TAREA: Implementar */ return this->firstFrame; }
	virtual uint16 GetLastFrame() { /* TAREA: Implementar */ return this->lastFrame; }
	virtual void SetCurrentFrame(uint16 frame) { /* TAREA: Implementar */ this->currentFrame = currentFrame; }
	virtual uint16 GetCurrentFrame() const { /* TAREA: Implementar */ return (uint16)this->currentFrame; }

	virtual void SetBlendMode(Renderer::BlendMode blend) { /* TAREA: Implementar */ this->blendMode = blendMode; }
	virtual Renderer::BlendMode GetBlendMode() const { /* TAREA: Implementar */ return this->blendMode; }
    virtual void SetColor(uint8 r, uint8 g, uint8 b, uint8 alpha = 255) { /* TAREA: Implementar */ this->r = r; this->g = g; this->b = b; this->a = alpha; }
	virtual uint8 GetRed() const { /* TAREA: Implementar */ return this->r; }
    virtual uint8 GetGreen() const { /* TAREA: Implementar */ return this->g; }
    virtual uint8 GetBlue() const { /* TAREA: Implementar */ return this->b; }
    virtual uint8 GetAlpha() const { /* TAREA: Implementar */ return this->a; }

	virtual void SetRadius(double radius) { /* TAREA: Implementar */ this->radius = radius; }
	virtual double GetRadius() const { /* TAREA: Implementar */ return this->radius; }

	virtual void SetCollision(CollisionMode mode);
	virtual void SetCollisionPixelData(const CollisionPixelData* colPixelData) { /* TAREA: Implementar */ this->colPixelData = colPixelData; }
    virtual const Collision* GetCollision() const { /* TAREA: Implementar */ return collision; }
    virtual bool CheckCollision(Sprite* sprite);
    virtual bool CheckCollision(const Map* map);
	virtual const Sprite* CollisionSprite() const { /* TAREA: Implementar */ return colSprite; }
    virtual bool DidCollide() const { /* TAREA: Implementar */ return collided; }

    virtual void RotateTo(int32 angle, double speed);
    virtual void MoveTo(double x, double y, double speedX, double speedY = 0.0);
	virtual bool IsRotating() const { /* TAREA: Implementar */ return this->rotating; }
	virtual bool IsMoving() const { /* TAREA: Implementar */ return this->moving; }

	virtual void ScaleTo(double scaleX, double scaleY, double scalingSpeedX, double scalingSpeedY);
	virtual bool IsScaling() const { return this->scaling; };

    virtual void Update(double elapsed, const Map* map = NULL);
    virtual void Render() const;
protected:
    virtual void UpdateCollisionBox();
    virtual void UpdateCollisionBox(double x, double y, double w, double h);
private:
    Image* image;
    double x, y, z;
    double colx, coly, colwidth, colheight;
    double angle;
    double scalex, scaley;
    double radius;
    int16 animFPS;
    uint16 firstFrame, lastFrame;
    double currentFrame;
    Renderer::BlendMode blendMode;
    uint8 r, g, b, a;
    Collision* collision;
    const CollisionPixelData* colPixelData;
    Sprite* colSprite;
    bool collided;

    bool rotating;
    uint16 toAngle;
    double rotatingSpeed;
    double anglesToRotate;

    bool moving;
    double toX, toY;
    double movingSpeedX, movingSpeedY;
    double prevX, prevY;

	bool scaling;
	double toScaleX, toScaleY;
	double scalingSpeedX, scalingSpeedY;
	double scalePointsX, scalePointsY;
};

#endif
