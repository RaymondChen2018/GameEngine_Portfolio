#ifndef GRAPHIC_COMPONENT_WIREFRAMENEW_H
#define GRAPHIC_COMPONENT_WIREFRAMENEW_H
#include "GraphicComponent.h"
class Model;
class Shader;
class GameObject;
class Vect;
enum PRIMITIVE:uint32_t;
enum ShaderType :uint32_t;
class GraphicComponent_WireframeNew : public GraphicComponent {
public:
	GraphicComponent_WireframeNew(PRIMITIVE _modelType, ShaderType _shaderType, const Vect* color = nullptr);
	~GraphicComponent_WireframeNew() override;
	void SetColor(const Vect* newColor);

protected:
	void SetState() override;
	void SetRenderParameter() override;
	void Draw() override;
	void RestoreState() override;

private:
	Vect* color;
};

#endif