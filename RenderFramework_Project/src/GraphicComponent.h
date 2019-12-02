#ifndef GRAPHIC_COMPONENT_H
#define GRAPHIC_COMPONENT_H

class Model;
class Shader;
class Matrix;
class GameObject;
class GameObject_DebugBSphere;
class BSphere;

enum RenderMode {
	Normal,
	WireFrame,
	TextureUnlit,
};
class GraphicComponent 
{
public:
	GraphicComponent(Model * _model, Shader * _shader);
	virtual ~GraphicComponent();
	void Render();
	
protected:
	virtual void SetState() = 0;
	virtual void SetRenderParameter() = 0;
	virtual void Draw() = 0;
	virtual void RestoreState() = 0;

	Matrix* worldMatrix = nullptr;
	Model* modelTemplate = nullptr;
	Shader* shader = nullptr;
	Matrix* poProjMatrix = nullptr;
private:
	friend GameObject;
	friend GameObject_DebugBSphere;
	void SetWorld(Matrix *world);

	BSphere* pCurrSphere;
};

#endif