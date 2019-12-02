//-----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include <stdio.h>
#include <assert.h>
#include "eat.h"
#include "ChunkHeader.h"
#include "ModelHeader.h"
#include "File.h"
#pragma warning( disable : 5045 )
#define UNUSED_VAR(x) ((void *)x)

//---------------------------------------------------------------------------
// Leave this signature - do your EAT magic here
// Feel free to add files and methods to this project
//---------------------------------------------------------------------------
unsigned int getfilesize(const char* infile) {
	DWORD infileSize(0);
	File::Handle fh(nullptr);
	File::Open(fh, infile, File::Mode::READ);
	File::Seek(fh, File::Location::END, 0);
	File::Tell(fh, infileSize);
	File::Close(fh);
	return infileSize;
}
bool GetModelInfo(const char* const inFileName, ModelHeader& modelInfoOut) {
	bool ret = false;

	// Open file
	File::Handle FileReader(nullptr);
	File::Error err = File::Open(FileReader, inFileName, File::Mode::READ);
	assert(err == File::Error::SUCCESS);

	// Get data to buffer
	File::Read(FileReader, &modelInfoOut, sizeof(ModelHeader));
	File::Close(FileReader);
	return ret;
}
bool eat(const char * const inFileName, ChunkType extractChkType, const char * const extractChkName, unsigned char *&chunkBuff, unsigned int &chunkSize)
{
	bool ret = false;

	// Open file
	unsigned int infileSize = getfilesize(inFileName);
	File::Handle FileReader(nullptr);
	File::Error err = File::Open(FileReader, inFileName, File::Mode::READ);
	assert(err == File::Error::SUCCESS);

	// Get data to buffer
	unsigned char* dataFromFile = new unsigned char[infileSize];
	err = File::Read(FileReader, &dataFromFile[0], infileSize);
	assert(err == File::Error::SUCCESS);

	// Variables
	ModelHeader *packageHeader = (ModelHeader*)dataFromFile;
	ChunkHeader *chunkHeader = (ChunkHeader *)(dataFromFile + (unsigned int)sizeof(ModelHeader));
	unsigned int chunkIndex = 0;

	// Loop through buffer
	while (chunkIndex < packageHeader->numChunks) {

		// If found
		if (chunkHeader->type == extractChkType && strcmp(chunkHeader->chunkName, extractChkName) == 0) {

			// Copy to buffer
			chunkBuff = (unsigned char*)malloc(chunkHeader->chunkSize);
			memcpy(chunkBuff, (unsigned char*)((unsigned int)chunkHeader + (unsigned int)sizeof(ChunkHeader)), chunkHeader->chunkSize);
			chunkSize = chunkHeader->chunkSize;

			// set return to true
			ret = true;
			break;
		}
			
		// Next chunk
		chunkIndex++;
		chunkHeader = (ChunkHeader *)((unsigned int)chunkHeader + (unsigned int)sizeof(ChunkHeader) + chunkHeader->chunkSize);
	}
	
	File::Close(FileReader);
	delete[] dataFromFile;
	return ret;
}
bool eat(const char* const inFileName, ChunkType extractChkType, const char* const extractChkName, unsigned char*& chunkBuff, unsigned int& chunkSize, char*& chunkname)
{
	bool ret = false;

	// Open file
	unsigned int infileSize = getfilesize(inFileName);
	File::Handle FileReader(nullptr);
	File::Error err = File::Open(FileReader, inFileName, File::Mode::READ);
	assert(err == File::Error::SUCCESS);

	// Get data to buffer
	unsigned char* dataFromFile = new unsigned char[infileSize];
	err = File::Read(FileReader, &dataFromFile[0], infileSize);
	assert(err == File::Error::SUCCESS);

	// Variables
	ModelHeader* packageHeader = (ModelHeader*)dataFromFile;
	ChunkHeader* chunkHeader = (ChunkHeader*)(dataFromFile + (unsigned int)sizeof(ModelHeader));
	chunkname = new char[ChunkHeader::CHUNK_NAME_SIZE + 1];
	strcpy_s(chunkname, ChunkHeader::CHUNK_NAME_SIZE, chunkHeader->chunkName);
	unsigned int chunkIndex = 0;

	// Loop through buffer
	while (chunkIndex < packageHeader->numChunks) {

		// If found
		if (chunkHeader->type == extractChkType && strcmp(chunkHeader->chunkName, extractChkName) == 0) {

			// Copy to buffer
			chunkBuff = (unsigned char*)malloc(chunkHeader->chunkSize);
			memcpy(chunkBuff, (unsigned char*)((unsigned int)chunkHeader + (unsigned int)sizeof(ChunkHeader)), chunkHeader->chunkSize);
			chunkSize = chunkHeader->chunkSize;

			// set return to true
			ret = true;
			break;
		}

		// Next chunk
		chunkIndex++;
		chunkHeader = (ChunkHeader*)((unsigned int)chunkHeader + (unsigned int)sizeof(ChunkHeader) + chunkHeader->chunkSize);
	}

	File::Close(FileReader);
	delete[] dataFromFile;
	delete[] chunkname;
	return ret;
}
// End of File
