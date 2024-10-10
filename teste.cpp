#include <iostream>
#include <cmath>
using namespace std;

double funcao(double x){
    return pow(x,3) - 10;
}

void bisseccao(double a, double b, double p, int k, int NumIt){
    double fini, fmeio, meio;
    while(fabs(b-a) > p && k < NumIt){
    k = k + 1;
    fini = funcao(a);
    meio = (a+b)/2;
    fmeio = funcao(meio);

        if(fini*fmeio<0){
            b = meio;
        }else{
            a = meio;
        }
    }
    cout << "Numero de Iteracoes: " << k << endl;
    cout << "Raiz: " << meio;
}

int main(){
    double a, b, p;
    int NumIt;
    int k;
    cout << "Insira as raizes:" << endl;
    cin >> a;
    cin >> b;
    cout << "Insira a precisao:" << endl;
    cin >> p;

    k = 0;

    if(fabs(b-a) < p){
        return b-a;
    }else{
        bisseccao(a, b, p, k, NumIt);
    }

}