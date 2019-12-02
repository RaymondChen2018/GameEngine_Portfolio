#include "AnimatorComponent.h"
#include "AnimationMan.h"
#include "Animation.h"
#include "MathEngine.h"
#include "VectApp.h"
#include "QuatApp.h"

AnimatorComponent::AnimatorComponent(AnimationClip clip)
{
	this->animationReference = AnimationMan::GetAnimation(clip);
	this->speedModifier = 1.0f;
	this->frameOffset = 0.0f;
	this->privGlobalTime = 0.0f;
	this->prevGlobalTime = 0.0f;
}

void AnimatorComponent::AnimTimeUpdate(float currentTime)
{
	float deltaTime = currentTime - this->prevGlobalTime;
	this->privGlobalTime += deltaTime * abs(this->speedModifier);
	this->prevGlobalTime = currentTime;
}

// Get bone id & globalTime and interpret it and dump data to position, orientation & scale
void AnimatorComponent::GetFrameData(unsigned int id, float globalTime, Vect& position, Quat& orientation, Vect& scale)
{
	assert(globalTime >= 0.0f);

	// Get animation time frame
	unsigned int numFrames = this->animationReference->getFrameCount();
	float animationTime = (this->privGlobalTime + this->frameOffset);// *this->speedModifier;
	float duration = (float)(numFrames - 1);
	unsigned int multiple = (unsigned int)(abs(animationTime) / duration);
	float clampTime = 0.0f;
	if (this->speedModifier >= 0.0f) {
		clampTime = animationTime - (float)multiple * duration;
	}
	else {
		clampTime = duration - (abs(animationTime) - (float)multiple * duration);
	}
	unsigned int frameIndex = (unsigned int)clampTime;
	unsigned int frameNextIndex = frameIndex + 1;
	float interpolateTime = (clampTime - (float)frameIndex);

	// Interpolate
	Vect tA = this->animationReference->GetTranslate(id, frameIndex);
	Vect currBoneQuat = this->animationReference->GetQuaternion(id, frameIndex);
	Quat currQuat(currBoneQuat[x], currBoneQuat[y], currBoneQuat[z], currBoneQuat[w]);
	Vect currBoneScale = this->animationReference->GetScale(id, frameIndex);

	Vect nextBoneTrans = this->animationReference->GetTranslate(id, frameNextIndex);
	Vect nextBoneQuat = this->animationReference->GetQuaternion(id, frameNextIndex);
	Quat nextQuat(nextBoneQuat[x], nextBoneQuat[y], nextBoneQuat[z], nextBoneQuat[w]);
	Vect nextBoneScale = this->animationReference->GetScale(id, frameNextIndex);

	VectApp::Lerp(position, tA, nextBoneTrans, interpolateTime);
	QuatApp::Slerp(orientation, currQuat, nextQuat, interpolateTime);
	VectApp::Lerp(scale, currBoneScale, nextBoneScale, interpolateTime);
}

void AnimatorComponent::SetAnimation(AnimationClip clip)
{
	this->animationReference = AnimationMan::GetAnimation(clip);
}
