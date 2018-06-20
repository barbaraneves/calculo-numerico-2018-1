#include <bits/stdc++.h>

using namespace std;

int conversao(vector <int> a, int b){
	
	int resultado = 0;
	int base = 1;
	for(int i = 0; i < a.size(); i++){
		resultado += a[i]*base;
		base = base*b;
	}
	return resultado;
	
}

int conversao2(vector <int> a, int b){
	int resultado = 0;
	
	for(int i = a.size()-1; i >= 1; i--){
		resultado += a[i];
		resultado *= b;
	}
	resultado += a[0];
	
	return resultado;
	
}

int conversao3(vector <int> a, int b){
	int n = a.size();
	int resultado = a[n-1];
	
	for(int i = n-2; i >= 0; i--){
		resultado *= b;
		resultado += a[i];
		
	}
	return resultado;
}

string baseB(int N, int b){
	string a;
	while( N != 0 ){
		a.push_back( '0' + N%b );
		N = N/b;
	}
	return a;
}

string baseF(double x, int b, int prec=32){
	string a;
	double fractional = x;
	a.push_back('.');
	while( prec-- ){
		fractional *= b;
		int frac_int = fractional;
		
		if( frac_int != 0){
			fractional -= frac_int;
			a.push_back('0' + frac_int);
		}else{
			a.push_back('0');
		}
	}
	return a;
}


void show(vector <int> a, int b = 10){
	int n = a.size();
	cout << "(";
	for(int i = n- 1; i >= 0; i--)
		cout << a[i] << " ";
	cout << ")" << b;
}

double conversaoF(vector <int> a, int b){
	
	double resultado = 0.0;
	double base = 1.0;
	for(int i = 0; i < a.size(); i++){
		base = base/b;
		resultado += a[i]*base;
	}
	return resultado;
}

float epsilonMaq(){
	float epsilon, eps = 1.0;
	do{
		epsilon = eps;
		eps /= 2;
	}while( eps + 1 != 1);
	return epsilon;
}

double epsilonMaq2(){
	double epsilon, eps = 1;
	do{
		epsilon = eps;
		eps /= 2;
	}while( eps + 1 != 1);
	return epsilon;
}


typedef union {
  float f;
  struct {
    unsigned int mantisa : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
  } parts;
} float_cast;


typedef union {
  double d;
  struct {
    unsigned long long mantisa : 52;
    unsigned int exponent : 11;
    unsigned int sign : 1;
  } parts;
} double_cast;


void printFloat(float f){
  float_cast d1;
  d1.f = f;
  printf("sign = %x\n", d1.parts.sign);
  printf("exponent = %d\n", d1.parts.exponent);
  printf("mantisa = %x\n", d1.parts.mantisa);
};

void printDouble(double d){
  double_cast d1;
  d1.d = d;
  printf("sign = %x\n", d1.parts.sign);
  printf("exponent = %d\n", d1.parts.exponent);
  printf("mantisa = %llx\n", d1.parts.mantisa);
};


int main(){
	float S;
	
	S = 0.0;

	for(int i = 1; i <= 30000; i++)
		S += 0.25;
		
	printf("%lf\n", S);	
	
	S = 0.0;
	
	for(int i = 1; i <= 30000; i++){
		S += 0.1;
		if(i%1000)
			printf("%d %lf\n", i, S);
	}
	
	printf("%f\n", S);
		
	double T;
		
	T = 0.0;
	
	for(int i = 1; i <= 30000; i++)
		T += 0.1;
	
	printf("%lf\n", T);
	
		
	vector <int> a;
	a.push_back(0);
	a.push_back(0);
	a.push_back(1);
	
	cout << conversao(a, 2) << endl;
	cout << conversao2(a, 2) << endl;
	cout << conversao3(a, 2) << endl;
	
	 
	
	cout << baseB(347,2) << endl;
	
	vector <int> b;
	b.push_back(1);
	b.push_back(0);
	b.push_back(1);
	
	cout << conversaoF(b, 2) << endl; 
	
	cout << baseF(0.1, 2, 64) << endl;
		
	S = 0.0;
	for(int i = 1; i <= 30000; i++){
		S += 0.1;
		if(i%2000==0){
			printf("%d sum = %lf prod = %lf\n", i, S, 0.1*i);
		}
	}		
	
	printf("%.40lf\n", epsilonMaq() );
	printf("%.40lf\n", epsilon2() );
	 
	cout << epsilonMaq() << endl;
	cout << epsilon2() << endl;
	
	printFloat(1.0);
	printFloat(0.5);
	printFloat(0.25);
	printFloat( epsilonMaq() );
	
	float_cast d1;
	d1.parts.sign = 0;
	d1.parts.exponent = 0xFF;
	d1.parts.mantisa = 1;
	
	cout << d1.f << endl;
	d1.parts.mantisa = 0;
	
	cout << d1.f << endl;
	
	d1.parts.sign = 0;
	d1.parts.exponent = 1;
	d1.parts.mantisa = 0;
	
	cout << d1.f << endl;
	
	d1.parts.sign = 0;
	d1.parts.exponent = 254;
	d1.parts.mantisa = ~0;
	
	cout << d1.f << endl;
	
	
	cout << "epsilon " << epsilonMaq() << endl;
	cout << "epsilon " << epsilonMaq2() << endl;
	
	
	printFloat( epsilonMaq() );





	printDouble( epsilonMaq2() );	


} 
