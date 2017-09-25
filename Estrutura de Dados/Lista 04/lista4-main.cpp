#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void mostraVetor(int vetor[],int tam)
{
    int i;
    for(i=0;i<tam-1;i++)
    {
        printf("%d, ",vetor[i]);
    }
    printf("%d\n",vetor[i]);
}

int SelectionSort(int vetor[],int tam)
{
    int i,j,aux;
    int qtrocas = 0;
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(vetor[i]>vetor[j])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
                qtrocas += 1;
            }
        }
    }
    return qtrocas;
}

int BubbleSort(int vetor[],int tam)
{
    int i, j,aux;
    int qtrocas=0;
    for(i=0;i<=tam-1;i++)
    {
        for(j=0;j<=tam-1;j++)
        {
            if(vetor[j]>vetor[j+1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
                qtrocas += 1;

            }
        }
    }
    return qtrocas;
}


void InsertionSort(int vetor[],int tam)
{
    int i,j,aux;
    int qtrocas = 0;
    for(i=0;i<tam;i++)
    {
        aux = vetor[i];
        j = i - 1;

        while ((j >= 0) && (aux < vetor[j]))
        {
			vetor[j + 1] = vetor[j];
			j -= 1;
			qtrocas += 1;// verificar
		}
        vetor[j + 1] = aux;
        qtrocas += 1;///// verificar
    }
}

void QuickSort(int vetor[10], int inicio, int fim){

   int pivo, aux, i, j, meio;

   i = inicio;
   j = fim;

   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];

   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;

      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);

   if(inicio < j) QuickSort(vetor, inicio, j);
   if(i < fim) QuickSort(vetor, i, fim);

}

char menu()
{
    char num;
    printf("\n---Algoritmos de ordenacao---\n\n");
    printf("1 - BubbleSort\n");
    printf("2 - InsertionSort\n");
    printf("3 - SelectionSort\n");
    printf("4 - QuickSort\n");
    printf("0 - Sair\n");
    printf("Escolha o metedo desejado: ");
    fflush(stdin);
    scanf("%c",&num);
    return num;

}
int main()
{
    char aux;
    int aux2;
    int vetor[] = {3,98,4,26,49,5,72,10,93,53};

    clock_t start_t, end_t, total_t;;

    while(1)
    {
        aux = menu();

        if(aux == '0')
        {
            printf("\nAplicativo Finalizado!!\n");
            break;
        }

        switch(aux)
        {
            case '1':
                printf("\nVetor Original: ");
                mostraVetor(vetor,10);
                start_t = clock(); ////// AQUI
                aux2=BubbleSort(vetor,10);
                end_t = clock();/////// AQUI
                total_t = (double) (end_t - start_t)  / CLOCKS_PER_SEC; // tempo em segundos
                //double Tempo = (Ticks[1] - Ticks[0]) * 100000000 / CLOCKS_PER_SEC;/////AQUI
                printf("Tempo gasto: %.f s.", total_t);
                printf("\nVetor Ordenado: ");
                mostraVetor(vetor,10);
                printf("Quantidade de trocas: %d\n",aux2);
                break;
            case '2':
                printf("\nVetor Original: ");
                mostraVetor(vetor,10);
                InsertionSort(vetor,10);
                printf("\nVetor Ordenado: ");
                mostraVetor(vetor,10);
                break;
            case '3':
                printf("\nVetor Original: ");
                mostraVetor(vetor,10);
                start_t = clock(); ////// AQUI
                aux2=SelectionSort(vetor,10);
                end_t = clock();/////// AQUI
                total_t = (double) (end_t - start_t)  / CLOCKS_PER_SEC; // tempo em segundos
                //double Tempo = (Ticks[1] - Ticks[0]) * 100000000 / CLOCKS_PER_SEC;/////AQUI
                printf("Tempo gasto: %.f s.", total_t);
                printf("\nVetor Ordenado: ");
                mostraVetor(vetor,10);
                printf("\nQuantidade de trocas: %d\n",aux2);
                break;
            case '4':
                printf("\nVetor Original: ");
                mostraVetor(vetor,10);
                QuickSort(vetor,0,9);
                printf("\nVetor Ordenado: ");
                mostraVetor(vetor,10);
                break;


        }
    }

    //clock_t Ticks[2];
    //Ticks[0] = clock();
    //QuickSort(vetor,0,15);
    //mostraVetor(vetor,16);
    //O código a ter seu tempo de execução medido ficaria neste ponto.
    //Ticks[1] = clock();
    //float Tempo = (Ticks[1] - Ticks[0]); //* 1000.0 / CLOCKS_PER_SEC;
    //printf("Tempo gasto: %.2f ms.", Tempo);


    return 0;
}
