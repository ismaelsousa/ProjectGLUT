#include <GL/glut.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
float vertice[3][2] = {{-25.0,-25.0},
                        {25.0,-25.0},
                        {0.0,25.0}};

float vertnew[1][2]= {0.0,0.0};

void pinta(){
float x,y;
for(int i = 0 ; i< 1000000; i++){
    int pontoAleatorio = rand() % 3;
    //calcula o nome
    x = (vertnew[0][0] + vertice[pontoAleatorio][0])/2;
    y = (vertnew[0][1] + vertice[pontoAleatorio][1])/2;

    //aqui atualiza o vertice medio
    vertnew[0][0] = x;
    vertnew[0][1] = y;
    sleep(0.5);
    glVertex2fv(vertnew[0]);
}
}

void initGL(){
glClearColor(1.0, 1.0, 1.0, 1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-40, 40, -30, 30, 10, -10);//coordenadas
glMatrixMode(GL_MODELVIEW);
}

void funcao(){
    glBegin(GL_POINTS);//inicio da modelagem
        glVertex3fv(vertice[0]);
        glVertex2fv(vertice[1]);
        glVertex2fv(vertice[2]);
        pinta();

    glEnd();//fechando a modelagem
}

void display(){
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0,0.0,0.0);
    funcao();
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
