
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#define x 0
#define y 1
#define z z
float pontos [8][3] = {{-20.0,-20.0,0.0},//p1
                        {20.0,-20.0,0.0},//p2
                        {20.0,20.0,0.0},//p3
                        {-20.0,20.0,0.0},//p4

                        //face de trás
                     {-20.0,-20.0,-20.0},//p5
                     {20.0,-20.0,-20.0},//p6
                     {20.0,20.0,-20.0},//p7
                     {-20.0,20.0,-20.0},//p8
};


void initGL(){
glClearColor(0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-20, 60, -30, 60, 50, -60);//coordenadas
glMatrixMode(GL_MODELVIEW);
}

void face(){
glColor3f(0.3,0.1,1.0);
//para criar triangulo
glBegin(GL_TRIANGLES);
    //a cada três ele cria um triângulo
    //p4 , p1, p3
    glVertex3fv(pontos[3]);
    glVertex3fv(pontos[0]);
    glVertex3fv(pontos[2]);

    //p1, p2, p3
    glVertex3fv(pontos[0]);
    glVertex3fv(pontos[1]);
    glVertex3fv(pontos[2]);

    //p3, p6, p8
    glVertex3fv(pontos[2]);
    glVertex3fv(pontos[6]);
    glVertex3fv(pontos[5]);

glEnd();

}
void display(){
glClear(GL_COLOR_BUFFER_BIT);//limpando a tela
face();

glFlush();
}


int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
        glutInitWindowSize(800, 600);
        glutInitWindowPosition(100,100);
        glutCreateWindow(" Hello, janela!");
        glutDisplayFunc(display);
    initGL();
    glutMainLoop();
}

