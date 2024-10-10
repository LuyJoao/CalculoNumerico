#include <iostream>
#include <cmath>
using namespace std;

float funcao(float x) {
    return pow(x, 3) - 0.5;
}

float divisao(float x0, float x1) {
    return funcao(x1) * (x1 - x0) / (funcao(x1) - funcao(x0));
}

float verifica(float x0, float x1, float precisao) {
    if (fabs(funcao(x0)) < precisao) {
        return x0;
    }
    if (fabs(funcao(x1)) < precisao || fabs(x1 - x0) < precisao) {
        return x1;
    }
    return 0;
}

int main() {
    float x0, x1, precisao, raiz;
    int k = 0, it = 100;

    cout << "Digite o x0: ";
    cin >> x0;
    cout << "Digite o x1: ";
    cin >> x1;
    cout << "Digite a precisao: ";
    cin >> precisao;

    raiz = verifica(x0, x1, precisao);
    if (raiz != 0) {
        cout << "Raiz inicial encontrada: " << raiz << endl;
        return 0;
    }

    while (k < it){
        float x2 = x1 - divisao(x0, x1);
        if (fabs(funcao(x2)) < precisao || fabs(x2 - x1) < precisao) {
            raiz = x2;
            break;
        }
        x0 = x1;
        x1 = x2;
        k++;
    };

    cout << "Raiz: " << raiz << endl;
    cout << "k: " << k << endl;
    cout << "x0: " << x0 << endl;
    cout << "x1: " << x1 << endl;

    return 0;
}