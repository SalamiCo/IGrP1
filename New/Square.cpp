#include "Square.h"

Square::Square(Point *x1, Point *x2, Point *x3, Point *x4){
	this->x1 = x1;
	this->x2 = x2;
	this->x3 = x3;
	this->x4 = x4;
}

Point* Square::GetX1(){
        return this->x1;
}

Point* Square::GetX2(){
        return this->x2;
}

Point* Square::GetX3(){
        return this->x3;
}

Point* Square::GetX4(){
        return this->x4;
}
 