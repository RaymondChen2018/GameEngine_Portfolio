#include "GraphicComponent_TextureUnlitNew.h"
#include "Model.h"
#include "TextureMan.h"
#include "Shader.h"
#include "ShaderMan.h"
#include "ModelMan.h"
#include "CameraMan.h"
GraphicComponent_TextureUnlitNew::GraphicComponent_TextureUnlitNew(PRIMITIVE _modelType, TextureName _texture):GraphicComponent(ModelMan::GetModel(_modelType),ShaderMan::GetShader(ShaderType::UnlitGenericNew)), textName(_texture)
{
	if (this->textName == TextureName::CustomTexture) {
		this->textName = this->modelTemplate->GetDefaultTexture();
	}
	TextureMan::refer(this->textName, true);
}

GraphicComponent_TextureUnlitNew::~GraphicComponent_TextureUnlitNew()
{
	TextureMan::refer(this->textName, false);
}

void GraphicComponent_TextureUnlitNew::SetState()
{
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);

	GLuint textureID = TextureMan::find(this->textName);
	glBindTexture(GL_TEXTURE_2D, textureID);

}

void GraphicComponent_TextureUnlitNew::SetRenderParameter()
{
	//Use model
	glBindVertexArray(modelTemplate->vao);

	//Use shader
	glUseProgram(shader->GetProgram());
	Matrix world = *this->worldMatrix;
	Matrix view = CameraMan::GetActiveCamWorldMatrix();
	Matrix proj = CameraMan::GetActiveCamProjectMatrix();

	glUniformMatrix4fv(this->shader->GetLocation("proj_matrix"), 1, GL_FALSE, (float*)& proj);
	glUniformMatrix4fv(this->shader->GetLocation("view_matrix"), 1, GL_FALSE, (float*)& view);
	glUniformMatrix4fv(this->shader->GetLocation("world_matrix"), 1, GL_FALSE, (float*)& world);
}

void GraphicComponent_TextureUnlitNew::Draw()
{
	glDrawElements(GL_TRIANGLES, (GLsizei)(3 * this->modelTemplate->numTris), GL_UNSIGNED_INT, 0);
}

void GraphicComponent_TextureUnlitNew::RestoreState()
{
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
}