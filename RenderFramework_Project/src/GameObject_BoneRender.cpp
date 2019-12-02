#include "Framework.h"
#include "GameObject_BoneRender.h"
#include "Model.h"
#include "Shader.h"
#include "GraphicComponent_WireframeNew.h"
#include "GameObject_DebugBSphere.h"
#include "GameObject.h"
#include "GameObjectMan.h"
#include "MathEngine.h"

GameObject_BoneRender::GameObject_BoneRender(float r, float g, float b)
	: GameObject(new GraphicComponent_WireframeNew(PRIMITIVE::Pyramid, ShaderType::SolidColor, new Vect(r, g, b, 1.0f)), GameObjectMan::GetPostUpdateRoot())
{
	GameObject_DebugBSphere* pZ = new GameObject_DebugBSphere(1.0f, 0.0f, 0.0f);
	pZ->SetBoundingSphereReference(this);
	this->fromMatrix = new Matrix(Matrix::Special::Identity);
	this->toMatrix = new Matrix(Matrix::Special::Identity);
}

GameObject_BoneRender::~GameObject_BoneRender()
{
	delete this->fromMatrix;
	delete this->toMatrix;
}

void GameObject_BoneRender::privComposeMatrix()
{
	Vect worldOrigin(0.0f, 0.0f, 0.0f);

	Vect ptA = worldOrigin * *fromMatrix;
	Vect ptB = worldOrigin * *toMatrix;

	// direction between the anchor points of the respective bones
	Vect dir = (ptB - ptA);

	// length of the bone
	float mag = dir.mag();

	// Tries to do orientation with the bone, but without custom rotation, the bone always stayed 90 degree off.

	Matrix S(Matrix::Scale::XYZ, 5.0f, mag, 5.0f);
	Quat Q(Quat::Orient::LocalToWorld, dir.getNorm(), Vect(0.0f, 1.0f, 0.0f));
	Quat AlignWithWorld(Quat::Orient::WorldToLocal, *this->defaultDof, *this->defaultUp);
	Matrix T(Matrix::Trans::XYZ, ptA);

	*this->worldMatrix = S * AlignWithWorld * Q * T;
}

void GameObject_BoneRender::SetColor(const Vect* newColor)
{
	((GraphicComponent_WireframeNew*)this->graphicComponent)->SetColor(newColor);
}

void GameObject_BoneRender::SetFromMatrix(const Matrix* _matrix)
{
	*(this->fromMatrix) = *_matrix;
}

void GameObject_BoneRender::SetToMatrix(const Matrix* _matrix)
{
	*(this->toMatrix) = *_matrix;
}

// End of File

