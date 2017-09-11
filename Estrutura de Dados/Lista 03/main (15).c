#include <stdio.h>
#include <stdlib.h>

                       /////// Exercicio 15
struct box
{
    char conteudo;
    struct box *prox;
};



int main()
{
    struct box *inicio, *fim, *novo,*p,*aux;

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

    //Exclua o último elemento.(F)
    p = inicio ->prox;
    while(1)
    {
        if('D' == p ->conteudo)
        {
            fim = p;
            fim ->prox = NULL;
            break;
        }
        p = p ->prox;
    }


    //Exclua o primeiro elemento.(G)
    p = inicio ->prox;
    inicio ->prox = p ->prox;


    //Insira um elemento contendo a letra H entre os elementos de conteúdo A e E.
    p = inicio ->prox;
    while(1)
    {
        if('A' == p ->conteudo)
        {
            novo = (struct box*)malloc(sizeof(struct box));
            novo ->conteudo = 'H';
            novo ->prox = p ->prox;
            p ->prox = novo;
            break;
        }
        p = p ->prox;
    }

    //Exclua o elemento de conteúdo A.
    p = inicio ->prox;
    while(1)
    {
        if('A' == p -> prox -> conteudo)
        {
            p ->prox = p ->prox ->prox;
            break;
        }
        p = p ->prox;
    }


    //Insira um elemento contendo a letra I entre os elementos de conteúdo E e D.
    // já existe o C entre eles
    p = inicio ->prox;
    while(1)
    {
        if('E' == p ->conteudo)
        {
            p = p->prox;
            p ->conteudo = 'I';
            break;
        }
        p = p ->prox;
    }


    //Insira um elemento contendo a letra J no final da lista.
    fim ->prox = (struct box*)malloc(sizeof(struct box));
    fim = fim ->prox;
    fim ->conteudo = 'J';
    fim ->prox = NULL;

    //Insira um elemento contendo a letra K entre os elementos de conteúdo B e H.
    p = inicio ->prox;
    while(1)
    {
        if('B' == p ->conteudo)
        {
            novo = (struct box*)malloc(sizeof(struct box));
            novo ->conteudo = 'K';
            novo ->prox = p ->prox;
            p ->prox = novo;
            break;
        }
        p = p ->prox;
    }

    //Exclua o elemento de conteúdo D, K e I.
    p = inicio ->prox;
    aux = p ->prox;
    while(1)
    {
        if('K' == aux ->conteudo)
        {
            p ->prox = aux ->prox;
            break;
        }
        aux = aux ->prox;
        p = p ->prox;
    }
    p = inicio ->prox;
    aux = p ->prox;
    while(1)
    {
        if('D' == aux ->conteudo)
        {
            p ->prox = aux ->prox;
            break;
        }
        aux = aux ->prox;
        p = p ->prox;
    }
    p = inicio ->prox;
    aux = p ->prox;
    while(1)
    {
        if('I' == aux ->conteudo)
        {
            p ->prox = aux ->prox;
            break;
        }
        aux = aux ->prox;
        p = p ->prox;
    }



    /////////////////////////////////////////////////////////
    p = inicio ->prox;

    while(p != NULL)
    {
        printf("%c",p->conteudo);
        p = p ->prox;
    }
    return 0;
}
