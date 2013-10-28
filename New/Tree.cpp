#include "Tree.h"

Tree::Tree(){
	//this->next = new Vector<Square>();
	Square* firstSquare = new Square(new Point(50,-50),
                                        new Point(-50,-50),
                                        new Point(-50,50),
                                        new Point(50,50));
        Square* secondSquare = new Square(new Point(50,50),
                                        new Point(25,75),
                                        new Point(50,100),
                                        new Point(75,75));
	this->next.push_back(firstSquare);
        this->next.push_back(secondSquare);
	//this->archive = new Vector<Square>();
}

void Tree::DrawNextLevel(){
        //Iterator
        std::vector<Square*>::iterator i;
        for(i=this->next.begin(); i!=this->next.end(); ++i){
                glBegin(GL_POLYGON);
                        glVertex2f((*i)->GetX1()->GetX(),(*i)->GetX1()->GetY());
                        glVertex2f((*i)->GetX2()->GetX(),(*i)->GetX2()->GetY());
                        glVertex2f((*i)->GetX3()->GetX(),(*i)->GetX3()->GetY());
                        glVertex2f((*i)->GetX4()->GetX(),(*i)->GetX4()->GetY());
                glEnd();
        }

}
 