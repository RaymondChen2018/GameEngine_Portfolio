#include <sb7.h>
#include <math.h>
#include "MathEngine.h"
#include "Game.h"
#include "CustomModels.cpp"
#include "Time.h"
#include "Timer.h"
#include "Camera.h"
#include "GraphicComponent_TextureUnlitNew.h"
#include "GraphicComponent_NormalNew.h"
#include "GraphicComponent_WireframeNew.h"
#include "GraphicComponent_VertexLitNew.h"
#include "Animation.h"
#include "Skeleton.h"
#include "Actor.h"
#include "Shader.h"
#include "GameObject.h"
#include "GameObject_Simple.h"
#include "GameObject_DebugBSphere.h"
#include "GameObject_Bone.h"
#include "CameraMan.h"
#include "InputMan.h"
#include "ShaderMan.h"
#include "ModelMan.h"
#include "GameObjectMan.h"
#include "TextureMan.h"
#include "ActorMan.h"
#include "AnimationMan.h"
#include "AnimatorComponent.h"
#include "SkeletonMan.h"

//-----------------------------------------------------------------------------
//  Game::Game()
//		Game Engine Constructor
//-----------------------------------------------------------------------------
	Game::Game(const char* windowName, const int Width, const int Height)
		:Engine(windowName, Width, Height)
{
	this->aspect = 1.0f;
	this->poProjMatrix = new Matrix(Matrix::Special::Identity);
	this->buffer = 0;
	this->mv_location = 0;
	this->proj_location = 0;
	this->vao = 0;
	this->program = 0;
}

//-----------------------------------------------------------------------------
//  Game::~Game()
//		Game Engine destructor
//-----------------------------------------------------------------------------
Game::~Game()
{
	delete this->poProjMatrix;
}

//-----------------------------------------------------------------------------
// Game::Initialize()
//		Allows the engine to perform any initialization it needs to before 
//      starting to run.  This is where it can query for any required services 
//      and load any non-graphic related content. 
//-----------------------------------------------------------------------------
void Game::Initialize()
{
	float tmpAspect = (float)info.windowWidth / (float)info.windowHeight;
	vmath::mat4 tmpMatrix = vmath::perspective(50.0f, tmpAspect, 0.1f, 1000.0f);
	*this->poProjMatrix = (Matrix &)tmpMatrix;
	GameObjectMan::Initialize();
	CameraMan::Initialize();
}


