#include "Model.h"
#include "ModelMan.h"
#include "File.h"
#include "eat.h"
#include "ModelHeader.h"
#include "TextureMan.h"
#include "TextureNode.h"
#include "BoundingSphere.h"
#include "StringOperation.h"
#pragma warning( disable : 5045 )
Model::Model(PRIMITIVE _modelType, const Vert_xyzuvn vertices[], unsigned int _numVerts, const Tri_index triList[], unsigned int _numTris)
{
	this->vao = 0;
	this->vbo_0 = 0;
	this->vbo_1 = 0;
	this->type = _modelType;
	this->numVerts = _numVerts;
	this->numTris = _numTris;
	privInitialize();
	privCreateVAO(vertices, _numVerts, triList, _numTris);
}

// Read .mdl file
Model::Model(PRIMITIVE _modelType, const char* ModelFileName, float modelScale, bool invertTris, bool isLegacyFormat)
{
	this->type = _modelType;

	Vert_xyzuvn* vertices = nullptr;
	Tri_index* tris = nullptr;

	if (!isLegacyFormat) {
		// Get model name
		char* ModelName = RemoveExt(ModelFileName);

		ModelHeader modelHeader;
		GetModelInfo(ModelFileName, modelHeader);
		this->numVerts = modelHeader.numVerts;
		this->numTris = modelHeader.numTriList;

		unsigned char* vert_xyz = nullptr;
		unsigned int vert_xyz_Size = 0;
		eat(ModelFileName, ChunkType::VERTS_NORM_UV_TYPE, ModelName, vert_xyz, vert_xyz_Size);
		unsigned char* vert_norm = nullptr;
		unsigned int vert_norm_Size = 0;
		eat(ModelFileName, ChunkType::NORMS_TYPE, ModelName, vert_norm, vert_norm_Size);
		unsigned char* vert_uv = nullptr;
		unsigned int vert_uv_Size = 0;
		eat(ModelFileName, ChunkType::UV_TYPE, ModelName, vert_uv, vert_uv_Size);
		unsigned char* vert_tri = nullptr;
		unsigned int vert_tri_Size = 0;
		eat(ModelFileName, ChunkType::TRI_TYPE, ModelName, vert_tri, vert_tri_Size);

		// Optional texture
		unsigned char* texture = nullptr;
		unsigned int texture_Size = 0;
		char* texture_Name = nullptr;
		bool hasTexture = eat(ModelFileName, ChunkType::TEXTURE_TYPE, ModelName, texture, texture_Size, texture_Name);
		if (hasTexture) {
			this->defaultTexture = TextureMan::addTexture(texture, texture_Name);
		}
		else {
			this->defaultTexture = TextureName::NOT_INITIALIZED;
		}
		delete ModelName;

		vertices = new Vert_xyzuvn[numVerts];
		tris = new Tri_index[numTris];

		for (unsigned int i = 0; i < this->numVerts; i++) {
			vertices[i].x = (((Vert_xyz*)vert_xyz) + i)->x;
			vertices[i].y = (((Vert_xyz*)vert_xyz) + i)->y;
			vertices[i].z = (((Vert_xyz*)vert_xyz) + i)->z;

			vertices[i].nx = (((Vert_norm*)vert_norm) + i)->nx;
			vertices[i].ny = (((Vert_norm*)vert_norm) + i)->ny;
			vertices[i].nz = (((Vert_norm*)vert_norm) + i)->nz;

			vertices[i].u = (((Vert_uv*)vert_uv) + i)->u;
			vertices[i].v = (((Vert_uv*)vert_uv) + i)->v;
		}

		for (unsigned int i = 0; i < this->numTris; i++) {
			tris[i].v0 = (((Tri_index*)vert_tri) + i)->v0;
			tris[i].v1 = (((Tri_index*)vert_tri) + i)->v1;
			tris[i].v2 = (((Tri_index*)vert_tri) + i)->v2;
		}
	}
	else {
		File::Handle fh;
		File::Error  ferror;

		ferror = File::Open(fh, ModelFileName, File::Mode::READ);
		assert(ferror == File::Error::SUCCESS);

		ModelHeaderCustom modelHdr2;

		ferror = File::Read(fh, &modelHdr2, sizeof(ModelHeaderCustom));
		assert(ferror == File::Error::SUCCESS);

		this->numVerts = modelHdr2.numVerts;
		this->numTris = modelHdr2.numTriList;

		vertices = new Vert_xyzuvn[numVerts];
		tris = new Tri_index[numTris];

		//Offset?
		ferror = File::Seek(fh, File::Location::BEGIN, (int)modelHdr2.vertBufferOffset);
		assert(ferror == File::Error::SUCCESS);

		ferror = File::Read(fh, vertices, sizeof(Vert_xyzuvn) * numVerts);
		assert(ferror == File::Error::SUCCESS);

		ferror = File::Seek(fh, File::Location::BEGIN, (int)modelHdr2.triListBufferOffset);
		assert(ferror == File::Error::SUCCESS);

		ferror = File::Read(fh, tris, sizeof(Tri_index) * numTris);
		assert(ferror == File::Error::SUCCESS);

		// CLOSE
		ferror = File::Close(fh);
		assert(ferror == File::Error::SUCCESS);
	}

	// Modifier
	// Scale
	for (unsigned int i = 0; i < numVerts; i++) {
		vertices[i].x *= modelScale;
		vertices[i].y *= modelScale;
		vertices[i].z *= modelScale;
	}
	// Invert triangles
	if (invertTris) {
		for (unsigned int i = 0; i < numTris; i++) {
			unsigned int temp = tris[i].v0;
			tris[i].v0 = tris[i].v2;
			tris[i].v2 = temp;
		}
	}
	
	privInitialize();
	privCreateVAO(vertices, numVerts, tris, numTris);
	delete[] vertices;
	delete[] tris;
}

