#include "GraphicComponent_Null.h"
#include "model.h"
#include "shader.h"
#include "modelMan.h"
#include "shaderMan.h"
#include "ModelNull.h"

GraphicComponent_Null::GraphicComponent_Null() :GraphicComponent(new ModelNull(),nullptr)
{

}

void GraphicComponent_Null::SetState()
{

}

void GraphicComponent_Null::SetRenderParameter()
{

}

void GraphicComponent_Null::Draw()
{
	
}

void GraphicComponent_Null::RestoreState()
{

}

GraphicComponent_Null::~GraphicComponent_Null()
{
}
