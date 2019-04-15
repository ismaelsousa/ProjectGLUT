#ifndef VETOR_H
#define VETOR_H

//estou usando

class Vetor
{
    public:
        float x;
        float y;
        float z;
        float w;
        //construtor
        Vetor();
        Vetor(float x, float y, float z,float w);
        Vetor(const Vetor &v);
        //operadores
        Vetor operator+ (Vetor v);//adi��o
        Vetor operator- (Vetor v);//subtra��o
        Vetor operator* (int n);//produto por escalar
        float operator* (Vetor v); //mult dois vetores
        float modulo();
        Vetor normalizar();
        Vetor inverto();
        Vetor produtoVetorial(Vetor v);
        Vetor transladar(Vetor b);

    protected:

    private:
};

#endif // VETOR_H
