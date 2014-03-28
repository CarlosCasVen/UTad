#ifndef __SPRITE_COMPONENT__
#define __SPRITE_COMPONENT__

#include "BaseComponent.h"
#include "../json/rapidjson/document.h"

class String;
class Sprite;
class Image;


class SpriteComponent : public BaseComponent
{
public:
    SpriteComponent ();
	~SpriteComponent();

	virtual TError Init();
	virtual void   End ();

	virtual void Update( double elapsedTime );

    void SetPosition( double x, double y, double z = 0 );
    void SetImage   ( const String& filename, unsigned int hframes = 1, unsigned int vframes = 1 );
    void SetColor   ( int r, int g, int b, int a = 255 );
    void SetScale   ( double x, double y );

    Sprite*      GetSprite();
    double       GetX     () const;
    double       GetY     () const;
    double       GetZ     () const;
    const Image* GetImage () const;
    int          GetR     () const;
    int          GetG     () const;
    int          GetB     () const;
    int          GetA     () const;
    double       GetScaleX() const;
    double       GetScaleY() const;

private:
    Sprite* m_sprite;

};


#endif