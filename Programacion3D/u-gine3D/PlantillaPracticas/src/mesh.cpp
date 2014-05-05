#include "../include/mesh.h"

//---------------------------------
//
//---------------------------------
Ptr<Mesh> Mesh::Create()
{
	return Ptr<Mesh>( new Mesh("") );
}
//---------------------------------
//
//---------------------------------
Ptr<Mesh> Mesh::Create(const String& filename)
{
	return Ptr<Mesh>( new Mesh( filename ) );
}
//---------------------------------
//
//---------------------------------
const String& Mesh::GetFilename() const
{
    return filename;
}
//---------------------------------
//
//---------------------------------
void Mesh::AddSubmesh(Ptr<Submesh> submesh)
{
	submeshes.Add( submesh );
}
//---------------------------------
//
//---------------------------------
void Mesh::RemoveSubmesh(uint32 i)
{
	submeshes.RemoveAt( i );
}
//---------------------------------
//
//---------------------------------
void Mesh::RemoveSubmesh(Ptr<Submesh> submesh)
{
	submeshes.Remove( submesh );
}
//---------------------------------
//
//---------------------------------
uint32 Mesh::NumSubmeshes() const
{
    return submeshes.Size(); 
}
//---------------------------------
//
//---------------------------------
Ptr<const Submesh> Mesh::GetSubmesh(uint32 i) const
{
	return submeshes[ i ].ConstCast();
}
//---------------------------------
//
//---------------------------------
Ptr<Submesh> Mesh::GetSubmesh(uint32 i)
{
    return submeshes[ i ];
}
//---------------------------------
//
//---------------------------------
void Mesh::Render()
{
	for( unsigned int index = 0; index < submeshes.Size(); index++ )	submeshes[ index ]->Render();
}
//---------------------------------
//
//---------------------------------
Mesh::Mesh(const String& filename) : filename( filename )
{
}
//---------------------------------
//
//---------------------------------
Mesh::~Mesh()
{
}