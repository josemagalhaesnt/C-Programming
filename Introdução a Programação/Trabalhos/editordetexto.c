#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void criar(FILE *arquivo);//Função para criar o arquivo
void editar(FILE *arquivo);//Função para editar o arquivo
void remover(FILE*arquivo);//Função para remover o arquivo
void inserir_linha (FILE *arquivo); // Adiciona linha

/*Nao conseguimos*/

void editar_linha(FILE *arquivo);// Edita linha
void remover_linha (FILE *arquivo);// Remove

//void criar_controle(FILE *nomeArquivo, char *nome, char *sobrenome, char *data);

char nomeDoArquivo[60]; //variavel que vai armazenar o nome do arquivo de texto
char *nomeArquivo = &nomeDoArquivo[60]; //ponteiro que aponta pro nome do arquivo fornecido pelo usu�rio
char result;


int respostaMenu1;
int *respMenu1 = &respostaMenu1; //variavel de controle do primeiro menu

int respostaMenu2; //variavel de controle do segundo menu (SUBMENU DE EDITAR)
int *respMenu2 = &respostaMenu2;

typedef struct {
    char line[81];
} linha;


int main (void){ //inicio do programa
//VARIAVEIS

    FILE *arquivo;
    char oper = 1, a, oper2 = 1;
    while (oper != '0'){

        printf("\bSeja bem vindo ao EDITOR DE TEXTO\n");
        printf("\nEscolha uma das opcoes abaixo:\n\n");
        printf("1: Para CRIAR um novo arquivo de texto\n");
        printf("2: Para EDITAR um arquivo de texto \n");
        printf("3: Para REMOVER um arquivo de texto\n");
        printf("0: Para SAIR\n");

        oper = getch();
        fflush(stdin);
        system("cls");

        switch (oper){
            case '1':
                criar(arquivo);
                printf("\n");
                a = getch();
                system("cls");
                break;
            case '2':
                editar(arquivo);
                printf("\n");
                a = getch();
                system("cls");
                break;
            case '3':
                remover(arquivo);
                printf("\n");
                a = getch();
                system("cls");
                break;
            case '0':
                break;
            default:
            printf ("Opcao invalida!");
        }
    }
return 0;
}
                /*INÍCIO DAS FUNÇÕES DO PROGRAMA*/
    /*INÍCIO DA FUNÇÃO DE CRIAR ARQUIVO DE TEXTO*/
void criar(FILE *arquivo){

int i=0;
linha texto[100];
int n=0;
time_t currentTime;
struct tm *timeInfo;
//const char *nome, *sobrenome, *data;
//data = asctime(timeInfo);

    printf("Voce escolheu CRIAR UM NOVO ARQUIVO DE TEXTO\n");

        printf("\nDiga abaixo o nome do seu arquivo de texto:\n (Nao precisa colocar a extensao do arquivo [.txt])\n");
        scanf("%s", nomeArquivo);
        strcat(nomeArquivo, ".txt");

        if((arquivo = fopen(nomeArquivo,"w+")) == NULL){
            printf("Nao foi possivel criar o arquivo\n");
        }
            do{
                printf("\nDigite a linha %d\n", i+1);
                fflush(stdin);
                gets(texto[i].line);
                fputs(texto[i].line, arquivo);
                fputs("\n", arquivo);
                i++;
                if (feof(stdin))
                    break;
            }while(1);
            fclose(arquivo);


}

     /*INICIO DA FUNÇÃO EDITAR UM ARQUIVO DE TEXTO*/
void editar (FILE *arquivo){
int i=0, cont=0, aux=0;
linha texto[100];
linha leitura[100];
char *procurar="321";

        printf("Voce escolheu EDITAR UM ARQUIVO DE TEXTO\n");

        /*printf("\nDiga abaixo o nome do seu arquivo de texto:\n (Nao precisa colocar a extensao do arquivo [.txt])\n");
        scanf("%s", nomeArquivo);
        strcat(nomeArquivo, ".txt");

        if((arquivo = fopen(nomeArquivo,"rb")) == NULL){
            printf("Nao foi possivel abrir o arquivo\n");*/

            char oper2 = 1, a;
            while (oper2 != '0'){
            printf("\nAgora, digite abaixo a opcao desejada:\n");
            printf("1: Para INSERIR uma nova linha.\n");
            printf("2: Para EDITAR uma linha existente.\n");
            printf("3: Para REMOVER uma linha existente.\n");
            printf("0: Para VOLTAR AO MENU 1\n");

            oper2 = getch();
            fflush(stdin);
            system("cls");

            switch (oper2){
            case '1':
                inserir_linha(arquivo);
                printf("\n");
                a = getch();
                system("cls");
                break;
            case '2':
                editar_linha(arquivo);
                printf("\n");
                a = getch();
                system("cls");
                break;
            case '3':
                remover_linha(arquivo);
                printf("\n");
                a = getch();
                system("cls");
                break;
            case '0':
                break;
            default:
                printf("Opcao invalida!");
                break;
            }
        }

    fclose(arquivo);
}

