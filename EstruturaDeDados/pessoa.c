#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"

struct pessoa{
  char nome[80];
  char telefone[20];
  struct pessoa* prox;
};

int i;

int main(void) {
  Pessoa* agenda;
  criarAgenda();
  printf("criou agenda \n");
  cadastrarPessoa(agenda,"José Neto","(85)99748-8974");
  cadastrarPessoa(agenda,"Anderson","(85)999999-9999");
  printf("cadastrou pessoas \n");
  mostrarAgenda(agenda);
  printf("fim programa \n");
  return 0;
}

//criar agenda telefonica
Pessoa* criarAgenda(){
    return NULL;
}

//inserir Pessoa na agenda
Pessoa* cadastrarPessoa(Pessoa* p, char n[80], char t[20]){
    Pessoa* nova = (Pessoa*)malloc(sizeof(Pessoa));
    nova->nome[80] = n[80];
    nova->telefone[20] = t[20];
    nova->prox = p;
    return nova;
}

void mostrarAgenda(Pessoa* p) {
    Pessoa* aux;
    for (aux= p; aux!= NULL; aux = aux->prox) {
        printf("Nome: %s \n", aux->nome);
        printf("Telefone: %s \n", aux->telefone);
    }
}
