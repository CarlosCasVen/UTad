#include "stdafx.h"

//---------------------------------------------

//---------------------------------------------
void DrawFunction::Gotoxy(int x, int y)
{
	COORD pos = {x, y};
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}
//---------------------------------------------

//---------------------------------------------
void DrawFunction::Hidecursor(void)
{
	HANDLE hdl;
	hdl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO t;
	t.bVisible = false;
	SetConsoleCursorInfo(hdl, &t);
}
//---------------------------------------------

//---------------------------------------------
void DrawFunction::Clear()
{
	system("cls");
}
//---------------------------------------------

//---------------------------------------------
void DrawFunction::GameOver( unsigned int score, unsigned int nBullets )
{
	DrawFunction::Gotoxy(WORLD_WIDTH/2, GROUND_HEIGHT);
	printf("GAME OVER");
	DrawFunction::Gotoxy((WORLD_WIDTH/2), GROUND_HEIGHT);
	printf("SCORE: %d ", score );
	DrawFunction::Gotoxy((WORLD_WIDTH/2), GROUND_HEIGHT * 2 );
	printf("NUMBER OF BULLETS SHOT: %d", nBullets);
}
//---------------------------------------------

//---------------------------------------------
void DrawFunction::PrintWorld()
{
	for(unsigned int i = 0; i <= WORLD_WIDTH; i++)
	{
		DrawFunction::Gotoxy( NUMBER_OF_SPACES + i, GROUND_HEIGHT);
		printf("_");
	}
}
//---------------------------------------------

//---------------------------------------------
void DrawFunction::PrintSimbolInWorld(char simbol)
{
	printf("%c",simbol);
}