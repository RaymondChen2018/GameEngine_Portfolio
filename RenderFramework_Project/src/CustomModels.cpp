#include "model.h"

// Cube
#define CUBENEW_DATA_NUM_TRIS (sizeof(TriList_cubeNew)/sizeof(Tri_index))

static const Tri_index TriList_cubeNew[] =
{
	{ 0,1,2 },
	{ 3,4,5 },
	{ 6,7,8 },
	{ 9,10,11 },
	{ 12,13,14 },
	{ 15,16,17 },
	{ 18,19,20 },
	{ 21,22,23 },
	{ 24,25,26 },
	{ 27,28,29 },
	{ 30,31,32 },
	{ 33,34,35 }
};

#define CUBENEW_DATA_NUM_VERTS (sizeof(Vertices_cubeNew)/sizeof(Vert_xyzuvn))

static const Vert_xyzuvn  Vertices_cubeNew[] =
{
	// Triangle 0
	{ -0.25f,  0.25f, -0.25f, 0.0f, 0.0f, -0.6f,  0.6f, -0.6f },
	{ -0.25f, -0.25f, -0.25f, 0.0f, 1.0f, -0.6f, -0.6f, -0.6f },
	{ 0.25f, -0.25f,  -0.25f, 1.0f, 1.0f,  0.6f,  -0.6f, -0.6f },

	// Triangle 1
	{ 0.25f,  -0.25f, -0.25f, 1.0f, 1.0f,  0.6f, -0.6f, -0.6f },
	{ 0.25f,   0.25f, -0.25f, 1.0f, 0.0f,  0.6f,  0.6f, -0.6f },
	{ -0.25f,  0.25f, -0.25f, 0.0f, 0.0f, -0.6f,  0.6f, -0.6f },

	// Triangle 2
	{ 0.25f, -0.25f, -0.25f, 0.0f, 1.0f, 0.6f, -0.6f, -0.6f },
	{ 0.25f, -0.25f,  0.25f, 1.0f, 1.0f, 0.6f, -0.6f,  0.6f },
	{ 0.25f,  0.25f, -0.25f, 0.0f, 0.0f, 0.6f,  0.6f, -0.6f },

	// Triangle 3
	{ 0.25f, -0.25f,  0.25f, 1.0f, 1.0f, 0.6f, -0.6f,  0.6f },
	{ 0.25f,  0.25f,  0.25f, 1.0f, 0.0f, 0.6f,  0.6f,  0.6f },
	{ 0.25f,  0.25f, -0.25f, 0.0f, 0.0f, 0.6f,  0.6f, -0.6f },

	// Triangle 4
	{ 0.25f, -0.25f,  0.25f, 1.0f, 1.0f,  0.6f, -0.6f, 0.6f },
	{ -0.25f, -0.25f, 0.25f, 0.0f, 1.0f, -0.6f, -0.6f, 0.6f },
	{ 0.25f,  0.25f,  0.25f, 1.0f, 0.0f,  0.6f,  0.6f, 0.6f },

	// Triangle 5
	{ -0.25f, -0.25f,  0.25f, 0.0f, 1.0f, -0.6f, -0.6f, 0.6f },
	{ -0.25f,  0.25f,  0.25f, 0.0f, 0.0f, -0.6f,  0.6f, 0.6f },
	{ 0.25f,   0.25f,  0.25f, 1.0f, 0.0f,  0.6f,  0.6f, 0.6f },

	// Triangle 6
	{ -0.25f, -0.25f,  0.25f, 0.0f, 0.0f, -0.6f, -0.6f,  0.6f },
	{ -0.25f, -0.25f, -0.25f, 0.0f, 1.0f, -0.6f, -0.6f, -0.6f },
	{ -0.25f,  0.25f,  0.25f, 1.0f, 0.0f, -0.6f,  0.6f,  0.6f },

	// Triangle 7
	{ -0.25f, -0.25f, -0.25f, 0.0f, 1.0f, -0.6f, -0.6f, -0.6f },
	{ -0.25f,  0.25f, -0.25f, 1.0f, 1.0f, -0.6f,  0.6f, -0.6f },
	{ -0.25f,  0.25f,  0.25f, 1.0f, 0.0f, -0.6f,  0.6f,  0.6f },

	// Triangle 8
	{ -0.25f, -0.25f,  0.25f, 0.0f, 0.0f, -0.6f, -0.6f,  0.6f },
	{ 0.25f, -0.25f,   0.25f, 1.0f, 0.0f,  0.6f, -0.6f,  0.6f },
	{ 0.25f, -0.25f,  -0.25f, 1.0f, 1.0f,  0.6f, -0.6f, -0.6f },

	// Triangle 9
	{ 0.25f, -0.25f,  -0.25f, 1.0f, 1.0f,  0.6f, -0.6f, -0.6f },
	{ -0.25f, -0.25f, -0.25f, 0.0f, 1.0f, -0.6f, -0.6f, -0.6f },
	{ -0.25f, -0.25f,  0.25f, 0.0f, 0.0f, -0.6f, -0.6f,  0.6f },

	// Triangle 10
	{ -0.25f,  0.25f, -0.25f, 0.0f, 1.0f, -0.6f, 0.6f, -0.6f },
	{ 0.25f,  0.25f,  -0.25f, 1.0f, 1.0f,  0.6f, 0.6f, -0.6f },
	{ 0.25f,  0.25f,   0.25f, 1.0f, 0.0f,  0.6f, 0.6f,  0.6f },

	// Triangle 11
	{ 0.25f,  0.25f,   0.25f, 1.0f, 0.0f,  0.6f, 0.6f,  0.6f },
	{ -0.25f,  0.25f,  0.25f, 0.0f, 0.0f, -0.6f, 0.6f,  0.6f },
	{ -0.25f,  0.25f, -0.25f, 0.0f, 1.0f, -0.6f, 0.6f, -0.6f }
};


