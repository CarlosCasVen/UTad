// Comportamientos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "include/u-gine.h"
#include "IGame.h"
#undef APIENTRY
#undef WINGDIAPI
#include <windows.h>
#include "bass/bass.h"
#undef LoadImage

int _tmain(int argc, _TCHAR* argv[])
{
  Screen&					screen		= Screen::Instance();
  const Renderer& renderer	= Renderer::Instance();

  screen.Open(800, 600, false);

	IGame::get()->init();
	
  Image* image = ResourceManager::Instance().LoadImage("data/images/alien.png");
  image->SetMidHandle();
	Sprite sprite(image);
	/*
	BASS_Init(-1, 44100, 0, NULL, NULL);

	HSAMPLE		sam = BASS_SampleLoad				(FALSE, "data/sound/explosion.mp3", 0, 0, 3, 0);
	HCHANNEL	ch	= BASS_SampleGetChannel	(sam, FALSE);
									BASS_ChannelPlay			(ch, FALSE);

	//BASS_Pause();
	//BASS_Start();
	//BASS_SampleFree(sam);

	HSTREAM stream = BASS_StreamCreateFile(FALSE,"data/sound/bgMusic.mp3", 0, 0 , 0);
	BASS_ChannelPlay(stream, FALSE);

	//BASS_ChannelStop(stream);
	//BASS_StreamFree(stream);
	*/
  while ( screen.IsOpened()  &&  !screen.KeyPressed(GLFW_KEY_ESC) ) 
	{
		float fDelta = static_cast<float>(screen.ElapsedTime());
		IGame::get()->update(fDelta);

		renderer.Clear(0, 0, 0);
		IGame::get()->render(fDelta);

		screen.Refresh();
	}

	IGame::get()->end();

  ResourceManager::Instance().FreeResources();

	DUMP_LEAKS

	return 0;
}

