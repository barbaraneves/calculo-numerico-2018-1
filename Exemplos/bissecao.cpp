/* Método da Bisseção                */ 
/* Autor: Marcone Jamilson Freitas Souza  */
/* E-mail: marcone@iceb.ufop.br           */
/* Data: março de 2009                    */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#pragma argsused

/* Protótipos                              */

float f(float x);

void geraintervalos(float a,
                    float b,
                    float delta);

float bissecao(float a,
               float b,
               float epsilon,
               int itermax);
               
float newton(float x0,
             float epsilon);               

void imprimelinhabissecao(int k,
                          float a,
                          float b,
                          float xk);


/* Programa principal                              */
int main(int argc, char* argv[])
{
    float a, b, delta, epsilon, x;

    printf("Entre com o extremo esquerdo do intervalo = ");
    scanf("%f", &a);
    printf("Entre com o extremo direito do intervalo = ");
    scanf("%f", &b);
    printf("Entre com o espacamento requerido = ");
    scanf("%f", &delta);
    printf("\n Gerando pontos (xi, f(xi)) espacados de %5.3f no intervalo [%5.3f, %5.3f]\n", delta, a, b);
    geraintervalos(a, b, delta);
  
    printf("\n");
    printf("Entre com o extremo esquerdo do intervalo = ");
    scanf("%f", &a);
    printf("Entre com o extremo direito do intervalo = ");
    scanf("%f", &b);
    printf("Entre com a precisao requerida = ");
    scanf("%f", &epsilon);
    printf("\n Aplicando o metodo da bissecao no intervalo [%5.3f, %5.3f]:\n", a, b);

    x = bissecao(a, b, epsilon, 10);
    getchar();getchar();
    return 0;
}

/* Implementações                              */

/* Função */
float f(float x){
  float fx;
  fx = 2*x - cos(x);
  return fx;
}


/* Gera subintervalos espaçados de delta em delta, a partir do ponto a até b */
void geraintervalos(float a,
                    float b,
                    float delta){
  float xk;
  int k;
  k = 0;
  xk = a;
  printf("--------------------------------\n");
  printf("k \t xk \t f(xk) \n");
  printf("--------------------------------\n");
  while (xk < b){
    printf("%2d \t %5.3f \t %6.3f \n", k,  xk, f(xk));
    k = k + 1;
    xk = xk + delta;
  }
  printf("%2d \t %5.3f \t %5.3f \n", k,  b, f(b));
  printf("--------------------------------\n");
}

/* Faz o cabecalho para aplicar o Método da Bisseção */
void imprimelinhabissecao(int k,
                          float a,
                          float b,
                          float xk){
   printf("%2d \t %5.8f \t %5.8f \t %5.8f \t %6.8f \t %5.8f \n",
          k, a, b, xk, f(xk), b - a);
}


/* Calcula e imprime uma iteração do Método da Bisseção */
float bissecao(float a,
               float b,
               float epsilon,
               int itermax){
   int k;
   float xk;
   printf("Resolucao pelo Metodo da Bissecao \n");
   printf("-------------------------------------------------\n");
   printf("k \t a \t b \t xk \t f(xk) \t b - a \n");
   printf("-------------------------------------------------\n");
   k = 0;
   xk = (a + b)/2;
   imprimelinhabissecao(k, a, b, xk);
   while (( b - a >= epsilon || fabs(f(xk)) >= epsilon) &&
           k <= itermax){
     if (f(a) * f(xk) < 0){
        b = xk;
     }
     else{
        a = xk;
     }
     xk = (a + b)/2;
     k = k + 1;
     imprimelinhabissecao(k, a, b, xk);
   }
   printf("-------------------------------------------------\n");
   if (k <= itermax){
     printf("raiz = %5.10f  com precisao < %5.10f \n", xk, epsilon);
   }
   return xk;
}