// Sphere
#define SPHERE_DATA_NUM_TRIS (sizeof(TriList_sphereNew)/sizeof(Tri_index))
#define SPHERE_DATA_NUM_VERTS (sizeof(Vertices_sphereNew)/sizeof(Vert_xyzuvn))
static Tri_index TriList_sphereNew[200];
static Vert_xyzuvn Vertices_sphereNew[121];
#pragma warning( disable : 4505 )
static void sphereFunction()
{
	TriList_sphereNew[0].v0 = 0;
	TriList_sphereNew[0].v1 = 1;
	TriList_sphereNew[0].v2 = 2;

	TriList_sphereNew[1].v0 = 1;
	TriList_sphereNew[1].v1 = 3;
	TriList_sphereNew[1].v2 = 2;

	TriList_sphereNew[2].v0 = 2;
	TriList_sphereNew[2].v1 = 3;
	TriList_sphereNew[2].v2 = 4;

	TriList_sphereNew[3].v0 = 3;
	TriList_sphereNew[3].v1 = 5;
	TriList_sphereNew[3].v2 = 4;

	TriList_sphereNew[4].v0 = 4;
	TriList_sphereNew[4].v1 = 5;
	TriList_sphereNew[4].v2 = 6;

	TriList_sphereNew[5].v0 = 5;
	TriList_sphereNew[5].v1 = 7;
	TriList_sphereNew[5].v2 = 6;

	TriList_sphereNew[6].v0 = 6;
	TriList_sphereNew[6].v1 = 7;
	TriList_sphereNew[6].v2 = 8;

	TriList_sphereNew[7].v0 = 7;
	TriList_sphereNew[7].v1 = 9;
	TriList_sphereNew[7].v2 = 8;

	TriList_sphereNew[8].v0 = 8;
	TriList_sphereNew[8].v1 = 9;
	TriList_sphereNew[8].v2 = 10;

	TriList_sphereNew[9].v0 = 9;
	TriList_sphereNew[9].v1 = 11;
	TriList_sphereNew[9].v2 = 10;

	TriList_sphereNew[10].v0 = 10;
	TriList_sphereNew[10].v1 = 11;
	TriList_sphereNew[10].v2 = 12;

	TriList_sphereNew[11].v0 = 11;
	TriList_sphereNew[11].v1 = 13;
	TriList_sphereNew[11].v2 = 12;

	TriList_sphereNew[12].v0 = 12;
	TriList_sphereNew[12].v1 = 13;
	TriList_sphereNew[12].v2 = 14;

	TriList_sphereNew[13].v0 = 13;
	TriList_sphereNew[13].v1 = 15;
	TriList_sphereNew[13].v2 = 14;

	TriList_sphereNew[14].v0 = 14;
	TriList_sphereNew[14].v1 = 15;
	TriList_sphereNew[14].v2 = 16;

	TriList_sphereNew[15].v0 = 15;
	TriList_sphereNew[15].v1 = 17;
	TriList_sphereNew[15].v2 = 16;

	TriList_sphereNew[16].v0 = 16;
	TriList_sphereNew[16].v1 = 17;
	TriList_sphereNew[16].v2 = 18;

	TriList_sphereNew[17].v0 = 17;
	TriList_sphereNew[17].v1 = 19;
	TriList_sphereNew[17].v2 = 18;

	TriList_sphereNew[18].v0 = 18;
	TriList_sphereNew[18].v1 = 19;
	TriList_sphereNew[18].v2 = 20;

	TriList_sphereNew[19].v0 = 19;
	TriList_sphereNew[19].v1 = 21;
	TriList_sphereNew[19].v2 = 20;

	TriList_sphereNew[20].v0 = 1;
	TriList_sphereNew[20].v1 = 22;
	TriList_sphereNew[20].v2 = 3;

	TriList_sphereNew[21].v0 = 22;
	TriList_sphereNew[21].v1 = 23;
	TriList_sphereNew[21].v2 = 3;

	TriList_sphereNew[22].v0 = 3;
	TriList_sphereNew[22].v1 = 23;
	TriList_sphereNew[22].v2 = 5;

	TriList_sphereNew[23].v0 = 23;
	TriList_sphereNew[23].v1 = 24;
	TriList_sphereNew[23].v2 = 5;

	TriList_sphereNew[24].v0 = 5;
	TriList_sphereNew[24].v1 = 24;
	TriList_sphereNew[24].v2 = 7;

	TriList_sphereNew[25].v0 = 24;
	TriList_sphereNew[25].v1 = 25;
	TriList_sphereNew[25].v2 = 7;

	TriList_sphereNew[26].v0 = 7;
	TriList_sphereNew[26].v1 = 25;
	TriList_sphereNew[26].v2 = 9;

	TriList_sphereNew[27].v0 = 25;
	TriList_sphereNew[27].v1 = 26;
	TriList_sphereNew[27].v2 = 9;

	TriList_sphereNew[28].v0 = 9;
	TriList_sphereNew[28].v1 = 26;
	TriList_sphereNew[28].v2 = 11;

	TriList_sphereNew[29].v0 = 26;
	TriList_sphereNew[29].v1 = 27;
	TriList_sphereNew[29].v2 = 11;

	TriList_sphereNew[30].v0 = 11;
	TriList_sphereNew[30].v1 = 27;
	TriList_sphereNew[30].v2 = 13;

	TriList_sphereNew[31].v0 = 27;
	TriList_sphereNew[31].v1 = 28;
	TriList_sphereNew[31].v2 = 13;

	TriList_sphereNew[32].v0 = 13;
	TriList_sphereNew[32].v1 = 28;
	TriList_sphereNew[32].v2 = 15;

	TriList_sphereNew[33].v0 = 28;
	TriList_sphereNew[33].v1 = 29;
	TriList_sphereNew[33].v2 = 15;

	TriList_sphereNew[34].v0 = 15;
	TriList_sphereNew[34].v1 = 29;
	TriList_sphereNew[34].v2 = 17;

	TriList_sphereNew[35].v0 = 29;
	TriList_sphereNew[35].v1 = 30;
	TriList_sphereNew[35].v2 = 17;

	TriList_sphereNew[36].v0 = 17;
	TriList_sphereNew[36].v1 = 30;
	TriList_sphereNew[36].v2 = 19;

	TriList_sphereNew[37].v0 = 30;
	TriList_sphereNew[37].v1 = 31;
	TriList_sphereNew[37].v2 = 19;

	TriList_sphereNew[38].v0 = 19;
	TriList_sphereNew[38].v1 = 31;
	TriList_sphereNew[38].v2 = 21;

	TriList_sphereNew[39].v0 = 31;
	TriList_sphereNew[39].v1 = 32;
	TriList_sphereNew[39].v2 = 21;

	TriList_sphereNew[40].v0 = 22;
	TriList_sphereNew[40].v1 = 33;
	TriList_sphereNew[40].v2 = 23;

	TriList_sphereNew[41].v0 = 33;
	TriList_sphereNew[41].v1 = 34;
	TriList_sphereNew[41].v2 = 23;

	TriList_sphereNew[42].v0 = 23;
	TriList_sphereNew[42].v1 = 34;
	TriList_sphereNew[42].v2 = 24;

	TriList_sphereNew[43].v0 = 34;
	TriList_sphereNew[43].v1 = 35;
	TriList_sphereNew[43].v2 = 24;

	TriList_sphereNew[44].v0 = 24;
	TriList_sphereNew[44].v1 = 35;
	TriList_sphereNew[44].v2 = 25;

	TriList_sphereNew[45].v0 = 35;
	TriList_sphereNew[45].v1 = 36;
	TriList_sphereNew[45].v2 = 25;

	TriList_sphereNew[46].v0 = 25;
	TriList_sphereNew[46].v1 = 36;
	TriList_sphereNew[46].v2 = 26;

	TriList_sphereNew[47].v0 = 36;
	TriList_sphereNew[47].v1 = 37;
	TriList_sphereNew[47].v2 = 26;

	TriList_sphereNew[48].v0 = 26;
	TriList_sphereNew[48].v1 = 37;
	TriList_sphereNew[48].v2 = 27;

	TriList_sphereNew[49].v0 = 37;
	TriList_sphereNew[49].v1 = 38;
	TriList_sphereNew[49].v2 = 27;

	TriList_sphereNew[50].v0 = 27;
	TriList_sphereNew[50].v1 = 38;
	TriList_sphereNew[50].v2 = 28;

	TriList_sphereNew[51].v0 = 38;
	TriList_sphereNew[51].v1 = 39;
	TriList_sphereNew[51].v2 = 28;

	TriList_sphereNew[52].v0 = 28;
	TriList_sphereNew[52].v1 = 39;
	TriList_sphereNew[52].v2 = 29;

	TriList_sphereNew[53].v0 = 39;
	TriList_sphereNew[53].v1 = 40;
	TriList_sphereNew[53].v2 = 29;

	TriList_sphereNew[54].v0 = 29;
	TriList_sphereNew[54].v1 = 40;
	TriList_sphereNew[54].v2 = 30;

	TriList_sphereNew[55].v0 = 40;
	TriList_sphereNew[55].v1 = 41;
	TriList_sphereNew[55].v2 = 30;

	TriList_sphereNew[56].v0 = 30;
	TriList_sphereNew[56].v1 = 41;
	TriList_sphereNew[56].v2 = 31;

	TriList_sphereNew[57].v0 = 41;
	TriList_sphereNew[57].v1 = 42;
	TriList_sphereNew[57].v2 = 31;

	TriList_sphereNew[58].v0 = 31;
	TriList_sphereNew[58].v1 = 42;
	TriList_sphereNew[58].v2 = 32;

	TriList_sphereNew[59].v0 = 42;
	TriList_sphereNew[59].v1 = 43;
	TriList_sphereNew[59].v2 = 32;

	TriList_sphereNew[60].v0 = 33;
	TriList_sphereNew[60].v1 = 44;
	TriList_sphereNew[60].v2 = 34;

	TriList_sphereNew[61].v0 = 44;
	TriList_sphereNew[61].v1 = 45;
	TriList_sphereNew[61].v2 = 34;

	TriList_sphereNew[62].v0 = 34;
	TriList_sphereNew[62].v1 = 45;
	TriList_sphereNew[62].v2 = 35;

	TriList_sphereNew[63].v0 = 45;
	TriList_sphereNew[63].v1 = 46;
	TriList_sphereNew[63].v2 = 35;

	TriList_sphereNew[64].v0 = 35;
	TriList_sphereNew[64].v1 = 46;
	TriList_sphereNew[64].v2 = 36;

	TriList_sphereNew[65].v0 = 46;
	TriList_sphereNew[65].v1 = 47;
	TriList_sphereNew[65].v2 = 36;

	TriList_sphereNew[66].v0 = 36;
	TriList_sphereNew[66].v1 = 47;
	TriList_sphereNew[66].v2 = 37;

	TriList_sphereNew[67].v0 = 47;
	TriList_sphereNew[67].v1 = 48;
	TriList_sphereNew[67].v2 = 37;

	TriList_sphereNew[68].v0 = 37;
	TriList_sphereNew[68].v1 = 48;
	TriList_sphereNew[68].v2 = 38;

	TriList_sphereNew[69].v0 = 48;
	TriList_sphereNew[69].v1 = 49;
	TriList_sphereNew[69].v2 = 38;

	TriList_sphereNew[70].v0 = 38;
	TriList_sphereNew[70].v1 = 49;
	TriList_sphereNew[70].v2 = 39;

	TriList_sphereNew[71].v0 = 49;
	TriList_sphereNew[71].v1 = 50;
	TriList_sphereNew[71].v2 = 39;

	TriList_sphereNew[72].v0 = 39;
	TriList_sphereNew[72].v1 = 50;
	TriList_sphereNew[72].v2 = 40;

	TriList_sphereNew[73].v0 = 50;
	TriList_sphereNew[73].v1 = 51;
	TriList_sphereNew[73].v2 = 40;

	TriList_sphereNew[74].v0 = 40;
	TriList_sphereNew[74].v1 = 51;
	TriList_sphereNew[74].v2 = 41;

	TriList_sphereNew[75].v0 = 51;
	TriList_sphereNew[75].v1 = 52;
	TriList_sphereNew[75].v2 = 41;

	TriList_sphereNew[76].v0 = 41;
	TriList_sphereNew[76].v1 = 52;
	TriList_sphereNew[76].v2 = 42;

	TriList_sphereNew[77].v0 = 52;
	TriList_sphereNew[77].v1 = 53;
	TriList_sphereNew[77].v2 = 42;

	TriList_sphereNew[78].v0 = 42;
	TriList_sphereNew[78].v1 = 53;
	TriList_sphereNew[78].v2 = 43;

	TriList_sphereNew[79].v0 = 53;
	TriList_sphereNew[79].v1 = 54;
	TriList_sphereNew[79].v2 = 43;

	TriList_sphereNew[80].v0 = 44;
	TriList_sphereNew[80].v1 = 55;
	TriList_sphereNew[80].v2 = 45;

	TriList_sphereNew[81].v0 = 55;
	TriList_sphereNew[81].v1 = 56;
	TriList_sphereNew[81].v2 = 45;

	TriList_sphereNew[82].v0 = 45;
	TriList_sphereNew[82].v1 = 56;
	TriList_sphereNew[82].v2 = 46;

	TriList_sphereNew[83].v0 = 56;
	TriList_sphereNew[83].v1 = 57;
	TriList_sphereNew[83].v2 = 46;

	TriList_sphereNew[84].v0 = 46;
	TriList_sphereNew[84].v1 = 57;
	TriList_sphereNew[84].v2 = 47;

	TriList_sphereNew[85].v0 = 57;
	TriList_sphereNew[85].v1 = 58;
	TriList_sphereNew[85].v2 = 47;

	TriList_sphereNew[86].v0 = 47;
	TriList_sphereNew[86].v1 = 58;
	TriList_sphereNew[86].v2 = 48;

	TriList_sphereNew[87].v0 = 58;
	TriList_sphereNew[87].v1 = 59;
	TriList_sphereNew[87].v2 = 48;

	TriList_sphereNew[88].v0 = 48;
	TriList_sphereNew[88].v1 = 59;
	TriList_sphereNew[88].v2 = 49;

	TriList_sphereNew[89].v0 = 59;
	TriList_sphereNew[89].v1 = 60;
	TriList_sphereNew[89].v2 = 49;

	TriList_sphereNew[90].v0 = 49;
	TriList_sphereNew[90].v1 = 60;
	TriList_sphereNew[90].v2 = 50;

	TriList_sphereNew[91].v0 = 60;
	TriList_sphereNew[91].v1 = 61;
	TriList_sphereNew[91].v2 = 50;

	TriList_sphereNew[92].v0 = 50;
	TriList_sphereNew[92].v1 = 61;
	TriList_sphereNew[92].v2 = 51;

	TriList_sphereNew[93].v0 = 61;
	TriList_sphereNew[93].v1 = 62;
	TriList_sphereNew[93].v2 = 51;

	TriList_sphereNew[94].v0 = 51;
	TriList_sphereNew[94].v1 = 62;
	TriList_sphereNew[94].v2 = 52;

	TriList_sphereNew[95].v0 = 62;
	TriList_sphereNew[95].v1 = 63;
	TriList_sphereNew[95].v2 = 52;

	TriList_sphereNew[96].v0 = 52;
	TriList_sphereNew[96].v1 = 63;
	TriList_sphereNew[96].v2 = 53;

	TriList_sphereNew[97].v0 = 63;
	TriList_sphereNew[97].v1 = 64;
	TriList_sphereNew[97].v2 = 53;

	TriList_sphereNew[98].v0 = 53;
	TriList_sphereNew[98].v1 = 64;
	TriList_sphereNew[98].v2 = 54;

	TriList_sphereNew[99].v0 = 64;
	TriList_sphereNew[99].v1 = 65;
	TriList_sphereNew[99].v2 = 54;

	TriList_sphereNew[100].v0 = 55;
	TriList_sphereNew[100].v1 = 66;
	TriList_sphereNew[100].v2 = 56;

	TriList_sphereNew[101].v0 = 66;
	TriList_sphereNew[101].v1 = 67;
	TriList_sphereNew[101].v2 = 56;

	TriList_sphereNew[102].v0 = 56;
	TriList_sphereNew[102].v1 = 67;
	TriList_sphereNew[102].v2 = 57;

	TriList_sphereNew[103].v0 = 67;
	TriList_sphereNew[103].v1 = 68;
	TriList_sphereNew[103].v2 = 57;

	TriList_sphereNew[104].v0 = 57;
	TriList_sphereNew[104].v1 = 68;
	TriList_sphereNew[104].v2 = 58;

	TriList_sphereNew[105].v0 = 68;
	TriList_sphereNew[105].v1 = 69;
	TriList_sphereNew[105].v2 = 58;

	TriList_sphereNew[106].v0 = 58;
	TriList_sphereNew[106].v1 = 69;
	TriList_sphereNew[106].v2 = 59;

	TriList_sphereNew[107].v0 = 69;
	TriList_sphereNew[107].v1 = 70;
	TriList_sphereNew[107].v2 = 59;

	TriList_sphereNew[108].v0 = 59;
	TriList_sphereNew[108].v1 = 70;
	TriList_sphereNew[108].v2 = 60;

	TriList_sphereNew[109].v0 = 70;
	TriList_sphereNew[109].v1 = 71;
	TriList_sphereNew[109].v2 = 60;

	TriList_sphereNew[110].v0 = 60;
	TriList_sphereNew[110].v1 = 71;
	TriList_sphereNew[110].v2 = 61;

	TriList_sphereNew[111].v0 = 71;
	TriList_sphereNew[111].v1 = 72;
	TriList_sphereNew[111].v2 = 61;

	TriList_sphereNew[112].v0 = 61;
	TriList_sphereNew[112].v1 = 72;
	TriList_sphereNew[112].v2 = 62;

	TriList_sphereNew[113].v0 = 72;
	TriList_sphereNew[113].v1 = 73;
	TriList_sphereNew[113].v2 = 62;

	TriList_sphereNew[114].v0 = 62;
	TriList_sphereNew[114].v1 = 73;
	TriList_sphereNew[114].v2 = 63;

	TriList_sphereNew[115].v0 = 73;
	TriList_sphereNew[115].v1 = 74;
	TriList_sphereNew[115].v2 = 63;

	TriList_sphereNew[116].v0 = 63;
	TriList_sphereNew[116].v1 = 74;
	TriList_sphereNew[116].v2 = 64;

	TriList_sphereNew[117].v0 = 74;
	TriList_sphereNew[117].v1 = 75;
	TriList_sphereNew[117].v2 = 64;

	TriList_sphereNew[118].v0 = 64;
	TriList_sphereNew[118].v1 = 75;
	TriList_sphereNew[118].v2 = 65;

	TriList_sphereNew[119].v0 = 75;
	TriList_sphereNew[119].v1 = 76;
	TriList_sphereNew[119].v2 = 65;

	TriList_sphereNew[120].v0 = 66;
	TriList_sphereNew[120].v1 = 77;
	TriList_sphereNew[120].v2 = 67;

	TriList_sphereNew[121].v0 = 77;
	TriList_sphereNew[121].v1 = 78;
	TriList_sphereNew[121].v2 = 67;

	TriList_sphereNew[122].v0 = 67;
	TriList_sphereNew[122].v1 = 78;
	TriList_sphereNew[122].v2 = 68;

	TriList_sphereNew[123].v0 = 78;
	TriList_sphereNew[123].v1 = 79;
	TriList_sphereNew[123].v2 = 68;

	TriList_sphereNew[124].v0 = 68;
	TriList_sphereNew[124].v1 = 79;
	TriList_sphereNew[124].v2 = 69;

	TriList_sphereNew[125].v0 = 79;
	TriList_sphereNew[125].v1 = 80;
	TriList_sphereNew[125].v2 = 69;

	TriList_sphereNew[126].v0 = 69;
	TriList_sphereNew[126].v1 = 80;
	TriList_sphereNew[126].v2 = 70;

	TriList_sphereNew[127].v0 = 80;
	TriList_sphereNew[127].v1 = 81;
	TriList_sphereNew[127].v2 = 70;

	TriList_sphereNew[128].v0 = 70;
	TriList_sphereNew[128].v1 = 81;
	TriList_sphereNew[128].v2 = 71;

	TriList_sphereNew[129].v0 = 81;
	TriList_sphereNew[129].v1 = 82;
	TriList_sphereNew[129].v2 = 71;

	TriList_sphereNew[130].v0 = 71;
	TriList_sphereNew[130].v1 = 82;
	TriList_sphereNew[130].v2 = 72;

	TriList_sphereNew[131].v0 = 82;
	TriList_sphereNew[131].v1 = 83;
	TriList_sphereNew[131].v2 = 72;

	TriList_sphereNew[132].v0 = 72;
	TriList_sphereNew[132].v1 = 83;
	TriList_sphereNew[132].v2 = 73;

	TriList_sphereNew[133].v0 = 83;
	TriList_sphereNew[133].v1 = 84;
	TriList_sphereNew[133].v2 = 73;

	TriList_sphereNew[134].v0 = 73;
	TriList_sphereNew[134].v1 = 84;
	TriList_sphereNew[134].v2 = 74;

	TriList_sphereNew[135].v0 = 84;
	TriList_sphereNew[135].v1 = 85;
	TriList_sphereNew[135].v2 = 74;

	TriList_sphereNew[136].v0 = 74;
	TriList_sphereNew[136].v1 = 85;
	TriList_sphereNew[136].v2 = 75;

	TriList_sphereNew[137].v0 = 85;
	TriList_sphereNew[137].v1 = 86;
	TriList_sphereNew[137].v2 = 75;

	TriList_sphereNew[138].v0 = 75;
	TriList_sphereNew[138].v1 = 86;
	TriList_sphereNew[138].v2 = 76;

	TriList_sphereNew[139].v0 = 86;
	TriList_sphereNew[139].v1 = 87;
	TriList_sphereNew[139].v2 = 76;

	TriList_sphereNew[140].v0 = 77;
	TriList_sphereNew[140].v1 = 88;
	TriList_sphereNew[140].v2 = 78;

	TriList_sphereNew[141].v0 = 88;
	TriList_sphereNew[141].v1 = 89;
	TriList_sphereNew[141].v2 = 78;

	TriList_sphereNew[142].v0 = 78;
	TriList_sphereNew[142].v1 = 89;
	TriList_sphereNew[142].v2 = 79;

	TriList_sphereNew[143].v0 = 89;
	TriList_sphereNew[143].v1 = 90;
	TriList_sphereNew[143].v2 = 79;

	TriList_sphereNew[144].v0 = 79;
	TriList_sphereNew[144].v1 = 90;
	TriList_sphereNew[144].v2 = 80;

	TriList_sphereNew[145].v0 = 90;
	TriList_sphereNew[145].v1 = 91;
	TriList_sphereNew[145].v2 = 80;

	TriList_sphereNew[146].v0 = 80;
	TriList_sphereNew[146].v1 = 91;
	TriList_sphereNew[146].v2 = 81;

	TriList_sphereNew[147].v0 = 91;
	TriList_sphereNew[147].v1 = 92;
	TriList_sphereNew[147].v2 = 81;

	TriList_sphereNew[148].v0 = 81;
	TriList_sphereNew[148].v1 = 92;
	TriList_sphereNew[148].v2 = 82;

	TriList_sphereNew[149].v0 = 92;
	TriList_sphereNew[149].v1 = 93;
	TriList_sphereNew[149].v2 = 82;

	TriList_sphereNew[150].v0 = 82;
	TriList_sphereNew[150].v1 = 93;
	TriList_sphereNew[150].v2 = 83;

	TriList_sphereNew[151].v0 = 93;
	TriList_sphereNew[151].v1 = 94;
	TriList_sphereNew[151].v2 = 83;

	TriList_sphereNew[152].v0 = 83;
	TriList_sphereNew[152].v1 = 94;
	TriList_sphereNew[152].v2 = 84;

	TriList_sphereNew[153].v0 = 94;
	TriList_sphereNew[153].v1 = 95;
	TriList_sphereNew[153].v2 = 84;

	TriList_sphereNew[154].v0 = 84;
	TriList_sphereNew[154].v1 = 95;
	TriList_sphereNew[154].v2 = 85;

	TriList_sphereNew[155].v0 = 95;
	TriList_sphereNew[155].v1 = 96;
	TriList_sphereNew[155].v2 = 85;

	TriList_sphereNew[156].v0 = 85;
	TriList_sphereNew[156].v1 = 96;
	TriList_sphereNew[156].v2 = 86;

	TriList_sphereNew[157].v0 = 96;
	TriList_sphereNew[157].v1 = 97;
	TriList_sphereNew[157].v2 = 86;

	TriList_sphereNew[158].v0 = 86;
	TriList_sphereNew[158].v1 = 97;
	TriList_sphereNew[158].v2 = 87;

	TriList_sphereNew[159].v0 = 97;
	TriList_sphereNew[159].v1 = 98;
	TriList_sphereNew[159].v2 = 87;

	TriList_sphereNew[160].v0 = 88;
	TriList_sphereNew[160].v1 = 99;
	TriList_sphereNew[160].v2 = 89;

	TriList_sphereNew[161].v0 = 99;
	TriList_sphereNew[161].v1 = 100;
	TriList_sphereNew[161].v2 = 89;

	TriList_sphereNew[162].v0 = 89;
	TriList_sphereNew[162].v1 = 100;
	TriList_sphereNew[162].v2 = 90;

	TriList_sphereNew[163].v0 = 100;
	TriList_sphereNew[163].v1 = 101;
	TriList_sphereNew[163].v2 = 90;

	TriList_sphereNew[164].v0 = 90;
	TriList_sphereNew[164].v1 = 101;
	TriList_sphereNew[164].v2 = 91;

	TriList_sphereNew[165].v0 = 101;
	TriList_sphereNew[165].v1 = 102;
	TriList_sphereNew[165].v2 = 91;

	TriList_sphereNew[166].v0 = 91;
	TriList_sphereNew[166].v1 = 102;
	TriList_sphereNew[166].v2 = 92;

	TriList_sphereNew[167].v0 = 102;
	TriList_sphereNew[167].v1 = 103;
	TriList_sphereNew[167].v2 = 92;

	TriList_sphereNew[168].v0 = 92;
	TriList_sphereNew[168].v1 = 103;
	TriList_sphereNew[168].v2 = 93;

	TriList_sphereNew[169].v0 = 103;
	TriList_sphereNew[169].v1 = 104;
	TriList_sphereNew[169].v2 = 93;

	TriList_sphereNew[170].v0 = 93;
	TriList_sphereNew[170].v1 = 104;
	TriList_sphereNew[170].v2 = 94;

	TriList_sphereNew[171].v0 = 104;
	TriList_sphereNew[171].v1 = 105;
	TriList_sphereNew[171].v2 = 94;

	TriList_sphereNew[172].v0 = 94;
	TriList_sphereNew[172].v1 = 105;
	TriList_sphereNew[172].v2 = 95;

	TriList_sphereNew[173].v0 = 105;
	TriList_sphereNew[173].v1 = 106;
	TriList_sphereNew[173].v2 = 95;

	TriList_sphereNew[174].v0 = 95;
	TriList_sphereNew[174].v1 = 106;
	TriList_sphereNew[174].v2 = 96;

	TriList_sphereNew[175].v0 = 106;
	TriList_sphereNew[175].v1 = 107;
	TriList_sphereNew[175].v2 = 96;

	TriList_sphereNew[176].v0 = 96;
	TriList_sphereNew[176].v1 = 107;
	TriList_sphereNew[176].v2 = 97;

	TriList_sphereNew[177].v0 = 107;
	TriList_sphereNew[177].v1 = 108;
	TriList_sphereNew[177].v2 = 97;

	TriList_sphereNew[178].v0 = 97;
	TriList_sphereNew[178].v1 = 108;
	TriList_sphereNew[178].v2 = 98;

	TriList_sphereNew[179].v0 = 108;
	TriList_sphereNew[179].v1 = 109;
	TriList_sphereNew[179].v2 = 98;

	TriList_sphereNew[180].v0 = 99;
	TriList_sphereNew[180].v1 = 110;
	TriList_sphereNew[180].v2 = 100;

	TriList_sphereNew[181].v0 = 110;
	TriList_sphereNew[181].v1 = 111;
	TriList_sphereNew[181].v2 = 100;

	TriList_sphereNew[182].v0 = 100;
	TriList_sphereNew[182].v1 = 111;
	TriList_sphereNew[182].v2 = 101;

	TriList_sphereNew[183].v0 = 111;
	TriList_sphereNew[183].v1 = 112;
	TriList_sphereNew[183].v2 = 101;

	TriList_sphereNew[184].v0 = 101;
	TriList_sphereNew[184].v1 = 112;
	TriList_sphereNew[184].v2 = 102;

	TriList_sphereNew[185].v0 = 112;
	TriList_sphereNew[185].v1 = 113;
	TriList_sphereNew[185].v2 = 102;

	TriList_sphereNew[186].v0 = 102;
	TriList_sphereNew[186].v1 = 113;
	TriList_sphereNew[186].v2 = 103;

	TriList_sphereNew[187].v0 = 113;
	TriList_sphereNew[187].v1 = 114;
	TriList_sphereNew[187].v2 = 103;

	TriList_sphereNew[188].v0 = 103;
	TriList_sphereNew[188].v1 = 114;
	TriList_sphereNew[188].v2 = 104;

	TriList_sphereNew[189].v0 = 114;
	TriList_sphereNew[189].v1 = 115;
	TriList_sphereNew[189].v2 = 104;

	TriList_sphereNew[190].v0 = 104;
	TriList_sphereNew[190].v1 = 115;
	TriList_sphereNew[190].v2 = 105;

	TriList_sphereNew[191].v0 = 115;
	TriList_sphereNew[191].v1 = 116;
	TriList_sphereNew[191].v2 = 105;

	TriList_sphereNew[192].v0 = 105;
	TriList_sphereNew[192].v1 = 116;
	TriList_sphereNew[192].v2 = 106;

	TriList_sphereNew[193].v0 = 116;
	TriList_sphereNew[193].v1 = 117;
	TriList_sphereNew[193].v2 = 106;

	TriList_sphereNew[194].v0 = 106;
	TriList_sphereNew[194].v1 = 117;
	TriList_sphereNew[194].v2 = 107;

	TriList_sphereNew[195].v0 = 117;
	TriList_sphereNew[195].v1 = 118;
	TriList_sphereNew[195].v2 = 107;

	TriList_sphereNew[196].v0 = 107;
	TriList_sphereNew[196].v1 = 118;
	TriList_sphereNew[196].v2 = 108;

	TriList_sphereNew[197].v0 = 118;
	TriList_sphereNew[197].v1 = 119;
	TriList_sphereNew[197].v2 = 108;

	TriList_sphereNew[198].v0 = 108;
	TriList_sphereNew[198].v1 = 119;
	TriList_sphereNew[198].v2 = 109;

	TriList_sphereNew[199].v0 = 119;
	TriList_sphereNew[199].v1 = 120;
	TriList_sphereNew[199].v2 = 109;






	Vertices_sphereNew[0].x = -0.000000f;
	Vertices_sphereNew[0].y = 0.000000f;
	Vertices_sphereNew[0].z = 0.500000f;
	Vertices_sphereNew[0].nx = -0.000000f;
	Vertices_sphereNew[0].ny = 0.000000f;
	Vertices_sphereNew[0].nz = 1.000000f;
	Vertices_sphereNew[0].u = 0.000000f;
	Vertices_sphereNew[0].v = 1.000000f;

	Vertices_sphereNew[1].x = -0.000000f;
	Vertices_sphereNew[1].y = 0.154509f;
	Vertices_sphereNew[1].z = 0.475528f;
	Vertices_sphereNew[1].nx = -0.000000f;
	Vertices_sphereNew[1].ny = 0.309017f;
	Vertices_sphereNew[1].nz = 0.951057f;
	Vertices_sphereNew[1].u = 0.000000f;
	Vertices_sphereNew[1].v = 0.900000f;

	Vertices_sphereNew[2].x = -0.000000f;
	Vertices_sphereNew[2].y = 0.000000f;
	Vertices_sphereNew[2].z = 0.500000f;
	Vertices_sphereNew[2].nx = -0.000000f;
	Vertices_sphereNew[2].ny = 0.000000f;
	Vertices_sphereNew[2].nz = 1.000000f;
	Vertices_sphereNew[2].u = 0.100000f;
	Vertices_sphereNew[2].v = 1.000000f;

	Vertices_sphereNew[3].x = -0.090818f;
	Vertices_sphereNew[3].y = 0.125000f;
	Vertices_sphereNew[3].z = 0.475528f;
	Vertices_sphereNew[3].nx = -0.181636f;
	Vertices_sphereNew[3].ny = 0.250000f;
	Vertices_sphereNew[3].nz = 0.951057f;
	Vertices_sphereNew[3].u = 0.100000f;
	Vertices_sphereNew[3].v = 0.900000f;

	Vertices_sphereNew[4].x = -0.000000f;
	Vertices_sphereNew[4].y = 0.000000f;
	Vertices_sphereNew[4].z = 0.500000f;
	Vertices_sphereNew[4].nx = -0.000000f;
	Vertices_sphereNew[4].ny = 0.000000f;
	Vertices_sphereNew[4].nz = 1.000000f;
	Vertices_sphereNew[4].u = 0.200000f;
	Vertices_sphereNew[4].v = 1.000000f;

	Vertices_sphereNew[5].x = -0.146946f;
	Vertices_sphereNew[5].y = 0.047746f;
	Vertices_sphereNew[5].z = 0.475528f;
	Vertices_sphereNew[5].nx = -0.293893f;
	Vertices_sphereNew[5].ny = 0.095491f;
	Vertices_sphereNew[5].nz = 0.951057f;
	Vertices_sphereNew[5].u = 0.200000f;
	Vertices_sphereNew[5].v = 0.900000f;

	Vertices_sphereNew[6].x = -0.000000f;
	Vertices_sphereNew[6].y = -0.000000f;
	Vertices_sphereNew[6].z = 0.500000f;
	Vertices_sphereNew[6].nx = -0.000000f;
	Vertices_sphereNew[6].ny = -0.000000f;
	Vertices_sphereNew[6].nz = 1.000000f;
	Vertices_sphereNew[6].u = 0.300000f;
	Vertices_sphereNew[6].v = 1.000000f;

	Vertices_sphereNew[7].x = -0.146946f;
	Vertices_sphereNew[7].y = -0.047746f;
	Vertices_sphereNew[7].z = 0.475528f;
	Vertices_sphereNew[7].nx = -0.293893f;
	Vertices_sphereNew[7].ny = -0.095492f;
	Vertices_sphereNew[7].nz = 0.951057f;
	Vertices_sphereNew[7].u = 0.300000f;
	Vertices_sphereNew[7].v = 0.900000f;

	Vertices_sphereNew[8].x = -0.000000f;
	Vertices_sphereNew[8].y = -0.000000f;
	Vertices_sphereNew[8].z = 0.500000f;
	Vertices_sphereNew[8].nx = -0.000000f;
	Vertices_sphereNew[8].ny = -0.000000f;
	Vertices_sphereNew[8].nz = 1.000000f;
	Vertices_sphereNew[8].u = 0.400000f;
	Vertices_sphereNew[8].v = 1.000000f;

	Vertices_sphereNew[9].x = -0.090818f;
	Vertices_sphereNew[9].y = -0.125000f;
	Vertices_sphereNew[9].z = 0.475528f;
	Vertices_sphereNew[9].nx = -0.181636f;
	Vertices_sphereNew[9].ny = -0.250000f;
	Vertices_sphereNew[9].nz = 0.951057f;
	Vertices_sphereNew[9].u = 0.400000f;
	Vertices_sphereNew[9].v = 0.900000f;

	Vertices_sphereNew[10].x = 0.000000f;
	Vertices_sphereNew[10].y = -0.000000f;
	Vertices_sphereNew[10].z = 0.500000f;
	Vertices_sphereNew[10].nx = 0.000000f;
	Vertices_sphereNew[10].ny = -0.000000f;
	Vertices_sphereNew[10].nz = 1.000000f;
	Vertices_sphereNew[10].u = 0.500000f;
	Vertices_sphereNew[10].v = 1.000000f;

	Vertices_sphereNew[11].x = 0.000000f;
	Vertices_sphereNew[11].y = -0.154509f;
	Vertices_sphereNew[11].z = 0.475528f;
	Vertices_sphereNew[11].nx = 0.000000f;
	Vertices_sphereNew[11].ny = -0.309017f;
	Vertices_sphereNew[11].nz = 0.951057f;
	Vertices_sphereNew[11].u = 0.500000f;
	Vertices_sphereNew[11].v = 0.900000f;

	Vertices_sphereNew[12].x = 0.000000f;
	Vertices_sphereNew[12].y = -0.000000f;
	Vertices_sphereNew[12].z = 0.500000f;
	Vertices_sphereNew[12].nx = 0.000000f;
	Vertices_sphereNew[12].ny = -0.000000f;
	Vertices_sphereNew[12].nz = 1.000000f;
	Vertices_sphereNew[12].u = 0.600000f;
	Vertices_sphereNew[12].v = 1.000000f;

	Vertices_sphereNew[13].x = 0.090818f;
	Vertices_sphereNew[13].y = -0.125000f;
	Vertices_sphereNew[13].z = 0.475528f;
	Vertices_sphereNew[13].nx = 0.181636f;
	Vertices_sphereNew[13].ny = -0.250000f;
	Vertices_sphereNew[13].nz = 0.951057f;
	Vertices_sphereNew[13].u = 0.600000f;
	Vertices_sphereNew[13].v = 0.900000f;

	Vertices_sphereNew[14].x = 0.000000f;
	Vertices_sphereNew[14].y = -0.000000f;
	Vertices_sphereNew[14].z = 0.500000f;
	Vertices_sphereNew[14].nx = 0.000000f;
	Vertices_sphereNew[14].ny = -0.000000f;
	Vertices_sphereNew[14].nz = 1.000000f;
	Vertices_sphereNew[14].u = 0.700000f;
	Vertices_sphereNew[14].v = 1.000000f;

	Vertices_sphereNew[15].x = 0.146946f;
	Vertices_sphereNew[15].y = -0.047746f;
	Vertices_sphereNew[15].z = 0.475528f;
	Vertices_sphereNew[15].nx = 0.293893f;
	Vertices_sphereNew[15].ny = -0.095492f;
	Vertices_sphereNew[15].nz = 0.951057f;
	Vertices_sphereNew[15].u = 0.700000f;
	Vertices_sphereNew[15].v = 0.900000f;

	Vertices_sphereNew[16].x = 0.000000f;
	Vertices_sphereNew[16].y = 0.000000f;
	Vertices_sphereNew[16].z = 0.500000f;
	Vertices_sphereNew[16].nx = 0.000000f;
	Vertices_sphereNew[16].ny = 0.000000f;
	Vertices_sphereNew[16].nz = 1.000000f;
	Vertices_sphereNew[16].u = 0.800000f;
	Vertices_sphereNew[16].v = 1.000000f;

	Vertices_sphereNew[17].x = 0.146946f;
	Vertices_sphereNew[17].y = 0.047746f;
	Vertices_sphereNew[17].z = 0.475528f;
	Vertices_sphereNew[17].nx = 0.293893f;
	Vertices_sphereNew[17].ny = 0.095492f;
	Vertices_sphereNew[17].nz = 0.951057f;
	Vertices_sphereNew[17].u = 0.800000f;
	Vertices_sphereNew[17].v = 0.900000f;

	Vertices_sphereNew[18].x = 0.000000f;
	Vertices_sphereNew[18].y = 0.000000f;
	Vertices_sphereNew[18].z = 0.500000f;
	Vertices_sphereNew[18].nx = 0.000000f;
	Vertices_sphereNew[18].ny = 0.000000f;
	Vertices_sphereNew[18].nz = 1.000000f;
	Vertices_sphereNew[18].u = 0.900000f;
	Vertices_sphereNew[18].v = 1.000000f;

	Vertices_sphereNew[19].x = 0.090818f;
	Vertices_sphereNew[19].y = 0.125000f;
	Vertices_sphereNew[19].z = 0.475528f;
	Vertices_sphereNew[19].nx = 0.181636f;
	Vertices_sphereNew[19].ny = 0.250000f;
	Vertices_sphereNew[19].nz = 0.951057f;
	Vertices_sphereNew[19].u = 0.900000f;
	Vertices_sphereNew[19].v = 0.900000f;

	Vertices_sphereNew[20].x = -0.000000f;
	Vertices_sphereNew[20].y = 0.000000f;
	Vertices_sphereNew[20].z = 0.500000f;
	Vertices_sphereNew[20].nx = -0.000000f;
	Vertices_sphereNew[20].ny = 0.000000f;
	Vertices_sphereNew[20].nz = 1.000000f;
	Vertices_sphereNew[20].u = 1.000000f;
	Vertices_sphereNew[20].v = 1.000000f;

	Vertices_sphereNew[21].x = -0.000000f;
	Vertices_sphereNew[21].y = 0.154509f;
	Vertices_sphereNew[21].z = 0.475528f;
	Vertices_sphereNew[21].nx = -0.000000f;
	Vertices_sphereNew[21].ny = 0.309017f;
	Vertices_sphereNew[21].nz = 0.951057f;
	Vertices_sphereNew[21].u = 1.000000f;
	Vertices_sphereNew[21].v = 0.900000f;

	Vertices_sphereNew[22].x = -0.000000f;
	Vertices_sphereNew[22].y = 0.293893f;
	Vertices_sphereNew[22].z = 0.404509f;
	Vertices_sphereNew[22].nx = -0.000000f;
	Vertices_sphereNew[22].ny = 0.587785f;
	Vertices_sphereNew[22].nz = 0.809017f;
	Vertices_sphereNew[22].u = 0.000000f;
	Vertices_sphereNew[22].v = 0.800000f;

	Vertices_sphereNew[23].x = -0.172746f;
	Vertices_sphereNew[23].y = 0.237764f;
	Vertices_sphereNew[23].z = 0.404509f;
	Vertices_sphereNew[23].nx = -0.345491f;
	Vertices_sphereNew[23].ny = 0.475528f;
	Vertices_sphereNew[23].nz = 0.809017f;
	Vertices_sphereNew[23].u = 0.100000f;
	Vertices_sphereNew[23].v = 0.800000f;

	Vertices_sphereNew[24].x = -0.279509f;
	Vertices_sphereNew[24].y = 0.090818f;
	Vertices_sphereNew[24].z = 0.404509f;
	Vertices_sphereNew[24].nx = -0.559017f;
	Vertices_sphereNew[24].ny = 0.181636f;
	Vertices_sphereNew[24].nz = 0.809017f;
	Vertices_sphereNew[24].u = 0.200000f;
	Vertices_sphereNew[24].v = 0.800000f;

	Vertices_sphereNew[25].x = -0.279508f;
	Vertices_sphereNew[25].y = -0.090818f;
	Vertices_sphereNew[25].z = 0.404509f;
	Vertices_sphereNew[25].nx = -0.559017f;
	Vertices_sphereNew[25].ny = -0.181636f;
	Vertices_sphereNew[25].nz = 0.809017f;
	Vertices_sphereNew[25].u = 0.300000f;
	Vertices_sphereNew[25].v = 0.800000f;

	Vertices_sphereNew[26].x = -0.172746f;
	Vertices_sphereNew[26].y = -0.237764f;
	Vertices_sphereNew[26].z = 0.404509f;
	Vertices_sphereNew[26].nx = -0.345491f;
	Vertices_sphereNew[26].ny = -0.475528f;
	Vertices_sphereNew[26].nz = 0.809017f;
	Vertices_sphereNew[26].u = 0.400000f;
	Vertices_sphereNew[26].v = 0.800000f;

	Vertices_sphereNew[27].x = 0.000000f;
	Vertices_sphereNew[27].y = -0.293893f;
	Vertices_sphereNew[27].z = 0.404509f;
	Vertices_sphereNew[27].nx = 0.000000f;
	Vertices_sphereNew[27].ny = -0.587785f;
	Vertices_sphereNew[27].nz = 0.809017f;
	Vertices_sphereNew[27].u = 0.500000f;
	Vertices_sphereNew[27].v = 0.800000f;

	Vertices_sphereNew[28].x = 0.172746f;
	Vertices_sphereNew[28].y = -0.237764f;
	Vertices_sphereNew[28].z = 0.404509f;
	Vertices_sphereNew[28].nx = 0.345492f;
	Vertices_sphereNew[28].ny = -0.475528f;
	Vertices_sphereNew[28].nz = 0.809017f;
	Vertices_sphereNew[28].u = 0.600000f;
	Vertices_sphereNew[28].v = 0.800000f;

	Vertices_sphereNew[29].x = 0.279508f;
	Vertices_sphereNew[29].y = -0.090818f;
	Vertices_sphereNew[29].z = 0.404509f;
	Vertices_sphereNew[29].nx = 0.559017f;
	Vertices_sphereNew[29].ny = -0.181636f;
	Vertices_sphereNew[29].nz = 0.809017f;
	Vertices_sphereNew[29].u = 0.700000f;
	Vertices_sphereNew[29].v = 0.800000f;

	Vertices_sphereNew[30].x = 0.279508f;
	Vertices_sphereNew[30].y = 0.090818f;
	Vertices_sphereNew[30].z = 0.404509f;
	Vertices_sphereNew[30].nx = 0.559017f;
	Vertices_sphereNew[30].ny = 0.181636f;
	Vertices_sphereNew[30].nz = 0.809017f;
	Vertices_sphereNew[30].u = 0.800000f;
	Vertices_sphereNew[30].v = 0.800000f;

	Vertices_sphereNew[31].x = 0.172746f;
	Vertices_sphereNew[31].y = 0.237764f;
	Vertices_sphereNew[31].z = 0.404509f;
	Vertices_sphereNew[31].nx = 0.345491f;
	Vertices_sphereNew[31].ny = 0.475528f;
	Vertices_sphereNew[31].nz = 0.809017f;
	Vertices_sphereNew[31].u = 0.900000f;
	Vertices_sphereNew[31].v = 0.800000f;

	Vertices_sphereNew[32].x = -0.000000f;
	Vertices_sphereNew[32].y = 0.293893f;
	Vertices_sphereNew[32].z = 0.404509f;
	Vertices_sphereNew[32].nx = -0.000000f;
	Vertices_sphereNew[32].ny = 0.587785f;
	Vertices_sphereNew[32].nz = 0.809017f;
	Vertices_sphereNew[32].u = 1.000000f;
	Vertices_sphereNew[32].v = 0.800000f;

	Vertices_sphereNew[33].x = -0.000000f;
	Vertices_sphereNew[33].y = 0.404509f;
	Vertices_sphereNew[33].z = 0.293893f;
	Vertices_sphereNew[33].nx = -0.000000f;
	Vertices_sphereNew[33].ny = 0.809017f;
	Vertices_sphereNew[33].nz = 0.587785f;
	Vertices_sphereNew[33].u = 0.000000f;
	Vertices_sphereNew[33].v = 0.700000f;

	Vertices_sphereNew[34].x = -0.237764f;
	Vertices_sphereNew[34].y = 0.327254f;
	Vertices_sphereNew[34].z = 0.293893f;
	Vertices_sphereNew[34].nx = -0.475528f;
	Vertices_sphereNew[34].ny = 0.654509f;
	Vertices_sphereNew[34].nz = 0.587785f;
	Vertices_sphereNew[34].u = 0.100000f;
	Vertices_sphereNew[34].v = 0.700000f;

	Vertices_sphereNew[35].x = -0.384710f;
	Vertices_sphereNew[35].y = 0.125000f;
	Vertices_sphereNew[35].z = 0.293893f;
	Vertices_sphereNew[35].nx = -0.769421f;
	Vertices_sphereNew[35].ny = 0.250000f;
	Vertices_sphereNew[35].nz = 0.587785f;
	Vertices_sphereNew[35].u = 0.200000f;
	Vertices_sphereNew[35].v = 0.700000f;

	Vertices_sphereNew[36].x = -0.384710f;
	Vertices_sphereNew[36].y = -0.125000f;
	Vertices_sphereNew[36].z = 0.293893f;
	Vertices_sphereNew[36].nx = -0.769421f;
	Vertices_sphereNew[36].ny = -0.250000f;
	Vertices_sphereNew[36].nz = 0.587785f;
	Vertices_sphereNew[36].u = 0.300000f;
	Vertices_sphereNew[36].v = 0.700000f;

	Vertices_sphereNew[37].x = -0.237764f;
	Vertices_sphereNew[37].y = -0.327254f;
	Vertices_sphereNew[37].z = 0.293893f;
	Vertices_sphereNew[37].nx = -0.475528f;
	Vertices_sphereNew[37].ny = -0.654509f;
	Vertices_sphereNew[37].nz = 0.587785f;
	Vertices_sphereNew[37].u = 0.400000f;
	Vertices_sphereNew[37].v = 0.700000f;

	Vertices_sphereNew[38].x = 0.000000f;
	Vertices_sphereNew[38].y = -0.404509f;
	Vertices_sphereNew[38].z = 0.293893f;
	Vertices_sphereNew[38].nx = 0.000000f;
	Vertices_sphereNew[38].ny = -0.809017f;
	Vertices_sphereNew[38].nz = 0.587785f;
	Vertices_sphereNew[38].u = 0.500000f;
	Vertices_sphereNew[38].v = 0.700000f;

	Vertices_sphereNew[39].x = 0.237764f;
	Vertices_sphereNew[39].y = -0.327254f;
	Vertices_sphereNew[39].z = 0.293893f;
	Vertices_sphereNew[39].nx = 0.475528f;
	Vertices_sphereNew[39].ny = -0.654508f;
	Vertices_sphereNew[39].nz = 0.587785f;
	Vertices_sphereNew[39].u = 0.600000f;
	Vertices_sphereNew[39].v = 0.700000f;

	Vertices_sphereNew[40].x = 0.384710f;
	Vertices_sphereNew[40].y = -0.125000f;
	Vertices_sphereNew[40].z = 0.293893f;
	Vertices_sphereNew[40].nx = 0.769421f;
	Vertices_sphereNew[40].ny = -0.250000f;
	Vertices_sphereNew[40].nz = 0.587785f;
	Vertices_sphereNew[40].u = 0.700000f;
	Vertices_sphereNew[40].v = 0.700000f;

	Vertices_sphereNew[41].x = 0.384710f;
	Vertices_sphereNew[41].y = 0.125000f;
	Vertices_sphereNew[41].z = 0.293893f;
	Vertices_sphereNew[41].nx = 0.769421f;
	Vertices_sphereNew[41].ny = 0.250000f;
	Vertices_sphereNew[41].nz = 0.587785f;
	Vertices_sphereNew[41].u = 0.800000f;
	Vertices_sphereNew[41].v = 0.700000f;

	Vertices_sphereNew[42].x = 0.237764f;
	Vertices_sphereNew[42].y = 0.327254f;
	Vertices_sphereNew[42].z = 0.293893f;
	Vertices_sphereNew[42].nx = 0.475528f;
	Vertices_sphereNew[42].ny = 0.654509f;
	Vertices_sphereNew[42].nz = 0.587785f;
	Vertices_sphereNew[42].u = 0.900000f;
	Vertices_sphereNew[42].v = 0.700000f;

	Vertices_sphereNew[43].x = -0.000000f;
	Vertices_sphereNew[43].y = 0.404509f;
	Vertices_sphereNew[43].z = 0.293893f;
	Vertices_sphereNew[43].nx = -0.000000f;
	Vertices_sphereNew[43].ny = 0.809017f;
	Vertices_sphereNew[43].nz = 0.587785f;
	Vertices_sphereNew[43].u = 1.000000f;
	Vertices_sphereNew[43].v = 0.700000f;

	Vertices_sphereNew[44].x = -0.000000f;
	Vertices_sphereNew[44].y = 0.475528f;
	Vertices_sphereNew[44].z = 0.154508f;
	Vertices_sphereNew[44].nx = -0.000000f;
	Vertices_sphereNew[44].ny = 0.951057f;
	Vertices_sphereNew[44].nz = 0.309017f;
	Vertices_sphereNew[44].u = 0.000000f;
	Vertices_sphereNew[44].v = 0.600000f;

	Vertices_sphereNew[45].x = -0.279509f;
	Vertices_sphereNew[45].y = 0.384710f;
	Vertices_sphereNew[45].z = 0.154508f;
	Vertices_sphereNew[45].nx = -0.559017f;
	Vertices_sphereNew[45].ny = 0.769421f;
	Vertices_sphereNew[45].nz = 0.309017f;
	Vertices_sphereNew[45].u = 0.100000f;
	Vertices_sphereNew[45].v = 0.600000f;

	Vertices_sphereNew[46].x = -0.452254f;
	Vertices_sphereNew[46].y = 0.146946f;
	Vertices_sphereNew[46].z = 0.154508f;
	Vertices_sphereNew[46].nx = -0.904509f;
	Vertices_sphereNew[46].ny = 0.293893f;
	Vertices_sphereNew[46].nz = 0.309017f;
	Vertices_sphereNew[46].u = 0.200000f;
	Vertices_sphereNew[46].v = 0.600000f;

	Vertices_sphereNew[47].x = -0.452254f;
	Vertices_sphereNew[47].y = -0.146946f;
	Vertices_sphereNew[47].z = 0.154508f;
	Vertices_sphereNew[47].nx = -0.904508f;
	Vertices_sphereNew[47].ny = -0.293893f;
	Vertices_sphereNew[47].nz = 0.309017f;
	Vertices_sphereNew[47].u = 0.300000f;
	Vertices_sphereNew[47].v = 0.600000f;

	Vertices_sphereNew[48].x = -0.279508f;
	Vertices_sphereNew[48].y = -0.384710f;
	Vertices_sphereNew[48].z = 0.154508f;
	Vertices_sphereNew[48].nx = -0.559017f;
	Vertices_sphereNew[48].ny = -0.769421f;
	Vertices_sphereNew[48].nz = 0.309017f;
	Vertices_sphereNew[48].u = 0.400000f;
	Vertices_sphereNew[48].v = 0.600000f;

	Vertices_sphereNew[49].x = 0.000000f;
	Vertices_sphereNew[49].y = -0.475528f;
	Vertices_sphereNew[49].z = 0.154508f;
	Vertices_sphereNew[49].nx = 0.000000f;
	Vertices_sphereNew[49].ny = -0.951057f;
	Vertices_sphereNew[49].nz = 0.309017f;
	Vertices_sphereNew[49].u = 0.500000f;
	Vertices_sphereNew[49].v = 0.600000f;

	Vertices_sphereNew[50].x = 0.279509f;
	Vertices_sphereNew[50].y = -0.384710f;
	Vertices_sphereNew[50].z = 0.154508f;
	Vertices_sphereNew[50].nx = 0.559017f;
	Vertices_sphereNew[50].ny = -0.769421f;
	Vertices_sphereNew[50].nz = 0.309017f;
	Vertices_sphereNew[50].u = 0.600000f;
	Vertices_sphereNew[50].v = 0.600000f;

	Vertices_sphereNew[51].x = 0.452254f;
	Vertices_sphereNew[51].y = -0.146946f;
	Vertices_sphereNew[51].z = 0.154508f;
	Vertices_sphereNew[51].nx = 0.904508f;
	Vertices_sphereNew[51].ny = -0.293893f;
	Vertices_sphereNew[51].nz = 0.309017f;
	Vertices_sphereNew[51].u = 0.700000f;
	Vertices_sphereNew[51].v = 0.600000f;

	Vertices_sphereNew[52].x = 0.452254f;
	Vertices_sphereNew[52].y = 0.146946f;
	Vertices_sphereNew[52].z = 0.154508f;
	Vertices_sphereNew[52].nx = 0.904508f;
	Vertices_sphereNew[52].ny = 0.293893f;
	Vertices_sphereNew[52].nz = 0.309017f;
	Vertices_sphereNew[52].u = 0.800000f;
	Vertices_sphereNew[52].v = 0.600000f;

	Vertices_sphereNew[53].x = 0.279508f;
	Vertices_sphereNew[53].y = 0.384711f;
	Vertices_sphereNew[53].z = 0.154508f;
	Vertices_sphereNew[53].nx = 0.559017f;
	Vertices_sphereNew[53].ny = 0.769421f;
	Vertices_sphereNew[53].nz = 0.309017f;
	Vertices_sphereNew[53].u = 0.900000f;
	Vertices_sphereNew[53].v = 0.600000f;

	Vertices_sphereNew[54].x = -0.000000f;
	Vertices_sphereNew[54].y = 0.475528f;
	Vertices_sphereNew[54].z = 0.154508f;
	Vertices_sphereNew[54].nx = -0.000000f;
	Vertices_sphereNew[54].ny = 0.951057f;
	Vertices_sphereNew[54].nz = 0.309017f;
	Vertices_sphereNew[54].u = 1.000000f;
	Vertices_sphereNew[54].v = 0.600000f;

	Vertices_sphereNew[55].x = -0.000000f;
	Vertices_sphereNew[55].y = 0.500000f;
	Vertices_sphereNew[55].z = -0.000000f;
	Vertices_sphereNew[55].nx = -0.000000f;
	Vertices_sphereNew[55].ny = 1.000000f;
	Vertices_sphereNew[55].nz = -0.000000f;
	Vertices_sphereNew[55].u = 0.000000f;
	Vertices_sphereNew[55].v = 0.500000f;

	Vertices_sphereNew[56].x = -0.293893f;
	Vertices_sphereNew[56].y = 0.404509f;
	Vertices_sphereNew[56].z = -0.000000f;
	Vertices_sphereNew[56].nx = -0.587785f;
	Vertices_sphereNew[56].ny = 0.809017f;
	Vertices_sphereNew[56].nz = -0.000000f;
	Vertices_sphereNew[56].u = 0.100000f;
	Vertices_sphereNew[56].v = 0.500000f;

	Vertices_sphereNew[57].x = -0.475528f;
	Vertices_sphereNew[57].y = 0.154508f;
	Vertices_sphereNew[57].z = -0.000000f;
	Vertices_sphereNew[57].nx = -0.951057f;
	Vertices_sphereNew[57].ny = 0.309017f;
	Vertices_sphereNew[57].nz = -0.000000f;
	Vertices_sphereNew[57].u = 0.200000f;
	Vertices_sphereNew[57].v = 0.500000f;

	Vertices_sphereNew[58].x = -0.475528f;
	Vertices_sphereNew[58].y = -0.154509f;
	Vertices_sphereNew[58].z = -0.000000f;
	Vertices_sphereNew[58].nx = -0.951057f;
	Vertices_sphereNew[58].ny = -0.309017f;
	Vertices_sphereNew[58].nz = -0.000000f;
	Vertices_sphereNew[58].u = 0.300000f;
	Vertices_sphereNew[58].v = 0.500000f;

	Vertices_sphereNew[59].x = -0.293893f;
	Vertices_sphereNew[59].y = -0.404509f;
	Vertices_sphereNew[59].z = -0.000000f;
	Vertices_sphereNew[59].nx = -0.587785f;
	Vertices_sphereNew[59].ny = -0.809017f;
	Vertices_sphereNew[59].nz = -0.000000f;
	Vertices_sphereNew[59].u = 0.400000f;
	Vertices_sphereNew[59].v = 0.500000f;

	Vertices_sphereNew[60].x = 0.000000f;
	Vertices_sphereNew[60].y = -0.500000f;
	Vertices_sphereNew[60].z = -0.000000f;
	Vertices_sphereNew[60].nx = 0.000000f;
	Vertices_sphereNew[60].ny = -1.000000f;
	Vertices_sphereNew[60].nz = -0.000000f;
	Vertices_sphereNew[60].u = 0.500000f;
	Vertices_sphereNew[60].v = 0.500000f;

	Vertices_sphereNew[61].x = 0.293893f;
	Vertices_sphereNew[61].y = -0.404508f;
	Vertices_sphereNew[61].z = -0.000000f;
	Vertices_sphereNew[61].nx = 0.587785f;
	Vertices_sphereNew[61].ny = -0.809017f;
	Vertices_sphereNew[61].nz = -0.000000f;
	Vertices_sphereNew[61].u = 0.600000f;
	Vertices_sphereNew[61].v = 0.500000f;

	Vertices_sphereNew[62].x = 0.475528f;
	Vertices_sphereNew[62].y = -0.154509f;
	Vertices_sphereNew[62].z = -0.000000f;
	Vertices_sphereNew[62].nx = 0.951056f;
	Vertices_sphereNew[62].ny = -0.309017f;
	Vertices_sphereNew[62].nz = -0.000000f;
	Vertices_sphereNew[62].u = 0.700000f;
	Vertices_sphereNew[62].v = 0.500000f;

	Vertices_sphereNew[63].x = 0.475528f;
	Vertices_sphereNew[63].y = 0.154509f;
	Vertices_sphereNew[63].z = -0.000000f;
	Vertices_sphereNew[63].nx = 0.951056f;
	Vertices_sphereNew[63].ny = 0.309017f;
	Vertices_sphereNew[63].nz = -0.000000f;
	Vertices_sphereNew[63].u = 0.800000f;
	Vertices_sphereNew[63].v = 0.500000f;

	Vertices_sphereNew[64].x = 0.293892f;
	Vertices_sphereNew[64].y = 0.404509f;
	Vertices_sphereNew[64].z = -0.000000f;
	Vertices_sphereNew[64].nx = 0.587785f;
	Vertices_sphereNew[64].ny = 0.809017f;
	Vertices_sphereNew[64].nz = -0.000000f;
	Vertices_sphereNew[64].u = 0.900000f;
	Vertices_sphereNew[64].v = 0.500000f;

	Vertices_sphereNew[65].x = -0.000000f;
	Vertices_sphereNew[65].y = 0.500000f;
	Vertices_sphereNew[65].z = -0.000000f;
	Vertices_sphereNew[65].nx = -0.000000f;
	Vertices_sphereNew[65].ny = 1.000000f;
	Vertices_sphereNew[65].nz = -0.000000f;
	Vertices_sphereNew[65].u = 1.000000f;
	Vertices_sphereNew[65].v = 0.500000f;

	Vertices_sphereNew[66].x = -0.000000f;
	Vertices_sphereNew[66].y = 0.475528f;
	Vertices_sphereNew[66].z = -0.154509f;
	Vertices_sphereNew[66].nx = -0.000000f;
	Vertices_sphereNew[66].ny = 0.951057f;
	Vertices_sphereNew[66].nz = -0.309017f;
	Vertices_sphereNew[66].u = 0.000000f;
	Vertices_sphereNew[66].v = 0.400000f;

	Vertices_sphereNew[67].x = -0.279508f;
	Vertices_sphereNew[67].y = 0.384710f;
	Vertices_sphereNew[67].z = -0.154509f;
	Vertices_sphereNew[67].nx = -0.559017f;
	Vertices_sphereNew[67].ny = 0.769421f;
	Vertices_sphereNew[67].nz = -0.309017f;
	Vertices_sphereNew[67].u = 0.100000f;
	Vertices_sphereNew[67].v = 0.400000f;

	Vertices_sphereNew[68].x = -0.452254f;
	Vertices_sphereNew[68].y = 0.146946f;
	Vertices_sphereNew[68].z = -0.154509f;
	Vertices_sphereNew[68].nx = -0.904509f;
	Vertices_sphereNew[68].ny = 0.293893f;
	Vertices_sphereNew[68].nz = -0.309017f;
	Vertices_sphereNew[68].u = 0.200000f;
	Vertices_sphereNew[68].v = 0.400000f;

	Vertices_sphereNew[69].x = -0.452254f;
	Vertices_sphereNew[69].y = -0.146946f;
	Vertices_sphereNew[69].z = -0.154509f;
	Vertices_sphereNew[69].nx = -0.904509f;
	Vertices_sphereNew[69].ny = -0.293893f;
	Vertices_sphereNew[69].nz = -0.309017f;
	Vertices_sphereNew[69].u = 0.300000f;
	Vertices_sphereNew[69].v = 0.400000f;

	Vertices_sphereNew[70].x = -0.279508f;
	Vertices_sphereNew[70].y = -0.384710f;
	Vertices_sphereNew[70].z = -0.154509f;
	Vertices_sphereNew[70].nx = -0.559017f;
	Vertices_sphereNew[70].ny = -0.769421f;
	Vertices_sphereNew[70].nz = -0.309017f;
	Vertices_sphereNew[70].u = 0.400000f;
	Vertices_sphereNew[70].v = 0.400000f;

	Vertices_sphereNew[71].x = 0.000000f;
	Vertices_sphereNew[71].y = -0.475528f;
	Vertices_sphereNew[71].z = -0.154509f;
	Vertices_sphereNew[71].nx = 0.000000f;
	Vertices_sphereNew[71].ny = -0.951057f;
	Vertices_sphereNew[71].nz = -0.309017f;
	Vertices_sphereNew[71].u = 0.500000f;
	Vertices_sphereNew[71].v = 0.400000f;

	Vertices_sphereNew[72].x = 0.279509f;
	Vertices_sphereNew[72].y = -0.384710f;
	Vertices_sphereNew[72].z = -0.154509f;
	Vertices_sphereNew[72].nx = 0.559017f;
	Vertices_sphereNew[72].ny = -0.769421f;
	Vertices_sphereNew[72].nz = -0.309017f;
	Vertices_sphereNew[72].u = 0.600000f;
	Vertices_sphereNew[72].v = 0.400000f;

	Vertices_sphereNew[73].x = 0.452254f;
	Vertices_sphereNew[73].y = -0.146946f;
	Vertices_sphereNew[73].z = -0.154509f;
	Vertices_sphereNew[73].nx = 0.904509f;
	Vertices_sphereNew[73].ny = -0.293893f;
	Vertices_sphereNew[73].nz = -0.309017f;
	Vertices_sphereNew[73].u = 0.700000f;
	Vertices_sphereNew[73].v = 0.400000f;

	Vertices_sphereNew[74].x = 0.452254f;
	Vertices_sphereNew[74].y = 0.146946f;
	Vertices_sphereNew[74].z = -0.154509f;
	Vertices_sphereNew[74].nx = 0.904509f;
	Vertices_sphereNew[74].ny = 0.293893f;
	Vertices_sphereNew[74].nz = -0.309017f;
	Vertices_sphereNew[74].u = 0.800000f;
	Vertices_sphereNew[74].v = 0.400000f;

	Vertices_sphereNew[75].x = 0.279508f;
	Vertices_sphereNew[75].y = 0.384711f;
	Vertices_sphereNew[75].z = -0.154509f;
	Vertices_sphereNew[75].nx = 0.559017f;
	Vertices_sphereNew[75].ny = 0.769421f;
	Vertices_sphereNew[75].nz = -0.309017f;
	Vertices_sphereNew[75].u = 0.900000f;
	Vertices_sphereNew[75].v = 0.400000f;

	Vertices_sphereNew[76].x = -0.000000f;
	Vertices_sphereNew[76].y = 0.475528f;
	Vertices_sphereNew[76].z = -0.154509f;
	Vertices_sphereNew[76].nx = -0.000000f;
	Vertices_sphereNew[76].ny = 0.951057f;
	Vertices_sphereNew[76].nz = -0.309017f;
	Vertices_sphereNew[76].u = 1.000000f;
	Vertices_sphereNew[76].v = 0.400000f;

	Vertices_sphereNew[77].x = -0.000000f;
	Vertices_sphereNew[77].y = 0.404509f;
	Vertices_sphereNew[77].z = -0.293893f;
	Vertices_sphereNew[77].nx = -0.000000f;
	Vertices_sphereNew[77].ny = 0.809017f;
	Vertices_sphereNew[77].nz = -0.587785f;
	Vertices_sphereNew[77].u = 0.000000f;
	Vertices_sphereNew[77].v = 0.300000f;

	Vertices_sphereNew[78].x = -0.237764f;
	Vertices_sphereNew[78].y = 0.327254f;
	Vertices_sphereNew[78].z = -0.293893f;
	Vertices_sphereNew[78].nx = -0.475528f;
	Vertices_sphereNew[78].ny = 0.654509f;
	Vertices_sphereNew[78].nz = -0.587785f;
	Vertices_sphereNew[78].u = 0.100000f;
	Vertices_sphereNew[78].v = 0.300000f;

	Vertices_sphereNew[79].x = -0.384710f;
	Vertices_sphereNew[79].y = 0.125000f;
	Vertices_sphereNew[79].z = -0.293893f;
	Vertices_sphereNew[79].nx = -0.769421f;
	Vertices_sphereNew[79].ny = 0.250000f;
	Vertices_sphereNew[79].nz = -0.587785f;
	Vertices_sphereNew[79].u = 0.200000f;
	Vertices_sphereNew[79].v = 0.300000f;

	Vertices_sphereNew[80].x = -0.384710f;
	Vertices_sphereNew[80].y = -0.125000f;
	Vertices_sphereNew[80].z = -0.293893f;
	Vertices_sphereNew[80].nx = -0.769421f;
	Vertices_sphereNew[80].ny = -0.250000f;
	Vertices_sphereNew[80].nz = -0.587785f;
	Vertices_sphereNew[80].u = 0.300000f;
	Vertices_sphereNew[80].v = 0.300000f;

	Vertices_sphereNew[81].x = -0.237764f;
	Vertices_sphereNew[81].y = -0.327254f;
	Vertices_sphereNew[81].z = -0.293893f;
	Vertices_sphereNew[81].nx = -0.475528f;
	Vertices_sphereNew[81].ny = -0.654509f;
	Vertices_sphereNew[81].nz = -0.587785f;
	Vertices_sphereNew[81].u = 0.400000f;
	Vertices_sphereNew[81].v = 0.300000f;

	Vertices_sphereNew[82].x = 0.000000f;
	Vertices_sphereNew[82].y = -0.404509f;
	Vertices_sphereNew[82].z = -0.293893f;
	Vertices_sphereNew[82].nx = 0.000000f;
	Vertices_sphereNew[82].ny = -0.809017f;
	Vertices_sphereNew[82].nz = -0.587785f;
	Vertices_sphereNew[82].u = 0.500000f;
	Vertices_sphereNew[82].v = 0.300000f;

	Vertices_sphereNew[83].x = 0.237764f;
	Vertices_sphereNew[83].y = -0.327254f;
	Vertices_sphereNew[83].z = -0.293893f;
	Vertices_sphereNew[83].nx = 0.475528f;
	Vertices_sphereNew[83].ny = -0.654508f;
	Vertices_sphereNew[83].nz = -0.587785f;
	Vertices_sphereNew[83].u = 0.600000f;
	Vertices_sphereNew[83].v = 0.300000f;

	Vertices_sphereNew[84].x = 0.384710f;
	Vertices_sphereNew[84].y = -0.125000f;
	Vertices_sphereNew[84].z = -0.293893f;
	Vertices_sphereNew[84].nx = 0.769421f;
	Vertices_sphereNew[84].ny = -0.250000f;
	Vertices_sphereNew[84].nz = -0.587785f;
	Vertices_sphereNew[84].u = 0.700000f;
	Vertices_sphereNew[84].v = 0.300000f;

	Vertices_sphereNew[85].x = 0.384710f;
	Vertices_sphereNew[85].y = 0.125000f;
	Vertices_sphereNew[85].z = -0.293893f;
	Vertices_sphereNew[85].nx = 0.769421f;
	Vertices_sphereNew[85].ny = 0.250000f;
	Vertices_sphereNew[85].nz = -0.587785f;
	Vertices_sphereNew[85].u = 0.800000f;
	Vertices_sphereNew[85].v = 0.300000f;

	Vertices_sphereNew[86].x = 0.237764f;
	Vertices_sphereNew[86].y = 0.327254f;
	Vertices_sphereNew[86].z = -0.293893f;
	Vertices_sphereNew[86].nx = 0.475528f;
	Vertices_sphereNew[86].ny = 0.654509f;
	Vertices_sphereNew[86].nz = -0.587785f;
	Vertices_sphereNew[86].u = 0.900000f;
	Vertices_sphereNew[86].v = 0.300000f;

	Vertices_sphereNew[87].x = -0.000000f;
	Vertices_sphereNew[87].y = 0.404509f;
	Vertices_sphereNew[87].z = -0.293893f;
	Vertices_sphereNew[87].nx = -0.000000f;
	Vertices_sphereNew[87].ny = 0.809017f;
	Vertices_sphereNew[87].nz = -0.587785f;
	Vertices_sphereNew[87].u = 1.000000f;
	Vertices_sphereNew[87].v = 0.300000f;

	Vertices_sphereNew[88].x = -0.000000f;
	Vertices_sphereNew[88].y = 0.293893f;
	Vertices_sphereNew[88].z = -0.404509f;
	Vertices_sphereNew[88].nx = -0.000000f;
	Vertices_sphereNew[88].ny = 0.587785f;
	Vertices_sphereNew[88].nz = -0.809017f;
	Vertices_sphereNew[88].u = 0.000000f;
	Vertices_sphereNew[88].v = 0.200000f;

	Vertices_sphereNew[89].x = -0.172746f;
	Vertices_sphereNew[89].y = 0.237764f;
	Vertices_sphereNew[89].z = -0.404509f;
	Vertices_sphereNew[89].nx = -0.345491f;
	Vertices_sphereNew[89].ny = 0.475528f;
	Vertices_sphereNew[89].nz = -0.809017f;
	Vertices_sphereNew[89].u = 0.100000f;
	Vertices_sphereNew[89].v = 0.200000f;

	Vertices_sphereNew[90].x = -0.279508f;
	Vertices_sphereNew[90].y = 0.090818f;
	Vertices_sphereNew[90].z = -0.404509f;
	Vertices_sphereNew[90].nx = -0.559017f;
	Vertices_sphereNew[90].ny = 0.181636f;
	Vertices_sphereNew[90].nz = -0.809017f;
	Vertices_sphereNew[90].u = 0.200000f;
	Vertices_sphereNew[90].v = 0.200000f;

	Vertices_sphereNew[91].x = -0.279508f;
	Vertices_sphereNew[91].y = -0.090818f;
	Vertices_sphereNew[91].z = -0.404509f;
	Vertices_sphereNew[91].nx = -0.559017f;
	Vertices_sphereNew[91].ny = -0.181636f;
	Vertices_sphereNew[91].nz = -0.809017f;
	Vertices_sphereNew[91].u = 0.300000f;
	Vertices_sphereNew[91].v = 0.200000f;

	Vertices_sphereNew[92].x = -0.172746f;
	Vertices_sphereNew[92].y = -0.237764f;
	Vertices_sphereNew[92].z = -0.404509f;
	Vertices_sphereNew[92].nx = -0.345491f;
	Vertices_sphereNew[92].ny = -0.475528f;
	Vertices_sphereNew[92].nz = -0.809017f;
	Vertices_sphereNew[92].u = 0.400000f;
	Vertices_sphereNew[92].v = 0.200000f;

	Vertices_sphereNew[93].x = 0.000000f;
	Vertices_sphereNew[93].y = -0.293893f;
	Vertices_sphereNew[93].z = -0.404509f;
	Vertices_sphereNew[93].nx = 0.000000f;
	Vertices_sphereNew[93].ny = -0.587785f;
	Vertices_sphereNew[93].nz = -0.809017f;
	Vertices_sphereNew[93].u = 0.500000f;
	Vertices_sphereNew[93].v = 0.200000f;

	Vertices_sphereNew[94].x = 0.172746f;
	Vertices_sphereNew[94].y = -0.237764f;
	Vertices_sphereNew[94].z = -0.404509f;
	Vertices_sphereNew[94].nx = 0.345492f;
	Vertices_sphereNew[94].ny = -0.475528f;
	Vertices_sphereNew[94].nz = -0.809017f;
	Vertices_sphereNew[94].u = 0.600000f;
	Vertices_sphereNew[94].v = 0.200000f;

	Vertices_sphereNew[95].x = 0.279508f;
	Vertices_sphereNew[95].y = -0.090818f;
	Vertices_sphereNew[95].z = -0.404509f;
	Vertices_sphereNew[95].nx = 0.559017f;
	Vertices_sphereNew[95].ny = -0.181636f;
	Vertices_sphereNew[95].nz = -0.809017f;
	Vertices_sphereNew[95].u = 0.700000f;
	Vertices_sphereNew[95].v = 0.200000f;

	Vertices_sphereNew[96].x = 0.279508f;
	Vertices_sphereNew[96].y = 0.090818f;
	Vertices_sphereNew[96].z = -0.404509f;
	Vertices_sphereNew[96].nx = 0.559017f;
	Vertices_sphereNew[96].ny = 0.181636f;
	Vertices_sphereNew[96].nz = -0.809017f;
	Vertices_sphereNew[96].u = 0.800000f;
	Vertices_sphereNew[96].v = 0.200000f;

	Vertices_sphereNew[97].x = 0.172746f;
	Vertices_sphereNew[97].y = 0.237764f;
	Vertices_sphereNew[97].z = -0.404509f;
	Vertices_sphereNew[97].nx = 0.345491f;
	Vertices_sphereNew[97].ny = 0.475528f;
	Vertices_sphereNew[97].nz = -0.809017f;
	Vertices_sphereNew[97].u = 0.900000f;
	Vertices_sphereNew[97].v = 0.200000f;

	Vertices_sphereNew[98].x = -0.000000f;
	Vertices_sphereNew[98].y = 0.293893f;
	Vertices_sphereNew[98].z = -0.404509f;
	Vertices_sphereNew[98].nx = -0.000000f;
	Vertices_sphereNew[98].ny = 0.587785f;
	Vertices_sphereNew[98].nz = -0.809017f;
	Vertices_sphereNew[98].u = 1.000000f;
	Vertices_sphereNew[98].v = 0.200000f;

	Vertices_sphereNew[99].x = -0.000000f;
	Vertices_sphereNew[99].y = 0.154508f;
	Vertices_sphereNew[99].z = -0.475528f;
	Vertices_sphereNew[99].nx = -0.000000f;
	Vertices_sphereNew[99].ny = 0.309017f;
	Vertices_sphereNew[99].nz = -0.951057f;
	Vertices_sphereNew[99].u = 0.000000f;
	Vertices_sphereNew[99].v = 0.100000f;

	Vertices_sphereNew[100].x = -0.090818f;
	Vertices_sphereNew[100].y = 0.125000f;
	Vertices_sphereNew[100].z = -0.475528f;
	Vertices_sphereNew[100].nx = -0.181636f;
	Vertices_sphereNew[100].ny = 0.250000f;
	Vertices_sphereNew[100].nz = -0.951057f;
	Vertices_sphereNew[100].u = 0.100000f;
	Vertices_sphereNew[100].v = 0.100000f;

	Vertices_sphereNew[101].x = -0.146946f;
	Vertices_sphereNew[101].y = 0.047746f;
	Vertices_sphereNew[101].z = -0.475528f;
	Vertices_sphereNew[101].nx = -0.293892f;
	Vertices_sphereNew[101].ny = 0.095491f;
	Vertices_sphereNew[101].nz = -0.951057f;
	Vertices_sphereNew[101].u = 0.200000f;
	Vertices_sphereNew[101].v = 0.100000f;

	Vertices_sphereNew[102].x = -0.146946f;
	Vertices_sphereNew[102].y = -0.047746f;
	Vertices_sphereNew[102].z = -0.475528f;
	Vertices_sphereNew[102].nx = -0.293892f;
	Vertices_sphereNew[102].ny = -0.095491f;
	Vertices_sphereNew[102].nz = -0.951057f;
	Vertices_sphereNew[102].u = 0.300000f;
	Vertices_sphereNew[102].v = 0.100000f;

	Vertices_sphereNew[103].x = -0.090818f;
	Vertices_sphereNew[103].y = -0.125000f;
	Vertices_sphereNew[103].z = -0.475528f;
	Vertices_sphereNew[103].nx = -0.181635f;
	Vertices_sphereNew[103].ny = -0.250000f;
	Vertices_sphereNew[103].nz = -0.951057f;
	Vertices_sphereNew[103].u = 0.400000f;
	Vertices_sphereNew[103].v = 0.100000f;

	Vertices_sphereNew[104].x = 0.000000f;
	Vertices_sphereNew[104].y = -0.154508f;
	Vertices_sphereNew[104].z = -0.475528f;
	Vertices_sphereNew[104].nx = 0.000000f;
	Vertices_sphereNew[104].ny = -0.309017f;
	Vertices_sphereNew[104].nz = -0.951057f;
	Vertices_sphereNew[104].u = 0.500000f;
	Vertices_sphereNew[104].v = 0.100000f;

	Vertices_sphereNew[105].x = 0.090818f;
	Vertices_sphereNew[105].y = -0.125000f;
	Vertices_sphereNew[105].z = -0.475528f;
	Vertices_sphereNew[105].nx = 0.181636f;
	Vertices_sphereNew[105].ny = -0.250000f;
	Vertices_sphereNew[105].nz = -0.951057f;
	Vertices_sphereNew[105].u = 0.600000f;
	Vertices_sphereNew[105].v = 0.100000f;

	Vertices_sphereNew[106].x = 0.146946f;
	Vertices_sphereNew[106].y = -0.047746f;
	Vertices_sphereNew[106].z = -0.475528f;
	Vertices_sphereNew[106].nx = 0.293892f;
	Vertices_sphereNew[106].ny = -0.095491f;
	Vertices_sphereNew[106].nz = -0.951057f;
	Vertices_sphereNew[106].u = 0.700000f;
	Vertices_sphereNew[106].v = 0.100000f;

	Vertices_sphereNew[107].x = 0.146946f;
	Vertices_sphereNew[107].y = 0.047746f;
	Vertices_sphereNew[107].z = -0.475528f;
	Vertices_sphereNew[107].nx = 0.293892f;
	Vertices_sphereNew[107].ny = 0.095491f;
	Vertices_sphereNew[107].nz = -0.951057f;
	Vertices_sphereNew[107].u = 0.800000f;
	Vertices_sphereNew[107].v = 0.100000f;

	Vertices_sphereNew[108].x = 0.090818f;
	Vertices_sphereNew[108].y = 0.125000f;
	Vertices_sphereNew[108].z = -0.475528f;
	Vertices_sphereNew[108].nx = 0.181635f;
	Vertices_sphereNew[108].ny = 0.250000f;
	Vertices_sphereNew[108].nz = -0.951057f;
	Vertices_sphereNew[108].u = 0.900000f;
	Vertices_sphereNew[108].v = 0.100000f;

	Vertices_sphereNew[109].x = -0.000000f;
	Vertices_sphereNew[109].y = 0.154508f;
	Vertices_sphereNew[109].z = -0.475528f;
	Vertices_sphereNew[109].nx = -0.000000f;
	Vertices_sphereNew[109].ny = 0.309017f;
	Vertices_sphereNew[109].nz = -0.951057f;
	Vertices_sphereNew[109].u = 1.000000f;
	Vertices_sphereNew[109].v = 0.100000f;

	Vertices_sphereNew[110].x = 0.000000f;
	Vertices_sphereNew[110].y = -0.000000f;
	Vertices_sphereNew[110].z = -0.500000f;
	Vertices_sphereNew[110].nx = 0.000000f;
	Vertices_sphereNew[110].ny = -0.000000f;
	Vertices_sphereNew[110].nz = -1.000000f;
	Vertices_sphereNew[110].u = 0.000000f;
	Vertices_sphereNew[110].v = -0.000000f;

	Vertices_sphereNew[111].x = 0.000000f;
	Vertices_sphereNew[111].y = -0.000000f;
	Vertices_sphereNew[111].z = -0.500000f;
	Vertices_sphereNew[111].nx = 0.000000f;
	Vertices_sphereNew[111].ny = -0.000000f;
	Vertices_sphereNew[111].nz = -1.000000f;
	Vertices_sphereNew[111].u = 0.100000f;
	Vertices_sphereNew[111].v = -0.000000f;

	Vertices_sphereNew[112].x = 0.000000f;
	Vertices_sphereNew[112].y = -0.000000f;
	Vertices_sphereNew[112].z = -0.500000f;
	Vertices_sphereNew[112].nx = 0.000000f;
	Vertices_sphereNew[112].ny = -0.000000f;
	Vertices_sphereNew[112].nz = -1.000000f;
	Vertices_sphereNew[112].u = 0.200000f;
	Vertices_sphereNew[112].v = -0.000000f;

	Vertices_sphereNew[113].x = 0.000000f;
	Vertices_sphereNew[113].y = 0.000000f;
	Vertices_sphereNew[113].z = -0.500000f;
	Vertices_sphereNew[113].nx = 0.000000f;
	Vertices_sphereNew[113].ny = 0.000000f;
	Vertices_sphereNew[113].nz = -1.000000f;
	Vertices_sphereNew[113].u = 0.300000f;
	Vertices_sphereNew[113].v = -0.000000f;

	Vertices_sphereNew[114].x = 0.000000f;
	Vertices_sphereNew[114].y = 0.000000f;
	Vertices_sphereNew[114].z = -0.500000f;
	Vertices_sphereNew[114].nx = 0.000000f;
	Vertices_sphereNew[114].ny = 0.000000f;
	Vertices_sphereNew[114].nz = -1.000000f;
	Vertices_sphereNew[114].u = 0.400000f;
	Vertices_sphereNew[114].v = -0.000000f;

	Vertices_sphereNew[115].x = -0.000000f;
	Vertices_sphereNew[115].y = 0.000000f;
	Vertices_sphereNew[115].z = -0.500000f;
	Vertices_sphereNew[115].nx = -0.000000f;
	Vertices_sphereNew[115].ny = 0.000000f;
	Vertices_sphereNew[115].nz = -1.000000f;
	Vertices_sphereNew[115].u = 0.500000f;
	Vertices_sphereNew[115].v = -0.000000f;

	Vertices_sphereNew[116].x = -0.000000f;
	Vertices_sphereNew[116].y = 0.000000f;
	Vertices_sphereNew[116].z = -0.500000f;
	Vertices_sphereNew[116].nx = -0.000000f;
	Vertices_sphereNew[116].ny = 0.000000f;
	Vertices_sphereNew[116].nz = -1.000000f;
	Vertices_sphereNew[116].u = 0.600000f;
	Vertices_sphereNew[116].v = -0.000000f;

	Vertices_sphereNew[117].x = -0.000000f;
	Vertices_sphereNew[117].y = 0.000000f;
	Vertices_sphereNew[117].z = -0.500000f;
	Vertices_sphereNew[117].nx = -0.000000f;
	Vertices_sphereNew[117].ny = 0.000000f;
	Vertices_sphereNew[117].nz = -1.000000f;
	Vertices_sphereNew[117].u = 0.700000f;
	Vertices_sphereNew[117].v = -0.000000f;

	Vertices_sphereNew[118].x = -0.000000f;
	Vertices_sphereNew[118].y = -0.000000f;
	Vertices_sphereNew[118].z = -0.500000f;
	Vertices_sphereNew[118].nx = -0.000000f;
	Vertices_sphereNew[118].ny = -0.000000f;
	Vertices_sphereNew[118].nz = -1.000000f;
	Vertices_sphereNew[118].u = 0.800000f;
	Vertices_sphereNew[118].v = -0.000000f;

	Vertices_sphereNew[119].x = -0.000000f;
	Vertices_sphereNew[119].y = -0.000000f;
	Vertices_sphereNew[119].z = -0.500000f;
	Vertices_sphereNew[119].nx = -0.000000f;
	Vertices_sphereNew[119].ny = -0.000000f;
	Vertices_sphereNew[119].nz = -1.000000f;
	Vertices_sphereNew[119].u = 0.900000f;
	Vertices_sphereNew[119].v = -0.000000f;

	Vertices_sphereNew[120].x = 0.000000f;
	Vertices_sphereNew[120].y = -0.000000f;
	Vertices_sphereNew[120].z = -0.500000f;
	Vertices_sphereNew[120].nx = 0.000000f;
	Vertices_sphereNew[120].ny = -0.000000f;
	Vertices_sphereNew[120].nz = -1.000000f;
	Vertices_sphereNew[120].u = 1.000000f;
	Vertices_sphereNew[120].v = -0.000000f;
}

