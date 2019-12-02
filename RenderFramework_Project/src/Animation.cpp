#include "Animation.h"
#include "StringOperation.h"
#include "AnimationMan.h"
#include "MathEngine.h"
#include "eat.h"
#include "RigAnimation_Format.h"
#include "SkeletonMan.h"
#include "Skeleton.h"

Animation::Animation(const char* pAnimationFileName, const char* clipName, AnimationClip clipType)
{

	assert("animation id not initialized!" && clipType != AnimationClip::Not_initialized_clip);
	//assert(("animation data not initilized!", false));
	this->type = clipType;

	// Read file & get data
	unsigned char* animationData = nullptr;
	unsigned int animationDataSize = 0;
	eat(pAnimationFileName, ChunkType::ANIM_TYPE, clipName, animationData, animationDataSize);
	this->data = (unsigned char*)malloc(animationDataSize);
	memcpy(this->data, animationData, animationDataSize);
	delete animationData;

	// Set header
	this->animationHeader = (AnimClipHeader*)this->data;

	AnimationMan::Add(this);
}
const AnimFrameData* Animation::privGetFrame(unsigned int boneID, unsigned int frame) {
	unsigned int frameIndex = frame;
	if (frame >= this->animationHeader->numFrames) {
		assert(frame < this->animationHeader->numFrames);
	}
	
	AnimFrameData* firstGlobalFrame = (AnimFrameData*)((unsigned int)this->data + (unsigned int)sizeof(AnimClipHeader));
	return (firstGlobalFrame + boneID * this->animationHeader->numFrames) + frameIndex;
}

Animation::~Animation()
{
	delete this->data;
}

Vect Animation::GetTranslate(unsigned int boneID, unsigned int frame)
{
	Vect ret(1.0f, 1.0f, 1.0f);
	const AnimFrameData* frameData = this->privGetFrame(boneID, frame);
	ret.set(frameData->tx, frameData->ty, frameData->tz);
	return ret;
}

Vect Animation::GetQuaternion(unsigned int boneID, unsigned int frame)
{
	Vect ret(0.0f, 0.0f, 0.0f);
	const AnimFrameData* frameData = this->privGetFrame(boneID, frame);
	ret.set(frameData->qx, frameData->qy, frameData->qz, frameData->qw);
	return ret;
}

Vect Animation::GetScale(unsigned int boneID, unsigned int frame)
{
	Vect ret(1.0f, 1.0f, 1.0f);
	const AnimFrameData* frameData = this->privGetFrame(boneID, frame);
	ret.set(frameData->sx, frameData->sy, frameData->sz);
	return ret;
}

unsigned int Animation::getFrameCount()
{
	return animationHeader->numFrames;
}
