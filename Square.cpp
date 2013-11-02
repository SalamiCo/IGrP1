#include "Square.h"

Square::Square(PointCoord p1, PointCoord p2, PointCoord p3, PointCoord p4){
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->p4 = p4;
}

PointCoord Square::GetP1(){
    return this->p1;
}

PointCoord Square::GetP2(){
    return this->p2;
}

PointCoord Square::GetP3(){
    return this->p3;
}

PointCoord Square::GetP4(){
    return this->p4;
}

GLdouble Square::GetEdge(){
	GLdouble dx = this->p1.GetX()-this->p2.GetX();
	GLdouble dy = this->p1.GetY()-this->p2.GetY();
	return sqrt(dx*dx + dy*dy);
}

GLdouble Square::GetAngle(){
	return atan2(this->p1.GetY() - this->p2.GetY(), this->p1.GetX() - this->p2.GetX());
}
 