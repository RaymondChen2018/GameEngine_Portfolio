#ifndef MODEL_MAN_H
#define MODEL_MAN_H
#include "GenericMan.h"
class Model;
enum PRIMITIVE:uint32_t;
class ModelMan : public GenericMan {
public:
	static void Add(Model* genericObject);
	static void Destroy();
	static Model* GetModel(PRIMITIVE shader);
private:
	static ModelMan* privGetInstance(void) {
		static ModelMan gom;
		return &gom;
	}


};

#endif