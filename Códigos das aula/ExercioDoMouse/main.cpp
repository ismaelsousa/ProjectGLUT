#ifdef __APPLE__
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<stdio.h>
#include <unistd.h>

static GLfloat spin = 0.0;
double rotacao_x = 0;
double rotacao_y =0;

//variaveis de click
int x_mouse= 450;
int y_mouse= 450;

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
    glOrtho(0.0,500.0,0.0,500.0,-500.0,500.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mouse(int button, int state, int x, int y){
    switch(button){
    case GLUT_LEFT_BUTTON:
        if(state == GLUT_DOWN){
            //glutIdleFunc(spinDisplay);

            //passa o valor para o x e y do mouse
            x_mouse =x;
            y_mouse = 500 - y;
            printf("x = %d y = %d \n",x_mouse,y_mouse);
            glutPostRedisplay();//para desenha imediatamente
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

    //desenho

    glBegin(GL_POINTS);//vou pintar um ponto aqui
        glColor3f(1.0,1.0,1.0);
        glVertex3f(x_mouse,y_mouse,0.0);
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

