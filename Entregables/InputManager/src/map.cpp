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
	this->filename = filename;
	this->firstColId = firstColId;
	this->valid = false;

	String file = String::Read( filename );
	xml_document<> map;
	map.parse<0>((char*) file.ToCString() );
	
	xml_node<>* firstNode = map.first_node( file.ToCString() );
	this->width = atoi( map.first_attribute( "width" )->value() );
	this->height = atoi( map.first_attribute( "height" )->value() );
	this->tileWidth = atoi( map.first_attribute( "tilewidth" )->value() );
	this->tileWidth = atoi( map.first_attribute( "tileheight" )->value() );

	xml_node<>* tileSet = firstNode->first_node( "tileset" );

	int firstGid = atoi( tileSet->first_attribute("firstgid")->value() );
	int tileWidth = atoi( tileSet->first_attribute( "tilewidth" )->value() );
	int tileHeight = atoi( tileSet->first_attribute( "tileheight" )->value() );

	xml_node<>* tileOffset = tileSet->first_node( "tileoffset" );
	int x = 0;
	int y = 0;

	if( tileOffset )
	{
		x = atoi( tileOffset->first_attribute( "x" )->value() );
		y = atoi( tileOffset->first_attribute( "y" )->value() );
	}

	xml_node<>* xmlImage = tileSet->first_node( "image" );
	char* source = xmlImage->first_attribute( "source" )->value();
	int widthImage = atoi( xmlImage->first_attribute( "width" )->value() );
	int heightImage = atoi( xmlImage->first_attribute( "height" )->value() );

	//Image* image = ResourceManager::Instance().LoadImage( source, widthImage, heightImage );

	xml_node<>* layer = tileSet->first_node( "layer" );
	xml_node<>* data = layer->first_node( "data" );

	if( data->first_attribute( "encoding" ) || data->first_attribute( "compression" ) )
	{
		return;
	}

	xml_node<>* tile = data->first_node( "tile" );

	if( tile )
	{
		int gid = atoi( tile->first_attribute( "gid" )->value() );
		tileIds.Add( gid - firstGid );

		tile = tile->next_sibling( "tile" );
		//PREGUNTAR ESTE PASO

//		int nFrames = ( width * height ) / ( widthImage * heightImage );
		Image* image = ResourceManager::Instance().LoadImage( source, width / widthImage, height / heightImage );
		image->SetHandle( x, y );
	}


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
