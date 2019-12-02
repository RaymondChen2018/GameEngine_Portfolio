#ifndef GAMEOBJECT_DEBUGBSPHERE_H
#define GAMEOBJECT_DEBUGBSPHERE_H

#include "MathEngine.h"
#include "GameObject.h"
class GraphicComponent;
class GameObject_DebugBSphere : public GameObject
{
public:
	GameObject_DebugBSphere(float r, float g, float b);

	// Big four
	GameObject_DebugBSphere() = delete;
	GameObject_DebugBSphere(const GameObject_DebugBSphere&) = delete;
	GameObject_DebugBSphere& operator=(GameObject_DebugBSphere&) = delete;
	virtual ~GameObject_DebugBSphere();

	void SetBoundingSphereReference(GameObject* pGameObj);

	virtual void update(float t) override;
	virtual void draw() override;

private:
	void privComposeMatrix();
	void privUpdateBoundingSphereReference();

	// Data: ------------------
	GameObject* pRefGameObj;

public:
	Vect* pScale;
	Vect* pTrans;
};


#endif

//--- End of File ------------------------------------------------------------
