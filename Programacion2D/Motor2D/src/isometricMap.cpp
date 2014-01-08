#include "../include/isometricMap.h"
#include "../include/math.h"
#include "../include/isometricSprite.h"


IsometricMap::IsometricMap(const String& filename, uint16 firstColId = 0) : Map( filename, firstColId )
{
}


void IsometricMap::GenerateLayerSprites(IsometricScene* scene)
{
	for ( uint16 y = 0; y < GetRows(); y++ ) 
	{
		for ( uint16 x = 0; x < GetColumns(); x++ ) 
		{
			int32 idTiled = GetTileId(x, y);
			if ( idTiled > -1 ) 
			{
				IsometricSprite* newSprite = scene->CreateSprite( GetImage() );
				newSprite->SetCurrentFrame( idTiled );

				if( GetFirstColId() >= idTiled )
				{
					newSprite->SetCollision( Sprite::COLLISION_RECT );
				}
				newSprite->SetPosition( x * GetImage()->GetWidth(), y * GetImage()->GetHeight() );				
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
			if ( GetTileId(x, y) >= 0 ) 
			{
				double posX = 0, posY = 0;
				TransformIsoCoords( x, y, 0, &posX, &posY );
				Renderer::Instance().DrawImage( GetImage(), posX * GetTileWidth(), posY * GetTileHeight(), GetTileId(x, y));
			}
		}
	}
}
