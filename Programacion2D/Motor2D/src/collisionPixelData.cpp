#include "../include/collisionPixelData.h"
#include "../include/image.h"
#include "../include/glinclude.h"
#include "../include/math.h"
#include <math.h>
#include <stdlib.h>

// TAREA: Declarar funciones de stb_image.c
extern "C" unsigned	char *stbi_load(const char *filename, int *x, int *y, int *comp, int req_comp);
extern "C" void	stbi_image_free(void *buffer);


CollisionPixelData::CollisionPixelData(const String& filename)
{
	data = NULL;
	int nComp = 4;
	int x = 0, y = 0;
	unsigned char* buf = stbi_load( filename.ToCString() , &x, &y, &nComp, nComp );

	if( data )
	{
		width = x;
		height = y;

		data = new bool[ width * height];

		for(int i = 0; i < height; i++)
			{
				for(int a = 0; a < width; a++)
				{
					for(int k = 0; k < 4; k++)
					{
						if( buf[ ( i * width + a ) * 4 + 3 ] == 0 )
						{
							data[ i * width + a ] = false;
						}
						else
						{
							data[ i * width + a ] = true;
						}
					}
				}
			}
		stbi_image_free( buf );
	}
}


CollisionPixelData::~CollisionPixelData()
{
	delete [] data;
}
	

bool CollisionPixelData::GetData(uint32 x, uint32 y) const
{
	if( data )
	{
		return data[ y * width + x ];
	}

	return false;
}