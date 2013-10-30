
#include "Tree.h"

Tree::Tree(){
	Square firstSquare = Square(PointCoord(50,-100),
                                        PointCoord(-50,-100),
                                        PointCoord(-50,-200),
                                        PointCoord(50,-200));
        
	this->next.push_back(firstSquare);
}

void Tree::DrawNextLevel(){
        std::list<Square>::iterator i;
        for(i=this->archive.begin(); i!=this->archive.end(); ++i){
                glBegin(GL_QUADS);
                        glColor3f(1.0,0.0,0.0); //Red
                        glVertex2f( i->GetX1().GetX(), i->GetX1().GetY());
                        glColor3f(0.0,1.0,0.0); //Green
                        glVertex2f( i->GetX2().GetX(), i->GetX2().GetY());
                        glColor3f(0.0,0.0,1.0); //Blue
                        glVertex2f( i->GetX3().GetX(), i->GetX3().GetY());
                        glColor3f(1.0,0.0,1.0); //Purple
                        glVertex2f( i->GetX4().GetX(), i->GetX4().GetY());
                glEnd();
        }
        for(i=this->next.begin(); i!=this->next.end(); ++i){
                glBegin(GL_QUADS);
                        glColor3f(1.0,0.0,0.0); //Red
                        glVertex2f( i->GetX1().GetX(), i->GetX1().GetY());
                        glColor3f(0.0,1.0,0.0); //Green
                        glVertex2f( i->GetX2().GetX(), i->GetX2().GetY());
                        glColor3f(0.0,0.0,1.0); //Blue
                        glVertex2f( i->GetX3().GetX(), i->GetX3().GetY());
                        glColor3f(1.0,0.0,1.0); //Purple
                        glVertex2f( i->GetX4().GetX(), i->GetX4().GetY());
                glEnd();
        }
}

void Tree::AddNextLevel(){
        Pencil pen;
        std::list<Square>::iterator level;
        std::list<Square>::iterator stop;
        stop = this->next.end();
        for(level=this->next.begin(); level!=stop; ++level){

                //First square
                PointCoord p1 (level->GetX1().GetX(), level->GetX1().GetY());
                pen.SetPos(p1);
                pen.SetDir(level->GetAngle() + M_PI_4);
                pen.Forward(level->GetEdge()*cos(M_PI_4));

                PointCoord p2 = pen.GetPos();
                pen.Turn(M_PI_2);
                pen.Forward(level->GetEdge()*cos(M_PI_4));

                PointCoord p3 = pen.GetPos();
                pen.Turn(M_PI_2);
                pen.Forward(level->GetEdge()*cos(M_PI_4));

                PointCoord p4 = pen.GetPos();
                pen.Turn(M_PI_2);
                pen.Forward(level->GetEdge()*cos(M_PI_4));

                Square s1 = Square(p2,p3,p4,p1);
                this->next.push_back(s1);

                //Second Square
                pen.Turn(M_PI_4+M_PI);
                pen.Forward(level->GetEdge());

                PointCoord p5 = pen.GetPos();
                pen.Turn(-M_PI_2 - M_PI_4);
                pen.Forward(level->GetEdge()*cos(M_PI_4));

                PointCoord p6 = pen.GetPos();
                pen.Turn(M_PI_2);
                pen.Forward(level->GetEdge()*cos(M_PI_4));

                PointCoord p7 = pen.GetPos();
                pen.Turn(M_PI_2);
                pen.Forward(level->GetEdge()*cos(M_PI_4));

                PointCoord p8 = pen.GetPos();
                pen.Turn(M_PI_2);
                pen.Forward(level->GetEdge()*cos(M_PI_4));

                Square s2 = Square(p7,p8,p5,p6);
                this->next.push_back(s2);

                this->archive.push_back(*level);
        }

        this->next.erase(this->next.begin(), stop);
}
 