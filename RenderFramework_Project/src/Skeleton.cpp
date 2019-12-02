#include "Skeleton.h"
#include "Animation.h"
#include "SkeletonMan.h"
#include "AnimationMan.h"
#include "eat.h"
#include "StringOperation.h"
#include "RigAnimation_Format.h"
#include "MathEngine.h"

Skeleton::Skeleton(const char* pSkeletonFileName, SkeletonRig rigType)
{
	this->defaultDOF = new Vect(0.0f, 0.0f, 1.0f);
	this->defaultUP = new Vect(0.0f, 1.0f, 0.0f);
	this->defaultScale = new Vect(1.0f, 1.0f, 1.0f);
	this->type = rigType;

	// Read bones
	const char* ModelName = RemoveExt(pSkeletonFileName);
	unsigned char* boneStructData = nullptr;
	unsigned int boneDataSize = 0;
	eat(pSkeletonFileName, ChunkType::SKELETON_TYPE, ModelName, boneStructData, boneDataSize);
	this->numBones = boneDataSize / sizeof(Bone);
	this->boneArray = (Bone*)malloc(boneDataSize);
	memcpy(this->boneArray, boneStructData, boneDataSize);
	/*for (unsigned int i = 0; i < this->numBones; i++) {
		Bone bone = *(this->boneArray + i);
		float testValue = bone.boneID;
	}*/

	// Read reference poses
	unsigned char* skeletonReferenceData = nullptr;
	unsigned int skeletonReferenceSize = 0;
	eat(pSkeletonFileName, ChunkType::POSE_TYPE, ModelName, skeletonReferenceData, skeletonReferenceSize);
	this->numBonePose = skeletonReferenceSize / sizeof(Pose);
	this->refPose = (Pose*)malloc(skeletonReferenceSize);
	memcpy(this->refPose, skeletonReferenceData, skeletonReferenceSize);

	//for (unsigned int i = 0; i < numBonePose; i++) {
	//	printf(this->refPose[i].boneName);
	//}

	// Get clips count and info
	//assert(("Not implemented, read file here", false));
	//this->numClips = 5;
	//defaultClips = new AnimationClip[this->numClips];

	//// Load animations
	//for (int i = 0; i < this->numClips; i++) {
	//	// Iterate the same package to find animation clip data
	//	assert(("Iterate the same package for data", false));
	//	void* dataChunk = nullptr;
	//	size_t dataSize = 0;



	//	AnimationClip clipID = AnimationMan::GetCustomClipID();
	//	defaultClips[i] = clipID;
	//	Animation* animation1 = new Animation(pSkeletonFileName, clipID);
	//}


	// Add this to collection
	SkeletonMan::Add(this);
	delete ModelName;
}

Skeleton::~Skeleton()
{
	delete this->defaultScale;
	delete this->defaultDOF;
	delete this->defaultUP;
}

const Bone* Skeleton::GetAnimatedBone(unsigned int index)
{
	const Bone* consBoneRef = this->boneArray + index;
	return consBoneRef;
}

const Pose* Skeleton::GetPose(unsigned int index)
{
	const Pose* consPoseRef = this->refPose + index;
	return consPoseRef;
}

void Skeleton::SetDefaultOrient(const Vect* _dof, const Vect* _up)
{
	*this->defaultDOF = *_dof;
	*this->defaultUP = *_up;
}

void Skeleton::SetDefaultScale(const Vect* _scale)
{
	*this->defaultScale = *_scale;
}

