#ifndef TEXTURE_MAN_H
#define TEXTURE_MAN_H

#include "sb7.h"
#include "TextureNode.h" 

// Singleton
class TextureMan
{
public:
	static void Destroy();

	//static void TextureMan::addTexture(const char* const _assetName);
	static TextureName addTexture( const unsigned char* _assetData, const char* const _assetName);
	static void addTexture( const char * const _assetName, const TextureName _name);
	static void deleteTextures();
	static GLuint find( const TextureName _name);
	static void refer(const TextureName _name, bool refer);


private:  // methods

	static TextureMan *privGetInstance();
	TextureMan();
	
	int customTextureIndex = 0;
	// helper private methods
	void privLoadTexture( const char * const _assetName, GLuint *&textureID );
	void privLoadTexture( const unsigned char* _assetData, GLuint*& textureID);
	bool privLoadTGATexture(const char *szFileName, GLint minFilter, GLint magFilter, GLint wrapMode);
	bool privLoadBufferTexture( const unsigned char* _assetData, GLint minFilter, GLint magFilter, GLint wrapMode);
	void privAddToFront(TextureNodeLink *node, TextureNodeLink *&head);
	GLbyte *gltReadTGABits(const char *szFileName, GLint *iWidth, GLint *iHeight, GLint *iComponents, GLenum *eFormat);
	GLbyte* gltReadBufferBits(const unsigned char* _assetData, GLint* iWidth, GLint* iHeight, GLint* iComponents, GLenum* eFormat);

private:  // add

	TextureNodeLink *active;

};

#endif

// --- End of File --------------------------------------------------
