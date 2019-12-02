#include "GameObject_Bone.h"
#include "GraphicComponent.h"
#include "GraphicComponent_Null.h"
#include "GameObject_BoneRender.h"

GameObject_Bone::GameObject_Bone(unsigned int _boneID) : GameObject(new GraphicComponent_Null())
{
	this->boneID = _boneID;
	this->privInitialize();
}

GameObject_Bone::GameObject_Bone(GameObject_Bone* parentBone, unsigned int _boneID) : GameObject(new GraphicComponent_Null(), parentBone)
{
	this->boneID = _boneID;
	this->privInitialize();
}

void GameObject_Bone::privInitialize()
{
	this->boneName = "";
	this->boneName = nullptr;
	this->animDeltaRotMatrix = new Matrix(Matrix::Special::Identity);
	this->refLocalMatrix = new Matrix(Matrix::Special::Identity);
	this->renderObject = new GameObject_BoneRender(1.0f, 1.0f, 1.0f);
}

GameObject_Bone::~GameObject_Bone()
{
	delete this->animDeltaRotMatrix;
	delete this->refLocalMatrix;
	delete this->boneName;
}

void GameObject_Bone::privComposeMatrix()
{
	// If Root bone, adhere original world composition
	if (this->boneID == BoneType::RootBone) {
		GameObject::privComposeMatrix();
	}
	// Child bone follows parent matrix
	else {
		// Follow parent matrix
		GameObject* parentObject = (GameObject*)this->GetParent();
		const Matrix* parentWorldMatrix = parentObject->GetWorldMatrix();

		//*this->worldMatrix = *(this->animDeltaRotMatrix) * (*this->refLocalMatrix) *(*parentWorldMatrix);
		*this->worldMatrix = *(this->animDeltaRotMatrix) * (*parentWorldMatrix);

		// Connect to parent
		this->renderObject->SetFromMatrix(parentWorldMatrix);
		this->renderObject->SetToMatrix(this->worldMatrix);
	}
}

void GameObject_Bone::SetColor(const Vect* newColor)
{
	this->renderObject->SetColor(newColor);
}


void GameObject_Bone::SetAnimationMatrix(const Matrix* _matrix)
{
	*(this->animDeltaRotMatrix) = *_matrix;
}

void GameObject_Bone::SetReferenceMatrix(const Matrix* _matrix)
{
	*(this->refLocalMatrix) = *_matrix;
}


