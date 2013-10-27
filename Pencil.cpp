#include <cmath.h>
#include "Pencil.h"

Pencil::Pencil(){
	this->pos = new Point();
	this->dir = 0;
}

Pencil::Pencil(Point p, GLdouble d){
	this->pos = p;
	this->dir = d;
}

void Pencil::setPos(Point p){
	this->pos = p;
}

void Pencil::setDir(GLdouble d){
	this->dir = d;
}

GLdouble Pencil::getDir(){
	return this->dir;
}

void Pencil::turn(GLdouble d){
	//d>0 -> left, d<0 -> right
	this->dir += d;
} 

void Pencil::forward(GLdouble dist){
	x += dist*cos(this->dir);
	y += dist*sin(this->dir);
}