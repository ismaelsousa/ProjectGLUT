#ifndef MATRIZ_H
#define MATRIZ_H
#include "Vetor.h"

class Matriz
{
    public:
        Vetor m[4];
        Matriz();
        Matriz(const Matriz &matriz);
        Matriz(const Vetor &posicao0,const Vetor &posicao1,const Vetor &posicao2,const Vetor &posicao3);
        Matriz operator + (Matriz &argMatriz);//<tipo_retorno> operator op (<lista_de_parametros>);
        Matriz operator - (Matriz &argMatriz);
        Matriz operator * (Matriz &argMatriz);
        Vetor extrairColuna(int c);
    protected:

    private:
};

#endif // MATRIZ_H
