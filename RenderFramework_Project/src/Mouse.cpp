//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
//----------------------------------------------------------------------------

#include <assert.h>

#include "Game.h"
#include "Mouse.h"

extern Game *pGame;

Mouse::Mouse()
{

}

// Use this to read mouse buttons
bool Mouse::GetKeyState(Button button)
{
	bool value;

	if ( pGame->GetMouseButton(button) == GLFW_PRESS)
	{
		value = true;
	}
	else
	{
		value = false;
	}
	return value;
}

void Mouse::GetCursor(float &xPos, float &yPos)
{
	// get mouse position
	pGame->GetCursorPos(xPos, yPos);
}

// Pin the mouse current position as pivot for delta analysis
void Mouse::Pin()
{
	assert(!locked);
	locked = true;

	// Get current pointer position
	POINT currPos;
	GetCursorPos(&currPos);

	// Lock at position
	lockPrevX = currPos.x;
	lockPrevY = currPos.y;
}

// Analyze mouse movement delta
void Mouse::GetMotionDelta(float& deltaX, float& deltaY)
{
	assert(locked);

	POINT currPos;
	GetCursorPos(&currPos);

	deltaX = (float)(currPos.x - lockPrevX);
	deltaY = (float)(currPos.y - lockPrevY);

	SetCursorPos(lockPrevX, lockPrevY);
}

// Unpin
void Mouse::Unpin()
{
	assert(locked);
	locked = false;
}

// --- End of File --------------------------------------------------
