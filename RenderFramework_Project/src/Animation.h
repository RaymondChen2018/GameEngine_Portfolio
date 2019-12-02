#ifndef ANIMATION_H
#define ANIMATION_H
#include "GenericObject.h"
class Vect;
enum AnimationClip : uint32_t {
	Bear_walk,
	Bear_idle,
	Bear_take003,
	Human_idle,
	Human_walk,
	Human_run,
	Human_punch,
	Human_shot,
	Not_initialized_clip,
	CustomClip
};
struct AnimClipHeader;
struct AnimFrameData;
class Vect;
class Animation : GenericObject {
public:
	Animation(const char* pAnimationFileName, const char* clipName, AnimationClip clipType);
	AnimationClip GetAnimationType() { return (AnimationClip)type; };
	~Animation();

	Vect GetTranslate(unsigned int boneID, unsigned int frame);
	Vect GetQuaternion(unsigned int boneID, unsigned int frame);
	Vect GetScale(unsigned int boneID, unsigned int frame);

	unsigned int getFrameCount();
	

private:
	

	const AnimFrameData* privGetFrame(unsigned int boneID, unsigned int frame);


	AnimClipHeader* animationHeader;
	unsigned char* data;
};

#endif

