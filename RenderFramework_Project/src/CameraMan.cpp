#include "CameraMan.h"
#include "Camera.h"
#include "Keyboard.h"
#include "InputMan.h"
#include "Mouse.h"
#include "MathEngine.h"
#include "Game.h"
#include <conio.h>

extern Game* pGame;
void CameraMan::Initialize()
{
	CameraMan* man = privGetInstance();
	man->pMouse = new Mouse();
}
void CameraMan::Add(Camera * obj)
{
	CameraMan * man = privGetInstance();
	Linker * link = new Linker(obj);
	man->privAddLinker(link);

	man->pActive = link;
}
void CameraMan::SwitchNext()
{
	CameraMan * cam = privGetInstance();

	if (cam->pActive->pNext != nullptr) {
		cam->pActive = cam->pActive->pNext;
	}
	else {
		cam->pActive = cam->pHead;
	}
}
void CameraMan::Update(float currTime)
{
	(void)currTime;
	CameraMan * camMan = privGetInstance();
	Camera* activeCam = camMan->pActive->obj;
	Keyboard* pKey = InputMan::GetKeyboard();

	// Free cam mode
	if (camMan->pMouse->GetKeyState(Mouse::BUTTON_LEFT)) {
		// Pressed
		if (!camMan->leftKeyPressed) {
			camMan->pMouse->Pin();
		}
		// Hold down
		else {
			float deltaX, deltaY;
			camMan->pMouse->GetMotionDelta(deltaX, deltaY);

			// Analyze mouse movement to rotate camera
			float camRotX, camRotY, camRotZ;
			activeCam->GetRotation(camRotX, camRotY, camRotZ);
			activeCam->SetRotation(camRotX+deltaY/10.0f, camRotY+deltaX / 10.0f, camRotZ);
		}
		camMan->leftKeyPressed = true;
	}
	else {
		// Release
		if (camMan->leftKeyPressed) {
			camMan->pMouse->Unpin();
		}
		camMan->leftKeyPressed = false;
	}
	
	// Arrows-control camera adjustment
	if (pKey->GetKeyState(Keyboard::KEY_ARROW_LEFT)) {
		activeCam->angleRadY -= 0.05f;
	}
	if (pKey->GetKeyState(Keyboard::KEY_ARROW_RIGHT)) {
		activeCam->angleRadY += 0.05f;
	}
	if (pKey->GetKeyState(Keyboard::KEY_ARROW_UP)) {
		activeCam->angleRadX -= 0.05f;
	}
	if (pKey->GetKeyState(Keyboard::KEY_ARROW_DOWN)) {
		activeCam->angleRadX += 0.05f;
	}

	// WASD Movement
	float deltaXLocal = 0.0f, deltaYLocal = 0.0f;
	if (pKey->GetKeyState(Keyboard::KEY_A)) {
		deltaXLocal += camMan->camMovementSpeed;
	}
	if (pKey->GetKeyState(Keyboard::KEY_D)) {
		deltaXLocal -= camMan->camMovementSpeed;
	}
	if (pKey->GetKeyState(Keyboard::KEY_W)) {
		deltaYLocal += camMan->camMovementSpeed;
	}
	if (pKey->GetKeyState(Keyboard::KEY_S)) {
		deltaYLocal -= camMan->camMovementSpeed;
	}
	activeCam->x += cosf(activeCam->angleRadY) * deltaXLocal + cosf(activeCam->angleRadY + 90.0f / MATH_180_PI) * deltaYLocal; // XZ Horizon
	activeCam->z += sinf(activeCam->angleRadY) * deltaXLocal + sinf(activeCam->angleRadY + 90.0f / MATH_180_PI) * deltaYLocal; // XZ Horizon
	activeCam->y += sinf(activeCam->angleRadX) * deltaYLocal; // Pitch

	// Switch camera
	if (pKey->GetKeyState(Keyboard::KEY_SPACE)) {
		if (!camMan->keySwitchPressedPrev) {//Pressed
			camMan->SwitchNext();
			camMan->keySwitchPressedPrev = true;
		}
	}
	else {
		camMan->keySwitchPressedPrev = false;
	}
}

void CameraMan::Destroy()
{
	CameraMan * man = privGetInstance();
	Linker * pTmp = man->pHead;
	Linker * pDead = nullptr;
	while (pTmp != nullptr) {
		pDead = pTmp;
		pTmp = pTmp->pNext;

		delete pDead->obj;
		delete pDead;
	}
	man->pHead = nullptr;

	delete man->pMouse;
}

Matrix CameraMan::GetActiveCamWorldMatrix()
{
	CameraMan *cam = privGetInstance();
	return (cam->pActive->obj)->GetWorldMatrix();
}

Matrix CameraMan::GetActiveCamProjectMatrix()
{
	CameraMan *cam = privGetInstance();
	return (cam->pActive->obj)->GetProjectionMatrix();//*pGame->poProjMatrix;
}

void CameraMan::privAddLinker(Linker * link)
{
	if (pHead == nullptr) {
		pHead = link;
		pHead->pNext = nullptr;
		pHead->pPrev = nullptr;
	}
	else {
		link->pPrev = nullptr;
		link->pNext = pHead;
		pHead->pPrev = link;
		pHead = link;
	}
}
