#ifndef RIG_ANIMATION_CUSTOM_H
#define RIG_ANIMATION_CUSTOM_H

// Bone
#define OBJECT_NAME_SIZE   32
struct Bone {
	unsigned int boneID;
	char	objName[OBJECT_NAME_SIZE];
	char	parentName[OBJECT_NAME_SIZE];
};
#endif

#ifndef POSE_H
#define POSE_H
#define MATRIX_FLOAT_SIZE   16
struct Pose
{
	char	boneName[OBJECT_NAME_SIZE];
	float world[MATRIX_FLOAT_SIZE];
};
#endif

//#ifndef ANIM_PER_BONE_H
//#define ANIM_PER_BONE_H
//
//struct AnimPerBone
//{
//	/*enum ANIM_DATA_TYPE {
//		ANIM_TX,
//		ANIM_TY,
//		ANIM_TZ,
//		ANIM_RX,
//		ANIM_RY,
//		ANIM_RZ
//	};*/
//	char	boneName[OBJECT_NAME_SIZE];
//
//	// TX
//	unsigned int numTX;
//	//DWORD	TXBufferOffset;
//	unsigned int getTXBufferOffset() { return (unsigned int)0; }
//
//	// TY
//	unsigned int numTY;
//	//DWORD	TYBufferOffset;
//	unsigned int getTYBufferOffset() { return getTXBufferOffset() + numTX * (unsigned int)sizeof(float); }
//
//	// TZ
//	unsigned int numTZ;
//	//DWORD	TZBufferOffset;
//	unsigned int getTZBufferOffset() { return getTYBufferOffset() + numTY * (unsigned int)sizeof(float); }
//
//	// RX
//	unsigned int numRX;
//	//DWORD	RXBufferOffset;
//	unsigned int getRXBufferOffset() { return getTZBufferOffset() + numTZ * (unsigned int)sizeof(float); }
//
//	// RY
//	unsigned int numRY;
//	//DWORD	RYBufferOffset;
//	unsigned int getRYBufferOffset() { return getRXBufferOffset() + numRX * (unsigned int)sizeof(float); }
//
//	// RZ
//	unsigned int numRZ;
//	//DWORD	RZBufferOffset;
//	unsigned int getRZBufferOffset() { return getRYBufferOffset() + numRY * (unsigned int)sizeof(float); }
//
//	// SX
//	unsigned int numSX;
//	//DWORD	SXBufferOffset;
//	unsigned int getSXBufferOffset() { return getRZBufferOffset() + numRZ * (unsigned int)sizeof(float); }
//
//	// SY
//	unsigned int numSY;
//	//DWORD	SYBufferOffset;
//	unsigned int getSYBufferOffset() { return getSXBufferOffset() + numSX * (unsigned int)sizeof(float); }
//
//	// SZ
//	unsigned int numSZ;
//	//DWORD	SZBufferOffset;
//	unsigned int getSZBufferOffset() { return getSYBufferOffset() + numSY * (unsigned int)sizeof(float); }
//
//	size_t getSizeOfBody() { return (numTX + numTY + numTZ + numRX + numRY + numRZ + numSX + numSY + numSZ)*sizeof(float); }
//
//	/*float* getData(ANIM_DATA_TYPE dataType) {
//		float* data = nullptr;
//
//		switch (dataType) {
//		case ANIM_TX:
//
//			break;
//				ANIM_TY,
//				ANIM_TZ,
//				ANIM_RX,
//				ANIM_RY,
//				ANIM_RZ
//		}
//	}*/
//};
//#endif

#ifndef ANIM_FRAME_DATA
#define ANIM_FRAME_DATA
struct AnimFrameData {
	float tx;
	float ty;
	float tz;
	
	float qx;
	float qy;
	float qz;
	float qw;

	float sx;
	float sy;
	float sz;
};
#endif

#ifndef ANIM_CLIP_HEADER
#define ANIM_CLIP_HEADER
// Index of chunk is the id of the bone
struct AnimClipHeader {
	char clipName[OBJECT_NAME_SIZE];
	unsigned int numFrames;
	unsigned int numBones; // Used to identify bottom address
};
#endif

// Animation data example:
//AnimClipHeader============
//Bone0--------------------
//	AnimFrameData
//	AnimFrameData
//	AnimFrameData
//	AnimFrameData
//	AnimFrameData
//Bone1--------------------
//	AnimFrameData
//	AnimFrameData
//	AnimFrameData
//	AnimFrameData
//	AnimFrameData
//Bone2--------------------
//	AnimFrameData
//	AnimFrameData
//	AnimFrameData
//	AnimFrameData
//	AnimFrameData
