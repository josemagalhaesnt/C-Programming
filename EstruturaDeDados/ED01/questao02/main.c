#include <stdio.h>

int t, i, n;
void fib (int x);

int main() {

   scanf("%d", &t);

    for (i=0; i < t; i++){
        scanf("%d", &n);
        fib(n);
    }

    return 0;
}

void fib (int x){
    int f[60], j;
    f[0] = 0, f[1] = 1;

    for (j = 2; j < 60; j++) {
        f[j] = f[j-1] + f[j-2];
    }

    printf("Fib (" "%d" ") = " "%d \n", x,f[x]);
}
