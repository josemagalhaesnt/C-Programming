#include <stdio.h>
#include <stdlib.h>

                                   ///////// EXERCICIO 1

struct box
{
    char conteudo;
    struct box *prox;
};



int main()
{
    struct box *inicio, *fim;

    inicio = (struct box*)malloc(sizeof(struct box));
    inicio -> prox = NULL;
    fim = inicio;

    ////// Inserindo o elemento A no finl da lista
    fim ->prox = (struct box*)malloc(sizeof(struct box));
    fim = fim ->prox;
    fim ->conteudo = 'A';
    fim ->prox = NULL;
    inicio ->prox = fim;


    return 0;
}
