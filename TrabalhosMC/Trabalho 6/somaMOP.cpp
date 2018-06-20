#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int grau = 0;
vector< long long int> equacao;
vector< vector < long double > > mEquacao;
vector<long double> MOP;

double calcEquacao(int x){
    
    double result = equacao[0];
    
    for(int i = 1; i <= grau; i++){
        result += equacao[i] * (pow(x, i));
    }
    return result;
}

double LG(int posicao, int pontos){
    
    if(pontos == 1){
        return 1;
    }
    else{
        double LG1 = 1;
        
        for(int i = 0; i < pontos; i++){
            if(posicao == i){

            }
            else{
               LG1 *= ((pontos + 1) - mEquacao[i][0]);
            }

        }

        double LG2 = 1;
        
        for(int i = 0; i < pontos; i++){
            if(posicao == i){

            }
            else{
                LG2 *= (mEquacao[posicao][0] - mEquacao[i][0]);
            }

        }
        return LG1 / LG2;
    }
}


double PN(int pontos){
    
    double pn = 0;
    
    for(int i = 0; i < pontos; i++){
        pn += mEquacao[i][1] * LG(i, pontos);
    }
    return pn;
}

int main(){
    
    cin >> grau;
    equacao.resize(grau);

    for(int i = 0; i <= grau; i++){
        cin >> equacao[i];
    }

    mEquacao.resize(grau);

    for(int i = 0; i < grau; i++){
        mEquacao[i].resize(2);
    }

    for(int i = 0; i < grau; i++){
        mEquacao[i][0] = i + 1;
    }

    for(int j = 0; j < grau; j++){
        mEquacao[j][1] = calcEquacao(mEquacao[j][0]);
    }

    MOP.resize(grau);

    for(int i = 1; i <= grau; i++){
        MOP[i - 1] = PN(i); 
    }

    long long int resposta = 0;
    
    for(int i = 0; i < grau; i++){
        resposta += MOP[i];
    }

    cout << resposta << endl;
    return 0;
}