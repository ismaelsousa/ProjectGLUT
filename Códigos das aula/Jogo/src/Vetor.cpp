#include "Vetor.h"
#include <cmath>
#include<stdio.h>
Vetor::Vetor()
{
    //ctor
}

Vetor::Vetor(float x, float y, float z,float w){
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

Vetor::Vetor(const Vetor& v){
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    this->w = v.w;
}

//Add e sub
Vetor Vetor::operator+ (Vetor v){
    return Vetor(this->x + v.x,this->y + v.y,this->z + v.z,this->w + v.w);
}



Vetor Vetor::operator- (Vetor v){
    return Vetor(this->x - v.x,this->y - v.y,this->z - v.z,this->w - v.w);
}

//produto por escalar
Vetor Vetor::operator* (int n){
    return Vetor(this->x *n,this->y *n,this->z *n,this->w *n);
}
float Vetor::operator* (Vetor v){//retorn um numero calculado
    return ((this->x * v.x)+(this->y * v.y)+(this->z * v.z)+(this->w * v.w));
}



//modulo
float Vetor::modulo(){
    return sqrt(this->x*this->x + this->y*this->y + this->z*this->z + this->w*this->w);
}

Vetor Vetor::normalizar(){
    float denominador = this->modulo();
    return Vetor((this->x/denominador),(this->y/denominador),(this->z/denominador),(this->w/denominador));
}

Vetor Vetor::inverto(){
    return Vetor(this->x *-1,this->y *-1,this->z *-1,this->w *-1);
}

Vetor Vetor::produtoVetorial(Vetor v){
    float x = (this->y*v.z) - (this->z*v.y);
    float y = (this->z*v.x) - (this->x*v.z);
    float z = (this->x*v.y) - (this->y*v.x);
    return Vetor(x,y,z,v.w);
}
