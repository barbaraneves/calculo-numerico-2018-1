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
		


LD bissecao(LD a, LD b, LD epsilon, int itermax){

	 int k;
   LD xk;
   k = 0;
   xk = (a + b)/2;
   while (( b - a >= epsilon || fabs(f(xk)) >= epsilon) &&
           k <= itermax){
     
     printf("%d %.5lf %.5lf %.5lf %.5lf\n",k, a, b, xk, f(xk)); 
     
     if (f(a) * f(xk) <= 0){
        b = xk;
     }
     else{
        a = xk;
     }
     xk = (a + b)/2;
     
     
     k = k + 1;
   }
   
   printf("%d %.5lf %.5lf %.5lf %.5lf\n",k, a, b, xk, f(xk)); 
     
   return xk;
}





LD falsaposicao(LD a, LD b, LD epsilon, int itermax){
   int k;
   LD xk, xant;
   k = 0;
   xant = a;
   xk = (a * f(b) - b * f(a))/(f(b) - f(a));
   while (( xk - xant >= epsilon || fabs(f(xk)) >= epsilon) &&
           k <= itermax){
     
     printf("%d %.5lf %.5lf %.5lf %.5lf\n",k, a, b, xk, f(xk)); 
     
     if (f(a) * f(xk) < 0){
        b = xk;
     }
     else{
        a = xk;
     }
     xant = xk;
     xk = (a * f(b) - b * f(a))/(f(b) - f(a));
     //printf("%.5lf %.5lf %.5lf %.5lf\n",a,b, xk, f(xk));
     k = k + 1;
   }
   
   printf("%d %.5lf %.5lf %.5lf %.5lf\n",k, a, b, xk, f(xk)); 
   
   return xk;
}
               


void geraintervalos(LD a, LD b, LD delta, LD epsilon){
  float xk;
  int k;
  k = 0;
  xk = a;
  while (xk < b){
    k = k + 1;
    if( f(xk)*f(xk+delta) < 0 ){
			LD x = bissecao(xk, xk+delta, epsilon, 100);
			printf("%lf\n", x);
		}
    
    xk = xk + delta;
  }
  
}



int main(int argc, char* argv[])
{
    int n;
    int max_iteracao;
    LD a, b, delta, epsilon, x;
		
		cin >> n;
		
		P.resize(n+1);
		for(int i = n; i >= 0; i--)
			cin >> P[i];
		
		
		cin >> a;
		cin >> b;
		cin >> epsilon;
		cin >> max_iteracao;
		//x = bissecao(a,b, epsilon, max_iteracao);
		//printf("%lf\n", x);
		//x = falsaposicao(a,b, epsilon, max_iteracao);
		//printf("%lf\n", x);
		//x = bissecaofalsa(a,b, epsilon, max_iteracao);
		//printf("%lf\n", x);
		x = falsaposicao(a,b, epsilon, max_iteracao);
		printf("%.8lf\n", x);
		
		
		//geraintervalos(a, b, delta, epsilon);
		
		
    
    return 0;
}



