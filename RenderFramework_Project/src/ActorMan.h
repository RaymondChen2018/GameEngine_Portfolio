#ifndef ACTOR_MAN_H
#define ACTOR_MAN_H
#include "GenericMan.h"
class Actor;
enum ActorRig :uint32_t;
class ActorMan : public GenericMan {
public:
	static void Add(Actor* genericObject);
	static void Update(float currentTime);
	static void Destroy();

private:
	static ActorMan* privGetInstance(void) {
		static ActorMan gom;
		return &gom;
	}
};

#endif