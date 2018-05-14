# Repositório que contém as atividades da disciplina de Matemática Computacional
- Atividade 1: Programa que recebe uma tolerância para o erro relativo da aproximação de épsilon (e) e imprime o valor dessa aproximação precisão com 15 casas decimais.

Entrada - Um número ponto flutuante com precisão dupla épsilon;

Saída - O menor valor e(n) tal que  o erro relativo entre duas aproximações seja menor que épsilon.
- Atividade 2: Implementação da eliminação de Gauss com pivoteamento parcial que transforma a matriz original em uma matriz triangular superior e devolve o determinante dessa matriz.

Entrada - A primeira linha possui um inteiro N, representando a dimensão a matriz. Cada uma das N linhas seguintes contém N+1 números reais, sendo o último número real representando o termo independente;

Saída - A saída contém N linhas. Cada linha contém N+1 números reais, escritos com a precisão de cinco casas decimais seguindo de mais N linhas. A i-ésima linha seguinte tem o formato "x[i] = v", onde v é um número real, escrito como a precisão de cinco casas decimais, representando o valor da variável i no sistema de equação;
- Atividade 3: Implementação do Método de Gauss-Seidel.

Entrada - A primeira linha possui um inteiro N, representando a dimensão a matriz. Cada uma das N linhas seguintes contém N+1 números reais, sendo o último número real representando o termo independente do sistema linear seguido de 1 linha contendo N números reais representando uma aproximação inicial para o solução do sistema. Na linha seguinte, um número real epsilon (e) representando a precisão tolerada. Na última linha, um inteiro MAX_ITER representando o número máximo de iterações do método;

Saída - A saída contém N+1 linhas por iteração do método. Na primeira linha, temos o identificador da iteração no seguinte formato "ITERACAO n", onde n é o número da iteração. As N linhas seguintes, temos os valores do vetor de solução no seguinte formato "x[i] = v", onde i é o identificador da variável variando entre 0 e n-1 e v o valor da variável i na iteração corrente;
- Atividade 4: Implementação do Método da Posição Falsa Modificada.

Entrada - A primeira linha da entrada tem um inteiro N, representando o grau da função f. Na segunda linha, temos N+1 números reais representando os coeficientes da função. Na terceira linha contém três números reais a, b e epsilon, e um inteiro MAX_ITER, onde [a,b] representam um intervalo que contém uma raiz da função f, o epsilon representa a precisão, e MAX_ITER representa o número máximo de iterações;

Saída - A saída possui uma linha para cada iteração do método. Cada linha possui um inteiro k, representando a iteração do método seguido de 4 números reais escritos com 8 casas decimais a,b,x_k,f(x_k);

