#include <iostream>
#include <cmath>

#define N 100

using namespace std;

float fi(float x){
    return cos(x) - exp(-pow(x,2)) + x;
    //return pow(x,3) - 10;
    //return exp(-pow(x,2))- cos(x);
}

float funcao(float x){
    return exp(-pow(x,2)) - cos(x);
}

void imprimir(int k, float raiz){
    cout << "Numeros de interacoes: " << k << endl;
    cout << "Raiz: " << raiz << endl; 
}

void MIL(float x0, float precisao){
    float raiz;
    float x = 0;
    int k = 1;
    if(fabs(fi(x0)) < precisao){
        raiz = x0;
        imprimir(k, raiz);
    }
    else{
        while(fabs(funcao(x0)) > precisao && k < N){
            x = fi(x0);
            k++;
            x0 = x;
        }
        imprimir(k, x0);
    }
}

int main(){
    float x0 = 1.5;
    float precisao = 0.01;
    MIL(x0, precisao);

}