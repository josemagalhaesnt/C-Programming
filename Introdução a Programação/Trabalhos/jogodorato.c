 #include <stdio.h>
 #include <stdlib.h>

 /* Definicoes, para facilitar o uso da funcao para desenhar o mapa */
 #define CHAO 0
 #define PAREDE 1
 #define RATO 2
 #define QUEIJO 3


 /*Outras definições para tratamento de erros*/
 #define OK 1
 #define ERRO 2
 #define LIMPARTELA "clear"

 int coluna_atual = 11, linha_atual = 5;

 /* O Mapa */
 int mapa[8][13] = {
 1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,0,3,1,1,0,0,0,0,0,0,0,1,
 1,0,1,0,0,1,0,1,0,1,1,0,1,
 1,0,0,1,0,1,0,1,0,0,0,1,1,
 1,0,1,0,1,0,0,0,1,1,0,0,1,
 1,0,0,0,1,0,1,0,0,0,1,0,1,
 1,0,1,0,0,0,0,0,0,1,0,0,1,
 1,1,1,1,1,1,1,1,1,1,1,1,1,
 };

 /* Funcao para desenhar o Mapa */
 int desenhar_mapa()
 {
    int linha,coluna;
    for (linha=0;linha<8;linha++) {
       for (coluna=0;coluna<13;coluna++) {

          if ((linha == linha_atual) && (coluna == coluna_atual)) {
             printf("R");
             continue;
          }
          if (mapa[linha][coluna] == CHAO)
             printf(" ");
          if (mapa[linha][coluna] == PAREDE)
             printf("|");
     if (mapa[linha][coluna] == QUEIJO)
        printf("Q");
  
       }
       printf("\n");
    }
    return OK;
 }

 int main()
 {
    char movimento;
    while ((movimento != 'x') && (movimento != 'X')) {
       system(LIMPARTELA);
       desenhar_mapa();
       printf("\n##################### L A B I R I N T O #####################################\n");
       printf("\n\n  (W)\n(A)+(D)\n  (S)\n"); /* Imprime as direcoes */
       printf("\nPressione X[x] para sair\n");
       printf("\n------------------------------------------------------------------------------\n");
       if ((scanf("%c",&movimento))==0) {
          getchar(); getchar();
          return ERRO;
       }
       if ((movimento == 'w') || (movimento == 'W')) {
          linha_atual = linha_atual - 1;
          /* Se não for chao, ele volta pra posicao anterior */
          if ((mapa[linha_atual][coluna_atual] != CHAO) && (mapa[linha_atual][coluna_atual] != QUEIJO)) {
             linha_atual = linha_atual + 1;
             getchar(); getchar();
             system(LIMPARTELA);

          }
       }
       if ((movimento == 's') || (movimento == 'S')) {
          linha_atual = linha_atual + 1;
          /* Se não for chao, ele volta pra posicao anterior */
          if ((mapa[linha_atual][coluna_atual] != CHAO) && (mapa[linha_atual][coluna_atual] != QUEIJO)) {
             linha_atual = linha_atual - 1;
              getchar(); getchar();
              system(LIMPARTELA);

          }
       }
       if ((movimento == 'd') || (movimento == 'D')) {
          coluna_atual = coluna_atual + 1;
          /* Se não for chao, ele volta pra posicao anterior */
          if ((mapa[linha_atual][coluna_atual] != CHAO) && (mapa[linha_atual][coluna_atual] != QUEIJO)) {
             coluna_atual = coluna_atual - 1;
             getchar(); getchar();
             system(LIMPARTELA);

          }
       }
       if ((movimento == 'a') || (movimento == 'A')) {
          coluna_atual = coluna_atual - 1;
          /* Se não for chao, ele volta pra posicao anterior */
          if ((mapa[linha_atual][coluna_atual] != CHAO) && (mapa[linha_atual][coluna_atual] != QUEIJO)) {
             coluna_atual = coluna_atual + 1;
             getchar(); getchar();
             system(LIMPARTELA);

          }

       }

       if (mapa[linha_atual][coluna_atual] == QUEIJO){
          movimento = 'x';
          system(LIMPARTELA);
          printf("\n             (/.");
          printf("\n             / _`> .---------.");
          printf("\n     _)     / _)=  |'-------'|");
          printf("\n    (      / _/    |O   O   o|");
          printf("\n     `-.__(___)_   | o O . o |");
          printf("\n                   `---------'");
          printf("\nQ U E I J O  E N C O N T R A D O !");
          printf("\n");
       }

    }
    

 }