// Pyramid
#define PYRAMID_DATA_NUM_TRIS (sizeof(TriList_pyramidNew)/sizeof(Tri_index))
#define PYRAMID_DATA_NUM_VERTS (sizeof(Vertices_pyramidNew)/sizeof(Vert_xyzuvn))
static const Tri_index TriList_pyramidNew[] =
{
	{0,1,2},
	{2,3,0},
	{4,5,6},
	{5,7,6},
	{8,9,10},
	{9,11,10},
	{12,13,14},
	{13,15,14},
	{16,17,18},
	{18,19,16},
	{20,21,22},
	{22,23,20}
};
static const Vert_xyzuvn  Vertices_pyramidNew[] =
{
	// Triangle 0
	{-0.25f,  0.0f, -0.25f, 0.0f, 0.0f, -0.6f,  0.6f, -0.6f  }, //0
	{-0.25f, -0.0f, -0.25f, 0.0f, 1.0f, -0.6f, -0.6f, -0.6f  },// 1
	{ 0.25f, -0.0f, -0.25f, 1.0f, 1.0f,  0.6f, -0.6f, -0.6f  }, //2

	// Triangle 1

	{ 0.0f,   1.0f, -0.0f, 1.0f, 0.0f,  0.6f,  0.6f, -0.6f  },  //4  3


	// Triangle 2
	{ 0.25f, -0.0f, -0.25f, 0.0f, 1.0f, 0.6f, -0.6f, -0.6f  }, //6
	{ 0.25f, -0.0f,  0.25f, 1.0f, 1.0f, 0.6f, -0.6f,  0.6f  }, //7
	{ 0.0f,  1.0f, -0.0f, 0.0f, 0.0f, 0.6f,  0.6f, -0.6f  }, //8

	// Triangle 3

	{ 0.25f,  0.0f,  0.25f, 1.0f, 0.0f, 0.6f,  0.6f,  0.6f  }, //9 


	// Triangle 4
	{ 0.25f, -0.0f,  0.25f, 1.0f, 1.0f,  0.6f, -0.6f, 0.6f  },  // 12
	{-0.25f, -0.0f, 0.25f, 0.0f, 1.0f, -0.6f, -0.6f, 0.6f  },   // 13
	{ 0.0f,  1.0f,  0.0f, 1.0f, 0.0f,  0.6f,  0.6f, 0.6f  },  // 14

	// Triangle 5

	{ -0.0f,  1.0f,  0.0f, 0.0f, 0.0f, -0.6f,  0.6f, 0.6f },  //15


	// Triangle 6
	{-0.25f, -0.0f,  0.25f, 0.0f, 0.0f, -0.6f, -0.6f,  0.6f }, //18
	{-0.25f, -0.0f, -0.25f, 0.0f, 1.0f, -0.6f, -0.6f, -0.6f }, //19
	{-0.0f,  1.0f,  0.0f, 1.0f, 0.0f, -0.6f,  0.6f,  0.6f }, //20

	// Triangle 7

	{-0.0f,  1.0f, -0.0f, 1.0f, 1.0f, -0.6f,  0.6f, -0.6f }, // 21


	// Triangle 8
	{-0.25f, -0.0f,  0.25f, 0.0f, 0.0f, -0.6f, -0.6f,  0.6f }, //24
	{0.25f, -0.0f,   0.25f, 1.0f, 0.0f,  0.6f, -0.6f,  0.6f }, //25
	{0.25f, -0.0f,  -0.25f, 1.0f, 1.0f,  0.6f, -0.6f, -0.6f }, //26

	// Triangle 9

	{-0.25f, -0.0f, -0.25f, 0.0f, 1.0f, -0.6f, -0.6f, -0.6f}, // 27


	// Triangle 10
	{-0.0f,  1.0f, -0.0f, 0.0f, 1.0f, -0.6f, 0.6f, -0.6f }, //30
	{0.0f,  1.0f,  -0.0f, 1.0f, 1.0f,  0.6f, 0.6f, -0.6f }, //31
	{0.0f,  1.0f,   0.0f, 1.0f, 0.0f,  0.6f, 0.6f,  0.6f }, //32

	// Triangle 11

	{-0.0f,  1.0f,  0.0f, 0.0f, 0.0f, -0.6f, 0.6f,  0.6f }, //33

};

