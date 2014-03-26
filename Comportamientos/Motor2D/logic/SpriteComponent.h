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
    void SetImage   ( const String& filename );
    void SetColor   ( int r, int g, int b, int a = 255 );

    double       GetX    () const;
    double       GetY    () const;
    double       GetZ    () const;
    const Image* GetImage() const;
    int          GetR    () const;
    int          GetG    () const;
    int          GetB    () const;
    int          GetA    () const;

private:
    Sprite* m_sprite;

};


#endif