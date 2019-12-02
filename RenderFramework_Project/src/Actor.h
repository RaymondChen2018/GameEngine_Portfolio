#ifndef ACTOR_H
#define ACTOR_H
#include "GenericObject.h"

//-----------------------------------------------------------------------------
// Actor is run-time version of a skeleton and, a puppet-master class that takes possession of a group of 
// GameObject_Bones via a double-linked list. It animates them according to a bone-based animation.
// 
// Actor's run-time update is LINEAR and does not follow any prioritized order. However, this will not affect
// the correctness of update between GameObject_Bone parent and its children, because Actor only update the
// animation matrix buffer of a GameObject_Bone and let the GameObject_Bone be updated by GameObjectMan later
// with effect of the animation matrix buffer.
//-----------------------------------------------------------------------------
enum SkeletonRig : uint32_t;
class AnimatorComponent;
class Skeleton;
class GameObject_Bone;
class Actor : public GenericObject {
public:
	Actor(SkeletonRig skeleyType, AnimatorComponent* _animator);
	~Actor();

	void SetBoneColor(float r, float g, float b, float a);

	void SetPosition(float x, float y, float z);
	void SetRotation(float x, float y, float z);
	void SetScale(float x, float y, float z);
	
	void GLinkUpdate(float currentTime) override;
	GameObject_Bone* FindBone(const char* boneName, bool nullCantFind = false);
	GameObject_Bone* GetRoot() { return this->root; };

private:
	// Animation controller
	AnimatorComponent* animator;

	// Bones
	GameObject_Bone* root;
	unsigned int numBones; // Including root bone
};
#endif