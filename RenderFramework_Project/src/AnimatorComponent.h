#ifndef ANIMATOR_COMPONENT
#define ANIMATOR_COMPONENT

enum AnimationClip : uint32_t;
class Animation;
class Vect;
class Quat;
class AnimatorComponent {
public:
	AnimatorComponent(AnimationClip clip);
	void AnimTimeUpdate(float currentTime);
	void GetFrameData(unsigned int id, float globalTime, Vect& position, Quat& orientation, Vect& scale);
	void SetAnimation(AnimationClip clip);
	void SetSpeedMultiplier(float _speed) { this->speedModifier = _speed; };
	void SetFrame(float _frameOffset) { this->frameOffset = _frameOffset;};

private:
	float privGlobalTime;
	float prevGlobalTime;
	float frameOffset;
	float speedModifier;
	Animation* animationReference;
};
#endif