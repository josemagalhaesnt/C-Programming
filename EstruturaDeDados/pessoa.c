#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
  char nome[80];
  char sexo[10];
  int idade;
} Pessoa;

bool fazRequisito(Pessoa* p);

int main(void) {

  Pessoa *p = (Pessoa*) malloc(sizeof(Pessoa));

  printf("Qual o seu sexo ?\n");
  scanf("%s", p->sexo);

  if (fazRequisito(p) == true) {
      printf("Qual o seu nome ? \n");
      scanf("%s", p->nome);
      printf("Ola, %s ! Quantos anos voce tem? \n", p->nome);
      scanf("%d", &p->idade);
  }

  else
    exit(-1);

  return 0;
}

bool fazRequisito(Pessoa* p){

    if (strcmp(p->sexo,"M") == true) {
       printf("Parabens, voce fez o requisito");
       return true;
    }

    else {
        printf("Sai hetero!");
        return false;
    }
}
