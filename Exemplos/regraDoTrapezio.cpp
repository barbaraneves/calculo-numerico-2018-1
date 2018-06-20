#include <bits/stdc++.h>

using namespace std;


double f(double x){
	return x*x;
}

double regra_trapezio(double (*f)(double), double a, double b){
	double h = b-a;
	return (h/2.0)*(f(a)+f(b));
}

double regra_trapezio_composta(double (*f)(double), double a, double b, int N){
	double h = (b-a)/N;
	
	double sum = 0.0;
	double x_0 = a;
	double x_1 = x_0 + h;
	for(int i = 0; i < N; i++){
		sum += regra_trapezio(f, x_0, x_1);
		
		x_0 = x_1;
		x_1 = x_0 + h;
	}
	return sum;
}

double regra_trapezio_adaptativa(double (*f)(double), double a, double b,double epsilon){

	double S1 = regra_trapezio(f,a,b);
	double Sleft = regra_trapezio(f,a,(a+b)/2.0);
	double Sright = regra_trapezio(f,(a+b)/2.0, b);
	double S2 = Sleft + Sright;
	
	if( fabs(S1-S2)/3.0 <= epsilon){
		return S2;	
	}else{
		return regra_trapezio_adaptativa(f,        a, (a+b)/2.0, epsilon/2.0) +
		       regra_trapezio_adaptativa(f,(a+b)/2.0,         b, epsilon/2.0) ;
	}
}


int main(){
	printf("%lf\n", regra_trapezio(f, 0, 1) );
	
	for(int i = 1 ; i < 30; i++)
		printf("%d %lf\n", i, regra_trapezio_composta(f, 0, 1, i) );
	
	printf("%lf\n", regra_trapezio_adaptativa(f, 0 , 1, 0.0001) );
	
}






