#include "../include/submesh.h"
#include "../include/scene.h"
#include <stddef.h>

//---------------------------------
//
//---------------------------------
Ptr<Submesh> Submesh::Create(Ptr<Texture> tex = nullptr)
{
    return Ptr<Submesh>( new Submesh( tex ) );
}
//---------------------------------
//
//---------------------------------
void Submesh::AddVertex(const Vertex& v)
{
    vertices.Add( v );
}
//---------------------------------
//
//---------------------------------
void Submesh::AddTriangle(uint32 v0, uint32 v1, uint32 v2)
{
    indices.Add( v0 );
    indices.Add( v1 );
    indices.Add( v2 );
}
//---------------------------------
//
//---------------------------------
Ptr<Texture> Submesh::GetTexture() const
{
    return texture;
}
//---------------------------------
//
//---------------------------------
void Submesh::SetTexture(Ptr<Texture> tex)
{
    texture = tex;
}
//---------------------------------
//
//---------------------------------
const Array<Vertex>& Submesh::GetVertices() const
{
    return vertices;
}
//---------------------------------
//
//---------------------------------
Array<Vertex>& Submesh::GetVertices()
{
    return vertices;
}
//---------------------------------
//
//---------------------------------
void Submesh::Rebuild()
{
}
//---------------------------------
//
//---------------------------------
void Submesh::Render()
{
    if( GetTexture() == NULL )
    {
        Renderer::Instance()->BindTexture( 0 );
    }
    else
    {
        Renderer::Instance()->BindTexture( GetTexture()->GetHandle() );
        Renderer::Instance()->BindVertexBuffer( vertexBuffer );

        for( unsigned int index; index < vertices.Size(); index++ )
        {
            Renderer::Instance()->DrawBuffer( indices, offsetof( vertices[ index ].position.X()
            
        }
    }
}
//---------------------------------
//
//---------------------------------
Submesh::Submesh(Ptr<Texture> tex)
{
    vertexBuffer    = 0;
    indices         = 0;
    SetTexture( tex );
}
//---------------------------------
//
//---------------------------------
Submesh::~Submesh()
{
    if( vertexBuffer != 0 || indexBuffer )
    {
        vertices.Clear();
        indices.Clear();
    }
}