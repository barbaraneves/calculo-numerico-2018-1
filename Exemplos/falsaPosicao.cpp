/* Metodo da Falsa Posicaoo                */ 
/* Autor: Marcone Jamilson Freitas Souza  */
/* E-mail: marcone@iceb.ufop.br           */
/* Data: março de 2009                    */
//---------------------------------------------------------------------------

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <float.h>

/*            Protótipos                      */
float f(float x);

void geraintervalos(float a,
                    float b,
                    float delta);

float falsaposicao(float a,
                   float b,
                   float epsilon,
                   int itermax);

void imprimelinhafalsaposicao(int k,
                              float a,
                              float b,
                              float xk,
                              float xant);


/* Programa principal                      */
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

    printf("Determinando uma raiz ... \n");
    printf("Entre com o extremo esquerdo do intervalo = ");
    scanf("%f", &a);
    printf("Entre com o extremo direito do intervalo = ");
    scanf("%f", &b);
    printf("Entre com a precisao requerida = ");
    scanf("%f", &epsilon);
    printf("\n Aplicando o metodo da Falsa Posicao intervalo [%5.3f, %5.3f]:\n", a, b);

    x = falsaposicao(a, b, epsilon, 10);
    getchar();getchar();
    return 0;
}


/*  Implementaçoes                      */

/* Função */
float f(float x){
  float fx;
  fx = x*x - 2;
  //fx = 2*x - cos(x);
  //fx = sin(x) - sqrt(10)*x + sqrt(10);
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
void imprimelinhafalsaposicao(int k,
                              float a,
                              float b,
                              float xk,
                              float xant){
   if (k == 0){                                    
     printf("%2d \t %5.8f \t %5.8f \t %5.8f \t %6.8f \t -  \n",
            k, a, b, xk, f(xk), fabs(xk - xant));
   }
   else{
     printf("%2d \t %5.8f \t %5.8f \t %5.8f \t %6.8f \t %5.8f \n",
            k, a, b, xk, f(xk), fabs(xk - xant));        
}
}


/* Calcula e imprime uma iteração do Método da Bisseção */
float falsaposicao(float a,
                   float b,
                   float epsilon,
                   int itermax){
   int k;
   float xk, xant;
   printf("Resolucao pelo Metodo da Falsa Posicao \n");
   printf("-------------------------------------------------\n");
   printf("k \t a \t b \t xk \t f(xk) \t x_k - x_{k-1} \n");
   printf("-------------------------------------------------\n");
   k = 0;
   xant = a;
   xk = (a * f(b) - b * f(a))/(f(b) - f(a));
   imprimelinhafalsaposicao(k, a, b, xk, xant);
   while (( xk - xant >= epsilon || fabs(f(xk)) >= epsilon) &&
           k <= itermax){
     if (f(a) * f(xk) < 0){
        b = xk;
     }
     else{
        a = xk;
     }
     xant = xk;
     xk = (a * f(b) - b * f(a))/(f(b) - f(a));
     k = k + 1;
     imprimelinhafalsaposicao(k, a, b, xk, xant);
   }
   printf("-------------------------------------------------\n");
   if (k <= itermax){
     printf("raiz = %5.8f  com precisao < %5.8f \n", xk, epsilon);
   }
   return xk;
}
