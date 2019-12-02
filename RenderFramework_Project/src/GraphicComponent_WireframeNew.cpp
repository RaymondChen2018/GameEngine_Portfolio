#include "GraphicComponent_WireframeNew.h"
#include "model.h"
#include "shader.h"
#include "modelMan.h"
#include "shaderMan.h"
#include "CameraMan.h"
GraphicComponent_WireframeNew::GraphicComponent_WireframeNew(PRIMITIVE _modelType, ShaderType _shaderType, const Vect* _color) :GraphicComponent(ModelMan::GetModel(_modelType), ShaderMan::GetShader(_shaderType)), color((Vect*)_color)
{
	
}

GraphicComponent_WireframeNew::~GraphicComponent_WireframeNew()
{
	delete this->color;
}

void GraphicComponent_WireframeNew::SetColor(const Vect* newColor)
{
	*this->color = *newColor;
}

void GraphicComponent_WireframeNew::SetState()
{
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDisable(GL_CULL_FACE);
}

void GraphicComponent_WireframeNew::SetRenderParameter()
{
	//Use model
	glBindVertexArray(modelTemplate->vao);

	//Use shader
	/*Matrix proj = CameraMan::GetActiveCamProjectMatrix();
	Matrix mv = (*this->worldMatrix) * CameraMan::GetActiveCamWorldMatrix();
	glUseProgram(shader->GetProgram());
	glUniformMatrix4fv(shader->GetLocation("proj_matrix"), 1, GL_FALSE, (float*)& proj);
	glUniformMatrix4fv(shader->GetLocation("mv_matrix"), 1, GL_FALSE, (float*)& mv);*/

	glUseProgram(shader->GetProgram());
	Matrix world = *this->worldMatrix;
	Matrix view = CameraMan::GetActiveCamWorldMatrix();
	Matrix proj = CameraMan::GetActiveCamProjectMatrix();

	glUniformMatrix4fv(this->shader->GetLocation("proj_matrix"), 1, GL_FALSE, (float*)& proj);
	glUniformMatrix4fv(this->shader->GetLocation("view_matrix"), 1, GL_FALSE, (float*)& view);
	glUniformMatrix4fv(this->shader->GetLocation("world_matrix"), 1, GL_FALSE, (float*)& world);

	// If color exist
	if (this->color != nullptr) {
		glUniform4fv(this->shader->GetLocation("wire_color"), 1, (float*)this->color);
	}
}

void GraphicComponent_WireframeNew::Draw()
{
	glDrawElements(GL_TRIANGLES, (GLsizei)(3 * this->modelTemplate->numTris), GL_UNSIGNED_INT, 0);
}

void GraphicComponent_WireframeNew::RestoreState()
{
	// Restore state
	glEnable(GL_CULL_FACE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}


