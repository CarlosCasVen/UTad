#include "../include/font.h"
#include "../include/glyph.h"
#include "../include/glinclude.h"

extern "C" unsigned	char *stbi_load(const char *filename, int *x, int *y, int *comp, int req_comp);
extern "C" void	stbi_image_free(void *buffer);


Font::Font(const String& filename) : Image(filename, 16, 16)
{
	int widthImage = 0;
	int heightImage = 0;
	int nComponents = 4;
	unsigned int nFrames = 16 * 16;
	uint16 widthFrame = GetWidth();
	uint16 heightFrame = GetHeight();
	uint16 nLine = -1;

	unsigned char* pixels = stbi_load( filename.ToCString(), &widthImage, &heightImage, &nComponents, nComponents);

	for(unsigned int n = 0; n < nFrames; n++)
	{
		Glyph glyph(0, 0, widthFrame, heightFrame);

		uint16 row = n / 16;
		uint16 column = n % 16;

		for(unsigned int posY = row * heightFrame; posY < (row + 1) * heightFrame ; posY++ )
		{
			for(unsigned int posX = column * widthFrame; posX < (column + 1) * widthFrame; posX++)
			{

				unsigned char pixelR = pixels[(posY * widthImage + posX) * 4 + 0];
				unsigned char pixelG = pixels[(posY * widthImage + posX) * 4 + 1];
				unsigned char pixelB = pixels[(posY * widthImage + posX) * 4 + 2];
				unsigned char* pixelA = &pixels[(posY * widthImage + posX) * 4 + 3];
				


				if( Glyph::IsYellow( pixelR, pixelG, pixelB))
				{
					glyph.SetInitialCoordinates(posX, posY);
					*pixelA = 0;
				}
				else if( Glyph::IsRed( pixelR, pixelG, pixelB))
				{
					glyph.SetFinalCoordinates(posX, posY);
					*pixelA = 0;				
				}
				else if( Glyph::IsBlack( pixelR, pixelG, pixelB))
				{
					*pixelA = 0;
				}
			}
		}
	
		glyphs.Add(glyph);
	}

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthImage, heightImage, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

	stbi_image_free(pixels);

}

void Font::Render(const String& text, double x, double y)
{
	double xIncrement = x;

	for(int i = 0; i < text.Length(); i++)
	{
		Renderer::Instance().DrawImage(this, xIncrement, y , (unsigned char)text[i]);
		xIncrement += glyphs[(unsigned char)text[i]].GetWidth();
	}
}


uint32 Font::GetTextWidth(const String& text) const 
{
	uint16 widthText = 0;

	for(int i = 0; i < text.Length(); i++)
	{
		widthText += glyphs[(unsigned char)text[i]].GetWidth();
	}

	return widthText;
}


uint32 Font::GetTextHeight(const String& text) const
{
	uint16 maxHeight = 0;

	for(int i = 0; i < text.Length(); i++)
	{
		if( maxHeight < glyphs[(unsigned char)text[i]].GetHeight())
		{
			maxHeight = glyphs[(unsigned char)text[i]].GetHeight();
		}
	}

	return maxHeight;

}