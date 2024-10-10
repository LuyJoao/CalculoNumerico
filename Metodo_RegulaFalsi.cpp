#include <iostream>
#include <cmath>


using namespace std;


double f(double x)
{
    // return exp(-pow(x,2)) - cos(x);
    return x * log10(x) - 1;
}


int main()
{
    double a, b, precisao1, precisao2, x, M;
    int it, k;


    cout << "Digite A: ";
    cin >> a;
    cout << "Digite B: ";
    cin >> b;
    cout << "Digite a primeira precisão: ";
    cin >> precisao1;
    cout << "Digite a segunda precisão: ";
    cin >> precisao2;
    cout << "Digite o número máximo de iterações: ";
    cin >> it;


    if (fabs(b - a) < precisao1)
    {
        x = (a + b) / 2;
        cout << "Raiz aproximada: " << x << endl;
        cout << "Numero de interacoes: " << k << endl;
        return 0;
    }


    if (fabs(f(a)) < precisao2)
    {
        cout << "Raiz aproximada: " << a << endl;
        cout << "Numero de interacoes: " << k << endl;
        return 0;
    }


    if (fabs(f(b)) < precisao2)
    {
        cout << "Raiz aproximada: " << b << endl;
        cout << "Numero de interacoes: " << k << endl;
        return 0;
    }


    k = 1;
    M = f(a);


    while (k <= it)
    {
        x = (a * f(b) - b * f(a)) / (f(b) - f(a));


        if (fabs(f(x)) < precisao2 || k > it)
        {
            cout << "Raiz aproximada: " << x << endl;
            cout << "Numero de interacoes: " << k << endl;
            return 0;
        }


        if (M * f(x) > 0)
        {
            a = x;
        }
        else
        {
            b = x;
        }


        if (fabs(b - a) < precisao1)
        {
            x = (a + b) / 2;
            cout << "Raiz aproximada: " << x << endl;
            cout << "Numero de interacoes: " << k << endl;
            return 0;
        }


        k++;
    }


    cout << "Número máximo de iterações atingido." << endl;


    return 0;
}