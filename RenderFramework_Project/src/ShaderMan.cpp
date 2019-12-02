#include "ShaderMan.h"

void ShaderMan::Add(Shader* genericObject)
{
	GenericMan* genericMan = privGetInstance();
	genericMan->Add((GenericObject*)genericObject);
}

void ShaderMan::Destroy()
{
	GenericMan* genericMan = privGetInstance();
	genericMan->Destroy();
}

Shader* ShaderMan::GetShader(ShaderType shader)
{
	GenericMan* genericMan = privGetInstance();
	return (Shader*)genericMan->GetGenericObject((uint32_t)shader);
}
