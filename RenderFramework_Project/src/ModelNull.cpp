#include "ModelNull.h"
#include "TextureNode.h"
#include "Model.h"
#include "BoundingSphere.h"

ModelNull::ModelNull():Model()
{
	this->type = PRIMITIVE::NullModel;
	this->numVerts = 0;
	this->numTris = 0;
}

ModelNull::~ModelNull()
{

}

//void ModelNull::GetBoundSphere(BSphere& bSphereOut)
//{
//	bSphereOut.cntr.set(0.0f, 0.0f, 0.0f);
//	bSphereOut.rad = 1.0f;
//}
