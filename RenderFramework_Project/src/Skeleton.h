#ifndef SKELETON_H
#define SKELETON_H
#include "GenericObject.h"

enum SkeletonRig : uint32_t {
	HUMANOID,
	BEARNOID,
	Not_initialized_skeleton
};
enum AnimationClip : uint32_t;
struct Bone;
struct Pose;
class Vect;
class GameObject_RigAnimation;
class Skeleton : GenericObject {
public:
	Skeleton(const char* pSkeletonFileName, SkeletonRig rigType);
	~Skeleton();
	unsigned int GetNumBones() { return numBones; }
	unsigned int GetNumPose() { return numBonePose; }
	const Bone* GetAnimatedBone(unsigned int index);
	const Pose* GetPose(unsigned int index);

	void SetDefaultOrient(const Vect* _dof, const Vect* _up);
	void SetDefaultScale(const Vect* _scale);

	const Vect* GetDefaultDOF() { return this->defaultDOF; }
	const Vect* GetDefaultUP() { return this->defaultUP; }
	const Vect* GetDefaultScale() { return this->defaultScale; }

private:
	Vect* defaultDOF;
	Vect* defaultUP;
	Vect* defaultScale;

	// Bone hierarchy
	Bone* boneArray;
	unsigned int numBones;

	// Skeleton reference
	Pose* refPose;
	unsigned int numBonePose;

	AnimationClip* defaultClips;
	unsigned int numClips;

	void* serializedData;
};
#endif