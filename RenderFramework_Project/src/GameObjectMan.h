#ifndef GAMEOBJECT_MAN_H
#define GAMEOBJECT_MAN_H
#include "GenericMan.h"
class GameObject;
class PCSTree;
class GameObjectMan : public GenericMan {
public:
	static void Initialize();
	static void Add(GameObject * obj);
	static void AddBeneath(GameObject* obj, GameObject* parent);
	static void Update(float currTime);
	static void Draw();
	static void Destroy();

	static GameObject* GetGameObject(uint32_t genericObjectID);

	static GameObject* GetPostUpdateRoot();
private:
	class Linker {
	public:
		Linker(GameObject * _obj) {
			obj = _obj;
		}
		~Linker(){}
		GameObject * obj = nullptr;
		Linker * pNext = nullptr;
		Linker * pPrev = nullptr;
	};

	static GameObjectMan * privGetInstance(void) {
		static GameObjectMan gom;
		return &gom;
	}

	Linker * pHead = nullptr;
	//void privAddLinker(Linker * link);

	PCSTree *pRootTree = nullptr;
	GameObject* postUpdateBucket;
};

#endif