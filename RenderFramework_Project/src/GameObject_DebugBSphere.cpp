#include "Framework.h"

#include "CameraMan.h"
#include "GameObject_DebugBSphere.h"
#include "GraphicComponent_WireframeNew.h"
#include "GameObject.h"
#include "BoundingSphere.h"
#include "Keyboard.h"
#include "InputMan.h"
#include "Model.h"
#include "Shader.h"

GameObject_DebugBSphere::GameObject_DebugBSphere(float r, float g, float b)
	: GameObject(new GraphicComponent_WireframeNew(PRIMITIVE::Sphere, ShaderType::SolidColor, new Vect(r, g, b, 1.0f)))
{
	this->pRefGameObj = nullptr;
	this->pScale = new Vect();
	this->pTrans = new Vect();
}

GameObject_DebugBSphere::~GameObject_DebugBSphere()
{
	delete this->pScale;
	delete this->pTrans;
}

void GameObject_DebugBSphere::SetBoundingSphereReference(GameObject* pGameObj)
{
	this->pRefGameObj = pGameObj;
}

void GameObject_DebugBSphere::privComposeMatrix()
{
	// Goal: update the world matrix

	Matrix ScaleMatrix(Matrix::Scale::XYZ, *this->pScale);
	Matrix TransMatrix(Matrix::Trans::XYZ, *this->pTrans);

	// world matrix
	*this->worldMatrix = ScaleMatrix * TransMatrix;



	// Flip the color based on camera_0
	//Camera* pCam = CameraMan::Find(Camera::Name::CAMERA_0);
	//Sphere* pCurrSphere = this->poGraphicsObject->pCurrSphere;

	//// Architecture issue... this doesn't feel good.
	//GraphicsObject_WireframeConstantColor* pGObj = (GraphicsObject_WireframeConstantColor*)this->poGraphicsObject;
	//if (pCam->CullTest(*pCurrSphere) == Camera::CullResult::CULL_OUTSIDE)
	//{
	//	pGObj->pWireColor->set(1.0f, 0.0f, 0.0f, 1.0f);
	//}
	//else
	//{
	//	pGObj->pWireColor->set(0.0f, 1.0f, 0.0f, 1.0f);
	//}


}

void GameObject_DebugBSphere::privUpdateBoundingSphereReference()
{
	// set the center and scale of bound box based on ref game object's world coord
	//BSphere pRefCurrSphere = this->pRefGameObj->GetBSphere();
	//this->pScale->set(pRefCurrSphere.rad * 2, pRefCurrSphere.rad * 2, pRefCurrSphere.rad * 2);
	//this->pTrans->set(pRefCurrSphere.cntr);

	

	BSphere* pCurrSphere = this->pRefGameObj->GetGraphicsObject()->pCurrSphere;
	this->pScale->set(pCurrSphere->rad * 2, pCurrSphere->rad * 2, pCurrSphere->rad * 2);
	this->pTrans->set(pCurrSphere->cntr);
}


void GameObject_DebugBSphere::update(float currentTime)
{
	(void)currentTime;
	// Set Translation & Scale from reference
	this->privUpdateBoundingSphereReference();

	// Goal: update the world matrix
	this->privComposeMatrix();

	// push to graphics object
	this->graphicComponent->SetWorld(this->worldMatrix);
}

void GameObject_DebugBSphere::draw()
{
	Keyboard* pKey = InputMan::GetKeyboard();
	if (pKey->GetKeyState(Keyboard::KEY_GRAVE_ACCENT)) {
		GameObject::draw();
	}
}

// End of File

