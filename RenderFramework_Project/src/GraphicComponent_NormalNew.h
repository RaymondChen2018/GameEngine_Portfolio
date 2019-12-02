#ifndef GRAPHIC_COMPONENT_NORMALNEW_H
#define GRAPHIC_COMPONENT_NORMALNEW_H
#include "GraphicComponent.h"
class Model;
class Shader;
class GameObject;
enum PRIMITIVE:uint32_t;
enum ShaderType :uint32_t;
class GraphicComponent_NormalNew : public GraphicComponent {
public:
	GraphicComponent_NormalNew(PRIMITIVE _modelType, ShaderType _shaderType);
	~GraphicComponent_NormalNew() override;


protected:
	void SetState() override;
	void SetRenderParameter() override;
	void Draw() override;
	void RestoreState() override;
};

#endif