#ifndef MODEL_HEADER_CUSTOM_H
#define MODEL_HEADER_CUSTOM_H

// Keenan(3.2.5) - VBO and Reduce
#define OBJECT_NAME_SIZE   32
struct ModelHeaderCustom {
	// Model name
	char	objName[OBJECT_NAME_SIZE];

	// Number of vertices
	unsigned int numVerts;
	DWORD	vertBufferOffset;

	// trilist index 
	unsigned int		numTriList;
	DWORD	triListBufferOffset;

	ModelHeaderCustom()
	{
		memset(this, 0x0, sizeof(ModelHeaderCustom));
	}
};
#endif

#ifndef TRI_INDEX_H
#define TRI_INDEX_H
struct Tri_index
{
	unsigned int v0;
	unsigned int v1;
	unsigned int v2;
};
#endif

#ifndef VERT_XYZUVN_H
#define VERT_XYZUVN_H
struct Vert_xyzuvn
{
	float x;
	float y;
	float z;
	float u;
	float v;
	float nx;
	float ny;
	float nz;
};
#endif

#ifndef VERT_XYZ_H
#define VERT_XYZ_H
struct Vert_xyz
{
	float x;
	float y;
	float z;
};
#endif

#ifndef VERT_NORM_H
#define VERT_NORM_H
struct Vert_norm
{
	float nx;
	float ny;
	float nz;
};
#endif

#ifndef VERT_UV_H
#define VERT_UV_H
struct Vert_uv
{
	float u;
	float v;
};
#endif
