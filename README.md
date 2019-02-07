# Matemática Computacional

Repositório que contém as atividades da disciplina de Matemática Computacional.

## Linguagens Utilizada

C e C++.

### Atividade 1

Programa que recebe uma tolerância para o erro relativo da aproximação de épsilon (e) e imprime o valor dessa aproximação precisão com 15 casas decimais.

- Entrada - Um número ponto flutuante com precisão dupla épsilon;

- Saída - O menor valor ```e(n)``` tal que o erro relativo entre duas aproximações seja menor que épsilon.

### Atividade 2

Implementação da eliminação de Gauss com pivoteamento parcial que transforma a matriz original em uma matriz triangular superior e devolve o determinante dessa matriz.

- Entrada - A primeira linha possui um inteiro ```N```, representando a dimensão a matriz. Cada uma das ```N``` linhas seguintes contém ```N + 1``` números reais, sendo o último número real representando o termo independente;

- Saída - A saída contém ```N``` linhas. Cada linha contém ```N + 1``` números reais, escritos com a precisão de cinco casas decimais seguindo de mais ```N``` linhas. A i-ésima linha seguinte tem o formato 
```
x[i] = v
```
onde ```v``` é um número real, escrito como a precisão de cinco casas decimais, representando o valor da variável ```i``` no sistema de equação;

### Atividade 3

Implementação do Método de Gauss-Seidel.

- Entrada - A primeira linha possui um inteiro ```N``` representando a dimensão a matriz. Cada uma das ```N``` linhas seguintes contém ```N + 1``` números reais, sendo o último número real representando o termo independente do sistema linear seguido de ```1``` linha contendo ```N``` números reais representando uma aproximação inicial para o solução do sistema. Na linha seguinte, um número real epsilon (e) representando a precisão tolerada. Na última linha, um inteiro ```MAX_ITER``` representando o número máximo de iterações do método;

- Saída - A saída contém ```N + 1``` linhas por iteração do método. Na primeira linha, temos o identificador da iteração no seguinte formato 
```
"ITERACAO n"
```
onde ```n``` é o número da iteração. As ```N``` linhas seguintes, temos os valores do vetor de solução no seguinte formato
```
x[i] = v
```
onde ```i``` é o identificador da variável variando entre ```0``` e ```n - 1``` e ```v``` o valor da variável ```i``` na iteração corrente;

### Atividade 4

Implementação do Método da Posição Falsa Modificada.

- Entrada - A primeira linha da entrada tem um inteiro ```N```, representando o grau da função ```f```. Na segunda linha, temos ```N + 1``` números reais representando os coeficientes da função. A terceira linha contém três números reais a, b e epsilon, e um inteiro ```MAX_ITER```, onde ```[a, b]``` representam um intervalo que contém uma raiz da função ```f```, o epsilon representa a precisão, e ```MAX_ITER``` representa o número máximo de iterações;

- Saída - A saída possui uma linha para cada iteração do método. Cada linha possui um inteiro ```k```, representando a iteração do método seguido de 4 números reais escritos com 8 casas decimais 
```
a,b,x_k,f(x_k)
```

### Atividade 5

Implementação da Interpolação Quadrática Dupla / Problema "Dieta do Professor Mil Grau": O professor Mil Grau precisa fazer uma dieta em que a quantidade ideal de calorias para homens que realizam atividade física moderada a uma temperatura ambiente depende da idade e do peso. O professor encontrou uma tabela que relaciona essa quantidade ideal de calorias em função da idade e do peso. Agora, o professor Mil Grau precisa determinar a cota aproximada de calorias para um homem de ```N``` anos que pesa ```M``` kg usando uma interpolação quadrática dupla.

- Entrada - A entrada possui dois inteiros
```
N (25 <= N <= 65)
``` 

e

```
M (50 <= M <= 70)
``` 
separados por um espaço;

- Saída - A saída devolve um número ponto flutuante com 5 casas decimais depois da vírgula representando a cota aproximada de calorias para um homem de ```N``` anos que pesa ```M``` kg;

### Atividade 6

