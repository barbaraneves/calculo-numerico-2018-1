#include <bits/stdc++.h>

using namespace std;

typedef double LD;

vector <LD> P;

//Método de Horner
LD f(LD x){
	LD res = 0.0;
	int n = P.size();
	
	for(int i = n-1; i >= 1; i--){
		res += P[i];
		res *= x;
	}
	res += P[0];
	return res;
}
		

LD falsaposicao(LD a, LD b, LD epsilon, int itermax){
    int k = 0;
    
    LD xk, xant, FA, FB;
    xant = a;
    
    xk = ((a * f(b)) - (b * f(a)))/(f(b) - f(a));
    
    while (( fabs(xk - xant) >= epsilon || fabs(f(xk)) >= epsilon) &&
            k <= itermax){
     
        FA = f(a);
        FB = f(b);
        
        printf("%d %.8lf %.8lf %.8lf %.8lf\n", k, a, b, xk, f(xk)); 
         
        if (FA * f(xk) < 0){
            b = xk;
            FB = f(xk);
            
            if(f(xk) * f(xant) > 0){
                FA = FA/2;
            }
        }
        else{
            a = xk;
            FA = f(xk);
            
            if(f(xk) * f(xant) > 0){
                FB = FB/2;
            }
        }
        
        xant = xk;
        xk = ((a * FB) - (b * FA))/(FB - FA);
        
        //printf("%.d %.8lf %.8lf %.8lf %8lf\n", k, a, b, xk, f(xk));
        k = k + 1;
    }
    
    printf("%d %.8lf %.8lf %.8lf %.8lf\n", k, a, b, xk, f(xk)); 
    
    return xk;
}

int main(int argc, char* argv[])
{
    int n;
    int max_iteracao;
    LD a, b, x, epsilon;
		
	cin >> n;
	
	P.resize(n + 1);
	for(int i = n; i >= 0; i--)
		cin >> P[i];
		
		
	cin >> a;
	cin >> b;
	cin >> epsilon;
	cin >> max_iteracao;
	
	x = falsaposicao(a, b, epsilon, max_iteracao);
	//printf("%.8lf\n", x);
		
    return 0;
}