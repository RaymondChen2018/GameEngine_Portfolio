//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#ifndef MODEL_HEADER_H
#define MODEL_HEADER_H

struct ModelHeader
{
	ModelHeader()
	{
		memset(this, 0x0, sizeof(ModelHeader));
	}

	// Model attributes
	static const unsigned int MODEL_VERSION_SIZE = 20;
	static const unsigned int MODEL_NAME_SIZE = 20;
	char	modelName[MODEL_NAME_SIZE];
	unsigned int numVerts;
	unsigned int numTriList;
	float originX;
	float originY;
	float centerX;
	float centerY;
	float maxX;
	float maxY;
	float boundingSphereRadius;

	// Number of animation clips
	int numAnimationClips;

	// Package attributes
	char	versionString[MODEL_VERSION_SIZE];
	unsigned int	numChunks;
	unsigned int	totalSize;   // size of file (without package header)

};

#endif

// End of File
