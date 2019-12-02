#ifndef GRAPHIC_COMPONENT_TEXTUREUNLITNEW_H
#define GRAPHIC_COMPONENT_TEXTUREUNLITNEW_H
#include "GraphicComponent.h"

class Model;
class Shader;
class GameObject;
enum PRIMITIVE :uint32_t;
enum class TextureName;
class GraphicComponent_TextureUnlitNew : public GraphicComponent {
public:
	GraphicComponent_TextureUnlitNew(PRIMITIVE _modelType, TextureName _texture);
	~GraphicComponent_TextureUnlitNew() override;

	void SetTexture(TextureName _texture) { textName = _texture; }

protected:
	void SetState() override;
	void SetRenderParameter() override;
	void Draw() override;
	void RestoreState() override;
private:
	TextureName textName;
};

#endif