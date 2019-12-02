#include "GraphicComponent.h"
#include "MathEngine.h"
#include "Model.h"
#include "Shader.h"
#include "Game.h"
#include "Camera.h"
#include "CameraMan.h"
#include "BoundingSphere.h"

extern Game *pGame;
GraphicComponent::GraphicComponent(Model * _model, Shader * _shader)
{
	shader = _shader;
	modelTemplate = _model;
	worldMatrix = new Matrix(Matrix::Special::Identity);
	this->pCurrSphere = new BSphere();
}

GraphicComponent::~GraphicComponent()
{
	delete worldMatrix;
	delete this->pCurrSphere;
}

void GraphicComponent::Render()
{
	SetState();
	SetRenderParameter();
	Draw();
	RestoreState();
}

//void GraphicComponent::SetState()
//{
//	glEnable(GL_CULL_FACE);
//	glFrontFace(GL_CW);
//}
//
//void GraphicComponent::SetRenderParameter()
//{
//	//Use model
//	glBindVertexArray(modelTemplate->vao);
//
//	//Use shader
//	Matrix mv = (*worldMatrix) * CameraMan::GetActiveCam();
//	glUseProgram(shader->GetProgram());
//	glUniformMatrix4fv(shader->GetProj(), 1, GL_FALSE, (float *)pGame->poProjMatrix);
//	glUniformMatrix4fv(shader->GetMv(), 1, GL_FALSE, (float *)&mv);
//}
//
//void GraphicComponent::Draw()
//{
//	glDrawArrays(GL_TRIANGLES, 0, (3 * modelTemplate->numVerts));
//}
//
//void GraphicComponent::RestoreState()
//{
//	glEnable(GL_CULL_FACE);
//	glFrontFace(GL_CW);
//}
void GraphicComponent::SetWorld(Matrix *world)
{
	assert(world);
	*worldMatrix = *world;
}
