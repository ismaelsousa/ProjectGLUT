#include "Bala.h"

Bala::Bala(int a, int b){
        this->x = a;
        this->y = b;
}

void Bala::desenhatiro(){
        glBegin(GL_TRIANGLES);
            glVertex2d(this->x, this->y+2);
            glVertex2d(this->x-2,this->y);
            glVertex2d(this->x+2,this->y);
        glEnd();
        atualizaY();
        glutPostRedisplay();
}
void Bala::atualizaY(){
        this->y+=5;
}
