#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

static GLfloat spin = 0.0;

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



void init(){
glClearColor(0.0, 0.0, 0.0, 1.0);
}

void spinDisplay(){//âmgulo de rotação
    spin += 2.0;
    if(spin > 360.0){
        spin -= 360.0;
    }
    glutPostRedisplay();

}

void reshape(int w, int h){

    glViewport(0,0,(GLsizei)w,(GLsizei)h);//porção da janela q vai usar
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0,50.0,-50.0,50.0,-50.0,50.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mouse(int button, int state, int x, int y){
    switch(button){
    case GLUT_LEFT_BUTTON:
        if(state == GLUT_DOWN){
            glutIdleFunc(spinDisplay);
        }
        break;

    case GLUT_RIGHT_BUTTON:
        if(state == GLUT_DOWN){
            glutIdleFunc(NULL);
        }
        break;
    default:
        break;
}
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(spin, 0.5,0.5,0.0); // rotação coloca o eixo de rotação
    glColor3f(1.0,0.0,0.0);

    //desenho

    glBegin(GL_TRIANGLES);
    //a cada três ele cria um triângulo
    //face 1 frente
    glColor3f(0.0,0.0,1.0);
    glVertex3f(-25.0,-25.0,0.0); //p1
    glVertex3f(25.0, 25.0,0.0);//p3
    glVertex3f(25.0,-25.0,0.0);//p2

    glVertex3f(-25.0,-25.0,0.0);//p1
    glVertex3f(-25.0,25.0,0.0); //p4
    glVertex3f(25.0, 25.0,0.0);//p3

    //face 2 trás
    glColor3f(1.0,0.0,0.0);

    glVertex3f(-25.0,-25.0,-25.0); //p1z
    glVertex3f(25.0, 25.0,-25.0);//p3z
    glVertex3f(25.0,-25.0,-25.0);//p2z

    glVertex3f(-25.0,25.0,-25.0); //p4z
    glVertex3f(-25.0,-25.0,-25.0);//p1z
    glVertex3f(25.0, 25.0,-25.0);//p2z


    //face 3 direita
    glColor3f(0.0,1.0,0.0);

    glVertex3f(25.0,-25.0,0.0);//p2
    glVertex3f(25.0, 25.0,-25.0);//p3z
    glVertex3f(25.0, 25.0,0.0);//p3

    glVertex3f(25.0,-25.0,0.0);//p2
    glVertex3f(25.0,-25.0,-25.0);//p2z
    glVertex3f(25.0, 25.0,-25.0);//p3z

    //face 4 esquerda
    glColor3f(0.0,1.0,1.0);
    glVertex3f(-25.0,-25.0,0.0);//p1
    glVertex3f(-25.0,25.0,0.0); //p4
    glVertex3f(-25.0,25.0,-25.0); //p4z

    glVertex3f(-25.0,-25.0,0.0);//p1
    glVertex3f(-25.0,25.0,-25.0); //p4z
    glVertex3f(-25.0,-25.0,-25.0); //p1z

    //face 5 tampa de cima
    glColor3f(1.0,1.0,0.0);
    glVertex3f(-25.0,25.0,0.0); //p4
    glVertex3f(25.0, 25.0,0.0);//p3
    glVertex3f(25.0, 25.0,-25.0);//p3z

    glVertex3f(-25.0,25.0,0.0); //p4
    glVertex3f(25.0, 25.0,-25.0);//p3z
    glVertex3f(-25.0,25.0,-25.0); //p4z

    //face 6 tampa de baixo
    glColor3f(1.0,0.5,0.0);
    glVertex3f(25.0,-25.0,0.0);//p2
    glVertex3f(-25.0,-25.0,0.0);//p1
    glVertex3f(-25.0,-25.0,-25.0);//p1z

    glVertex3f(25.0,-25.0,0.0);//p2
    glVertex3f(-25.0,-25.0,-25.0);//p1z
    glVertex3f(25.0,-25.0,-25.0);//p2z


    glEnd();


    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
        glutInitWindowSize(500, 500);
        glutInitWindowPosition(100,100);
        glutCreateWindow("girar");
        init();
        glutDisplayFunc(display);
        glutReshapeFunc(reshape);
        glutMouseFunc(mouse);
        glutMainLoop();

}

