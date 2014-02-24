#include "stdafx.h"

//---------------------------------------------

//---------------------------------------------
void DrawFunction::Gotoxy( int x, int y )
{
	COORD pos = {x, y};
	HANDLE output = GetStdHandle( STD_OUTPUT_HANDLE );
	SetConsoleCursorPosition( output, pos );
}
//---------------------------------------------

//---------------------------------------------
void DrawFunction::Hidecursor( void )
{
	HANDLE hdl;
	hdl = GetStdHandle( STD_OUTPUT_HANDLE );
	CONSOLE_CURSOR_INFO t;
	t.bVisible = false;
	SetConsoleCursorInfo( hdl, &t );
}
//---------------------------------------------

//---------------------------------------------
void DrawFunction::Clear()
{
    Gotoxy( 0, 0 );
    for( unsigned int i = 0; i < GROUND_HEIGHT; i++ )
    {
        for( unsigned int a = 0; a < WORLD_WIDTH + NUMBER_OF_SPACES; a++ )
        {
            printf( " " );
        }

        printf(  "\n" );  
    }
}
//---------------------------------------------

//---------------------------------------------
void DrawFunction::GameOver( unsigned int score, unsigned int nBullets )
{
    DrawFunction::Gotoxy( GAME_OVER_X_POSITION, GAME_OVER_Y_POSITION );
	printf( "GAME OVER" );
    DrawFunction::Gotoxy( GAME_OVER_X_POSITION, GAME_OVER_Y_POSITION + 1 );
    printf( "SCORE: %d ", score );
    DrawFunction::Gotoxy( GAME_OVER_X_POSITION, GAME_OVER_Y_POSITION + 2 );
	printf( "NUMBER OF BULLETS SHOT: %d", nBullets );
}
//---------------------------------------------

//---------------------------------------------
void DrawFunction::PrintWorld()
{
	printf( "\r" );

    for( unsigned int i = 0; i <= WORLD_WIDTH; i++ )
	{
		DrawFunction::Gotoxy( NUMBER_OF_SPACES + i, GROUND_HEIGHT );
        printf( "_" );
	}
}
//---------------------------------------------

//---------------------------------------------
void DrawFunction::PrintSimbolInWorld( char simbol )
{
	printf( "%c", simbol );
}