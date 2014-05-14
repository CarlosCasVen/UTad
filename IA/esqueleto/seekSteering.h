#ifndef __SEEK_STEERING_H
#define __SEEK_STEERING_H

#include "stdafx.h"

class Character;

class SeekSteering
{
public:
	USVec3D GetSteering( Character* character, const USVec3D& targetPos );
	
	USVec3D GetSteeringArrive( Character* character, const USVec3D& targetPos );

	float GetSteeringAlign( Character* character, const float angle );
	
	void  DrawDebug  ();
};

#endif