#include "ModelMan.h"

void ModelMan::Add(Model* genericObject)
{
	GenericMan* genericMan = privGetInstance();
	genericMan->Add((GenericObject*)genericObject);
}

void ModelMan::Destroy()
{
	GenericMan* genericMan = privGetInstance();
	genericMan->Destroy();
}

Model * ModelMan::GetModel(PRIMITIVE model)
{
	GenericMan* genericMan = privGetInstance();
	return (Model*)genericMan->GetGenericObject((uint32_t)model);
}

