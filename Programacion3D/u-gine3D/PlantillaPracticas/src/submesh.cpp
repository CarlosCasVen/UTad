#include "../include/submesh.h"
#include "../include/scene.h"
#include "../include/vertex.h"
#include <stddef.h>

//---------------------------------
//
//---------------------------------
Ptr<Submesh> Submesh::Create(Ptr<Texture> tex )
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
	if( indexBuffer == 0 )	indexBuffer  = Renderer::Instance()->CreateBuffer();			
	if( vertexBuffer == 0 )	 vertexBuffer = Renderer::Instance()->CreateBuffer();

	Renderer::Instance()->BindIndexBuffer( indexBuffer   );
	Renderer::Instance()->SetIndexBufferData( &indices[0]  , indices.Size () );
	Renderer::Instance()->BindIndexBuffer ( 0 );
	Renderer::Instance()->BindVertexBuffer( vertexBuffer );
	Renderer::Instance()->SetVertexBufferData( &vertices[0], vertices.Size() );
	Renderer::Instance()->BindVertexBuffer( 0 );		
	
}
//---------------------------------
//
//---------------------------------
void Submesh::Render()
{
    if( GetTexture() == NULL )  Renderer::Instance()->BindTexture( 0 );
    else						Renderer::Instance()->BindTexture( GetTexture()->GetHandle() );

	Renderer::Instance()->BindVertexBuffer( vertexBuffer );
	Renderer::Instance()->BindIndexBuffer ( indexBuffer  );
	Renderer::Instance()->DrawBuffer( indices.Size(), offsetof( Vertex, position ), offsetof( Vertex, u ), sizeof( Vertex ) );
}
//---------------------------------
//
//---------------------------------
Submesh::Submesh(Ptr<Texture> tex) : texture( tex )
{
    vertexBuffer    = 0;
	indexBuffer     = 0;
    SetTexture( tex );
}
//---------------------------------
//
//---------------------------------
Submesh::~Submesh()
{
    if( vertexBuffer != 0 )  
    {
        vertices.Clear();
		vertexBuffer = 0;
		Renderer::Instance()->FreeBuffer( vertexBuffer );
    }
	if( indexBuffer  != 0 )
	{
		indices.Clear();
		indexBuffer = 0;
		Renderer::Instance()->FreeBuffer( indexBuffer );
	}

}