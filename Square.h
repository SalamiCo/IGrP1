#ifndef SquareH
#define SquareH

#include "PointCoord.h"
#include <math.h>

class Square{
	private:
		PointCoord p1,p2,p3,p4;
	public:
		Square();
		Square(PointCoord p1, PointCoord p2, PointCoord p3, PointCoord p4);
        PointCoord GetP1();
        PointCoord GetP2();
        PointCoord GetP3();
        PointCoord GetP4();
        GLdouble GetEdge();
        GLdouble GetAngle();
};

#endif
 