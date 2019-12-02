//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
//----------------------------------------------------------------------------

#ifndef TEXTURE_NODE_H
#define TEXTURE_NODE_H

#include "sb7.h"

#define TEXTURE_ASSET_NAME_SIZE 64

enum class TextureName
{
	STONES,
	RED_BRICK,
	DUCKWEED,
	ROCKS,
	SPACE_FRIGATE,
	CrashBandicoo,
	NOT_INITIALIZED,
	CustomTexture
};

class TextureNodeLink
{
public:
	TextureNodeLink()
	{
		this->next = 0;
		this->prev = 0;
	}

	virtual ~TextureNodeLink() = default;

	TextureNodeLink *next;
	TextureNodeLink *prev;
	
};

class TextureNode: public TextureNodeLink
{
public:
	TextureNode();
	~TextureNode() override;

	void set( const char * const _assetName, 
				TextureName _name, 
				GLuint _TextureID, 
				GLenum minFilter, 
				GLenum magFilter, 
				GLenum wrapMode);

private:
	char assetName[TEXTURE_ASSET_NAME_SIZE];

public:
	TextureName name;
	GLuint textureID;
	GLenum minFilter;
	GLenum magFilter;
	GLenum wrapMode;

	int refCount = 0;
};

#endif

// --- End of File --------------------------------------------------
