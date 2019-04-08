/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
static GLfloat spin = 0.0;
double rotacao_x= 0;
double rotacao_y=0;



void tecla(unsigned char tecla, int x, int y){
    if (tecla == 'd'){
        rotacao_y += 11;
    } else if(tecla == 'a'){
        rotacao_y -= 6;
    } else if (tecla == 'w'){
        rotacao_x += 11;
    } else if (tecla == 's'){
        rotacao_x -= 6;
    }
    glutPostRedisplay();
}

void init(){
glClearColor(0.0, 0.0, 0.0, 1.0);
glEnable(GL_DEPTH_TEST);
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
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(rotacao_x,1.0,0.0,0.0); // rotação coloca o eixo de rotação
    glRotatef(rotacao_y,0.0,1.0,0.0);
    glColor3f(1.0,0.0,0.0);

    //desenho da linhas
    glBegin(GL_LINES);
        glColor3f(0.0,1.0,0.0);
        glVertex3f(-50.0,0.0,0.0);
        glVertex3f(50.0,0.0,0.0);

        glColor3f(1.0,0.0,0.0);
        glVertex3f(0.0,50.0,0.0);
        glVertex3f(0.0,-50.0,0.0);

        glColor3f(0.0,0.0,1.0);
        glVertex3f(0.0,0.0,50.0);
        glVertex3f(0.0,0.0,-50.0);

    glEnd();

    glBegin(GL_LINE_STRIP);
        glColor3f(1.0,1.0,0.0);
        for(int i=-50 ; i<50;i++){

                glVertex3d(i*4,(i*i),10);

        }
    glEnd();

    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
        glutInitWindowSize(500, 500);
        glutInitWindowPosition(100,100);
        glutCreateWindow("girar");
        init();
        glutDisplayFunc(display);
        glutReshapeFunc(reshape);
        glutMouseFunc(mouse);
        glutKeyboardFunc(tecla);
        glutMainLoop();

}

