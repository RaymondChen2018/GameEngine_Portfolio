#ifndef Camera_H
#define Camera_H
#include "MathEngine.h"
class Camera {
public:
	Camera();
	~Camera() {}

	// Position
	float x;
	float y;
	float z;

	// Rotation
	float angleRadX;
	float angleRadY;
	float angleRadZ;

	// Projection
	float aspect;
	float fovy;
	float nearClip;
	float farClip;

	// Setters
	void SetPosition(float _x, float _y, float _z);
	void SetRotation(float angleX, float angleY, float angleZ);
	void SetProjection(float _fovy, float _aspect, float _nearClip, float _farClip);
	void SetFovy(float _fovy);
	void SetAspect(float _aspect);
	void SetClip(float _nearClip, float _farClip);

	// Getters
	void GetRotation(float& angleXOut, float& angleYOut, float& angleZOut);
	Matrix GetWorldMatrix();
	Matrix GetProjectionMatrix();
};

#endif

