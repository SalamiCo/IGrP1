#include "Point.h"

Point::Point(){
	this->x = 0;
	this->y = 0;
}

Point::Point(GLdouble x, GLdouble y){
	this->x = x;
	this->y = y;
}

GLdouble Point::getX(){
	return this->x;
}

GLdouble Point::getY(){
	return this->y;
}

void Point::setX(GLdouble x){
	this->x = x;
}

void Point::setY(GLdouble y){
	this->y = y;
}