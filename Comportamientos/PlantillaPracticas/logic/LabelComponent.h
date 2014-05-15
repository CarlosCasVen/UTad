#ifndef __LABEL_COMPONENT__
#define __LABEL_COMPONENT__

#include "BaseComponent.h"

class String;
class Font;

class LabelComponent : public BaseComponent
{
public:
    LabelComponent ();
	~LabelComponent();

	virtual TError Init();
	virtual void   End ();

	virtual void Update( double elapsedTime );
    virtual void Render()                    ;

    void SetLabel   ( String& label                            );
    void SetX       ( double x                                 );
    void SetY       ( double y                                 );
    void SetPosition( double x, double y                       );
    void SetColor   ( uint8 r, uint8 g, uint8 b, uint8 a = 255 );
    void SetFont    ( const String* font                       );

    String GetLabel()                                        const;
    double GetX    ()                                        const;
    double GetY    ()                                        const;
    Font&  GetFont ()                                        const;
    void   GetColor( uint8& r, uint8& g, uint8& b, uint8 a ) const;

private:
    double       m_x, m_y;
    uint8        m_red, m_green, m_blue, m_alpha;
    String       m_label;
    Font*        m_font;
};

#endif