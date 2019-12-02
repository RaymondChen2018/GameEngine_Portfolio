#include "SkeletonMan.h"
#include "Skeleton.h"
#include "GameObjectMan.h"
#include "GameObject_Bone.h"
#include "GraphicComponent_Null.h"
#include "MathEngine.h"
#include "MathApp.h"
#include "RigAnimation_Format.h"
#include "Actor.h"
#pragma warning( disable : 5045 )
void SkeletonMan::Add(Skeleton* genericObject)
{
	GenericMan* genericMan = privGetInstance();
	genericMan->Add((GenericObject*)genericObject);
}

void SkeletonMan::Destroy()
{
	GenericMan* genericMan = privGetInstance();
	genericMan->Destroy();
}

Skeleton* SkeletonMan::GetSkeleton(SkeletonRig model)
{
	GenericMan* genericMan = privGetInstance();
	return (Skeleton*)genericMan->GetGenericObject((uint32_t)model);
}

// Construct bones under the specified root bone
// Return the number of bones constructed under the root, not counting the root bone
unsigned int SkeletonMan::constructBones(Actor* actor, unsigned int& actorBoneCount, SkeletonRig rigType)
{
	GameObject_Bone* root = actor->GetRoot();
	
	assert("Need to provide a root bone" && root != nullptr);
	assert("Rig type not initialized" && rigType != SkeletonRig::Not_initialized_skeleton);
	

	// Construct skeleton
	Skeleton* skel = GetSkeleton(rigType);
	root->SetDefaultOrientation(skel->GetDefaultDOF(), skel->GetDefaultUP());
	root->SetDefaultScale(skel->GetDefaultScale());
	assert("Skeleton not found" && skel != nullptr);
	unsigned int numBones = skel->GetNumBones();
	assert("Not bone" && numBones != 0);
	//unsigned int numPoses = skel->GetNumPose();
	//assert("Not reference pose" && numPoses != 0);
	
	assert("Root bone name null!" && skel->GetAnimatedBone(0)->parentName != nullptr);
	root->SetBoneName(skel->GetAnimatedBone(0)->parentName);
	GameObject_Bone* parentNode = root;

	for (unsigned int i = 0; i < numBones; i++) {
		const Bone* bone = skel->GetAnimatedBone(i);

		Vect boneColor(1.0f, 1.0f, 1.0f, 1.0f);
		if (i > 0) {
			parentNode = actor->FindBone(bone->parentName);
			if (parentNode == nullptr) {
				parentNode = root;
			}
		}
		else { // Animated root bone
			boneColor.set(0.0f, 0.0f, 0.0f, 0.0f);
		}

		GameObject_Bone* boneObject = new GameObject_Bone(parentNode, bone->boneID);
		boneObject->SetBoneName(bone->objName);
		boneObject->SetColor(&boneColor);

		actorBoneCount++;
	}

	// Set to reference pose
	// Buffer pose's world matrix to bone's world matrix, later used offset parent to get delta matrix for children
	//for (unsigned int i = 0; i <= numPoses; i++) {
	//	// Get bone info
	//	const Pose* poseRef = skel->GetPose(i);
	//	GameObject_Bone* boneNode = actor->FindBone(poseRef->boneName, true);
	//	if (boneNode == nullptr) {
	//		continue;
	//	}

	//	boneNode->SetWorldMatrix(((Matrix*)(poseRef->world)));
	//	printf("");
	//}
	//// Calculate delta reference
	//for (unsigned int i = 0; i <= numPoses; i++) {
	//	// Get bone info
	//	const Pose* poseRef = skel->GetPose(i);
	//	GameObject_Bone* boneNode = actor->FindBone(poseRef->boneName, true);
	//	if (boneNode == nullptr) {
	//		continue;
	//	}

	//	GameObject_Bone* parentBone = (GameObject_Bone*)(boneNode->GetParent());
	//	const Matrix* parentBoneMatrix = parentBone->GetWorldMatrix();
	//	const Matrix* currBoneMatrix = (Matrix*)(poseRef->world);

	//	// starting point
	//	Vect start(0.0f, 0.0f, 0.0f);

	//	//  At this point, Find the two bones initial positions in world space
	//	//  Now get the length and directions

	//	Vect ptA = start * *parentBoneMatrix;
	//	Vect ptB = start * *currBoneMatrix;

	//	// direction between the anchor points of the respective bones
	//	Vect dir = (ptA - ptB);

	//	Matrix T(Matrix::Trans::XYZ, -dir);

	//	boneNode->SetReferenceMatrix(&T);

	//}


	

	

	return numBones;
}

