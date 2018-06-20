#include <bits/stdc++.h>

using namespace std;

typedef double LD;

const LD EPS = 1e-8;

vector< vector<LD> > M; // Matriz
vector <LD> x; // Solucao


int main(){
    
    int n;

    cin >> n;
		
		//Inicializacao matriz
		M.resize(n);
		for(int i=0; i<n; i++)
        M[i].resize(n+1, 0.0);
		
		//Leitura da matriz
		for(int i = 0; i < n; i++)
        for(int j = 0; j < n+1; j++)
            cin >> M[i][j];
    
    
    //Eliminacao de Gauss
    for(int i=0;i<n;i++){    
        
        if( fabs(M[i][i]) < EPS ){
            cout << "Pivo nulo" << endl;
            return 0;
        }
        for(int j=i+1; j<n; j++){
            LD r = M[j][i]/M[i][i];
            for(int k=i; k<n+1; k++){
                M[j][k]= M[j][k] - r*M[i][k];
            }
        }
    }
    
    //Mostrando matriz
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n+1; j++){
            LD elem = M[i][j];
            cout << fixed << setprecision(5) << elem << " ";
        }
        cout << endl;
    }
    
    
    x.resize(n);
    //Substituição retroativa
    for(int i = n-1; i >= 0; i--){
			x[i]  = M[i][n];
			for(int j = i+1; j < n; j++){
				x[i] -= M[i][j]*x[j];
			}
			x[i] = x[i]/M[i][i];
		}
    
    //Solucao
    for(int i = 0; i < n; i++){
			cout << "x[" << i << "] = " << fixed << setprecision(5) << x[i] << " " << endl;
    }
    
 		
    return 0;


}
