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
	rapidjson::Document jsonDoc;
    String jsonDocStr;

	this->filename = filename;
	
	if (filename.Length() == 0)
		return;

	jsonDocStr = String::Read(filename);

	if (jsonDoc.Parse<0>(jsonDocStr.ToCString()).HasParseError() == true)
        return;

	rapidjson::Value& submeshesJson = jsonDoc["submeshes"];

    if (submeshesJson.IsArray()) {
		for (rapidjson::SizeType i = 0; i < submeshesJson.Size(); i++) {
			String textureJson = submeshesJson[i]["texture"].GetString();

			Ptr<Texture> t = Texture::Create(textureJson);
			Ptr<Submesh> s = Submesh::Create(t);

			rapidjson::Value& indicesJson = submeshesJson[i]["indices"];
            if (indicesJson.IsArray()) {
				for (rapidjson::SizeType j = 0; j < indicesJson.Size(); j+=3)
                    s->AddTriangle(indicesJson[j].GetInt(), indicesJson[j+1].GetInt(), indicesJson[j+2].GetInt());
            }

            rapidjson::Value& coordsJson = submeshesJson[i]["coords"];
            if (coordsJson.IsArray()) {
				for (rapidjson::SizeType j = 0; j < coordsJson.Size(); j+=3) {
					Vector3 vector((float)coordsJson[j].GetDouble(), (float)coordsJson[j+1].GetDouble(), (float)coordsJson[j+2].GetDouble());

                    rapidjson::Value& texCoordsJson = submeshesJson[i]["texcoords"];                 
                    float u;
                    float v;

                    if (j % 2 == 0) {
                        u = (float)texCoordsJson[j/2].GetDouble();
                        v = (float)texCoordsJson[j/2+1].GetDouble();
                    }
                    else {
                        u = (float)texCoordsJson[j/2+1].GetDouble();
                        v = (float)texCoordsJson[j/2+2].GetDouble();
                    }
                    
                    Vertex vertex(vector, u, v);
                    s->AddVertex(vertex);                                       
                }
            }           

			AddSubmesh(s);
		}
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