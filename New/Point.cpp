#include "Point.h"

Point::Point(){
	this->x = 0;
	this->y = 0;
}

Point::Point(GLdouble x, GLdouble y){
	this->x = x;
	this->y = y;
}

GLdouble Point::GetX(){
	return this->x;
}

GLdouble Point::GetY(){
	return this->y;
}

void Point::SetX(GLdouble x){
	this->x = x;
}

void Point::SetY(GLdouble y){
	this->y = y;
}
 