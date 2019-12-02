#ifndef SHADER_MAN_H
#define SHADER_MAN_H
#include "GenericMan.h"
class Shader;
enum ShaderType :uint32_t;
class ShaderMan : public GenericMan {
public:
	static void Add(Shader* genericObject);
	static void Destroy();
	static Shader* GetShader(ShaderType shader);
private:
	static ShaderMan* privGetInstance(void) {
		static ShaderMan gom;
		return &gom;
	}
};

#endif