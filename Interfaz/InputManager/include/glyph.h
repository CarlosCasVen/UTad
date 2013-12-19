#ifndef UGINE_GLYPH_H
#define UGINE_GLYPH_H

#include "glyph.h"
#include "types.h"
#include "math.h"
#include <math.h>

class Glyph{
public:
	Glyph(){};
	Glyph(uint16 x0, uint16 y0, uint16 x1, uint16 y1){ this->x0 = x0; this->y0 = y0; this->x1 = x1; this->y1 = y1; };
	void SetInitialCoordinates( uint16 x, uint16 y){ x0 = x; y0 = y; };
	void SetFinalCoordinates( uint16 x, uint16 y){ x1 = x; y1 = y; };
	static bool IsRed(uint8 r, uint8 g, uint8 b){ return  r == 255 && g == 0 && b == 0; }
	static bool IsYellow(uint8 r, uint8 g, uint8 b){ return  r == 255 && g == 255 && b == 0; };
	static bool IsBlack(uint8 r, uint8 g, uint8 b){ return  r == 0 && g == 0 && b == 0; };
	uint16 GetWidth() const{ return x1 - x0; };
	uint16 GetHeight() const{ return y1 - y0; };

private:
	uint16 x0, y0;
	uint16 x1, y1;
};


#endif