void Model::SetOrient(const Vect* dof, const Vect* up)
{
	*(this->defaultDOF) = *dof;
	*(this->defaultUp) = *up;
}

void Model::GetOrientation(Vect& dof, Vect& up)
{
	dof = *this->defaultDOF;
	up = *this->defaultUp;
}

Model::~Model()
{
	delete this->boundingSphere;
	delete this->defaultDOF;
	delete this->defaultUp;
}

const BSphere* Model::GetBoundingSphereRef()
{
	return this->boundingSphere;
}

void Model::GetBoundSphere(BSphere& bSphereOut)
{
	bSphereOut.cntr = this->boundingSphere->cntr;
	bSphereOut.rad = this->boundingSphere->rad;
}

//void Model::privCreateVAO(const Vert_xyzuv Verts[], int _numVerts)
//{
//	ModelMan::Add(this);
//
//	//Create VAO
//	glGenVertexArrays(1, &this->vao);
//	assert(this->vao != 0);
//	glBindVertexArray(this->vao);
//
//	// Create a VBO
//	glGenBuffers(1, &this->vbo_0);
//	assert(this->vbo_0 != 0);
//
//	// Load the combined data
//	glBindBuffer(GL_ARRAY_BUFFER, this->vbo_0);
//
//	glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(sizeof(Vert_xyzuv) * this->numVerts), Verts, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vert_xyzuv), 0);
//
//	glEnableVertexAttribArray(0);
//
//	void *offsetTex = (void *)((unsigned int)&Verts[0].u - (unsigned int)Verts);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vert_xyzuv), offsetTex);
//	glEnableVertexAttribArray(1);
//
//}

Model::Model()
{
	this->privInitialize();
}

void Model::privInitialize()
{
	this->defaultTexture = TextureName::NOT_INITIALIZED;
	this->defaultDOF = new Vect(0.0f, 0.0f, 1.0f);
	this->defaultUp = new Vect(0.0f, 1.0f, 0.0f);
	this->boundingSphere = new BSphere();
	this->boundingSphere->cntr.set(0.0f, 0.0f, 0.0f, 1.0f);
	this->boundingSphere->rad = 1.0f;
	ModelMan::Add(this);
}

void Model::privCreateVAO(const Vert_xyzuvn Verts[], unsigned int _numVerts, const Tri_index triList[], unsigned int _numTris)
{
	(void*)_numVerts;
	(void*)_numTris;
	// Create a VAO
	glGenVertexArrays(1, &this->vao);
	assert(this->vao != 0);
	glBindVertexArray(this->vao);

	// Create a VBO
	glGenBuffers(1, &this->vbo_0);
	assert(this->vbo_0 != 0);
	glGenBuffers(1, &this->vbo_1);
	assert(this->vbo_1 != 0);

	// Vertices buffer
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo_0);
	glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(sizeof(Vert_xyzuvn) * this->numVerts), Verts, GL_STATIC_DRAW);
	// Vertices [x y z]: 0 - 3 (Verts[0].x => 0)
	void* offsetVert = (void*)((unsigned int)& Verts[0].x - (unsigned int)Verts);
		//						1st GLuint		xyz 3 values
		glVertexAttribPointer(	0,				3,					GL_FLOAT, GL_FALSE, sizeof(Vert_xyzuvn), offsetVert);
		glEnableVertexAttribArray(0);
	// Texture  [u v]: 1  (Verts[0].u => 3)
	void* offsetTex = (void*)((unsigned int)& Verts[0].u - (unsigned int)Verts);
		//						2nd GLuint		uv 2 values
		glVertexAttribPointer(	1,				2,					GL_FLOAT, GL_FALSE, sizeof(Vert_xyzuvn), offsetTex);
		glEnableVertexAttribArray(1);
	// Normals: [nx ny nz] (Verts[0].nx => 5)
	void* offsetNorm = (void*)((unsigned int)& Verts[0].nx - (unsigned int)Verts);
		//						1st GLuint		nx ny nz 3 values
		glVertexAttribPointer(	2,				3,					GL_FLOAT, GL_FALSE, sizeof(Vert_xyzuvn), offsetNorm);
		glEnableVertexAttribArray(2);



	// Index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo_1);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (GLsizeiptr)(sizeof(Tri_index) * this->numTris), triList, GL_STATIC_DRAW);

	

	Vect* vertList = new Vect[this->numVerts];
	for (unsigned int i = 0; i < this->numVerts; i++) {
		vertList[i][x] = Verts[i].x;
		vertList[i][y] = Verts[i].y;
		vertList[i][z] = Verts[i].z;
	}
	this->boundingSphere->RitterSphere(vertList, this->numVerts);
	delete[] vertList;
}
