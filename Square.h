#ifndef SquareH
#define SquareH

#include "PointCoord.h"
#include <math.h>

class Square{
	private:
		PointCoord x1,x2,x3,x4;
	public:
		Square();
		Square(PointCoord x1, PointCoord x2, PointCoord x3, PointCoord x4);
        PointCoord GetX1();
        PointCoord GetX2();
        PointCoord GetX3();
        PointCoord GetX4();
        GLdouble GetEdge();
        GLdouble GetAngle();
};

#endif
 