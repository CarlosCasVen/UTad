#include "../include/isometricMap.h"
#include "../include/math.h"
#include "../include/isometricSprite.h"
#include "../lib/rapidxml.hpp"
#include <limits.h>


using namespace rapidxml;

IsometricMap::IsometricMap(const String& filename, uint16 firstColId ) : Map( filename, firstColId )
{


	String content = String::Read( filename.ToCString() );
	xml_document<> file;
	file.parse<0>( (char*) content.ToCString() );

	xml_node<>* map = file.first_node( "map" );


	xml_node<>* tileSet = map->first_node( "tileset" );
	int firstgid = atoi( tileSet->first_attribute( "firstgid" )->value() );

	xml_node<>* layer = map->first_node( "layer" );
	layer = layer->next_sibling( "layer" );
	xml_node<>* data = layer->first_node( "data" );

	if( data->first_attribute( "encoding" ) || data->first_attribute( "compression" ) )
	{
		return;
	}

	xml_node<>* tile = data->first_node( "tile" );
	
	while( tile )
	{
		int gid = atoi( tile->first_attribute( "gid" )->value() );
		topLayerIds.Add( gid - firstgid );
		tile = tile->next_sibling( "tile" );
	}

	int handleX = GetImage()->GetHandleX() + GetTileWidth();
	int handleY = GetImage()->GetHeight() - GetImage()->GetHandleY() - GetTileHeight();
	GetImage()->SetHandle( handleX, handleY );
}


void IsometricMap::GenerateLayerSprites(IsometricScene* scene)
{
	for ( uint16 y = 0; y < GetRows(); y++ ) 
	{
		for ( uint16 x = 0; x < GetColumns(); x++ ) 
		{	
			int tileId = GetLayerId( x, y );

			if( tileId > -1 )
			{
				IsometricSprite* newSprite = scene->CreateSprite( GetImage() );
				newSprite->SetCurrentFrame( tileId );

				if( GetFirstColId() >= tileId )
				{
					newSprite->SetCollision( Sprite::COLLISION_RECT );
				}
				int tileWidth = GetTileWidth();
				int tileHeight = GetTileHeight();
				newSprite->SetPosition( x * GetTileWidth(), y * GetTileHeight() );	
			}
		}
	}
}


void IsometricMap::Render() const
{

	for ( uint16 y = 0; y < GetRows(); y++ ) 
	{
		for ( uint16 x = 0; x < GetColumns(); x++ ) 
		{			
			int tileId =  GetTileId( x, y );
			if ( GetTileId( x, y ) >= 0 ) 
			{
				double posX = 0, posY = 0;
				TransformIsoCoords( x * GetTileWidth(), y * GetTileHeight(), 0, &posX, &posY );
				Renderer::Instance().DrawImage( GetImage(), posX , posY, GetTileId(x, y) );
			}
		}
	}
}


