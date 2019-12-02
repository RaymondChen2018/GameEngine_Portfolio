#ifndef ANIMATION_MAN_H
#define ANIMATION_MAN_H
#include "GenericMan.h"
class Animation;
enum AnimationClip : uint32_t;
class AnimationMan : public GenericMan {
public:
	// Add animation during reading a file, eg. adding animation during loading skeleton file
	static void Add(Animation* genericObject);
	static void Destroy();
	static AnimationClip GetCustomClipID();
	static Animation* GetAnimation(AnimationClip clipID);

private:
	static AnimationMan* privGetInstance(void) {
		static AnimationMan gom;
		return &gom;
	}
	unsigned int customAnimationClipIndex = 0;
};
#endif