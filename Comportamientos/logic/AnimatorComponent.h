#ifndef __ANIMATOR_COMPONENT__
#define __ANIMATOR_COMPONENT__

#include "BaseComponent.h"
#include "../json/rapidjson/document.h"

enum TError;
class Sprite;

class AnimatorComponent : public BaseComponent
{
public:
    AnimatorComponent ();
	~AnimatorComponent();

	virtual TError Init();
	virtual void   End ();

	virtual void Update( double elapsedTime );

    void         SetSprite    ( Sprite* sprite );
    void         SetFrameRange( int firstFrame, int endFrame );
    void         SetFPS       ( int fps );

private:
    Sprite* m_sprite;

};

#endif