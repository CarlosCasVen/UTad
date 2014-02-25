#include "../include/math.h"
#include <math.h>
#include <stdlib.h>
#include <Windows.h>

#define DEG2RAD 0.0174532925
#define RAD2DEG 57.2957795

double Log2(double x) {
	return log(x) / log(2.0);
}

double DegSin(double degrees) {
	return sin(DEG2RAD * degrees);
}

double DegCos(double degrees) {
	return cos(DEG2RAD * degrees);
}

double DegTan(double degrees) {
	return tan(DEG2RAD * degrees);
}

double DegASin(double sin) {
	return asin(sin) * RAD2DEG;
}

double DegACos(double cos) {
	return acos(cos) * RAD2DEG;
}

double DegATan(double tan) {
	return atan(tan) * RAD2DEG;
}

double DegATan2(double y, double x) {
	return atan2(y, x) * RAD2DEG;
}

double WrapValue(double val, double mod) {
    if (mod == 0) return val;
    return val - mod*floor(val/mod);
}


double Angle(double x1, double y1, double x2, double y2) {
	// TAREA: Implementar funcion
	double x = x2 - x1;
	double y = -(y2 - y1);
	double angle = 0;

	angle = WrapValue( DegATan2(y, x), 360);
	
	return angle;
}

double Distance(double x1, double y1, double x2, double y2) {
	// TAREA: Implementar funcion
	double xCuad = x2 - x1;
	double yCuad = y2 - y1;
	
	xCuad *= xCuad;
	yCuad *= yCuad;

	return sqrt(xCuad + yCuad);
}

bool ValueInRange(double value, double min, double max) {
	return (value >= min) && (value <= max);
}

bool PointInRect(double x, double y, double rectx, double recty, double width, double height) {
	// TAREA: Implementar funcion
	return x >= rectx && x <= rectx + width &&
		y >= recty && y <= recty + height;
}

void ClosestPointToRect(double x, double y, double rectx, double recty, double width, double height, double* outx, double* outy) {
	*outx = (x < rectx) ? rectx : (x > rectx+width) ? rectx+width : x;
	*outy = (y < recty) ? recty : (y > recty+height) ? recty+height : y;
}

bool RectsOverlap(double x1, double y1, double width1, double height1, double x2, double y2, double width2, double height2) {
	// TAREA: Implementar funcion	

	if ( x1 > (x2 + width2) || (x1 + width1) < x2)
		return false;
	if (y1 > (y2 + height2) || (y1 + height1) < y2)
		return false;
	return true;
}

void OverlappingRect(double x1, double y1, double width1, double height1, double x2, double y2, double width2, double height2, double* outx, double* outy, double* outwidth, double* outheight) {
	// TAREA: Implementar funcion

	double right1 = x1 + width1;
	double right2 = x2 + width2;

	double down1 = y1 + height1;
	double down2 = y2 + height2;

	if( x1 >= x2 && x1 <= ( x2 + width2 ) )
	{
		*outx = x1;
	}
	else 
	{
		*outx = x2;
	}

	if( y1 >= y2 && y1 <= ( y2 + height2 ) )
	{
		*outy = y1;
	}
	else
	{
		*outy = y2;
	}

	if( right1 >= x2 && right1 <= ( x2 + width2 ) )
	{
		*outwidth = right1 - *outx;
	}
	else
	{
		*outwidth = right2 - *outx;
	}

	if( down1 >= y2 && down1 <= ( y2 + height2 ) )
	{
		*outheight = down1 - *outy;
	}
	else
	{
		*outheight = down2 - *outy;
	}

}

void TransformIsoCoords(double isoX, double isoY, double isoZ, double* screenX, double* screenY) {
	// TAREA: Implementar funcion
	*screenX = ( isoX - isoY ) * DegCos( 26.6 );
	*screenY = isoZ + ( isoX + isoY ) * DegSin( 26.6 );
}


double RangeRand ( double minRange, double maxRange )
{
	return (double)minRange + (maxRange - minRange) * (double)rand() / RAND_MAX;
} 


double PowDistance(double x1, double y1, double x2, double y2)
{
	double xCuad = x2 - x1;
	double yCuad = y2 - y1;
	
	xCuad *= xCuad;
	yCuad *= yCuad;

	return xCuad + yCuad;
}