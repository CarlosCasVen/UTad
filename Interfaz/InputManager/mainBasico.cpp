#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "include/u-gine.h"
/*
int	main(int	argc,	char*	argv[])	{	

	double x0;
	double y0;
	double radious = 30.0;

	Screen& screen = Screen::Instance();
	
	screen.Open(800, 600, false);

	x0 = screen.GetWidth() / 3.0;
	y0 = 0;

	while( screen.IsOpened() && !screen.KeyPressed(GLFW_KEY_ESC))
	{
		//TAREA: Pintar franjas de pantalla 
		Renderer::Instance().Clear(0, 0, 0);
		Renderer::Instance().SetColor(255,255,255,255);
		Renderer::Instance().DrawRect(x0, y0, x0, screen.GetHeight());

		//TAREA: Pintar círculos en modo SOLID
		Renderer::Instance().SetBlendMode(Renderer::BlendMode::SOLID);
		Renderer::Instance().SetColor(255, 0, 0, 255);
		Renderer::Instance().DrawEllipse(screen.GetWidth() / 2, radious * 2, radious,radious);
		Renderer::Instance().SetColor(0, 255, 0, 255);
		Renderer::Instance().DrawEllipse((screen.GetWidth() / 2) - radious / 2, radious * 2 + radious, radious,radious);
		Renderer::Instance().SetColor(0, 0, 255, 255);
		Renderer::Instance().DrawEllipse((screen.GetWidth() / 2) + radious / 2, radious * 2 + radious, radious,radious);

		//TAREA: Pintar círculos en modo ALPHA 
		Renderer::Instance().SetBlendMode(Renderer::BlendMode::ALPHA);
		Renderer::Instance().SetColor(255, 0, 0, 128);
		Renderer::Instance().DrawEllipse((screen.GetWidth() / 2) / 2, (screen.GetHeight() / 2) - radious * 2, radious,radious);
		Renderer::Instance().SetColor(0, 255, 0, 128);
		Renderer::Instance().DrawEllipse(((screen.GetWidth() / 2) / 2) - radious / 2, (screen.GetHeight() / 2) - radious * 2 + radious, radious,radious);
		Renderer::Instance().SetColor(0, 0, 255, 128);
		Renderer::Instance().DrawEllipse(((screen.GetWidth() / 2) / 2) + radious / 2, (screen.GetHeight() / 2) - radious * 2 + radious, radious,radious);

		//TAREA: Pintar círculos en modo MULTIPLICATIVE
		Renderer::Instance().SetBlendMode(Renderer::BlendMode::MULTIPLICATIVE);
		Renderer::Instance().SetColor(255, 0, 0, 255);
		Renderer::Instance().DrawEllipse(screen.GetWidth() / 2, screen.GetHeight() / 2 +  radious * 2, radious,radious);
		Renderer::Instance().SetColor(0, 255, 0, 255);
		Renderer::Instance().DrawEllipse((screen.GetWidth() / 2) - radious / 2, screen.GetHeight() / 2 +  radious * 2 + radious, radious,radious);
		Renderer::Instance().SetColor(0, 0, 255, 255);
		Renderer::Instance().DrawEllipse((screen.GetWidth() / 2) + radious / 2, screen.GetHeight() / 2 +  radious * 2 + radious, radious,radious);

		//TAREA: Pintar círculos en modo ADDITIVE 
		Renderer::Instance().SetBlendMode(Renderer::BlendMode::ADDITIVE);
		Renderer::Instance().SetColor(255, 0, 0, 255);
		Renderer::Instance().DrawEllipse((screen.GetWidth() / 3) * 2 + (screen.GetWidth() / 3) / 2, (screen.GetHeight() / 2) - radious * 2, radious,radious);
		Renderer::Instance().SetColor(0, 255, 0, 255);
		Renderer::Instance().DrawEllipse((screen.GetWidth() / 3) * 2 + (screen.GetWidth() / 3) / 2 - radious / 2, (screen.GetHeight() / 2) - radious * 2 + radious, radious,radious);
		Renderer::Instance().SetColor(0, 0, 255, 255);
		Renderer::Instance().DrawEllipse((screen.GetWidth() / 3) * 2 + (screen.GetWidth() / 3) / 2 + radious / 2, (screen.GetHeight() / 2) - radious * 2 + radious, radious,radious);
	
		//Refrescamos la pantalla 
		screen.Refresh();
	}

	return	0;	
}

*/