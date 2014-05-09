#include "../include/entity.h"
#include "../include/scene.h"

//---------------------------------
//
//---------------------------------
Ptr<Entity> Entity::Create()
{
    Ptr<Entity> entity = new Entity();

    return entity;
}
//---------------------------------
//
//---------------------------------
const Vector3& Entity::GetPosition() const
{
    return position;
}
//---------------------------------
//
//---------------------------------
Vector3& Entity::GetPosition()
{
    return position;
}
//---------------------------------
//
//---------------------------------
const Quat& Entity::GetRotation() const
{
    return rotation;
}
//---------------------------------
//
//---------------------------------
Quat& Entity::GetRotation()
{
    return rotation;
}
//---------------------------------
//
//---------------------------------
const Vector3& Entity::GetScale() const
{
    return scale;
}
//---------------------------------
//
//---------------------------------
Vector3& Entity::GetScale()
{
    return scale;
}
//---------------------------------
//
//---------------------------------
void Entity::Move(const Vector3& speed)
{
    position += rotation * speed;
}
//---------------------------------
//
//---------------------------------
void Entity::Render()
{
    Matrix4 model;

	model.Translate	( position			);
    model.Rotate	( rotation.Axis()	);    
	model.Scale		( scale				);

    Scene::Instance()->SetModel( model );
    
}
//---------------------------------
//
//---------------------------------
Entity::Entity()
{
	scale = Vector3( 1, 1, 1 );
}
//---------------------------------
//
//---------------------------------
Entity::~Entity()
{
    
}