Encontrar a soma ```MOP``` para um certo polinômio: Definiremos 
```
OP(k, n)
``` 
como o enésimo termo da função geradora polinomial ótima para os primeiros ```k``` termos de uma sequência. ```OP(k, n)``` irá gerar com precisão os termos da sequência para ```n ≤ k```, e potencialmente o primeiro termo incorreto será ```OP(k, k + 1)```, o qual chamaremos de um 
```
MOP (Mal OP)
```
Como base, se nos fosse dado apenas o primeiro termo de sequência, seria mais sensato assumir constância, isto é, para 
```
n ≥ 2, OP(1, n) = u1
```

- Entrada - A entrada possui duas linhas: a primeira linha contém um inteiro ```D``` representando o grau do polinômio dado, e a segunda linha contém ```N + 1``` inteiros representando ```a_0, a_1, ..., a_D``` que são os coeficientes do grau do polinômio tal que  
```
P(n) = a_0 + (a_1 * n) + (a_2 * n^2) + ... + (a_D * n^D)
```

- Saída - A saída devolve um inteiro representando a soma dos ```MOPs``` obtidas pelos polinômios ```OP(1, N) + OP(2, N) + ... + OP(D - 1, N)```;

### Atividade 7

Problema "Professor Mil Grau": Dada a sequência ```{1, 2, 3, 4, 5}```, qual é o próximo número? Às vezes é muito fácil responder, às vezes pode ser bem difícil. O professor Mil Grau da disciplina de Matemática Computacional notou que essas perguntas podem ser resolvidas descrevendo a sequência usando polinômios. Por exemplo, a sequência ```{1, 2, 3, 4, 5}``` pode ser facilmente entendida como um polinômio trivial: ```P(n) = n```, ou seja, o próximo número será 6. Mas, sequências mais complexas, como ```{1, 2, 4, 7, 11}```, podem ser descritas pelo polinômio ```P(n) = (1/2 * n^2) - (1/2 * n+1)```. Note que mesmo se os membros da sequência são inteiros, os coeficientes polinomiais podem ser quaisquer números reais. Sabemos que um polinômio é uma expressão da seguinte forma
```
P(n) = (a_D * x^D) + (a_{D - 1} * n^{D - 1}) + ... + (a_1 * n) + a_0
```
Dada uma sequência com comprimento ```N```, qual o menor grau de um polinômio que pode ser usado para descrever uma sequência?

- Entrada - A entrada do problema é composta por duas linhas. A primeira linha possui um inteiro ```N``` representando o comprimento da sequência dada, e a segunda linha contém ```N``` números inteiros ```X1, X2, ..., XN``` separados por um espaço. Esses números formam a sequência dada;

- Saída - A saída devolve um inteiro ```D``` que representa o menor grau possível de um polinômio ```P(n)``` tal que ```P(i) = Xi```, para todo ```i = 1, ..., n```;

### Atividade 8: 

Regra de Simpson Composta: Calcular a integral ```f(x)``` no intervalo ```[A, B]``` usando a Regra de Simpson Composta realizando a divisão em ```N``` intervalos.

- Entrada - A entrada possui três linhas. A primeira linha contém um inteiro ```D``` representando o grau do polinômio dado; a segunda linha possui ```D + 1``` inteiros ```a_0, ..., a_D``` representando os coeficientes do polinômio dado tal que 
```
P(x) = a_0 + (a_1 * x) + (a_2 * x^2) + ... + (a_D * x^D)
```
E, a terceira linha possui três inteiros ```A```, ```B``` e ```N``` sendo que ```[C, D]``` representa o intervalo de integração e ```N``` representa a quantidade de subintervalos da Regra de Simpson Composta.

- Saída - A saída devolve um número ponto flutuante com 5 casas decimais depois da vírgula representando o valor aproximado da integral calculada usando a Regra de Simpson Composta.

### Atividade 9: Lista sobre Programação Linear.

Tópicos:
- Resolução Gráfica do PPL;
- Modelagem;
- Método Simplex; 
- e, Dualidade.

