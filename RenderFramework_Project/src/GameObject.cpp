//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
//----------------------------------------------------------------------------

#include <math.h>
#include "MathEngine.h"
#include "GameObject.h"
#include "Game.h"
#include "GameObjectMan.h"
#include "Shader.h"
#include "Model.h"
#include "GraphicComponent.h"
#include "ShaderMan.h"
#include "GraphicComponent_Null.h"
#include "GraphicComponent_NormalNew.h"
#include "GraphicComponent_WireFrameNew.h"
#include "GraphicComponent_TextureUnlitNew.h"
#include "TextureMan.h"
#include "CameraMan.h"
#include "BoundingSphere.h"

extern Game *pGame;

GameObject::GameObject(GraphicComponent* _graphicComponent, uint32_t gameObjectID)
{
	assert(_graphicComponent != nullptr);
	this->type = gameObjectID;
	
	this->graphicComponent = _graphicComponent;
	privInitialize();

	GameObjectMan::Add(this);
}

GameObject::GameObject(GraphicComponent* _graphicComponent, GameObject* parent, uint32_t gameObjectID)
{
	assert(_graphicComponent != nullptr);
	assert(parent != nullptr);
	this->type = gameObjectID;
	this->graphicComponent = _graphicComponent;
	privInitialize();
	
	GameObjectMan::AddBeneath(this, parent);
}


GameObject::~GameObject()
{
	delete graphicComponent;
	delete this->bSphere;
	delete this->worldMatrix;
	delete this->scaleVect;
	delete this->transVect;
	delete this->rotVect;
	delete this->defaultUp;
	delete this->defaultDof;
	delete this->defaultScale;
}

void GameObject::update(float currentTime)
{
	UNUSED_VAR(currentTime);
	privComposeMatrix();

	//composeFunctionalMatrix();

	if (this->bSphere != nullptr) {
		privComposeBSphereMatrix();
	}
	

	this->graphicComponent->SetWorld(this->worldMatrix);
}

void GameObject::privComposeMatrix()
{
	Matrix ScaleMatrix(Matrix::Scale::XYZ, *this->scaleVect);
	Matrix defaultScaleMatrix(Matrix::Scale::XYZ, *this->defaultScale);
	Matrix TransMatrix(Matrix::Trans::XYZ, *this->transVect);
	Matrix RotMatrix(Matrix::Rot3::XYZ, this->rotVect->x(), this->rotVect->y(), this->rotVect->z());
	Quat AlignWithWorld(Quat::Orient::WorldToLocal, *this->defaultDof, *this->defaultUp);
	*this->worldMatrix = defaultScaleMatrix * ScaleMatrix * AlignWithWorld * RotMatrix * TransMatrix;
}

void GameObject::privComposeBSphereMatrix()
{
	// Get the ref Sphere
	const BSphere* pRefSphere = graphicComponent->modelTemplate->GetBoundingSphereRef();
	assert(pRefSphere);

	// Get the curr Sphere
	BSphere* pCurrSphere = this->graphicComponent->pCurrSphere;
	assert(pCurrSphere);

	// Update... cntr process through the world
	// Assuming a uniform scaling
	Vect A = pRefSphere->cntr;
	//Vect radius(1.0f, 0.0f, 0.0f);
	//Vect B = refCenter + radius;
	Vect A_out = A * (*this->worldMatrix);
	//Vect B_out = B * (*this->worldMatrix);

	float scaleX = this->scaleVect->x();
	float scaleY = this->scaleVect->y();
	float scaleZ = this->scaleVect->z();
	float maxScale = scaleX;
	if (scaleX > scaleY) {
		if (scaleX > scaleZ) {
			maxScale = scaleX;
		}
		else {
			maxScale = scaleZ;
		}
	}
	else {
		if (scaleY > scaleZ) {
			maxScale = scaleY;
		}
		else {
			maxScale = scaleZ;
		}
	}
	
	pCurrSphere->rad = maxScale * pRefSphere->rad;
	pCurrSphere->cntr = A_out;
}

void GameObject::SetWorldMatrix(Matrix *world)
{
	*this->worldMatrix = *world;
}

const Matrix* GameObject::GetWorldMatrix()
{
	return this->worldMatrix;
}

//Matrix GameObject::GetLookAtMatrix(float length)
//{
//	// Up vector as the lookat position
//	Vect lengthVect = *this->transVect;
//	lengthVect[y] = length;
//
//	// Orient
//	Matrix RotMatrix(Matrix::Rot_XYZ, this->rotVect->x(), this->rotVect->y(), this->rotVect->z());
//
//	// Length matrix
//	Matrix TransMatrix(Matrix::Trans, lengthVect);
//	
//	return TransMatrix * RotMatrix;
//}

const Vect* GameObject::GetRotationVector()
{
	return rotVect;
}

void GameObject::SetScale(const Vect& _scale)
{
	this->scaleVect->set(_scale);
}

void GameObject::SetScale(float _x, float _y, float _z)
{
	this->scaleVect->set(Vect(_x, _y, _z, 1.0f));
}

void GameObject::SetPosition(const Vect& _pos)
{
	this->transVect->set(_pos);
}

void GameObject::SetPosition(float _x, float _y, float _z)
{
	this->transVect->set(Vect(_x, _y, _z, 1.0f));
}

void GameObject::SetRotation(const Vect& _rot)
{
	this->rotVect->set(Vect(_rot));
	//this->rotationX = _rot[x];
	//this->rotationY = _rot[y];
	//this->rotationZ = _rot[z];
}

void GameObject::SetRotation(float anglex, float angley, float anglez)
{
	this->rotVect->set(Vect(anglex / MATH_180_PI, angley / MATH_180_PI, anglez / MATH_180_PI, 1.0f));
	//this->rotationX = anglex / MATH_180_PI;
	//this->rotationY = angley / MATH_180_PI;
	//this->rotationZ = anglez / MATH_180_PI;
}

void GameObject::SetDefaultOrientation(const Vect* _dof, const Vect* _up)
{
	*this->defaultDof = *_dof;
	*this->defaultUp = *_up;
}
void GameObject::SetDefaultScale(const Vect* _scale)
{
	*this->defaultScale = *_scale;
}

GraphicComponent* GameObject::GetGraphicsObject()
{
	return this->graphicComponent;
}

void GameObject::privInitialize()
{
	worldMatrix = new Matrix(Matrix::Special::Identity);
	scaleVect = new Vect(1.0f, 1.0f, 1.0f, 1.0f);
	transVect = new Vect(0.0f, 0.0f, 0.0f, 1.0f);
	rotVect = new Vect(0.0f, 0.0f, 0.0f, 1.0f);
	defaultUp = new Vect(0.0f, 1.0f, 0.0f, 1.0f);
	defaultDof = new Vect(0.0f, 0.0f, 1.0f, 1.0f);
	defaultScale = new Vect(1.0f, 1.0f, 1.0f, 1.0f);
	this->graphicComponent->modelTemplate->GetOrientation(*this->defaultDof, *this->defaultUp);
	this->bSphere = new BSphere();
	this->graphicComponent->modelTemplate->GetBoundSphere(*this->bSphere);
	//this->rotationX = 0.0f;
	//this->rotationY = 0.0f;
	//this->rotationZ = 0.0f;
}

BSphere GameObject::GetBSphere()
{
	return *this->bSphere;
}

void GameObject::draw()
{
	graphicComponent->Render();
}


//--- End of File ------------
