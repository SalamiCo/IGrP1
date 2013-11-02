#include "Square.h"

Square::Square(PointCoord x1, PointCoord x2, PointCoord x3, PointCoord x4){
	this->x1 = x1;
	this->x2 = x2;
	this->x3 = x3;
	this->x4 = x4;
}

PointCoord Square::GetX1(){
    return this->x1;
}

PointCoord Square::GetX2(){
    return this->x2;
}

PointCoord Square::GetX3(){
    return this->x3;
}

PointCoord Square::GetX4(){
    return this->x4;
}

GLdouble Square::GetEdge(){
	GLdouble dx = this->x1.GetX()-this->x2.GetX();
	GLdouble dy = this->x1.GetY()-this->x2.GetY();
	return sqrt(dx*dx + dy*dy);
}

GLdouble Square::GetAngle(){
	return atan2(this->x1.GetY() - this->x2.GetY(), this->x1.GetX() - this->x2.GetX());
}
 