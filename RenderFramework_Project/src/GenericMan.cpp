#include "GenericMan.h"
#include "Shader.h"
#include "GenericObject.h"
void GenericMan::Add(GenericObject* genericObject)
{
	/*GenericMan * man = _privGetInstance();*/
	Linker * link = new Linker(genericObject);
	this->privAddLinker(link);
}

void GenericMan::GLinkUpdate(float currentTime)
{
	Linker* pTmp = this->pHead;
	while (pTmp != nullptr) {
		pTmp->obj->GLinkUpdate(currentTime);
		pTmp = pTmp->pNext;
	}
}

void GenericMan::Destroy()
{
	Linker * pTmp = this->pHead;
	Linker * pDead = nullptr;
	while (pTmp != nullptr) {
		pDead = pTmp;
		pTmp = pTmp->pNext;

		delete pDead->obj;
		delete pDead;
	}
	this->pHead = nullptr;
}

void GenericMan::DestroyGenericLinkers()
{
	Linker* pTmp = this->pHead;
	Linker* pDead = nullptr;
	while (pTmp != nullptr) {
		pDead = pTmp;
		pTmp = pTmp->pNext;

		delete pDead;
	}
	this->pHead = nullptr;
}

GenericObject* GenericMan::GetGenericObject(uint32_t genericObject)
{
	Linker * pRet = this->pHead;
	while (pRet != nullptr) {
		if (pRet->obj->getGenericType() == genericObject) {
			break;
		}
		pRet = pRet->pNext;
	}
	assert("Object not found" && pRet);
	return pRet->obj;
}

//// Return nullptr if not found
//GenericObject* GenericMan::GetGenericObject(const char* objectName)
//{
//	Linker* pRet = this->pHead;
//	while (pRet != nullptr) {
//		if (pRet->obj->getGenericName() != nullptr && strcmp(pRet->obj->getGenericName(), objectName) == 0) {
//			break;
//		}
//		pRet = pRet->pNext;
//	}
//	//assert(("Object not found", pRet));
//
//	if (pRet == nullptr) {
//		return nullptr;
//	}
//	return pRet->obj;
//}

void GenericMan::privAddLinker(Linker * link)
{
	if (pHead == nullptr) {
		pHead = link;
		pHead->pNext = nullptr;
		pHead->pPrev = nullptr;
	}
	else {
		link->pPrev = nullptr;
		link->pNext = pHead;
		pHead->pPrev = link;
		pHead = link;
	}
}
