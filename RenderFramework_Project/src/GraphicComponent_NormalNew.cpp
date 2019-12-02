#include "GraphicComponent_NormalNew.h"
#include "model.h"
#include "shader.h"
#include "modelMan.h"
#include "shaderMan.h"
#include "CameraMan.h"
GraphicComponent_NormalNew::GraphicComponent_NormalNew(PRIMITIVE _modelType, ShaderType _shaderType):GraphicComponent(ModelMan::GetModel(_modelType),ShaderMan::GetShader(_shaderType))
{

}

void GraphicComponent_NormalNew::SetState()
{
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
}

void GraphicComponent_NormalNew::SetRenderParameter()
{
	//Use model
	glBindVertexArray(modelTemplate->vao);

	//Use shader
	/*Matrix proj = CameraMan::GetActiveCamProjectMatrix();
	Matrix mv = (*this->worldMatrix) * CameraMan::GetActiveCamWorldMatrix();
	glUseProgram(shader->GetProgram());
	glUniformMatrix4fv(shader->GetLocation("proj_matrix"), 1, GL_FALSE, (float *)&proj);
	glUniformMatrix4fv(shader->GetLocation("mv_matrix"), 1, GL_FALSE, (float *)&mv);*/

	glUseProgram(shader->GetProgram());
	Matrix world = *this->worldMatrix;
	Matrix view = CameraMan::GetActiveCamWorldMatrix();
	Matrix proj = CameraMan::GetActiveCamProjectMatrix();

	glUniformMatrix4fv(this->shader->GetLocation("proj_matrix"), 1, GL_FALSE, (float*)& proj);
	glUniformMatrix4fv(this->shader->GetLocation("view_matrix"), 1, GL_FALSE, (float*)& view);
	glUniformMatrix4fv(this->shader->GetLocation("world_matrix"), 1, GL_FALSE, (float*)& world);
}

void GraphicComponent_NormalNew::Draw()
{
	glDrawElements(GL_TRIANGLES, (GLsizei)(3 * this->modelTemplate->numTris), GL_UNSIGNED_INT, 0);
}

void GraphicComponent_NormalNew::RestoreState()
{
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
}



GraphicComponent_NormalNew::~GraphicComponent_NormalNew()
{

}


