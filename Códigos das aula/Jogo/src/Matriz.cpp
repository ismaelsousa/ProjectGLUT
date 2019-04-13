#include "Matriz.h"
//construtores
Matriz::Matriz()
{
    //ctor
}
//passando uma matriz
Matriz::Matriz(const Matriz &matriz){
    this->m[0] = matriz.m[0];
    this->m[1] = matriz.m[1];
    this->m[2] = matriz.m[2];
    this->m[3] = matriz.m[3];
}
//passando vario vetores
Matriz::Matriz(const Vetor &posicao0,const Vetor &posicao1,const Vetor &posicao2,const Vetor &posicao3){
    this->m[0] = posicao0;
    this->m[1] = posicao1;
    this->m[2] = posicao2;
    this->m[3] = posicao3;
}

//sobrecarga de operadores
Matriz Matriz::operator + (Matriz &argMatriz){
    // ideia: para somar linha por linha eu usei o proprio operador do vetor de somar
    return Matriz(this->m[0]+argMatriz.m[0],
                  this->m[1]+argMatriz.m[1],
                  this->m[2]+argMatriz.m[2],
                  this->m[3]+argMatriz.m[3]);
}

Matriz Matriz::operator - (Matriz &argMatriz){
    return Matriz(this->m[0]-argMatriz.m[0],
                  this->m[1]-argMatriz.m[1],
                  this->m[2]-argMatriz.m[2],
                  this->m[3]-argMatriz.m[3]);
}

//multiplicação por escalar
Matriz Matriz::operator * (Matriz &argMatriz){
    float calculada[4][4];

    for(int i =0; i<4;i++){
        for(int j=0; j<4; j++){
            calculada[i][j] = this->m[i]*(argMatriz.extrairColuna(j));
        }
    }


    return Matriz(Vetor(calculada[0][0],//x
                        calculada[0][1],//y
                        calculada[0][2],//z
                        calculada[0][3]),//w

                  Vetor(calculada[1][0],//x
                        calculada[1][1],//y
                        calculada[1][2],//z
                        calculada[1][3]),//w

                  Vetor(calculada[2][0],//x
                        calculada[2][1],//y
                        calculada[2][2],//z
                        calculada[2][3]),//w

                  Vetor(calculada[3][0],//x
                        calculada[3][1],//y
                        calculada[3][2],//z
                        calculada[3][3]));//w

}


//
Vetor Matriz::extrairColuna(int c){
    if(c == 0){
       float x0 = this->m[0].x;
       float x1 = this->m[1].x;
       float x2 = this->m[2].x;
       float x3 = this->m[3].x;
       return Vetor(x0,x1,x2,x3);
    }
    if(c == 1){
       float y0 = this->m[0].y;
       float y1 = this->m[1].y;
       float y2 = this->m[2].y;
       float y3 = this->m[3].y;
       return Vetor(y0,y1,y2,y3);
    }if(c == 2){
       float z0 = this->m[0].z;
       float z1 = this->m[1].z;
       float z2 = this->m[2].z;
       float z3 = this->m[3].z;
       return Vetor(z0,z1,z2,z3);
    }if(c == 3){
       float w0 = this->m[0].w;
       float w1 = this->m[1].w;
       float w2 = this->m[2].w;
       float w3 = this->m[3].w;
       return Vetor(w0,w1,w2,w3);
    }
    return Vetor();
}

