#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "include/u-gine.h"

const float POS_INCREMENT = 0.2f;
const float PITCH_INCREMENT = 0.2f;

int	main(int	argc,	char*	argv[])	{	
	Screen::Instance().Refresh();
	Screen::Instance().Open( 800, 600, false );

	glfwSetMousePos(400, 300);
	//glfwDisable(GLFW_MOUSE_CURSOR);

    AudioEngine::Instance().Init();
    AudioBuffer audio( String( "data/music.wav" ) );
    AudioSource source( &audio );
    Listener* listener = &Listener::Instance();
    
    source.SetLooping( true );

    float pitch = 1.0;
    float pos = 0.0;
    bool pause = false;

    source.Play();
	while(Screen::Instance().IsOpened()	&& !Screen::Instance().KeyPressed( GLFW_KEY_ESC ))
	{	
        if( Screen::Instance().KeyPressed( GLFW_KEY_RIGHT ) ) pos += POS_INCREMENT;
       
        if( Screen::Instance().KeyPressed( GLFW_KEY_LEFT ) ) pos -= POS_INCREMENT;

        if( Screen::Instance().KeyPressed( GLFW_KEY_UP ) ) pitch += PITCH_INCREMENT;

        if( Screen::Instance().KeyPressed( GLFW_KEY_DOWN ) ) pitch -= PITCH_INCREMENT;

        source.SetPosition( pos, 0, 0 );
        source.SetPitch( pitch );

		Screen::Instance().Refresh();
	}

    source.Stop();
    AudioEngine::Instance().Finish();
	return	0;	
}

