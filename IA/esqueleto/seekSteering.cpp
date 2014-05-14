#include "stdafx.h"
#include "seekSteering.h"
#include "character.h"

USVec3D SeekSteering::GetSteering( Character* character, const USVec3D& targetPos )
{
	USVec3D newDir = targetPos - character->GetLoc();
	
	newDir.Norm();
	newDir *= character->GetMaxVel();

	USVec3D speed = newDir - character->GetLinearVelocity();
	speed.Norm();

	return speed * character->GetMaxAcc();
}


USVec3D SeekSteering::GetSteeringArrive( Character* character, const USVec3D& targetPos )
{
	USVec3D newDir = targetPos - character->GetLoc();
	float radius =   character->GetDstRadius();
	float distance = newDir.Length();

	newDir.Norm();

	if( distance > radius )	newDir *= character->GetMaxVel();
	else					newDir *= character->GetMaxVel() * ( distance / radius );
	

	USVec3D speed = newDir - character->GetLinearVelocity();
	speed.Norm();

	return speed * character->GetMaxAcc();

}


float SeekSteering::GetSteeringAlign( Character* character, const float angle )
{
	Params params = *character->GetParams();
	//USVec2D dir = params.targetPosition - character->GetLoc();
	//dir.Norm();

	//USVec2D currentDir = character->GetLinearVelocity();
	//currentDir.Norm();

	//float currentAngle = acosf( currentDir.Dot( dir ) );

	

	float characterRot = character->GetRot();
	float finalRot     = params.targetRotation;

	finalRot -= characterRot;

	float currentVelRot = character->GetAngularVelocity();
	float desiredVelRot = params.max_angular_velocity;

	desiredVelRot -= currentVelRot;
}

void SeekSteering::DrawDebug()
{

}