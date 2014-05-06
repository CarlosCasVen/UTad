#include "../include/mesh.h"
#include "../lib/rapidjson/document.h"

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
	String dataMesh = String::Read( filename );
	
	rapidjson::Document jDoc;
	jDoc.Parse<0>( dataMesh.ToCString() );
	rapidjson::Value& buffers = jDoc["submeshes"];
	Array<int> indices;
	Array<float> coords;
	Array<int> colours;

	for( unsigned int numSub = 0; numSub < jDoc["submeshes"].Size(); numSub++ ) 
	{
		buffers = jDoc["submeshes"][ numSub ];
		for( unsigned int index = 0; index < buffers["indices"].Size(); index++ )
		{
			indices.Add( buffers[ index ].GetInt() );			
		}
		
		for( unsigned int index = 0; index < buffers["indices"].Size(); index++ )
		{
			coords.Add( buffers[ index ].GetDouble() );	
		}

		for( unsigned int index = 0; index < buffers["indices"].Size(); index++ )
		{
			colours.Add( buffers[ index ].GetInt() ); 	
		}
	
	]
}
//---------------------------------
//
//---------------------------------
Mesh::~Mesh()
{
}