//-----------------------------------------------------------------------------
// Game::LoadContent()
//		Allows you to load all content needed for your engine,
//	    such as objects, graphics, etc.
//-----------------------------------------------------------------------------
void Game::LoadContent()
{
	InputMan::Create();
	Vect up(0.0f, 1.0f, 0.0f), back(0.0f, 0.0f, -1.0f), down(0.0f, -1.0f, 0.0f), forward(0.0f, 0.0f, 1.0f);
	//Create Cameras
	float initAspect = (float)info.windowWidth / (float)info.windowHeight;
	Camera* camA = new Camera();
	camA->SetPosition(-147.159760f, -102.207428f, -296.796875f);
	camA->SetRotation(0.198968f * MATH_180_PI, -0.607374f * MATH_180_PI, 0.000000f * MATH_180_PI);
	camA->SetProjection(50.0f, initAspect, 0.1f, 8000.0f);
	Camera* camB = new Camera();
	camB->SetPosition(267.246490f, -106.562210f, -313.427216f);
	camB->SetRotation(0.244347f * MATH_180_PI, 0.626574f * MATH_180_PI, 0.000000f * MATH_180_PI);
	camB->SetProjection(50.0f, initAspect, 0.1f, 8000.0f);

	// Create Shaders
	new Shader(ShaderType::ColorPositionNew, "shader_ColorPosition");
	new Shader(ShaderType::UnlitGenericNew, "shader_UnlitGeneric");
	new Shader(ShaderType::VertexLit, "shader_VertexLitGeneric");
	new Shader(ShaderType::SolidColor, "shader_SolidColor");

	// Primitive Models
	new Model(PRIMITIVE::Quad, Vertices_quadNew, QUAD_DATA_NUM_VERTS, TriList_quadNew, QUAD_DATA_NUM_TRIS);
	new Model(PRIMITIVE::CubeNew, Vertices_cubeNew, CUBENEW_DATA_NUM_VERTS, TriList_cubeNew, CUBENEW_DATA_NUM_TRIS);
	sphereFunction(); // populate the sphere vert lists
	new Model(PRIMITIVE::Sphere, Vertices_sphereNew, SPHERE_DATA_NUM_VERTS, TriList_sphereNew, SPHERE_DATA_NUM_TRIS);
	
	Model* pyramid = new Model(PRIMITIVE::Pyramid, Vertices_pyramidNew, PYRAMID_DATA_NUM_VERTS, TriList_pyramidNew, PYRAMID_DATA_NUM_TRIS);
	pyramid->SetOrient(&up, &back);
	
	// External Models
	new Model(PRIMITIVE::Space_frigate, "space_frigate.smdl", 0.3f, true);
	Model* crash = new Model(PRIMITIVE::CrashBandicoo, "CrashBandicoot.smdl", 0.1f, true);
	crash->SetOrient(&down, &forward);

	// Outdated model, need to reconvert
	//new Model(PRIMITIVE::GroupA_Astroboy, "astroboy.smdl", 0.1f, true);
	//new Model(PRIMITIVE::GroupB_Buggy, "buggy.smdl", 0.05f, true);
	//new Model(PRIMITIVE::GroupC_Warbear, "warbear.smdl", 0.1f, true);

	// Teddy
	Model* teddyMdl; Skeleton* teddySkely;
	teddyMdl = new Model(PRIMITIVE::Teddy, "teddy_TGA.smdl", 1.0f, true);
	teddySkely = new Skeleton("teddy_TGA.smdl", SkeletonRig::BEARNOID);
	Vect teddyDefaultScale(0.7f, 0.7f, 0.7f);
	teddySkely->SetDefaultScale(&teddyDefaultScale);
	new Animation("teddy_TGA.smdl", "walk", AnimationClip::Bear_walk);
	new Animation("teddy_TGA.smdl", "idle", AnimationClip::Bear_idle);
	new Animation("teddy_TGA.smdl", "Take 003", AnimationClip::Bear_take003);

	// Human
	Model* humanMdl; Skeleton* humanSkely;
	humanMdl = new Model(PRIMITIVE::Humanoid, "humanoid.smdl", 1.0f, true);
	humanSkely = new Skeleton("humanoid.smdl", SkeletonRig::HUMANOID);
	Vect humanDefaultScale(0.12f, 0.12f, 0.12f);
	humanSkely->SetDefaultOrient(&down, &forward);
	humanSkely->SetDefaultScale(&humanDefaultScale);
	new Animation("humanoid.smdl", "run", AnimationClip::Human_run);
	new Animation("humanoid.smdl", "punch", AnimationClip::Human_punch);
	new Animation("humanoid.smdl", "shot", AnimationClip::Human_shot);

	// Texture
	TextureMan::addTexture("Rocks.tga", TextureName::ROCKS);
	TextureMan::addTexture("Stone.tga", TextureName::STONES);
	TextureMan::addTexture("RedBrick.tga", TextureName::RED_BRICK);
	TextureMan::addTexture("Duckweed.tga", TextureName::DUCKWEED);
	TextureMan::addTexture("Missing_texture.tga", TextureName::NOT_INITIALIZED);

	// Skeleton
	//new Skeleton("Bear.exo", SkeletonRig::BEARNOID);
	//new Skeleton("Human.exo", SkeletonRig::HUMANOID);

	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
}
AnimatorComponent* humanAnimatorS;
AnimationClip humanAnimatorSAnimation;
float humanSSpeed = 30.0f;
void Game::CreateScene()
{
	// Duckweed floor
	GraphicComponent* pGroundGraphic = new GraphicComponent_TextureUnlitNew(PRIMITIVE::CubeNew, TextureName::DUCKWEED);
	GameObject* pGround = new GameObject_Simple(pGroundGraphic, 1);
	pGround->SetPosition(0.0f, 0.0f, 0.0f);
	pGround->SetScale(1000.0f, 0.0f, 1000.0f);


	// Actors
	humanAnimatorSAnimation = AnimationClip::Human_run;
	humanAnimatorS = new AnimatorComponent(AnimationClip::Human_run);
	humanAnimatorS->SetSpeedMultiplier(humanSSpeed);
	Actor* actorHumanS = new Actor(SkeletonRig::HUMANOID, humanAnimatorS);
	actorHumanS->SetPosition(250.0f, 0.0f, 0.0f);
	actorHumanS->SetRotation(0.0f, 0.0f, 0.0f);
	actorHumanS->SetBoneColor(1.0f, 0.0f, 0.0f, 1.0f);

	AnimatorComponent* humanAnimator0 = new AnimatorComponent(AnimationClip::Human_run);
	humanAnimator0->SetSpeedMultiplier(30.0f);
	Actor* actorHuman0 = new Actor(SkeletonRig::HUMANOID, humanAnimator0);
	actorHuman0->SetPosition(50.0f, 0.0f, -200.0f);
	actorHuman0->SetRotation(0.0f, -90.0f, 0.0f);
	actorHuman0->SetBoneColor(0.0f, 0.0f, 1.0f, 1.0f);

	AnimatorComponent* humanAnimator1 = new AnimatorComponent(AnimationClip::Human_run);
	humanAnimator1->SetSpeedMultiplier(30.0f);
	humanAnimator1->SetFrame(40.0f);
	Actor* actorHuman1 = new Actor(SkeletonRig::HUMANOID, humanAnimator1);
	actorHuman1->SetPosition(50.0f, 0.0f, -250.0f);
	actorHuman1->SetRotation(0.0f, -90.0f, 0.0f);
	actorHuman1->SetBoneColor(0.0f, 0.0f, 1.0f, 1.0f);

	AnimatorComponent* humanAnimator2 = new AnimatorComponent(AnimationClip::Human_punch);
	humanAnimator2->SetSpeedMultiplier(30.0f);
	humanAnimator2->SetFrame(40.0f);
	Actor* actorHuman2 = new Actor(SkeletonRig::HUMANOID, humanAnimator2);
	actorHuman2->SetPosition(0.0f, 0.0f, 100.0f);
	actorHuman2->SetRotation(0.0f, -90.0f, 0.0f);

	AnimatorComponent* humanAnimator3 = new AnimatorComponent(AnimationClip::Human_shot);
	humanAnimator3->SetSpeedMultiplier(30.888f);
	Actor* actorHuman3 = new Actor(SkeletonRig::HUMANOID, humanAnimator3);
	actorHuman3->SetPosition(-220.0f, 0.0f, 50.0f);
	actorHuman3->SetRotation(0.0f, 90.0f, 0.0f);

	AnimatorComponent* humanAnimator4 = new AnimatorComponent(AnimationClip::Human_run);
	humanAnimator4->SetSpeedMultiplier(-30.0f);
	humanAnimator4->SetFrame(20.0f);
	Actor* actorHuman4 = new Actor(SkeletonRig::HUMANOID, humanAnimator4);
	actorHuman4->SetPosition(50.0f, 0.0f, -100.0f);
	actorHuman4->SetRotation(0.0f, -90.0f, 0.0f);
	actorHuman4->SetBoneColor(0.0f, 1.0f, 1.0f, 1.0f);


	// Bear
	AnimatorComponent* animatorBear0 = new AnimatorComponent(AnimationClip::Bear_walk);
	animatorBear0->SetSpeedMultiplier(30.0f);
	Actor* actorBear0 = new Actor(SkeletonRig::BEARNOID, animatorBear0);
	actorBear0->SetPosition(150.0f, 0.0f, 200.0f);
	actorBear0->SetBoneColor(1.0f, 0.6f, 0.0f, 1.0f);

	AnimatorComponent* animatorBear1 = new AnimatorComponent(AnimationClip::Bear_idle);
	animatorBear1->SetSpeedMultiplier(30.0f);
	Actor* actorBear1 = new Actor(SkeletonRig::BEARNOID, animatorBear1);
	actorBear1->SetPosition(200.0f, 0.0f, 200.0f);
	actorBear1->SetBoneColor(1.0f, 0.6f, 0.0f, 1.0f);
}

