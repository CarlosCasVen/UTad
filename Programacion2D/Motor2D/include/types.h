#ifndef UGINE_TYPES_H
#define UGINE_TYPES_H

typedef signed char int8;
typedef signed short int16;
typedef signed int int32;
typedef signed long int64;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long uint64;


//Define para activar effector
#define ALL_DESACTIVE 0
#define VELX_ACTIVE 1
#define VELY_ACTIVE 2
#define VELANG_ACTIVE 4
#define COLOR_ACTIVE 8
#define BLEND_MODE_ACTIVE 16
#define IMAGE_ACTIVE 32
#define ALL_ACTIVE 63
#endif