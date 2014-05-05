#include "../include/scene.h"

//---------------------------------
//
//---------------------------------
Ptr<Scene> Scene::Instance()
{
}
//---------------------------------
//
//---------------------------------
Ptr<const Camera> Scene::GetCurrentCamera() const
{
}
//---------------------------------
//
//---------------------------------
Ptr<Camera> Scene::GetCurrentCamera()
{
    return currentCamera;
}
//---------------------------------
//
//---------------------------------
const Matrix4& Scene::GetModel() const
{
    return modelMatrix;
}
//---------------------------------
//
//---------------------------------
const Matrix4& Scene::GetMVP() const
{
    return mvp;
}
//---------------------------------
//
//---------------------------------
void Scene::SetModel(const Matrix4& m)
{
    modelMatrix = m;
}
//---------------------------------
//
//---------------------------------
void Scene::AddEntity(Ptr<Entity> entity)
{
    entities.Add( entity );
}
//---------------------------------
//
//---------------------------------
void Scene::RemoveEntity(Ptr<Entity> entity)
{
    entities.Remove( entity );
}
//---------------------------------
//
//---------------------------------
uint32 Scene::NumEntities() const
{
    return entities.Size();
}
//---------------------------------
//
//---------------------------------
Ptr<const Entity> Scene::GetEntity(uint32 index) const
{
}
//---------------------------------
//
//---------------------------------
Ptr<Entity> Scene::GetEntity(uint32 index)
{
    return entities[ index ];
}
//---------------------------------
//
//---------------------------------
void Scene::Update(float elapsed)
{
    
}
//---------------------------------
//
//---------------------------------
void Scene::Render()
{
}
//---------------------------------
//
//---------------------------------
Scene::Scene()
{
}