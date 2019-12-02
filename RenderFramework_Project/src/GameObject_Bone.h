#ifndef GAME_OBJECT_BONE_H
#define GAME_OBJECT_BONE_H
#include "GameObject.h"

class GraphicComponent;
class GameObject_BoneRender;
enum BoneType:uint32_t {
	RootBone = 10000000U, // Bone that Actor holds on to, not animated
	AnimRootBone = 10000001U, // Bone that resides as the root of the animation, animated but not rendered to its parent
	ChildrenBone
};
class GameObject_Bone : public GameObject {
public:
	GameObject_Bone(unsigned int _boneID);
	GameObject_Bone(GameObject_Bone* parentBone, unsigned int _boneID);
	virtual ~GameObject_Bone();

	// Reason to override this because we don't want gameobject's computing matrix based on
	virtual void privComposeMatrix() override;
	void SetColor(const Vect* newColor);
	void SetAnimationMatrix(const Matrix* _matrix);
	void SetReferenceMatrix(const Matrix* _matrix);

	unsigned int GetBoneID() { return this->boneID;  }

	void SetBoneName(const char* nameCopy) {
		this->boneName = new char[strlen(nameCopy) + 1];
		memcpy(this->boneName, nameCopy, strlen(nameCopy) + 1);
	}
	const char* GetBoneName() {
		return this->boneName;
	}

	const Matrix* GetReferenceMatrix() { return this->refLocalMatrix; }

private:
	void privInitialize();

	unsigned int boneID;
	char* boneName;
	// The delta matrix of an animation
	Matrix* animDeltaRotMatrix; 
	// T-pose reference matrix, inintial relative matrix to parent 
	Matrix* refLocalMatrix; 
	GameObject_BoneRender* renderObject;
};

#endif
