#include <stdio.h>
#include <stdlib.h>

int idade;
int peso;
int numJogadores = 23;
int numTimes = 40;
int pesototal = 0;
int idadetotal = 0;
int imediatime = 0;
int pmediatime = 0;
int imediatotal = 0;
int pmediatotal = 0;


int main()
{
    for (int ti = 0; ti < numTimes; ti++)
    {
        for (int i = 0; i < numJogadores; i++)
        {
            printf("\nDigite a idade do jogador %d do time %d \n", i+1, ti+1);
            scanf("%d", &idade);
            idadetotal = idadetotal + idade;
            printf("\nDigite o peso do jogador %d do time %d \n", i+1, ti+1);
            scanf("%d", &peso);
            pesototal = pesototal + peso;
        }

        imediatime = (idadetotal / numJogadores) / (ti+1);
        pmediatime = (pesototal / numJogadores) / (ti+1);

        printf("A média de idade do time %d eh: %d \n ",ti+1, imediatime);
        printf("A média de peso do time %d eh: %d \n ",ti+1, pmediatime);

    }

    imediatotal = idadetotal / (numTimes * numJogadores);
    pmediatotal = pesototal / (numTimes * numJogadores);


    printf("\n A média total de idade dos times eh: %d \n ", imediatotal);
    printf("\n A média total de peso dos times eh: %d \n", pmediatotal);

    return 0;
}
