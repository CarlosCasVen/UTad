#include "../include/scene.h"
#include "../include/renderer.h"
#include "../include/screen.h"

Ptr<Scene> Scene::instance = NULL;

//---------------------------------
//
//---------------------------------
Ptr<Scene> Scene::Instance()
{
	if( instance == NULL ) instance = Ptr<Scene>( new Scene() );

	return instance;
}
//---------------------------------
//
//---------------------------------
Ptr<const Camera> Scene::GetCurrentCamera() const
{
	return currentCamera.ConstCast();
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

	Matrix4 p = GetCurrentCamera()->GetProjection();
	Matrix4 v = GetCurrentCamera()->GetView();

	Matrix4 mvp = GetCurrentCamera()->GetProjection() * GetCurrentCamera()->GetView() * modelMatrix ;
	
	float values[ MATRIX_SIZE ];
	
	Renderer::Instance()->SetMVP( &mvp[ 0 ] );
}
//---------------------------------
//
//---------------------------------
void Scene::AddEntity(Ptr<Entity> entity)
{
	if(  entity.DownCast<Camera>() != NULL ) cameras.Add( entity.DownCast<Camera>() );
    entities.Add( entity );
}
//---------------------------------
//
//---------------------------------
void Scene::RemoveEntity(Ptr<Entity> entity)
{
	if(  entity.DownCast<Camera>() != NULL ) cameras.Remove( entity.DownCast<Camera>() );
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
	return entities[ index ].ConstCast();
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
	for( unsigned int index = 0; index < entities.Size(); index++ ) entities[ index ]->Update( Screen::Instance()->GetElapsed() );
}
//---------------------------------
//
//---------------------------------
void Scene::Render()
{
	for( unsigned int nCam = 0; nCam < cameras.Size(); nCam++ )
	{
		currentCamera = cameras [ nCam ];
		currentCamera->Prepare();

		for( unsigned int index = 0; index < entities.Size(); index++ ) entities[ index ]->Render();
	}
}
//---------------------------------
//
//---------------------------------
Scene::Scene()
{
	Renderer::Instance()->Setup3D();
}