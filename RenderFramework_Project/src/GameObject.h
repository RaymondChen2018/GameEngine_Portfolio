//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
//----------------------------------------------------------------------------

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "MathEngine.h"
#include "PCSNode.h"
#include "GenericObject.h"
class Shader;
class GraphicComponent;
class Model;
enum PRIMITIVE:uint32_t;
enum ShaderType :uint32_t;
enum RenderMode:int;
enum class TextureName:int;
class BSphere;
class GameObject : public PCSNode, public GenericObject
{
public:
	GameObject(GraphicComponent* _graphicComponent, uint32_t gameObjectID = -1);
	GameObject(GraphicComponent* _graphicComponent, GameObject* parent, uint32_t gameObjectID = -1);
	~GameObject();

	virtual void update(float t);
	virtual void draw();
	void SetWorldMatrix(Matrix *world);
	const Matrix* GetWorldMatrix();
	//Matrix GetLookAtMatrix(float length);
	const Vect* GetRotationVector();
	const Vect* GetUpVector() { return this->defaultUp; }

	void SetScale(const Vect& _scale);
	void SetScale(float _x, float _y, float _z);
	void SetPosition(const Vect& _pos);
	void SetPosition(float _x, float _y, float _z);
	void SetRotation(const Vect& _rot);
	void SetRotation(float _x, float _y, float _z);

	void SetDefaultOrientation(const Vect* _dof, const Vect* _up);
	void SetDefaultScale(const Vect* _scale);

	GraphicComponent* GetGraphicsObject();
	BSphere GetBSphere();

	int pad;
	int pad2;
protected:
	virtual void privComposeMatrix();

	// Orientation
	Vect* defaultDof;
	Vect* defaultUp;
	Vect* defaultScale;

private:
	void privInitialize();
	void privComposeBSphereMatrix();
	
	// World properties
	Vect* scaleVect;
	Vect* transVect;
	Vect* rotVect;
	
	//float rotationX, rotationY, rotationZ;
	//const BSphere* boundingSphereRef;
	GameObject* parent = nullptr;
	
protected:
	Matrix* worldMatrix;
	GraphicComponent * graphicComponent = nullptr;
	
private:
	BSphere* bSphere;

};

#endif

//--- End of File ------------
