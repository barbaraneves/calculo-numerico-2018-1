#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int fatorial(int x){
    if(x == 1){
        return 1;
    }
    return x*fatorial(x - 1);
}

double euler(double epsilon){
	double x0 = 1.0; //aproximacao anterior
	int iter = 0; // iteracao
	double termo = 1.0;
	double x; // nova aproximacao
	double error; // erro relativo
	
	do{
		iter++;
		termo = 1.0/(fatorial(iter)); // calcula termo
		x = x0 + termo; //calcule x
		error = fabs((x-x0)/x); // calcula erro relativo
		x0 = x;
	}while(error > epsilon); // criterio de parada

	return x;
}



int main(){

	double epsilon;
			
	cin >> epsilon;
	
	cout << fixed << setprecision(15) << euler(epsilon) << endl;
	
}