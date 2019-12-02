#include "GameObjectMan.h"
#include "GameObject.h"
#include "PCSTree.h"
#include "PCSTreeForwardIterator.h"
#include "PCSTreeReverseIterator.h"
#include "GraphicComponent_Null.h"
#include "Model.h"
#include "Shader.h"
#include "GenericMan.h"

void GameObjectMan::Initialize()
{
	GameObjectMan * man = privGetInstance();
	man->pRootTree = new PCSTree();

	// Create root gameObject
	GraphicComponent* nullGraphic = new GraphicComponent_Null();
	new GameObject(nullGraphic);

	GraphicComponent* nullGraphic2 = new GraphicComponent_Null();
	man->postUpdateBucket = new GameObject(nullGraphic2);
}

void GameObjectMan::Add(GameObject * obj)
{
	assert(obj != 0);

	GameObjectMan * man = privGetInstance();
	
	// Add through genericmanager
	((GenericMan*)man)->Add((GenericObject*)obj);

	// Add via Tree
	man->pRootTree->Insert(obj, man->pRootTree->GetRoot());
}

void GameObjectMan::AddBeneath(GameObject* obj, GameObject* parent)
{
	assert(obj != 0);
	assert(parent != 0);

	GameObjectMan* man = privGetInstance();

	// Add through genericmanager
	((GenericMan*)man)->Add((GenericObject*)obj);

	// Add via Tree
	man->pRootTree->Insert(obj, parent);
}

void GameObjectMan::Update(float currTime)
{
	//GameObjectMan * man = privGetInstance();

	//// Update via Tree
	//PCSTreeForwardIterator pForwardIter(man->pRootTree->GetRoot());
	//PCSNode *pNode = pForwardIter.Next();
	//GameObject *pGameObj = 0;
	//while (!(pForwardIter.CurrentItem() == man->pRootTree->GetRoot()))
	//{
	//	// forward iteraotr not working
	//	pGameObj = (GameObject *)pNode;
	//	pGameObj->update(currTime);
	//	pNode = pForwardIter.Next();
	//}

	GameObjectMan* pGOM = GameObjectMan::privGetInstance();
	assert(pGOM);

	PCSNode* pRootNode = pGOM->pRootTree->GetRoot();
	assert(pRootNode);

	PCSTreeForwardIterator pIter(pRootNode);
	
	PCSNode* pNode = pIter.First();

	GameObject* pGameObj = 0;

	while (!pIter.IsDone())
	{
		assert(pNode);
		// Update the game object
		pGameObj = (GameObject*)pNode;
		pGameObj->update(currTime);

		pNode = pIter.Next();
	}
}

void GameObjectMan::Draw()
{
	GameObjectMan* pGOM = GameObjectMan::privGetInstance();
	assert(pGOM);

	PCSNode* pRootNode = pGOM->pRootTree->GetRoot();
	assert(pRootNode);

	PCSTreeForwardIterator pForwardIter(pRootNode);
	PCSNode* pNode = pForwardIter.First();

	GameObject* pGameObj = 0;

	while (!pForwardIter.IsDone())
	{
		assert(pNode);
		// Update the game object
		pGameObj = (GameObject*)pNode;

		pGameObj->draw();

		pNode = pForwardIter.Next();
	}
}

void GameObjectMan::Destroy()
{
	GameObjectMan* man = privGetInstance();
	GenericMan* genericMan = man;

	// Delete genericmanager linkers
	genericMan->Destroy();

	// Delete Tree
	delete man->pRootTree;
}

// Get gameobject via genericmanager ID
GameObject* GameObjectMan::GetGameObject(uint32_t genericObjectID)
{
	return (GameObject*)privGetInstance()->GetGenericObject(genericObjectID);
}

GameObject* GameObjectMan::GetPostUpdateRoot()
{
	GameObjectMan* man = privGetInstance();
	return man->postUpdateBucket;
}
