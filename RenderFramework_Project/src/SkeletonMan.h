#ifndef SKELETON_MAN_H
#define SKELETON_MAN_H
#include "GenericMan.h"
class Skeleton;
class Actor;
class GameObject_Bone;
enum SkeletonRig :uint32_t;
class SkeletonMan : public GenericMan {
public:
	static void Add(Skeleton* genericObject);
	static void Destroy();
	static Skeleton* GetSkeleton(SkeletonRig shader);
	static unsigned int constructBones(Actor* actor, unsigned int& actorBoneCount, SkeletonRig rigType);
private:
	static SkeletonMan* privGetInstance(void) {
		static SkeletonMan gom;
		return &gom;
	}
};

#endif