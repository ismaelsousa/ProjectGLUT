#ifndef VETOR_H
#define VETOR_H


class Vetor{
    public:
        float x;
        float y;
        float z;
        float w;
        //construtor
        Vetor(float x, float y, float z,float w);
        //operadores
        Vetor operator+ (Vetor v);
        Vetor operator* (int n);
        float modulo();
        Vetor normalizar();
};

#endif // VETOR_H
