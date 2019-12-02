#ifndef GENERIC_OBJECT_H
#define GENERIC_OBJECT_H

class GenericObject {
public:
	GenericObject() = default;
	virtual ~GenericObject() {};

	virtual void GLinkUpdate(float currentTime) { (void)currentTime; }
	uint32_t getGenericType() { return type;}


protected:
	uint32_t type;
};
#endif
