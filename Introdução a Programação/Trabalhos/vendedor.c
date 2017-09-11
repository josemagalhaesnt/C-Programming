 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <locale.h>

 #define LIMPARTELA "cls"
 #define ERRO "system_error"
 #define FECHAR "exit(0)"

 //Definição das Estruturas

 typedef struct {

  char nome[50];
  int codigo;

 } Vendedor;

 typedef struct {
  char nome[50]; //Pegar nome do vendedor
  float valor;
  int data; //Mês que a compra foi realizada

 } Compra;

 //Declaração das funções

 int menu();
 void cadastrarCompra();
 void cadastrarVendedor();
 int buscar(char nome[50]);
 void listarCompra();
 void criar(FILE *arquivo);
 void editar(FILE *arquivo);
 void remover(FILE*arquivo);

 //Declaração das variáveis globais

 Vendedor v[10];
 Compra c [10];
 FILE *arquivo;
 char linha [60]; //variável de leitura
 char op, continuar;
 char *nomeVend = v[0].nome;
 char nomeDoArquivo[60]; //variavel que vai armazenar o nome do arquivo de texto
 char *nomeArquivo = &nomeDoArquivo[60]; //ponteiro que aponta pro nome do arquivo fornecido pelo usuario
 int resposta, i;
 char auxNome[50];

 /*INÍCIO do PROGRAMA*/
 void main () {
    setlocale(LC_ALL, "pt_BR_utf8");

    do {
       switch(menu()) {

          case '1':
            system(LIMPARTELA);
            cadastrarVendedor();

            break;

          case '2':
            system(LIMPARTELA);
            cadastrarCompra();

            break;

          case '3':
            editar(arquivo);

            break;

          case '4':
            remover(arquivo);

            break;

          case '5':
            listarCompra();

            break;

          case '0':
            system(FECHAR);
            break;

          default:
            printf("Opcao invalida");
            break;

       } //FIM DO SWITCH
       getchar();
       printf("\nDeseja continuar? (S/N)\n");
       scanf("%c", &continuar);
       getchar();
   } while (continuar == 's' || continuar == 'S');

   printf("Sessao encerrada \n");
   system("pause");

 }
 /*FIM do PROGRAMA*/

/*Implementação das Funções do Programa*/

    /*Menu*/
int menu () {
    system(LIMPARTELA);
    printf("################  SISTEMA DE VENDAS  ################");
    printf("\nO que deseja fazer ?");
    printf("\n1. Cadastrar vendedor \n2. Cadastrar compra \n3. Editar compra \n4. Remover Compra \n5. Mostrar Compra \n0. Sair");
    printf("\nOpcao: ");
    scanf("%c", &op);
    return op;
}

    /*Pesquisa Binária*/
int buscar(char nome[50]){
    int aux = -1;
    for (i = 0; i < sizeof(Vendedor); i++){
       if (strcmp(nome,v[i].nome) == 0)
            aux = i;
    }
    return aux;
}

    /*Cadastrar Vendedor*/
 void cadastrarVendedor(){
    system(LIMPARTELA);
    printf("Nome: ");
    scanf("%s", &v[0].nome);
    printf("\nCodigo de ID: ");
    scanf("%d", &v[0].codigo);
    printf("\n");
 }
    /*Cadastrar Compra*/
void cadastrarCompra(){
    system(LIMPARTELA);
    do {
        printf("Nome do Vendedor: ");
        scanf("%s", &auxNome[50]);
        if(buscar(auxNome)== 1) {
           c[0].nome == auxNome;
        }

    } while(buscar(auxNome) != 55);


    printf("\nValor da Compra: ");
    scanf("%d", &c[0].valor);
    printf("\nMes da Compra: ");
    scanf("%d", &c[0].data);
    printf("\n");
    criar(arquivo);
 }

    /*Listar Compra*/
void listarCompra() {

    printf("\nDiga abaixo o arquivo que deseja remover:\n \n(NAO precisa colocar a extensao do arquivo (.dat)\n");
	scanf("%s",nomeArquivo); //lê o nome do arquivo
	strcat(nomeArquivo, ".dat");
    arquivo = fopen(nomeArquivo,"rb");

   /*    if((arquivo = fopen(nomeArquivo,"rb")) == NULL){

        printf("Nao foi possivel abrir o arquivo\n");
    }*/
        do {

           fread(&c[0],sizeof(Compra),1,arquivo);

        } while(!feof(arquivo));

    fclose(arquivo);

}
    /*Criar Arquivo*/
void criar(FILE *arquivo){
    printf("\nDiga abaixo o nome do seu arquivo de texto:\n (Nao precisa colocar a extensao do arquivo [.dat])\n");
    scanf("%s", nomeArquivo);
    strcat(nomeArquivo, ".dat");

    if((arquivo = fopen(nomeArquivo,"wb")) == NULL){

        printf("Nao foi possivel criar o arquivo\n");
    }

    fwrite(&c[0],sizeof(Compra),1,arquivo);

    fclose(arquivo);
}
    /*Editar Arquivo*/
void editar (FILE *arquivo){
    printf("\nDiga abaixo o arquivo que deseja editar:\n \n(NAO precisa colocar a extensao do arquivo (.dat)\n");
	scanf("%s",nomeArquivo); //lê o nome do arquivo
	strcat(nomeArquivo, ".dat");
    arquivo = fopen(nomeArquivo,"rb");

        if (arquivo) { //se conseguiu abrir o arquivo
            fclose(arquivo); //fecha o arquivo
    }
}
    /*Remover Arquivo*/
void remover(FILE*arquivo){

    printf("\nDiga abaixo o arquivo que deseja remover:\n \n(NAO precisa colocar a extensao do arquivo (.dat)\n");
	scanf("%s",nomeArquivo); //lê o nome do arquivo
	strcat(nomeArquivo, ".dat");
    arquivo = fopen(nomeArquivo,"rb");

        if (arquivo) { //se conseguiu abrir o arquivo
            fclose(arquivo); //fecha o arquivo

        printf("\nDeseja mesmo apagar o arquivo? (%s)\n", nomeArquivo); //verifica se o usuario quer mesmo apagar o arquivo
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



