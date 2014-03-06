#include "../include/map.h"
#include "../include/rectcollision.h"
#include "../include/collision.h"
#include "../include/image.h"
#include "../include/renderer.h"
#include "../include/resourcemanager.h"
#include "../include/string.h"
#include "../lib/rapidxml.hpp"
#include <limits.h>

using namespace rapidxml;

Map::Map(const String &filename, uint16 firstColId) {
	// TAREA: Implementar constructor
	this->width = this->height = this->tileWidth = this->tileHeight = 0;
	this->valid = false;
	this->filename = filename;
	this->firstColId = firstColId;

	String content = String::Read( filename.ToCString() );
	xml_document<> file;
	file.parse<0>( (char*) content.ToCString() );

	//PRIMER NODO
	xml_node<>* map = file.first_node( "map" );
	this->width = atoi( map->first_attribute( "width" )->value() );
	this->height = atoi( map->first_attribute( "height" )->value() );
	this->tileWidth = atoi( map->first_attribute( "tilewidth" )->value() );
	this->tileHeight = atoi( map->first_attribute( "tileheight" )->value() );

	//TILESET
	xml_node<>* tileSet = map->first_node( "tileset" );
	int firstgid = atoi( tileSet->first_attribute( "firstgid" )->value() );
	int tilesetWidth = atoi( tileSet->first_attribute( "tilewidth" )->value() );
	int tilesetHeight = atoi( tileSet->first_attribute( "tileheight" )->value() ) ;

	//tileoffset
	int offsetX = 0, offsetY = 0;
	xml_node<>* tileoffset = tileSet->first_node( "tileoffset" );
	if( tileoffset )
	{
		offsetX = atoi( tileoffset->first_attribute( "x" )->value() );
		offsetY= atoi( tileoffset->first_attribute( "y" )->value() );
	}

	//IMAGE
	xml_node<>* imageXml = tileSet->first_node( "image" );
	imageFile = String( imageXml->first_attribute( "source" )->value() ).StripDir() ;
	int widthImageTileSet = atoi( imageXml->first_attribute( "width" )->value() );
	int heightImageTileSet = atoi( imageXml->first_attribute( "height" )->value() );

	//LAYER && DATA
	xml_node<>* layer = map->first_node( "layer" );
	xml_node<>* data = layer->first_node( "data" );

	if( data->first_attribute( "encoding" ) || data->first_attribute( "compression" ) )
	{
		return;
	}

	//TILE
	xml_node<>* tile = data->first_node( "tile" );

	while( tile )
	{
		int gid = atoi( tile->first_attribute( "gid" )->value() );
		tileIds.Add( gid - firstgid );
		tile = tile->next_sibling( "tile" );
	}

	String imageRoute = filename.ExtractDir() + "/" + imageFile;
	image = ResourceManager::Instance().LoadImage( imageRoute, widthImageTileSet / tilesetWidth, heightImageTileSet / tilesetHeight );
	image->SetHandle( offsetX, offsetY);

	valid = true;
}


void Map::Render() const {
	for ( uint16 y = 0; y < GetRows(); y++ ) {
		for ( uint16 x = 0; x < GetColumns(); x++ ) {
			if ( GetTileId(x, y) >= 0 ) {
				Renderer::Instance().DrawImage(image, x*GetTileWidth(), y*GetTileHeight(), GetTileId(x, y));
			}
		}
	}
}

bool Map::CheckCollision(const Collision* collision) const {
	// Creamos caja de colisiones
	double boxX = 0, boxY = 0, boxWidth = GetTileWidth(), boxHeight = GetTileHeight();
	RectCollision boxCol(&boxX, &boxY, &boxWidth, &boxHeight);
	
	// Comprobamos colision con cada tile
	for ( uint16 y = 0; y < GetRows(); y++ ) {
		for ( uint16 x = 0; x < GetColumns(); x++ ) {
			if ( GetTileId(x, y) >= firstColId ) {
				boxX = x * GetTileWidth();
				boxY = y * GetTileHeight();

				if ( collision->DoesCollide(&boxCol) )
					return true;
			}
		}
	}

	return false;
}

double Map::GetGroundY(double x, double y) const {
	double groundY = UINT_MAX;

	if ( x < 0  ||  x >= width*tileWidth  ||  y >= height*tileHeight ) return groundY;
	if ( y < 0 ) y = 0;

	// Buscamos el primer tile en esa columna
	for ( int tiley = int(y/tileHeight); tiley < height; tiley++ ) {
		if ( tileIds[tiley*width + int(x/tileWidth)] >= 0 ) {
			groundY = tiley*tileHeight;
			break;
		}
	}
	return groundY;
}
