#include <stdio.h>

int n, i, menor = 0, pos = 0;

int main()
{
    scanf("%d", &n);

    int x[n];

    for (i = 0; i< n ; i++){
        scanf("%d", &x[i]);
        if(i==0){
            menor = x[i];
            pos = i;
        }
      else {
        if(x[i] < menor){
            menor = x[i];
            pos = i;
        }
      }
    }

    printf("\nMenor valor: %d \nPosicao: %d", menor, pos);

    return 0;
}



