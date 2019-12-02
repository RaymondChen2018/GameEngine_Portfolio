#ifndef CAMERA_MAN_H
#define CAMERA_MAN_H
class Camera;
class Matrix;
class Mouse;
class CameraMan {
public:
	CameraMan() = default;
	CameraMan(const CameraMan& p2) = delete;
	CameraMan& operator= (const CameraMan&) = delete;
	CameraMan& operator= (CameraMan&&) = delete;

	static void Initialize();
	static void Add(Camera * obj);
	static void SwitchNext();
	static void Update(float currTime);
	static void Destroy();

	static Matrix GetActiveCamWorldMatrix();
	static Matrix GetActiveCamProjectMatrix();
private:
	class Linker {
	public:
		Linker(Camera * _obj) {
			obj = _obj;
		}
		~Linker(){}
		Camera * obj = nullptr;
		Linker * pNext = nullptr;
		Linker * pPrev = nullptr;
	};

	static CameraMan * privGetInstance(void) {
		static CameraMan gom;
		return &gom;
	}
	void privAddLinker(Linker * link);
	Linker * pHead = nullptr;
	Linker * pActive = nullptr;
	const float camMovementSpeed = 2.5f;
	// Mouse
	Mouse* pMouse = nullptr;
	bool keySwitchPressedPrev = false;
	bool leftKeyPressed = false;
	bool pad1 = false;
	bool pad3 = false;

};

#endif