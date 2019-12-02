//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
//----------------------------------------------------------------------------

#ifndef GAME_H
#define GAME_H

#include "Engine.h"

#include <sb7.h>
#include <math.h>
#include <vmath.h>
#include "MathEngine.h"

class Game : public Engine
{
public:
	// constructor
	Game(const char* windowName, const int Width, const int Height);
	~Game();

private:
	virtual void Initialize() override;
	virtual void LoadContent() override;
	virtual void CreateScene() override;
	virtual void Update(float currentTime) override;
	virtual void Draw() override;
	virtual void UnLoadContent() override;
	virtual void ClearBufferFunc() override;

	//virtual void onResize(int w, int h) override;

public:
	GLuint          program;
	GLuint          vao;
	GLuint          buffer;
	GLint           mv_location;
	GLint           proj_location;

	float           aspect;
	Matrix			*poProjMatrix;
};

#endif

// ---  End of File ---------------
