//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
//----------------------------------------------------------------------------

#include <assert.h>
#include "InputMan.h"

InputMan *InputMan::poInputMan = nullptr;

void InputMan::Create( )
{
	InputMan::privCreate( );
}

void InputMan::Destroy()
{
	InputMan *pMan = InputMan::privInstance();
	assert(pMan);

	delete pMan->poInputMan;
}

InputMan::InputMan( )
{
	this->poKeyboard = new Keyboard(  );
	assert(this->poKeyboard);
}

void InputMan::privCreate(   )
{
	InputMan::poInputMan = new InputMan(  );
	assert(poInputMan);
}

InputMan::~InputMan()
{
	delete this->poKeyboard;
}

Keyboard *InputMan::GetKeyboard()
{
	InputMan *pMan = InputMan::privInstance();
	return pMan->poKeyboard;
}

Mouse *InputMan::GetMouse()
{
	InputMan *pMan = InputMan::privInstance();
	return pMan->poMouse;
}

InputMan *InputMan::privInstance()
{
	assert( poInputMan );
	return poInputMan;
}

// --- End of File --------------------------------------------------
