#include <GL/glut.h>

void initGL(){
glClearColor(0.5, 0.0, 0.7, 1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-40, 40, -30, 30, 10, -10);//coordenadas
glMatrixMode(GL_MODELVIEW);
}
void display(){
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0,0.0,0.0);
glBegin(GL_POINTS);//inicio da modelagem
    glVertex2f(0.0,0.0);//2 == numero de parametros, f == tipo de paramento float
glEnd();//fechando a modelagem
glFlush();
}

void main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
        glutInitWindowSize(800, 600);
        glutInitWindowPosition(100,100);
        glutCreateWindow(" Hello, janela!");
        glutDisplayFunc(display);
    initGL();
    glutMainLoop();
}
