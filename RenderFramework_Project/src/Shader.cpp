#include "Shader.h"
#include "ShaderMan.h"
#include "File.h"
#include "StringOperation.h"

Shader::Shader(const char * fs_script[], const char * vs_script[])
{
	program = glCreateProgram();
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, fs_script, NULL);
	glCompileShader(fs);

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, vs_script, NULL);
	glCompileShader(vs);

	glAttachShader(program, vs);
	glAttachShader(program, fs);

	glLinkProgram(program);

	ShaderMan::Add(this);
}


Shader::Shader(ShaderType _type, const char* const shaderFileName)//const char * fs_script[], const char * vs_script[])
{
	// Read shader files
	this->type = _type;
	File::Handle fh;
	File::Error  ferror;
	const char* const postFix_fs = ".fs.glsl";
	const char* const postFix_vs = ".vs.glsl";

	/*char* fileName_fs = new char[std::strlen(shaderFileName) + std::strlen(postFix_vs) + 1];
	std::strcpy(fileName_fs, shaderFileName);
	std::strcat(fileName_fs, postFix_fs);*/

	char* fileName_fs = AddString(shaderFileName, postFix_fs);

	ferror = File::Open(fh, fileName_fs, File::Mode::READ);
	assert(ferror == File::Error::SUCCESS);
	delete fileName_fs;
	ferror = File::Seek(fh, File::Location::END, 0);
	assert(ferror == File::Error::SUCCESS);
	DWORD numBytesInFile;
	ferror = File::Tell(fh, numBytesInFile);
	assert(ferror == File::Error::SUCCESS);
	ferror = File::Seek(fh, File::Location::BEGIN, 0);
	assert(ferror == File::Error::SUCCESS);
	char* fs_script = new char[numBytesInFile + 1];
	assert(fs_script != 0);
	ferror = File::Read(fh, fs_script, numBytesInFile);
	assert(ferror == File::Error::SUCCESS);
	// null termination character
	fs_script[numBytesInFile] = 0;
	ferror = File::Close(fh);
	assert(ferror == File::Error::SUCCESS);

	/*char* fileName_vs = new char[std::strlen(shaderFileName) + std::strlen(postFix_vs) + 1];
	std::strcpy(fileName_vs, shaderFileName);
	std::strcat(fileName_vs, postFix_vs);*/
	char* fileName_vs = AddString(shaderFileName, postFix_vs);

	ferror = File::Open(fh, fileName_vs, File::Mode::READ);
	assert(ferror == File::Error::SUCCESS);
	delete[] fileName_vs;
	ferror = File::Seek(fh, File::Location::END, 0);
	assert(ferror == File::Error::SUCCESS);
	ferror = File::Tell(fh, numBytesInFile);
	assert(ferror == File::Error::SUCCESS);
	ferror = File::Seek(fh, File::Location::BEGIN, 0);
	assert(ferror == File::Error::SUCCESS);
	char* vs_script = new char[numBytesInFile + 1];
	assert(vs_script != 0);
	ferror = File::Read(fh, vs_script, numBytesInFile);
	assert(ferror == File::Error::SUCCESS);
	// null termination character
	vs_script[numBytesInFile] = 0;
	ferror = File::Close(fh);
	assert(ferror == File::Error::SUCCESS);



	// Compile shaders
	GLuint fs;
	fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fs_script, NULL);
	glCompileShader(fs);

	GLuint vs;
	vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vs_script, NULL);
	glCompileShader(vs);

	// Create empty program
	this->program = glCreateProgram();

	// Attach shaders
	glAttachShader(program, vs);
	glAttachShader(program, fs);

	glLinkProgram(program);

	delete fs_script;
	delete vs_script;

	ShaderMan::Add(this);
}

GLint Shader::GetLocation(const char* const pUniformName) const
{
	assert(pUniformName);
	GLint loc = glGetUniformLocation(this->program, pUniformName);
	assert(loc != -1);

	return loc;
}
