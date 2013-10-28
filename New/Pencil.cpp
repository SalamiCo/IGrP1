#include "Pencil.h"

Pencil::Pencil(){
	this->pos = new Point();
	this->dir = 0;
}

Pencil::Pencil(Point *p, GLdouble dir){
	this->pos = p;
	this->dir = dir;
}

void Pencil::SetPos(Point *p){
	this->pos = p;
}

void Pencil::SetDir(GLdouble d){
	this->dir = d;
}

GLdouble Pencil::GetDir(){
	return this->dir;
}

void Pencil::Turn(GLdouble d){
	//d>0 -> left, d<0 -> right
	this->dir += d;
} 

void Pencil::Forward(GLdouble dist){
	x += dist*cos(this->dir);
	y += dist*sin(this->dir);
}