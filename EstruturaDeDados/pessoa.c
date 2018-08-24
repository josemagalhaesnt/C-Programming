#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
  char nome[80];
  char sexo[10];
  int idade;
} Pessoa;

bool fazRequisito(Pessoa *p);

int main(void) {
  Pessoa *p = (Pessoa*) malloc(sizeof(Pessoa));

  printf("Qual o seu sexo ?\n");
  fgets(p->sexo, sizeof(p->sexo), stdin);

  if (fazRequisito(p) == true) {
      getchar();
      printf("Qual o seu nome ? \n");
      fgets(p->nome, sizeof(p->nome),stdin);
      printf("Ola, %s ! Quantos anos voce tem? \n", p->nome);
      scanf("%d", &p->idade);
  }

  else
    exit(-1);

  return 0;
}

bool fazRequisito(Pessoa *p){

  int check1 = strncmp(p->sexo,"M", strlen(p->sexo));
  int check2 = strncmp(p->sexo,"Masculino", strlen(p->sexo));

  printf("%d \n", check1);
  printf("%d \n", check2);

    if (check1 == 0 || check2 == 0){

       printf("Parabens, voce fez o requisito \n");
       return true;
    }

    else {
        printf("Sai racha, quero piroca \n");
        return false;
    }
}
