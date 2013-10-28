#ifndef SquareH
#define SquareH

#include "Point.h"

class Square{
	private:
                // The two points :: is for resolving ambiguity
		::Point *x1,*x2,*x3,*x4;
	public:
		Square();
		Square(::Point *x1, ::Point *x2, ::Point *x3, ::Point *x4);
                ::Point* GetX1();
                ::Point* GetX2();
                ::Point* GetX3();
                ::Point* GetX4();
};

#endif
 