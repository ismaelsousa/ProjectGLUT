#include "Vetor.h"
#include <cmath>
Vetor::Vetor(float x, float y, float z,float w){
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}


Vetor Vetor::operator+ (Vetor v){
    return Vetor(this->x + v.x,this->y + v.y,this->z + v.z,this->w + v.w);
}

Vetor Vetor::operator* (int n){
    return Vetor(this->x *n,this->y *n,this->z *n,this->w *n);
}

float Vetor::modulo(){
    return sqrt(this->x*this->x + this->y*this->y + this->z*this->z + this->w*this->w);
}

Vetor Vetor::normalizar(){

}
