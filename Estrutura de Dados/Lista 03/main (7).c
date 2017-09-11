#include <stdio.h>
#include <stdlib.h>

                               /////// Exercicio 7
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

    //Inserindo um elemento contendo a letra E entre os elementos de conteúdo A e C.
    p = inicio ->prox;
    while(1)
    {
        if('A' == p ->conteudo)
        {
            novo = (struct box*)malloc(sizeof(struct box));
            novo ->conteudo = 'E';
            novo ->prox = p ->prox;
            p ->prox = novo;
            break;
        }
        p = p ->prox;
    }

    ////// Inserindo o elemento F no finl da lista
    fim ->prox = (struct box*)malloc(sizeof(struct box));
    fim = fim ->prox;
    fim ->conteudo = 'F';
    fim ->prox = NULL;

    //Insirindo um elemento contendo a letra G no inicio da lista.
    novo = (struct box*)malloc(sizeof(struct box));
    novo ->conteudo = 'G';
    novo ->prox = inicio ->prox;
    inicio ->prox = novo;

    p = inicio ->prox;

    while(p != NULL)
    {
        printf("%c",p->conteudo);
        p = p ->prox;
    }

    return 0;
}
