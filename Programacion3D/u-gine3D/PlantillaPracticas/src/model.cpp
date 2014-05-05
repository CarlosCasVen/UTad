#include "../include/model.h"
#include "../include/mesh.h"
#include "../include/submesh.h"

//---------------------------------
//
//---------------------------------
Ptr<Model> Model::Create(Ptr<Mesh> mesh)
{
    
    
    if( mesh != NULL ) 
    {
        return Ptr<Model>( new Model( mesh ) );
    }

    return NULL;
}
//---------------------------------
//
//---------------------------------
void Model::Render()
{
}
//---------------------------------
//
//---------------------------------
Model::Model(Ptr<Mesh> mesh) : mesh( mesh )
{
    
}
//---------------------------------
//
//---------------------------------
Model::~Model()
{
}