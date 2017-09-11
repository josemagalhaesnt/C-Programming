#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char nome [50];
    int idade;
    float salario;

} Funcionario;

char linha [60];
int op;
char resp;
Funcionario f[3];
int i;
FILE *arquivo;

int main()
{

    do {
        printf("********************* MENU *********************");
        printf("\n1. Cadastrar Funcionarios");
        printf("\n2. Verificar Funcionarios Cadastrados\n");
        printf("************************************************");
        printf("\nOpcao: ");
        scanf("%d",&op);

            switch(op){
                case 1:
                    for (i=0; i<3; i++){
                        fflush(stdin);
                        printf("Nome: ");
                        //scanf("%s", f[i].nome);
                        gets(f[i].nome);
                        printf("\nIdade: ");
                        scanf("%d", &f[i].idade);
                        printf("\nSalario: ");
                        scanf("%f", &f[i].salario);
                        printf("\n");
                    }

                    arquivo = fopen("funcionarios.txt","wt");

                    for (i=0; i<3; i++){
                        fprintf(arquivo, "Nome: %s",f[i].nome);
                        fprintf(arquivo, "\nIdade: %d",f[i].idade);
                        fprintf(arquivo, "\nSalario: %.2f",f[i].salario);
                        fprintf(arquivo, "\n");

                    }

                    fclose(arquivo);
                    break;
                case 2:
                    arquivo = fopen("funcionarios.txt","rt");
                    //tá no slide XD
                    fread(&f[i],sizeof(Funcionario),1,arquivo);
                    fclose(arquivo);
                    for(i=0;i<3;i++){
                        printf("Nome: %s\n",f[i].nome);
                        printf("Idade: %d\n",f[i].idade);
                        printf("Salario: %.2f\n",f[i].salario);
                    }
                    break;

                default:
                    printf("Operacao invalida");
                    break;

            }

        getchar();
        printf("Deseja continuar ? S/N \n");
        scanf("%c", &resp);
        //strcmp compara strings e não compara caracteres
        } while ('S'==toupper(resp));

    system("pause");
    return 0;
}
