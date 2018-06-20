#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int dimensaoG = 3;

vector< vector<double> > matriz;
vector< vector<double> > matrizCriada;
vector<double> X;

void criacaoMatriz(){

    matrizCriada.resize(5);
    
    for(int i = 0; i < 5; i++)
        matrizCriada[i].resize(6, 0.0);

    matrizCriada[0][0] = 0;
    matrizCriada[0][1] = 25;
    matrizCriada[0][2] = 45;
    matrizCriada[0][3] = 65;

    matrizCriada[1][0] = 50;
    matrizCriada[1][1] = 2500;
    matrizCriada[1][2] = 2350;
    matrizCriada[1][3] = 1900;

    matrizCriada[2][0] = 60;
    matrizCriada[2][1] = 2850;
    matrizCriada[2][2] = 2700;
    matrizCriada[2][3] = 2250;

    matrizCriada[3][0] = 70;
    matrizCriada[3][1] = 3200;
    matrizCriada[3][2] = 3000;
    matrizCriada[3][3] = 2750;

    matrizCriada[4][0] = 80;
    matrizCriada[4][1] = 3550;
    matrizCriada[4][2] = 3350;
    matrizCriada[4][3] = 2850;
}

void trocaLinha(int L1, int L2){
    
    vector<double> linha;
    linha.resize(dimensaoG + 1);
    
    for(int i = 0; i < dimensaoG + 1; i++){
        linha[i] = matriz[L1][i];
    }

    for(int i = 0; i < dimensaoG + 1; i++){
        matriz[L1][i] = matriz[L2][i];
        matriz[L2][i] = linha[i];
    }
}

void pivoteamento(int pivo){
    
    double maior = matriz[pivo][pivo];
    int linhaM = pivo;
    
    for(int i = pivo + 1; i < dimensaoG; i++){
        
        if(fabs(maior) < fabs(matriz[i][pivo])){
            maior = matriz[i][pivo];
            linhaM = i;
        }
    }

    if(pivo != linhaM){
        trocaLinha(pivo, linhaM);
    }
}

int contaZeroLinha(int linha){
    
    int cont = 0;
    
    for(int i = 0; i < dimensaoG; i++){
        if(matriz[linha][i] == 0){
            cont++;
        }
        else{
            return cont;
        }
    }
    return cont;
}

vector<double> eliminacaoDeGauss(vector< vector<double> > M){

    matriz.resize(dimensaoG);
    
    for(int i = 0; i < dimensaoG; i++)
        matriz[i].resize(dimensaoG+1, 0.0);

        for (int i = 0; i < dimensaoG; i++){
            for (int j = 0; j < dimensaoG + 1; j++){
                matriz[i][j] = M[i][j];
            }
        }

        for(int i = 0; i < dimensaoG -1; i++){
            for(int j = 1; j < dimensaoG; j++){
                if(contaZeroLinha(i) > contaZeroLinha(j)){
                    trocaLinha(i, j);
                }
            }
        }

        for(int i = 0; i < dimensaoG; i++){
            
            pivoteamento(i);
            
            if(fabs(matriz[i][i]) == 0){
                    cout << "pivo nulo" << endl;
            }
            
            for(int k = i + 1; k < dimensaoG; k++){
                
                double mult = matriz[k][i] / matriz[i][i];
                
                for(int j = i; j < dimensaoG + 1; j++){
                    matriz[k][j] = matriz[k][j] - (mult * matriz[i][j]);
                }
            }
        }

        X.resize(dimensaoG);

        for(int i = dimensaoG - 1; i >= 0; i--){
            
            X[i]  = matriz[i][dimensaoG];
            
            for(int j = i+1; j < dimensaoG; j++){
                X[i] -= matriz[i][j] * X[j];
            }
            
            X[i] = X[i] / matriz[i][i];
        }

        return X;
}

double calculaFuncao(double x, vector<double> a){
    
    return a[0] + a[1] * x + a[2] * pow(x,2);
}


int main(){

    int idade;
    double peso;

    cin >> idade >> peso;

    if((idade < 25 || idade > 65) || (peso < 50 && peso > 80)){
        
        cout << "Idade ou peso invalido!" << endl;
        
        return 0;
     }

    criacaoMatriz();

    vector<double> resultIdade;
    vector< vector<double> > matrizE;
    vector< vector<double> > matrizResultado;

    resultIdade.resize(dimensaoG);

    matrizE.resize(3);
    
    for(int i=0; i<3; i++)
        matrizE[i].resize(4, 0.0);

    matrizResultado.resize(3);
    
    for(int i=0; i<3; i++)
        matrizResultado[i].resize(4, 0.0);

    for(int i = 0;i < 3;i++)
        matrizE[i][0] = 1;

    if(peso >= 50 && peso <=70){
        matrizE[0][1] = 50;
        matrizE[0][2] = 2500;

        matrizE[1][1] = 60;
        matrizE[1][2] = 3600;

        matrizE[2][1] = 70;
        matrizE[2][2] = 4900;

        for (int i = 0; i < dimensaoG; i++) {
            
            for (int j = 0; j < dimensaoG; j++) {
                matrizE[j][3] = matrizCriada[j+1][i+1];
            }
            resultIdade[i] = calculaFuncao(peso, eliminacaoDeGauss(matrizE));
        }
    }
    else{
        matrizE[0][1] = 60;
        matrizE[0][2] = 3600;

        matrizE[1][1] = 70;
        matrizE[1][2] = 4900;

        matrizE[2][1] = 80;
        matrizE[2][2] = 6400;

        for (int i = 1; i < dimensaoG; ++i) {
            
            for (int j = 0; j < dimensaoG; ++j) {
                matrizE[j][3] = matrizCriada[j+1][i];
            }
            resultIdade[i] = calculaFuncao(peso, eliminacaoDeGauss(matrizE));
        }
    }

    for(int i = 0;i < 3;i++)
        matrizResultado[i][0] = 1;

    matrizResultado[0][1] = 25;
    matrizResultado[0][2] = 625;

    matrizResultado[1][1] = 45;
    matrizResultado[1][2] = 2025;

    matrizResultado[2][1] = 65;
    matrizResultado[2][2] = 4225;


    for (int j = 0; j < dimensaoG; ++j)
        matrizResultado[j][3] = resultIdade[j];

    double resultF = calculaFuncao(idade, eliminacaoDeGauss(matrizResultado));
    
    cout << fixed << setprecision(5) << resultF << endl;

    return resultF;
}