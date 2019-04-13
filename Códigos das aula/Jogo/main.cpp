

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Vetor.h"
#include "Matriz.h"





static GLfloat spin = 0.0;
double rotacao_x= 0;
double rotacao_y=0;





class Bala{
public:
    int x;
    int y;
    Bala(int a, int b){
        this->x = a;
        this->y = b;
    }

    void desenhatiro(){
        glBegin(GL_TRIANGLES);
            glVertex2d(this->x, this->y+2);
            glVertex2d(this->x-2,this->y);
            glVertex2d(this->x+2,this->y);
        glEnd();
        atualizaY();
        glutPostRedisplay();
    }
    void atualizaY(){
        this->y+=5;
    }
};
Bala *tiros[30];
class Nave{
public:
    int x = 0;
    int y = -48;
    int qtdTiro=0;
    bool inimiga;//saber qual nave vou criar
    Bala *bala;
    bool colidiuParede = false;
    Nave(int a, int b, bool ini){
     this->x = a;
     this->y = b;
     this->inimiga = ini;
     if(ini){//se for inimiga aparece aleatorio
        int aux = rand() % 50;
        if(aux %2 == 0){
            this->x = aux;
        }else{
            this->x = aux *= -1;
        }
     }
    }
    void desenha(){
        glBegin(GL_TRIANGLES);
            if(this->inimiga){
                glVertex2d(this->x, this->y-4);
            }else{
                glVertex2d(this->x, this->y+4);
            }
            glVertex2d(this->x-4,this->y);
            glVertex2d(this->x+4,this->y);
        glEnd();
        glutPostRedisplay();
    }
    void trajetoriaInimiga(){
            //cada vez que o objeto colidir com uma parede ele inverte a direção
           if(this->colidiuParede==false){
                this->x -= 1;//esquerda
                this->y -= 1;
                this->desenha();
                if(this->x < -46)
                    this->colidiuParede=true;
           }else{
                this->x += 1;//direita
                this->y -= 1;
                this->desenha();
                if(this->x > 46)
                    this->colidiuParede=false;
           }
           Sleep(20);

    }
    void atira(){
        bala = new Bala(this->x,this->y);
        if(this->qtdTiro < 30){
            tiros[this->qtdTiro] = bala;
            this->qtdTiro++;
            if(this->qtdTiro==30){
                this->qtdTiro = 0;
                delete(tiros[this->qtdTiro]);

            }
        }
    }
    bool colisao(int xN , int yN){
        if(((this->y)-4 < yN+4) &&   (xN-4 <= this->x)   && (this->x <= xN+4) ){
             printf("colidiu xn:%d xi:%d yn:%d yi:%d\n",xN,x,yN,y);
            return true;
        }else{
            return false;
        }
    }
};

//nave do inimigo
Nave *inimigos = new Nave(0,48,true);


//minha nave
Nave *navee = new Nave(0,-48, false);

void tecla(unsigned char tecla, int x, int y){
    if (tecla == 'd'){
        if((navee->x+4)<50)
            navee->x+=4;
        //rotacao_y += 11;
    } else if(tecla == 'a'){
        if((navee->x+4) > -42){
            navee->x-=4;
        }
        //rotacao_y -= 6;
    } else if (tecla == 'w'){
       navee->y+=1;
       // rotacao_x += 11;
    } else if (tecla == 's'){
        //rotacao_x -= 6;
        navee->y-=1;
    }else if(tecla = 'p'){
        navee->atira();
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
    navee->desenha();

    //imprime tiros

    glColor3f(1.0,1.0,1.0);
    for(int in = 0; in<30;in++){
        if(tiros[in] != NULL)
            tiros[in]->desenhatiro();
    }

    glColor3f(1.0,1.0,0.0);
    if(inimigos->colisao(navee->x,navee->y)){
        delete(inimigos);
        inimigos = new Nave(0,48,true);
    }
    inimigos->trajetoriaInimiga();

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

