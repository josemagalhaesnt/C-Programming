#include <stdio.h>
#include <stdlib.h>

                               //////////////EXERCICIO 3

void intercaVetor(int tam,int vetor1[],int vetor2[],int vetor3[])
{
    int i, aux=0;
    for(i=0;i<tam;i++)
    {
        vetor3[aux] = vetor1[i];
        aux++;
        vetor3[aux] = vetor2[i];
        aux++;
    }
}

int main()
{
    int vetor1[10]={18,2,73,98,12,73,9,27,39,8};
    int vetor2[10]={98,3,29,72,49,82,37,49,64,56};
    int vetor3[10];
    int i,num;

    intercaVetor(10,vetor1,vetor2,vetor3);

    for(i=0;i<10;i++)
    {
        printf("%d, ",vetor3[i]);
    }// imprindo os elementos do vetor3

    printf("\nDigite o n%cmero desejado: ",163);
    scanf("%d",&num);
    i = 0;// aproveitando a variável
    while(1)// inicializando busca
    {
        if(num == vetor3[i])
        {
            printf("o n%cmero %d est%c na posi%c%co %d do vetor\n",163,num,160,135,198,i);
            break;
        }
        else if(i>=10)
        {
           printf("\nO numero nao esta no vetor\n");
           break;
        }

        i++;
    }// com o for é mais fácil...dica do professor sobre o objetivo de cada função


    return 0;
}
