#include "GraphicComponent_VertexLitNew.h"
#include "Model.h"
#include "TextureMan.h"
#include "Shader.h"
#include "ShaderMan.h"
#include "ModelMan.h"
#include "CameraMan.h"
GraphicComponent_VertexLitNew::GraphicComponent_VertexLitNew(PRIMITIVE _modelType, TextureName _texture):GraphicComponent(ModelMan::GetModel(_modelType),ShaderMan::GetShader(ShaderType::VertexLit)), textName(_texture)
{
	if (this->textName == TextureName::CustomTexture) {
		this->textName = this->modelTemplate->GetDefaultTexture();
	}
	TextureMan::refer(this->textName, true);
}

GraphicComponent_VertexLitNew::~GraphicComponent_VertexLitNew()
{
	TextureMan::refer(this->textName, false);
}

void GraphicComponent_VertexLitNew::SetState()
{
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);

	GLuint textureID = TextureMan::find(this->textName);
	glBindTexture(GL_TEXTURE_2D, textureID);

}

void GraphicComponent_VertexLitNew::SetRenderParameter()
{
	//Use model
	glBindVertexArray(modelTemplate->vao);

	//Use shader
	glUseProgram(shader->GetProgram());
	Matrix world = *this->worldMatrix;
	Matrix view = CameraMan::GetActiveCamWorldMatrix();
	Matrix proj = CameraMan::GetActiveCamProjectMatrix();

	//Matrix lightWorld = Matrix(Matrix::Trans, Vect(0.0f, 0.0f, 100.0f, 0.0f));

	glUniformMatrix4fv(this->shader->GetLocation("proj_matrix"), 1, GL_FALSE, (float*)& proj);
	glUniformMatrix4fv(this->shader->GetLocation("view_matrix"), 1, GL_FALSE, (float*)& view);
	glUniformMatrix4fv(this->shader->GetLocation("world_matrix"), 1, GL_FALSE, (float*)& world);

	Vect lightPos(0.0f, 0.0f, 0.0f, 0.0f);
	Vect lightColor(0.0f, 0.0f, 0.0f, 0.0f);
	glUniform3fv(this->shader->GetLocation("vLightPos"), 1, (float*)& lightPos);
	glUniform4fv(this->shader->GetLocation("vColor"), 1, (float*)& lightColor);
}

void GraphicComponent_VertexLitNew::Draw()
{
	glDrawElements(GL_TRIANGLES, (GLsizei)(3 * this->modelTemplate->numTris), GL_UNSIGNED_INT, 0);
}

void GraphicComponent_VertexLitNew::RestoreState()
{
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
}