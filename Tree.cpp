#include "Tree.h"

Tree::Tree(){
	this->next = new Vector<Square>();
	Square firstSquare = new Square(-50, -50, 50, 50);
	this->next->push_back(firstSquare);
	this->archive = new Vector<Square>();
}

void Tree::drawNextLevel(){
	glRectf(-100,-100,100,100);
}