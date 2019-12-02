#include "Framework.h"
#include "GameObject_Simple.h"
#include "Model.h"
#include "Shader.h"
#include "GameObject_DebugBSphere.h"

GameObject_Simple::GameObject_Simple(GraphicComponent* pGraphicsObject, uint32_t gameObjectID)
	: GameObject(pGraphicsObject, gameObjectID)
{
	GameObject_DebugBSphere* pZ = new GameObject_DebugBSphere(1.0f, 0.0f, 0.0f);
	pZ->SetBoundingSphereReference(this);
}

// End of File