// Quad
#define QUAD_DATA_NUM_TRIS (sizeof(TriList_quadNew)/sizeof(Tri_index))
#define QUAD_DATA_NUM_VERTS (sizeof(Vertices_quadNew)/sizeof(Vert_xyzuvn))
static const Tri_index TriList_quadNew[] =
{
	{ 0, 1, 2 },
	{ 2, 3, 1 },
}; 
static const Vert_xyzuvn  Vertices_quadNew[] =
{
	// Triangle 0
	{ -0.5f,  0.0f,  -0.5f, 0.0f, 0.0f,  0.0f,  1.0f,   0.0f },
	{ -0.5f,  0.0f,  -0.5f, 0.0f, 1.0f,  0.0f,  1.0f,  -0.0f },
	{ 0.5f,   0.0f,  -0.5f, 1.0f, 1.0f,  0.0f,  1.0f,  -0.0f },

	// Triangle 1
	{  0.5f,   0.0f, -0.5f, 1.0f, 1.0f,  0.0f,   1.0f, -0.0f },
	{  0.5f,   0.0f, -0.5f, 1.0f, 0.0f,  0.0f,   1.0f, -0.0f },
	{ -0.5f,  0.0f, -0.5f, 0.0f, 0.0f,  -0.0f,   1.0f,  -0.0f },

	// Triangle 2
	{ 0.5f, -0.0f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f },
	{ 0.5f, -0.0f,  0.5f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f },
	{ 0.5f,  0.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f },

	// Triangle 3
	{ 0.5f, -0.0f,  0.5f, 1.0f, 1.0f, 0.0f, 1.0f,  0.0f },
	{ 0.5f,  0.0f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f,  0.0f },
	{ 0.5f,  0.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,  0.0f },
};