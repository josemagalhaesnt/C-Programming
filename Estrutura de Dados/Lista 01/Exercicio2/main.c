#include <stdio.h>
#include <stdlib.h>

                                    ///////EXERCICIO 2

void GeraVetor(int tam,int *pi)
{
    int i;
    for(i=0;i<tam-1;i++)
    {
        *pi = rand() % 130;// gera números de 0 a 100
        pi++;
    }
}

int GeraVetorY(int tam,int vetor1[],int vetor2[])
{
    int i,n=0;
    for(i=0;i<tam;i++)
    {
        if(vetor1[i]>= 10 && vetor1[i]<=40)
        {
            vetor2[n] = vetor1[i];
            n += 1;
        }
    }
    return n; // retorna o número de elementos do vetor
}

void PosPares (int tam,int vetor1[], int vetor2[])
{
    int i, n=0;
    for(i=0;i<tam;i+=2)
    {
        vetor2[n] = vetor1[i];
        n += 1;
    }
}

void MaiorNume(int tam,int vetor[])
{
    int aux = vetor[0],i;
    for(i=1;i<tam;i++)
    {
        if(vetor[i]>aux)
        {
            aux = vetor[i];
        }
    }
    printf("\nO maior n%cmero %c: %d",163,130,aux);
}

void MenorNume(int tam,int vetor[])
{
    int aux = vetor[0], i;
    for(i=1;i<80;i++)
    {
        if(vetor[i]<aux)
        {
            aux = vetor[i];
        }
    }
    printf("\nO menor n%cmero %c: %d",163,130,aux);
}
int main()
{
    srand(time(NULL));
    int vetorX[80],vetorY[80],vetorW[40], numele, i,aux;
    GeraVetor(80,vetorX);//preenche o vetorx com números aleatórios
    numele = GeraVetorY(80,vetorX,vetorY);//preenche vetory e retorna o número de elementos
    printf("o n%cmero de elemntos do vetorY %c: %d \n\n",163,130,numele);
    for(i=0;i<numele;i++)
    {
        printf("%d, ",vetorY[i]);
    }//mostra os elementos do vetory
    printf("\n\n");
    PosPares(80,vetorX,vetorW);
    for(i=0;i<40;i++)
    {
        printf("%d, ",vetorW[i]);
    }//mostrando os elemntos do vetorw
    printf("\nDigite um n%cmero a ser pesquisado: ",163);
    scanf("%d",&aux);
    for(i=0;i<80;i++)
    {
        if(vetorX[i] == aux)
        {
            printf("\nO n%cmero %d est%c no vetorX na posi%c%co %d ",163,aux,160,135,198,i);
            break;
        }
        else if(i == 79 && vetorX[i]!=aux)
        {
            printf("\nO n%cmero n%co est%c no vetorX",163,198,160);
        }// se i chegar no último elemento sem executar o if então o valor não pertence ao vetor
    }

    MaiorNume(80,vetorX);// Encontrando o maior número
    MenorNume(80,vetorX);// Encontrando o menor número
    return 0;
}
