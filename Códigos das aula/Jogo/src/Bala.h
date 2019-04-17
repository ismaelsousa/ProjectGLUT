#ifndef BALA_H
#define BALA_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

class Bala
{
    public:
        int x;
        int y;
        Bala(int a, int b);
        void desenhatiro();
        void atualizaY();

};

#endif // BALA_H
