//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef BOUNDING_SPHERE_H
#define BOUNDING_SPHERE_H

#include "Vect.h"

class BSphere : public Align16
{
public:
	BSphere();
	BSphere(const BSphere&) = default;
	BSphere& operator = (const BSphere&) = default;
	~BSphere() = default;

	void RitterSphere(Vect* pt, unsigned int numPts);

	// Data: ---------------------------------
	Vect cntr;
	float rad;
	float pad[3];  // love and hate this new compiler

private:

	void privMostSeparatedPointsOnAABB(unsigned int& min, unsigned int& max, Vect* pt, unsigned int numPts);
	void privSphereFromDistantPoints(Vect* pt, unsigned int numPts);
	void privSphereOfSphereAndPt(Vect& p);

};

//void RitterSphere(BSphere& s, Vect* pt, int numPts);

#endif

//--- End of File -------------------------------------------------------------
