#ifndef GENERIC_MAN_H
#define GENERIC_MAN_H
class GenericObject;
class GenericMan {
public:
	void Add(GenericObject* genericObject);
	void GLinkUpdate(float currentTime);
	void Destroy();

	void DestroyGenericLinkers();

	GenericObject* GetGenericObject(uint32_t genericObject);
	//GenericObject* GetGenericObject(const char* objectName);

protected:
	class Linker {
	public:
		Linker(GenericObject* _obj) {
			obj = _obj;
		}
		~Linker(){}
		GenericObject* obj = nullptr;
		Linker * pNext = nullptr;
		Linker * pPrev = nullptr;
	};

	Linker * pHead = nullptr;
	void privAddLinker(Linker * link);
};

#endif