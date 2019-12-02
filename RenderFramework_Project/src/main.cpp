//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
//----------------------------------------------------------------------------

#include "Framework.h"
#include "Game.h"

Game *pGame = 0;

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// const char* windowName, const int Width,const int Height

	pGame = new Game("Raymond", 800, 600);
	pGame->run();
	delete pGame;


	return 0;
}

// ---  End of File ---------------
