#include "AnimationMan.h"
#include "Animation.h"

AnimationClip AnimationMan::GetCustomClipID()
{
	AnimationMan* man = privGetInstance();
	AnimationClip ret = (AnimationClip)(AnimationClip::CustomClip + (AnimationClip)man->customAnimationClipIndex);
	man->customAnimationClipIndex++;
	return ret;
}

Animation* AnimationMan::GetAnimation(AnimationClip clipID)
{
	AnimationMan* man = privGetInstance();
	return (Animation*)(man->GetGenericObject(clipID));
}

void AnimationMan::Add(Animation* genericObject)
{
	GenericMan* genericMan = privGetInstance();
	genericMan->Add((GenericObject*)genericObject);
}

void AnimationMan::Destroy()
{
	GenericMan* genericMan = privGetInstance();
	genericMan->Destroy();
}
