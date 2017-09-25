#include <stdio.h>
#include <stdlib.h>

                         ////////////// EXERCICIO 5

void OrdenaVetor(int tam, int matriz[])
{
    int i, j,aux;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(matriz[i]>matriz[j])
            {
                aux = matriz[i];
                matriz[i] = matriz[j];
                matriz[j] = aux;
            }
        }
    }
}

int buscaBinaria(int tam, int vetor[], int valor)
{
    int i, menor = 0, meio = tam/ 2, maior = tam -1;
    while(maior >= menor)
    {
        if(valor == vetor[meio])
        {
            return 1;
            break;
        }
        else if(valor > vetor[meio])
        {
            menor = meio -1 ;
        }
        else
        {
            maior = meio - 1;
        }
        meio = (maior+menor)/2;
    }
    return 0;
}
int removeVetor(int tam,int vetor[])
{
    int aux;
    int verificador = 0;
    int contador = 0 ;
    int i,j,k;
    for(i=0;i<tam-1;i++)//só precisa ir até tam-1 porque j vai até tam
    {
        for(j=i+1;j<tam;j++)
        {
            if(vetor[i] == vetor[j])
            {
                verificador++;
                contador++;
            }
        }// bloco verificador de repetições
        if(verificador != 0)
        {
            while(verificador != 0)
            {
                for(j=i+1;j<tam;j++)////....verifica qual é repetido
                {
                    if(vetor[j] == vetor[i])
                    {
                        for(k=j+1;k<tam;k++)
                        {
                            vetor[k-1] = vetor[k];
                        }//aqui ele deleta e reordena os elementos
                        tam--; // tamanho perde uma unidade
                        verificador--;
                    }
                }
            }
        }//bloco deletar repetições
        verificador = 0;

    }
    return contador;


}
int main()
{
    int i, elemremovidos,num;
    int vetor[10] = {8,3,3,4,2,1,6,10,5,7};// adicionando um 3 no lugar do 9
    OrdenaVetor(10,vetor);// ordenando o vetor para facilitar
    elemremovidos = removeVetor(10,vetor);
    if(elemremovidos == 0)
    {
        printf("Nenhum elemento repetido %d\n",elemremovidos);
    }// retorna ok se nada for alterado
    else if(elemremovidos > 0)
    {
        printf("%d elemto foi removido",elemremovidos);
    }// retorna o número de repetições

    printf("\nDigite o numero desejado: ");
    scanf("%d",&num);
    while(1)
    {
        if(buscaBinaria(10-elemremovidos,vetor,num))
        {
            printf("O elemento pertence ao vetor");
            break;
        }
        else
        {
            printf("O elemento nao pertence ao vetor");
        }
    }



    return 0;
}
