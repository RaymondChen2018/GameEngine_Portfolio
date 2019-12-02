#include "Actor.h"
#include "Animation.h"
#include "ActorMan.h"
#include "GameObject_Bone.h"
#include "GraphicComponent_Null.h"
#include "GraphicComponent_WireframeNew.h"
#include "SkeletonMan.h"
#include "PCSNode.h"
#include "PCSTreeForwardIterator.h"
#include "Model.h"
#include "Shader.h"
#include "AnimationMan.h"
#include "Animation.h"
#include "SkeletonMan.h"
#include "VectApp.h"
#include "QuatApp.h"
#include "AnimatorComponent.h"
#include "ActorMan.h"

Actor::Actor(SkeletonRig skeleyType, AnimatorComponent* _animator)
{
	this->animator = _animator;

	// Create root bone
	this->root = new GameObject_Bone(BoneType::RootBone);
	this->numBones = 1;

	// Build bone rig
	unsigned int constructedBoneCount = SkeletonMan::constructBones(this, this->numBones, skeleyType);
	this->numBones = constructedBoneCount + 1;

	// Swap bone render
	//SetBoneColor(1.0f, 1.0f, 1.0f);

	// Add to collection
	ActorMan::Add(this);
}

Actor::~Actor()
{
	delete this->animator;
}

void Actor::SetBoneColor(float r, float g, float b, float a)
{
	PCSTreeForwardIterator pIter(this->root);
	PCSNode* pNode = pIter.First();
	pIter.Next();
	pNode = pIter.Next();

	GameObject_Bone* pBone = 0;

	unsigned int boneIndex = 0;
	while (boneIndex < this->numBones - 2)
	{
		assert(pNode);
		// Update the game object
		pBone = (GameObject_Bone*)pNode;

		Vect tmpColor(r, g, b, a);
		pBone->SetColor(&tmpColor);

		pNode = pIter.Next();
		boneIndex++;
	}
}

void Actor::SetPosition(float x, float y, float z)
{
	this->root->SetPosition(x,y,z);
}

void Actor::SetRotation(float x, float y, float z)
{
	this->root->SetRotation(x, y, z);
}

void Actor::SetScale(float x, float y, float z)
{
	this->root->SetScale(x, y, z);
}

void Actor::GLinkUpdate(float currentTime)
{
	// Compose animation matrix on all bones via animation info
	PCSTreeForwardIterator pIter(this->root);
	PCSNode* pNode = pIter.First();

	// Start from the node below root bone
	pNode = pIter.Next();

	GameObject_Bone* pBone = 0;

	unsigned int boneIndex = 0;
	Matrix* animMatrix = new Matrix(Matrix::Special::Identity);
	this->animator->AnimTimeUpdate(currentTime);
	while (boneIndex < this->numBones - 1)
	{
		assert(pNode);
		// Update the game object
		pBone = (GameObject_Bone*)pNode;

		Vect resultTrans;
		Quat resultQuat;
		Vect resultScale;
		
		this->animator->GetFrameData(pBone->GetBoneID(), currentTime, resultTrans, resultQuat, resultScale);

		Matrix trans(Matrix::Trans::XYZ, resultTrans[x], resultTrans[y], resultTrans[z]);
		Matrix scale(Matrix::Scale::XYZ, resultScale[x], resultScale[y], resultScale[z]);

		Matrix tmpAnimMatrix = scale * resultQuat * trans;
		pBone->SetAnimationMatrix(&tmpAnimMatrix);

		pNode = pIter.Next();
		boneIndex++;
	}
	delete animMatrix;
}

GameObject_Bone* Actor::FindBone(const char* boneName, bool nullCantFind)
{
	PCSTreeForwardIterator pIter(this->root);
	PCSNode* pNode = pIter.First();

	GameObject_Bone* pBone = nullptr;

	unsigned int boneIndex = 0;

	while (boneIndex < this->numBones)
	{
		assert(pNode);

		pBone = (GameObject_Bone*)pNode;
		if (strcmp(pBone->GetBoneName(), boneName) == 0) {
			break;
		}

		pNode = pIter.Next();
		boneIndex++;
	}
	assert("Cant find bone"&& (pNode || (nullCantFind)));
	return (GameObject_Bone*)pNode;
}