void remover(FILE*arquivo){
    int i=0, cont=0, aux=0;
    linha texto[100];
    linha leitura[100];
	int resposta;

    printf("---------------------------------------------------------\n");
    printf("\nVoce escolheu REMOVER UM ARQUIVO DE TEXTO\n");
    printf("---------------------------------------------------------\n");
    printf("\nDiga abaixo o arquivo que deseja remover:\n \n(NAO precisa colocar a extensao do arquivo (.txt)\n");
    printf("---------------------------------------------------------\n");
	scanf("%s",nomeArquivo); //lê o nome do arquivo texto
	strcat(nomeArquivo, ".txt");


    arquivo=fopen(nomeArquivo,"rb");

        if (arquivo) { //se conseguiu abrir o arquivo
        fclose(arquivo); //fecha o arquivo
        printf("\nDeseja mesmo apagar o arquivo? (%s)\n", nomeArquivo); //verifica se o usu�rio quer mesmo apagar o arquivo
        printf("\nDigite 1 para SIM e 2 para NAO\n");
        scanf("%d",&resposta);

        if (resposta == 1) {
            if (!remove(nomeArquivo)){
            printf("\nArquivo removido com sucesso!\n");
            }
        }

            else {
            printf("\nNao foi possivel remover o arquivo.\n");
            }
        }
        else {
        printf("\nO arquivo a ser removido nao existe ou nao se encontra em diretorio acessivel.\n");
        }

}

     /*INICIO DA FUNÇÃO INSERIR LINHA EM UM ARQUIVO EXISTENTE*/


void inserir_linha (FILE *arquivo){
int result;
int i=0;
char caractere;
linha texto[100];

        printf("\nDiga abaixo o nome do seu arquivo de texto:\n (Nao precisa colocar a extensao do arquivo [.txt])\n");
        scanf("%s", nomeArquivo);
        strcat(nomeArquivo, ".txt");

        if((arquivo = fopen(nomeArquivo,"a+")) == NULL){
            printf("Nao foi possivel abrir o arquivo!!");
        }

        //So estamos conseguindo inserir linha no final

            do{
                printf("\nDigite a nova linha %d:\n", i+1);
                fflush(stdin);
                gets(texto[i].line);
                fputs(texto[i].line, arquivo);
                fputs("\n", arquivo);
                i++;
                if (feof(stdin))
                    break;
            }while(1);
            fclose(arquivo);

            exit(0);

}
    /*FIM DA FUNÇÃO INSERIR LINHA EM UM ARQUIVO EXISTENTE*/
    /*INICIO DA FUNÇÃO PROCURAR*/

void editar_linha(FILE *arquivo){
    int i=0, cont=0, aux=0;
    linha texto[100];
    linha leitura[100];

        printf("\nVoce escolheu EDITAR UMA LINHA\n");
        printf("\nDiga abaixo o nome do arquivo que deseja editar:\n \n(NAO precisa colocar a extensao do arquivo (.txt)\n");
        scanf("%s",nomeArquivo); //lê o nome do arquivo texto
        strcat(nomeArquivo, ".txt");

        printf("\nOk, agora diga abaixo o numero da linha (ou o que esta escrito na linha) que voce deseja alterar\n");
        //ler a informação apresentada
        //localizar a linha

}


void remover_linha (FILE *arquivo){
    typedef struct {
    char line[81];
} linha;
     linha leitura[100];
     linha texto[100];
    int cont;
    int i, aux=0;
    linha blank = {""};

    if((arquivo = fopen(nomeArquivo,"a++")) == NULL){
            printf("Nao foi possivel abrir o arquivo\n");
    }else{

    printf("Digite o numero da linha da string a ser apagada.\n");
    scanf("%d", &i);
    printf("%d", i);
    gets(texto[i].line);

    fseek(arquivo,i*sizeof(linha), SEEK_SET );

    fread(&texto, sizeof(linha), 1, arquivo);
    printf("%s", texto[i].line);

    if(texto[i].line == '\0'){
        printf("Sem conteudo na linha\n");
    } else{
        fseek(arquivo,i*sizeof(linha), SEEK_SET );
    }
    fwrite(&blank, sizeof (linha), 1, arquivo);
    }
    fclose(arquivo);
}
/*void criar_controle(const char *nomeArquivo, const char *nome, const char *sobrenome, char *data) {
                    int i=0;
                    time_t currentTime;
                    struct tm *timeInfo;

                    *data = asctime(timeInfo);

                            printf("\n Ok, seu arquivo foi criado, agora digite o nome e sobrenome do autor do texto!\n");
                            gets(nome);
                            gets(sobrenome);
                            currentTime=time(NULL);
                            timeInfo=localtime(&currentTime);
                            printf("%s", asctime(timeInfo));

                            FILE *arqControle = fopen(nomeArquivo,"a+");
                            strcat(nomeArquivo,"_control.txt");

                            if(arqControle == NULL) {
                            printf("Erro!");
                            }
                            fputs(*nome, *nomeArquivo);

                            fclose(arqControle);
    }*/

