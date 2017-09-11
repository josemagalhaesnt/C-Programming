/*** Esse programa é um cálculo de quando a população dos EUA e do BRASIL teriam o mesmo número de habitantes
Sabendo que a População dos EUA é maior que a do BRASIL no ano de 2000 e suas taxas de crescimento de acordo com o programado***/

#include <stdio.h>
 
int main(void) {
	int ano = 2000;
	int populacaoUS = 10000;
	int populacaoBR = 8000;
 
	while (populacaoUS != populacaoBR)
	{
		populacaoUS = populacaoUS + (populacaoUS * 0.02);
		populacaoBR = populacaoBR + (populacaoBR * 0.04);
		ano++;
	}
 
	printf("A população é igual no ano de %d", ano);
	return 0;
}
