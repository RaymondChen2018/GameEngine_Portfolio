#ifndef EAT_H
#define EAT_H

#include "ChunkHeader.h"
struct ModelHeader;
bool eat(const char * const packageFileName,
		 ChunkType type,
		 const char * const chunkName,
		 unsigned char *&chunkBuff,
		 unsigned int &chunkSize);
bool eat(const char* const packageFileName,
	ChunkType type,
	const char* const chunkName,
	unsigned char*& chunkBuff,
	unsigned int& chunkSize,
	char *& chunkname);
bool GetModelInfo(const char* const inFileName, ModelHeader& modelInfoOut);
#endif

// End of File
