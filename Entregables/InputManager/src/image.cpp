#include "../include/image.h"
#include "../include/glinclude.h"
#include "../include/math.h"
#include <math.h>
#include <stdlib.h>

// TAREA: Declarar funciones de stb_image.c
extern "C" unsigned	char *stbi_load(const char *filename, int *x, int *y, int *comp, int req_comp);
extern "C" void	stbi_image_free(void *buffer);


Image::Image(const String &filename, uint16 hframes, uint16 vframes) {
	this->filename = filename;
	this->hframes = hframes;
	this->vframes = vframes;
	width = 0;
	height = 0;
	handlex = 0;
	handley = 0;
	gltex = 0;
	lastU = 1.0;
	lastV = 1.0;

	int pX = 0;
	int pY = 0;
	int nComponents = 4;

	// TAREA: Cargar el buffer de la imagen
	unsigned char* buffer = stbi_load(filename.ToCString(), &pX, &pY, &nComponents, 4);  
	width = (int16)pX;
	height = (int16)pY;

	// Generamos la textura
	if (buffer)
	{

		//PARTE AVANZADA
		unsigned char* newBuffer = NULL;
		bool supportedPowerOfTwo = glfwExtensionSupported("GL_ARB_texture_non_power_of_two") == 1;
		bool newBufferNeeded = false;
		uint16 newWidth = (uint16)pow(2,ceil(Log2(pX)));
		uint16 newHeight = (uint16)pow(2,ceil(Log2(pY)));

		if(!supportedPowerOfTwo)
		{
			if(pX != newWidth)
			{
				newBufferNeeded = true;
			}
	
			if(pY != newHeight)
			{
				newBufferNeeded = true;
			}
		}

		if(newBufferNeeded)
		{
			unsigned int sizeNewBuffer = newWidth * newHeight * 4;
			unsigned char* newBuffer = new unsigned char [sizeNewBuffer];

			memset(newBuffer, 0, sizeNewBuffer);

			//COPIA EN EL NUEVO BUFFER
			uint16 nElemBuffer = 0;

			for(int i = 0; i < pY; i++)
			{
				for(int a = 0; a < pX; a++)
				{
					for(int k = 0; k < 4; k++)
					{
						newBuffer[(i * newWidth + a) * 4 + k] = buffer[nElemBuffer++];
					}
				}
			}
			//FIN COPIA 

			lastU = (width * 1.0) / newWidth;
			lastV = (height * 1.0) / newHeight;
			pX = newWidth;
			pY = newHeight;
			stbi_image_free(buffer);
			buffer = newBuffer;
		}
		//FIN PARTE AVANZADA

		// TAREA: Generar la textura de OpenGL
		glGenTextures(1, &gltex);

		Bind();
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, pX, pY, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);

		if(!newBufferNeeded)
		{
			stbi_image_free(buffer);
		}
		else
		{
			delete []newBuffer;
		}
	}

}

Image::~Image() {
	glDeleteTextures(1, &gltex);
}

void Image::Bind() const {
	// TAREA: Establecer la textura actual
	glBindTexture(GL_TEXTURE_2D, gltex);
}


