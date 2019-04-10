
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
        Vetor(const Vetor &v);
        //operadores
        Vetor operator+ (Vetor v);//adi��o
        Vetor operator- (Vetor v);//subtra��o
        Vetor operator* (int n);//produto por escalar
        float modulo();
        Vetor normalizar();
        Vetor inverto();
        Vetor produtoVetorial(Vetor v);

};

#endif // VETOR_H
