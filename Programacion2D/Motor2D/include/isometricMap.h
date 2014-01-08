#ifndef UGINE_ISOMETRICMAP_H
#define UGINE_ISOMETRICMAP_H

#include "isometricScene.h"
#include "map.h"
#include "string.h"
#include "Array.h"
#include "types.h"


class IsometricMap : public Map 
{ 
public: 
	IsometricMap(const String& filename, uint16 firstColId = 0); 
	virtual void GenerateLayerSprites(IsometricScene* scene); 
	virtual uint16 GetTileWidth() const{ Map::GetTileWidth() / 2; }
	virtual void Render() const; 
	virtual int32 GetLayerId(uint16 column, uint16 row){ return GetTileId( column, row ); }

private: 
	Array<int32> topLayerIds;
};

#endif