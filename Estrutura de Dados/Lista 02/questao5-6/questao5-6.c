#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define qt 5

typedef struct {
    char nome[30];
    char endereco[30];
    int telefone;
    char situacao;
} Contato;

/** Assinatura das Funções **/
void inserir(Contato *cto, int contatos);
int pesquisar(Contato *cto, char *nome, int contatos);
void listar(Contato *cto, int indice);

/** Programa **/
int main()
{
    /** Variáveis **/
    char nome[30];
    int contatos=0, op, menu=1, n, i=0;
    Contato ct[qt];

    do{
        system("cls");
        printf("\n ------------- \n");
        printf(" MINHA AGENDA \n");
        printf(" ------------- \n \n");
        printf("1 - Inserir contato\n");
        printf("2 - Pesquisar contato\n");
        printf("3 - Alterar contato\n");
        printf("4 - Fechar\n");
        printf("Digite uma opcao: ");
        scanf("%d", &op);
        fflush(stdin);

        switch(op){
            case 1:
                system("cls");
                if(contatos<qt){
                    printf("\n --- INSERIR CONTATO --- \n");
                    inserir(ct, contatos);
                    printf("\n *CONTATO INSERIDO!* \n");
                    system("pause");
                    contatos+=1;
                }
                else {
                    printf("\n * AGENDA LOTADA! * \n");
                    system("pause");
                }
                break;

            case 2:
                system("cls");
                printf("\n --- PESQUISAR CONTATO --- \n");
                if(contatos <=0 ) {printf ("\n * NÃO HÁ CONTATOS! *\n");}

                else{
                    printf("Digite o nome a ser pesquisado: ");
                    scanf("%s", nome);
                    fflush(stdin);
                    n = pesquisar(ct, nome, contatos);

                    if(n == -1){
                        printf("\n * ESSE CONTATO NAO FOI ENCONTRADO OU NAO EXISTE *\n");
                        system("pause");
                    }
                    else{
                        printf("\n * CONTATO ENCONTRADO *\n");
                        listar(ct, n);
                        system("pause");
                    }
                }
                break;

            case 3:
                system("cls");
                printf("\n --- ALTERAR CONTATO --- \n");
                if(contatos <= 0)
                    printf ("\n * ESSE CONTATO NAO FOI ENCONTRADO OU NAO EXISTE *\n");

                else{
                    for(i=0; i<contatos; i++){
                        printf("%d - %s \n", i, ct[i].nome);
                    }
                    printf("\nDigite a opcao a ser alterada: ");
                    scanf("%d", &op);
                    fflush(stdin);

                    if(op < contatos){
                        listar(ct, op);
                        printf("\n ALTERANDO DADOS... \n");
                        printf("Nome: ");
                        gets(ct[op].nome);
                        printf("Endereco: ");
                        gets(ct[op].endereco);
                        printf("Telefone: ");
                        scanf("%d", &ct[op].telefone);
                        printf("Situacao (L – Livre; X – Ocupado ou * - Apagado): ");
                        scanf("%s", &ct[op].situacao);

                        fflush(stdin);
                    }
                    else
                        printf("\n OPERACAO INVALIDA! \n");
                    system("pause");
                }
                break;

            case 4:
                system("cls");
                printf("\n -> Deseja sair (1 - SIM // 2 - NÃO): ");
                scanf("%d", &op);
                if(op == 1){
                    printf("\n FECHANDO...\n");
                    menu=0;
                }
                else {break;}
                break;

            default:
                printf("\n * OPCAO INVALIDA! * \n");
                system("pause");
                break;
        }
    } while (menu);

    return 0;
}
/** Funções **/
void inserir(Contato *cto, int contatos){
    printf("Digite o nome: ");
    gets(cto[contatos].nome);

    printf("Digite endereco: ");
    gets(cto[contatos].endereco);

    printf("Digite telefone: ");
    scanf("%d", &cto[contatos].telefone);

    printf("Digite situacao (L. Livre; X. Ocupado ou * Apagado): ");
    scanf("%s", &cto[contatos].situacao);

    fflush(stdin);
}

int pesquisar(Contato *cto, char *nome, int contatos){
    int i=0;
    for(i=0; i<contatos; i++){
        if(!strcmp(cto[i].nome, nome)){
            return i;
        }
    }
    return -1;
}

void listar(Contato *cto, int indice){
    char sit[10];
    printf("Nome: %s \n", cto[indice].nome);
    printf("Endereco: %s \n", cto[indice].endereco);
    printf("Telefone: %d \n", cto[indice].telefone);
    if(cto[indice].situacao == 'L') {strcpy(sit, "Livre");}
    else if(cto[indice].situacao == 'X') {strcpy(sit, "Ocupado");}
    else if(cto[indice].situacao == '*') {strcpy(sit, "Apagado");}

    printf("Situacao: %s \n", sit);
}
