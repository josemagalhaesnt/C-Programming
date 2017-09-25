#include <stdio.h>
#include <stdlib.h>

                              ////////////////EXERCICIO 4

int Eprimo(int x)// verifica se é primo
{
    int i;
    if(x == 2)
    {
        return 1;
    }
    for(i=2;i<(x/2)+2;i++)
    {
        if(x%i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int mostraPrimo(int x)
{
    int y, contador = 0, primo1 = 0,primo2 = 0;
    if(x == 2)
    {
        printf("3 e 5 s%co os primos posteriores\nN%co existem primos anteriores\n",198,198);
        return 0 ;
    }
    if(x == 3)
    {
        printf("5 e 7 s%co os primos posteriores\nApenas 2 %c primo anterior\n",198,130);
        return 0;
    }
    if(x == 5)
    {
        printf("7 e 11 s%co os primos posteriores\n2 e 3 s%co primos anteriores\n",198,198);
        return 0;
    }//// o algorítmo para encontrar primos anteriores não funicona para 2, 3 e 5
    y = x + 2;
    while(contador != 2)
    {
        if(Eprimo(y) && primo1 == 0)
        {
            primo1 = y;
            contador += 1;
            y += 2;
        }
        else if(Eprimo(y))
        {
            primo2 = y;
            contador += 1;
        }

        y+= 2;
    }
    printf("\n%d e %d s%co os primos posteriores",primo1,primo2,198);
    ///////////////////////////////////////////////////////////////////////// acima posteriores, abaixo anteriores
     y = x - 2;
     primo1 = 0;
     primo2 = 0;
     contador = 0;
     while(contador != 2)
     {
         if(Eprimo(y) && primo1 == 0)
         {
             primo1 = y;
             contador += 1;
             y -= 2;
         }
         else if(Eprimo(y))
        {
            primo2 = y;
            contador += 1;
        }
        y-= 2;
     }

    printf("\n%d e %d s%co os primos anteriores",primo2,primo1,198);

    return 0;
}



int main()
{
    int  d, contador = 0;

    while(contador == 0)
    {
        printf("Digite um n%cmero primo: ",163);
        fflush(stdin);
        scanf("%d",&d);
        if(Eprimo(d))
        {
            mostraPrimo(d);
            contador +=1;
        }
        else
        {
            printf("O n%cmero n%co %c primo\n",163, 198, 130);
        }

    }
    return 0;
}
