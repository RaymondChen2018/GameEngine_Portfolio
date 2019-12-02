#ifndef MODEL_H
#define MODEL_H
#include "sb7.h"
#include "MathEngine.h"
#include "VBOModel_Format.h"
#include "GenericObject.h"
enum PRIMITIVE :uint32_t {
	NullModel,
	Quad,
	Cube,
	CubeNew,
	Sphere,
	Pyramid,
	Space_frigate,
	CrashBandicoo,
	GroupA_Astroboy,
	GroupB_Buggy,
	GroupC_Warbear,
	Teddy,
	Humanoid,
};
enum class TextureName;
class BSphere;
class Model : public GenericObject
{
public:
	// Add model default up direction
	//

	Model(PRIMITIVE _modelType, const Vert_xyzuvn vertices[], unsigned int _numVerts, const Tri_index triList[], unsigned int _numTris);
	Model(PRIMITIVE _modelType, const char* ModelFileName, float modelScale = 1.0f, bool invertTris = false, bool isLegacyFormat = false);
	
	virtual ~Model();
	
	unsigned int numVerts;
	unsigned int numTris;
	//float *pVertices;

	GLuint vao;
	GLuint vbo_0;
	GLuint vbo_1;

	PRIMITIVE GetModelType() { return (PRIMITIVE)type; };
	TextureName GetDefaultTexture() { return defaultTexture; }
	virtual const BSphere* GetBoundingSphereRef();
	virtual void GetBoundSphere(BSphere& bSphereOut);

	// The orientation direction of the model when it's not adjusted
	void SetOrient(const Vect* dof, const Vect* up);
	void GetOrientation(Vect& dof, Vect& up);

protected:
	Model();
	void privInitialize();
	TextureName defaultTexture;
	void privCreateVAO(const Vert_xyzuvn Verts[], unsigned int _numVerts, const Tri_index triList[], unsigned int _numTris);
	BSphere* boundingSphere;
	Vect* defaultDOF;
	Vect* defaultUp;
};

#endif

// --- End of File -------
