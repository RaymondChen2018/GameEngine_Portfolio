#ifndef GRAPHIC_COMPONENT_NULL_H
#define GRAPHIC_COMPONENT_NULL_H
#include "GraphicComponent.h"
class Model;
class Shader;
class Matrix;
class GameObject;
class GraphicComponent_Null : public GraphicComponent {
public:
	GraphicComponent_Null();
	~GraphicComponent_Null() override;

private:
	void SetState()			 override;
	void SetRenderParameter()	 override;
	void Draw()			 override;
	void RestoreState()		 override;
};

#endif