//-----------------------------------------------------------------------------
// Game::Update()
//      Called once per frame, update data, tranformations, etc
//      Use this function to control process order
//      Input, AI, Physics, Animation, and Graphics
//-----------------------------------------------------------------------------
void Game::Update(float currentTime)
{
	Timer timer;
	timer.Tic();

	CameraMan::Update(currentTime);

	// Rig animation update
	ActorMan::Update(currentTime);

	// Calculate gameObject matrices
	GameObjectMan::Update(currentTime);

	Time time = timer.Toc();
}


//-----------------------------------------------------------------------------
// Game::Draw()
//		This function is called once per frame
//	    Use this for draw graphics to the screen.
//      Only do rendering here
//-----------------------------------------------------------------------------
void Game::Draw()
{
	GameObjectMan::Draw();
}


//-----------------------------------------------------------------------------
// Game::UnLoadContent()
//       unload content (resources loaded above)
//       unload all content that was loaded before the Engine Loop started
//-----------------------------------------------------------------------------
void Game::UnLoadContent()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteProgram(program);
	glDeleteBuffers(1, &buffer);

	ActorMan::Destroy();
	SkeletonMan::Destroy();
	
	CameraMan::Destroy();
	GameObjectMan::Destroy();
	InputMan::Destroy();

	ShaderMan::Destroy();
	ModelMan::Destroy();
	AnimationMan::Destroy();
	TextureMan::Destroy();
}

//------------------------------------------------------------------
// Game::ClearBufferFunc()
// Allows user to change the way the clear buffer function works
//------------------------------------------------------------------
void Game::ClearBufferFunc()
{
	const GLfloat grey[] = { 0.7f, 0.7f, 0.8f, 1.0f };
	const GLfloat one = 1.0f;

	glViewport(0, 0, info.windowWidth, info.windowHeight);
	glClearBufferfv(GL_COLOR, 0, grey);
	glClearBufferfv(GL_DEPTH, 0, &one);
}
// ---  End of File ---------------
