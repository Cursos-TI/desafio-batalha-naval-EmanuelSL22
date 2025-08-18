#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {

   int Tabuleiro[10][10] = {0};
   int navio = 3;
   char vertical[10] = {'A','B','C','D','E','F','G','H','I','J'};
   int horizontal[10] = {1,2,3,4,5,6,7,8,9,10};
   int linhaV, colunaV;
   int linhaH, colunaH;
   int linhaD1, colunaD1;
   int linhaD2, colunaD2;
   int sobreposicao = 0;
   

   //coodernadas dos navios
   linhaH = 1;
   colunaH = 3;

   linhaV = 4;
   colunaV = 6;

   linhaD1 = 2;
   colunaD1 = 2;

   linhaD2 = 5;
   colunaD2 = 2;


   //posição Horizontal do navio
   for (int i = 0; i < 10; i++)
   {
     printf("\t%d", horizontal[i]);
   }

printf("\n");
if (colunaH + 3 <= 10)
  {
   for (int a = 0; a < 3; a++)
   {
     printf("Navio Horizontal: %c%d\n", vertical[linhaH], horizontal[colunaH +a]);
     Tabuleiro[linhaH][colunaH + a] = 3;
   }
   
  } else {
    printf("Navio fora dos limites!\n");
  }

  //posição Vertical do navio
  if (linhaV + 3 <= 10)
  {
    for (int a = 0; a < 3; a++)
    {
      if (Tabuleiro[linhaV + a][colunaV] != 0)
      {
        sobreposicao = 1;
      }
      
    } 
    if(sobreposicao == 0)
  {
      for (int a = 0; a < 3; a++)
      {
        printf("Navio Vertical: %c%d\n", vertical[linhaV + a], horizontal[colunaV]);
        Tabuleiro[linhaV + a][colunaV] = 3;
      } 
    
  } else {
    printf("Navio fora dos limites!\n");
  } 
  }

  // Navio diagonal 1 (principal)
    sobreposicao = 0;
    if (linhaD1 + 3 <= 10) {
        if (colunaD1 + 3 <= 10) {
            for (int a = 0; a < 3; a++) {
                if (Tabuleiro[linhaD1 + a][colunaD2 + a] != 0) {
                    sobreposicao = 1;
                }
            }
            if (sobreposicao == 0) {
                for (int a = 0; a < 3; a++) {
                    Tabuleiro[linhaD1 + a][colunaD1 + a] = 3;
                }
            } else {
                printf("\nSobreposição detectada para navio diagonal ↘!");
            }
        } else {
            printf("\nNavio diagonal 1 fora dos limites (coluna)!");
        }
    } else {
        printf("\nNavio diagonal 1 fora dos limites (linha)!");
    }

    // Navio diagonal 2 (secundária)
    sobreposicao = 0;
    if (linhaD2 + 3 <= 10) {
        if (colunaD2 - (3 - 1) >= 0) {
            for (int a = 0; a < 3; a++) {
                if (Tabuleiro[linhaD2 + a][colunaD2 - a] != 0) {
                    sobreposicao = 1;
                }
            }
            if (sobreposicao == 0) {
                for (int a = 0; a < 3; a++) {
                    Tabuleiro[linhaD2 + a][colunaD2 - a] = 3;
                }
            } else {
                printf("\nSobreposição detectada para navio diagonal 2!");
            }
        } else {
            printf("\nNavio diagonal 2 fora dos limites (coluna)!");
        }
    } else {
        printf("\nNavio diagonal 2 fora dos limites (linha)!");
    }

  int cone[5][5] = {0};
  int cruz[5][5] = {0};
  int octaedro[5][5] = {0};
  int tamanho = 5;
  int centro = 2;

  //matriz cone
  for (int i = 0; i < tamanho; i++){
    for (int j = 0; j < tamanho; j++){
      if (i==0 && j==2) // topo do cone
        cone[i][j] = 1;
      else if (i==1 && (j>=1 && j<=3))
        cone[i][j] = 1;
      else if (i==2)
        cone[i][j] = 1;
      else
        cone[i][j] = 0;
    }
  }

  // matriz cruz
  for (int i = 0; i < tamanho; i++){
    for (int j = 0; j < tamanho; j++){
      if (i == centro || j == centro)
        cruz[i][j] = 1;
      else
        cruz[i][j] = 0;
    }
  }

  //matriz octaedro
  for (int i=0; i < tamanho; i++){
    for (int j = 0; j < tamanho; j++){
      int di = i - centro;
      int dj = j - centro;
      if ((di < 0) ? -di : di + (dj < 0 ? -dj : dj) <= 2) {
        octaedro[i][j] = 1;
      } else {
        octaedro[i][j] = 0;
      }
    }
  }

  int origemLinha, origemColuna;
  int offset = tamanho / 2;

  origemLinha = 3;
  origemColuna = 3;
  for (int i=0; i<tamanho; i++){
    for (int j=0; j<tamanho; j++){
      int linha = origemLinha - offset + i;
      int coluna = origemColuna - offset + j;
      if (linha >=0 && linha < 10 && coluna >= 0 && coluna < 10){
        if (cone[i][j] == 1 && Tabuleiro[linha][coluna] == 0){
          Tabuleiro[linha][coluna] = 5; // Marca área da habilidade
        }
      }
    }
  }

   
  origemLinha = 6;
  origemColuna = 6;
  for (int i=0; i<tamanho; i++){
    for (int j=0; j<tamanho; j++){
      int linha = origemLinha - offset + i;
      int coluna = origemColuna - offset + j;
      if (linha >=0 && linha < 10 && coluna >= 0 && coluna < 10){
        if (cruz[i][j] == 1 && Tabuleiro[linha][coluna] == 0){
          Tabuleiro[linha][coluna] = 5;
        }
      }
    }
  }

  
  origemLinha = 8;
  origemColuna = 2;
  for (int i=0; i<tamanho; i++){
    for (int j=0; j<tamanho; j++){
      int linha = origemLinha - offset + i;
      int coluna = origemColuna - offset + j;
      if (linha >=0 && linha < 10 && coluna >= 0 && coluna < 10){
        if (octaedro[i][j] == 1 && Tabuleiro[linha][coluna] == 0){
          Tabuleiro[linha][coluna] = 5;
        }
      }
    }
  }



  for (int i = 0; i < 10; i++)
   {
    printf("\n%c", vertical[i]);
    for (int k = 0; k < 10; k++)
    {
      printf("\t%d", Tabuleiro[i][k]);//imprime o tabuleiro com 0 como água
      
    }
   }

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
