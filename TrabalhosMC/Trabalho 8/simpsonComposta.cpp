#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <math.h>

using namespace std;

int grau = 0;
int quant = 0;
double inicio = 0;
double fim = 0;
vector<int> coeficientes;


double calculaFuncao (double x){
    
    double equacao = coeficientes[0];
    
    for(int i = 1; i <= grau; i++){
        equacao += coeficientes[i] * (pow(x,i));
    }
    return equacao;
}

double regraSimpson(double inicio, double fim){
    
    double h = (fim - inicio)/2;
    double meio = inicio + h;

    double resolucao = (h/3) * (calculaFuncao(inicio) + (4 * calculaFuncao(meio)) + calculaFuncao(fim));

    return resolucao;
}


double regraSimpsonComposta(double inicio, double fim, int quant){

    double h = (fim - inicio)/quant;
    double soma = 0.0;
    double x0 = inicio;
    double x1 = x0 + h;

    for(int i = 0; i < quant; i++){
        soma += regraSimpson(x0, x1);
        x0 = x1;
        x1 = x0 + h;
    }

    return soma;
}

int main(){

    cin >> grau;

    coeficientes.resize(grau);

    for(int i = 0; i <= grau; i++){
        cin >> coeficientes[i];
    }

    cin >> inicio >> fim >> quant;

    double resultado = regraSimpsonComposta(inicio, fim, quant);

    cout << fixed << setprecision(5) << resultado << endl;

    return 0;
}