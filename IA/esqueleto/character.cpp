#include <stdafx.h>
#include "character.h"
#include <tinyxml.h>

#include <params.h>


Character::Character() : mLinearVelocity(0.0f, 0.0f), mAngularVelocity(0.0f)
{
	RTTI_BEGIN
		RTTI_EXTEND (MOAIEntity2D)
	RTTI_END
}

Character::~Character()
{

}

void Character::OnStart()
{
    ReadParams("params.xml", mParams);
}

void Character::OnStop()
{

}

void Character::OnUpdate(float step)
{
	USVec3D newDir = mSeek.GetSteering( this, mParams.targetPosition );
	
	mLinearVelocity += newDir;

	SetLoc( GetLoc() + mLinearVelocity * step );

}

void Character::DrawDebug()
{
	MOAIGfxDevice& gfxDevice = MOAIGfxDevice::Get();
	gfxDevice.SetPenColor(0.0f, 0.0f, 1.0f, 0.5f);

	//MOAIDraw::DrawPoint(0.0f, 0.0f);
	MOAIDraw::DrawEllipseOutline( mParams.targetPosition.mX, mParams.targetPosition.mY,
		mParams.dest_radius, mParams.dest_radius, 30 );
	
}





// Lua configuration

void Character::RegisterLuaFuncs(MOAILuaState& state)
{
	MOAIEntity2D::RegisterLuaFuncs(state);
	
	luaL_Reg regTable [] = {
		{ "setLinearVel",			_setLinearVel},
		{ "setAngularVel",			_setAngularVel},
		{ "setMaxVel",				_setMaxVel},
		{ "setMaxAcc",				_setMaxAcc},
		{ "setDstRaius",			_setDstRaius},
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}

int Character::_setLinearVel(lua_State* L)
{
	MOAI_LUA_SETUP(Character, "U")
	
	float pX = state.GetValue<float>(2, 0.0f);
	float pY = state.GetValue<float>(2, 0.0f);
	self->SetLinearVelocity(pX, pY);
	return 0;	
}

int Character::_setAngularVel(lua_State* L)
{
	MOAI_LUA_SETUP(Character, "U")
	
	float angle = state.GetValue<float>(2, 0.0f);
	self->SetAngularVelocity(angle);

	return 0;
}
	
int Character::_setMaxVel(lua_State* L)
{
	MOAI_LUA_SETUP( Character, "U" )

	float maxSpeed =state.GetValue<float>( 2, 0.0f );
	self->mParams.max_velocity = maxSpeed;
	
	return 0;
}


int Character::_setMaxAcc(lua_State* L)
{
	MOAI_LUA_SETUP( Character, "U" )

	float maxAcceleration =state.GetValue<float>( 2, 0.0f );
	self->mParams.max_acceleration = maxAcceleration;

	return 0;
}


int Character::_setDstRaius(lua_State* L)
{
	MOAI_LUA_SETUP( Character, "U" )

	float maxAcceleration =state.GetValue<float>( 2, 0.0f );
	self->mParams.dest_radius= maxAcceleration;

	return 0;
}