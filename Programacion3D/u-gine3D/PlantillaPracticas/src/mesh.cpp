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
	submesh->Rebuild();
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
    String content = String::Read( filename );

    rapidjson::Document json;

    if( json.Parse<0>( content.ToCString() ).HasParseError() ) return;

    rapidjson::Value& sub = json[ "submeshes" ];

    for( unsigned int index = 0; index < sub.Size(); index++ )
    {
        String tex = sub[ index ][ "texture" ].GetString();

        rapidjson::Value& indexes     = sub[ index ][ "indices"   ];
        rapidjson::Value& coords      = sub[ index ][ "coords"    ];
        rapidjson::Value& texCoords   = sub[ index ][ "texcoords" ];

        Ptr< Texture > pTex = Texture::Create( tex  );
        Ptr< Submesh > pSub = Submesh::Create( pTex );

        for( unsigned int nIndex = 0; nIndex < indexes.Size(); nIndex += 3 )
        {
            pSub->AddTriangle( indexes[ nIndex ].GetInt(), indexes[ nIndex + 1 ].GetInt(), indexes[ nIndex + 2 ].GetInt() );
        }

        Array< Vector3 > vertexPositions;

        for( unsigned int nCoords = 0; nCoords < coords.Size(); nCoords += 3 )
        {
            vertexPositions.Add( 
                                Vector3(
                                        static_cast<float>( coords[ nCoords     ].GetDouble() ), 
                                        static_cast<float>( coords[ nCoords + 1 ].GetDouble() ), 
                                        static_cast<float>( coords[ nCoords + 2 ].GetDouble() ) 
                                        )
                               );
        }

        for( unsigned int nTex = 0; nTex < texCoords.Size(); nTex += 2 )
        {
            pSub->AddVertex( 
                            Vertex( 
                                    vertexPositions[ nTex / 2 ], 
                                    static_cast<float>( texCoords[ nTex     ].GetDouble() ), 
                                    static_cast<float>( texCoords[ nTex + 1 ].GetDouble() ) 
                                   )
                           );
        }

        AddSubmesh( pSub );
    }
}
//---------------------------------
//
//---------------------------------
Mesh::~Mesh()
{
	submeshes.Clear();
	filename = "";
}