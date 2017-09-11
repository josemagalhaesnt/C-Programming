#include <stdio.h>
#include <stdlib.h>
#include <string.h>

                                /////// Exercicio 4
struct box
{
    char conteudo;
    struct box *prox;
};



int main()
{
    struct box *inicio, *fim, *novo,*p;

    inicio = (struct box*)malloc(sizeof(struct box));
    inicio -> prox = NULL;
    fim = inicio;

    ////// Inserindo o elemento A no finl da lista
    fim ->prox = (struct box*)malloc(sizeof(struct box));
    fim = fim ->prox;
    fim ->conteudo = 'A';
    fim ->prox = NULL;
    inicio ->prox = fim;

    ////// Inseridno o elemento B no inicio da lista
    novo = (struct box*)malloc(sizeof(struct box));
    novo ->conteudo = 'B';
    novo ->prox = fim;
    inicio ->prox = novo;


    ////// Inserindo o elemento C no finl da lista
    fim ->prox = (struct box*)malloc(sizeof(struct box));
    fim = fim ->prox;
    fim ->conteudo = 'C';
    fim ->prox = NULL;


    ////// Inserindo o elemento D no finl da lista
    fim ->prox = (struct box*)malloc(sizeof(struct box));
    fim = fim ->prox;
    fim ->conteudo = 'D';
    fim ->prox = NULL;




    p = inicio ->prox;

    while(p != NULL)
    {
        printf("%c",p->conteudo);
        p = p ->prox;
    }

    return 0;
}
