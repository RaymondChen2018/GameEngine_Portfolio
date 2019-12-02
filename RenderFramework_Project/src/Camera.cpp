#include "Camera.h"
#include "Keyboard.h"
#include "InputMan.h"
#include "CameraMan.h"
#include <vmath.h>	
Camera::Camera() :x(0.0f), y(0.0f), z(0.0f), 
angleRadX(0.0f), angleRadY(0.0f), angleRadZ(0.0f), 
aspect(1.0f), fovy(50.0f), nearClip(0.1f), farClip(1000.0f)
{
	CameraMan::Add(this);
}

void Camera::SetPosition(float _x, float _y, float _z)
{
	this->x = _x;
	this->y = _y;
	this->z = _z;
}

void Camera::SetRotation(float angleX, float angleY, float angleZ)
{
	this->angleRadX = angleX / MATH_180_PI;
	this->angleRadY = angleY / MATH_180_PI;
	this->angleRadZ = angleZ / MATH_180_PI;
}

void Camera::SetProjection(float _fovy, float _aspect, float _nearClip, float _farClip)
{
	this->fovy = _fovy;
	this->aspect = _aspect;
	this->nearClip = _nearClip;
	this->farClip = _farClip;
}

void Camera::SetFovy(float _fovy)
{
	this->fovy = _fovy;
}

void Camera::SetAspect(float _aspect)
{
	this->aspect = _aspect;
}

void Camera::SetClip(float _nearClip, float _farClip)
{
	this->nearClip = _nearClip;
	this->farClip = _farClip;
}

void Camera::GetRotation(float& angleXOut, float& angleYOut, float& angleZOut)
{
	angleXOut = this->angleRadX * MATH_180_PI;
	angleYOut = this->angleRadY * MATH_180_PI;
	angleZOut = this->angleRadZ * MATH_180_PI;
}

Matrix Camera::GetWorldMatrix()
{
	Matrix tScreen(Matrix::Trans::XYZ, this->x, this->y, this->z);
	Matrix rxScreen(Matrix::Rot1::X, this->angleRadX);
	Matrix ryScreen(Matrix::Rot1::Y, this->angleRadY);
	Matrix rzScreen(Matrix::Rot1::Z, this->angleRadZ);
	printf("x: %f, y: %f, z: %f, radx: %f, rady: %f, radz: %f\n", this->x, this->y, this->z, this->angleRadX, this->angleRadY, this->angleRadZ);
	return tScreen * ryScreen * rxScreen;//  *rzScreen;
}

Matrix Camera::GetProjectionMatrix()
{
	vmath::mat4 tmpMatrix = vmath::perspective(this->fovy, this->aspect, this->nearClip, this->farClip);
	return (Matrix&)tmpMatrix;
}



