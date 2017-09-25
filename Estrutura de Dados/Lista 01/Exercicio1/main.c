#include <stdio.h>
#include <stdlib.h>

                              ///////// EXERCICIO 1

void GeraVetor(int tam,int *pi)
{
    int i;
    for(i=0;i<tam-1;i++)
    {
        *pi = rand() % 256;
        pi++;
    }
}

void OrdenaDecrescente(int tam, int matriz[])
{
    int i, j,aux;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(matriz[i]<matriz[j])
            {
                aux = matriz[i];
                matriz[i] = matriz[j];
                matriz[j] = aux;
            }
        }
    }
}

int NumPares(int tam, int vetor[])
{
    int i, cont=0;
    for(i=0;i<tam;i++)
    {
        if(vetor[i] % 2 == 0)
        {
            cont += 1;
        }
    }
    return cont;
}
int NumImpares(int tam, int vetor[])
{
    int i, cont=0;
    for(i=0;i<tam;i++)
    {
        if(vetor[i] % 2 != 0)
        {
            cont += 1;
        }
    }
    return cont;
}

float MediaNumeros(int tam,int matriz[])
{
    int i;
    float cont=0,result=0;//contador e resultado
    for(i=0;i<tam;i++)
    {
        if(matriz[i]>50)
        {
            cont+=1;
            result += matriz[i];
        }
    }
    return result/cont;

}




int main()
{
    srand(time(NULL));
    int matriz[6], i;
    int *pi;
    pi = matriz;
    GeraVetor(6,matriz);
    for(i=0;i<6;i++)
    {
        printf("%d, ",*pi++);
    }// imprimir os elementos do vetor
    printf("\n\n");
    OrdenaDecrescente(6,matriz);
    for(i=0;i<6;i++)
    {
        printf("%d, ",matriz[i]);
    }//imprimir os elemnetos ordenados decrescentes
    printf("\nO n%cmero de pares do vetor %c: %d",163,130,NumPares(6,matriz));
    printf("\nO n%cmero de impares do vetor %c: %d",163,130,NumImpares(6,matriz));
    printf("\nA m%cdia %c: %.2f",130,130,MediaNumeros(6,matriz));
    return 0;
}
