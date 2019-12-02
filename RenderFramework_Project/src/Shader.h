#ifndef SHADER_H
#define SHADER_H
#include <sb7.h>
#include "GenericObject.h"
enum ShaderType :uint32_t {
	NullShader,
	ColorPosition,
	ColorPositionNew,
	SolidColor,
	UnlitGeneric,
	UnlitGenericNew,
	VertexLit
};
class Shader : GenericObject {
public:
	Shader(const char * fs_script[], const char * vs_script[]);
	Shader(ShaderType _type, const char* const shaderFileName);

	virtual ~Shader() {};

	GLuint GetProgram() { return program; }

	ShaderType getShaderType() { return (ShaderType)type; }
	GLint GetLocation(const char* const pUniformName) const;

private:
	//ShaderType shaderType;

	GLuint program;

	GLint Matrix_proj;
	GLint Matrix_mv;
};

#endif