//-----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef CHUNK_HEADER_H
#define CHUNK_HEADER_H

enum class ChunkType// : uint32_t
{
	VERTS_NORM_UV_TYPE,// = 0xA0000000u,
	NORMS_TYPE,
	ANIM_TYPE,
	TEXTURE_TYPE,
	UV_TYPE,
	TRI_TYPE,
	SKELETON_TYPE,
	POSE_TYPE,
	ANIM_TX,
	ANIM_TY,
	ANIM_TZ,
	ANIM_RX,
	ANIM_RY,
	ANIM_RZ
};

struct ChunkHeader
{
	static const unsigned int CHUNK_NAME_SIZE = 20;

	// data:
	ChunkType      type;
	char           chunkName[CHUNK_NAME_SIZE];
	unsigned int   chunkSize;
	unsigned int   hashNum;
};

#endif