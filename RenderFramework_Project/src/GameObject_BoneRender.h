#ifndef GameObject_BoneRender_H
#define GameObject_BoneRender_H

#include "MathEngine.h"
#include "GameObject.h"
class GraphicComponent;
class GameObject_BoneRender : public GameObject
{
public:
	GameObject_BoneRender(float r, float g, float b);
	virtual ~GameObject_BoneRender();

	virtual void privComposeMatrix() override;
	void SetColor(const Vect* newColor);
	void SetFromMatrix(const Matrix* _matrix);
	void SetToMatrix(const Matrix* _matrix);

private:
	Matrix* fromMatrix;
	Matrix* toMatrix;
};


#endif

//--- End of File ------------------------------------------------------------
