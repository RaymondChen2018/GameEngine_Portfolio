#include "ActorMan.h"
#include "Actor.h"

void ActorMan::Add(Actor* genericObject)
{
	GenericMan* genericMan = privGetInstance();
	genericMan->Add((GenericObject*)genericObject);
}

void ActorMan::Update(float currentTime)
{
	GenericMan* genericMan = privGetInstance();
	genericMan->GLinkUpdate(currentTime);
}

void ActorMan::Destroy()
{
	GenericMan* genericMan = privGetInstance();
	genericMan->Destroy();
}

