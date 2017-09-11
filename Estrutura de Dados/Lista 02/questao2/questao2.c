/** Questão 2 - Funcionarios de uma Fábrica **/

#include <stdio.h>
#include <stdlib.h>

/** Registro/Struct de Funcionario **/
  typedef struct {
    char nome[50];
    char genero;
    int pecasProd;
  } Funcionario;

/** Variáveis Globais **/
  int resp;
  int validaResp;
  char *func_do_mes;
  int prod_m = 0;
  int prod_f = 0;
  int aux = 0; //para verificar quem vendeu mais
  int qtFunc = 3;
  Funcionario func[3];

/** Assinatura das Funções **/
  char continua();
  void cadastro();
  void listar();
  void relatorio_prod();

/** Programa **/
int main (void) {

  do {
    system("cls");
    printf("\n Beco da Poeira LTDA (Fabrica)");
    printf("\n 1. Cadastro de Funcionario");
    printf("\n 2. Listar Funcionarios");
    printf("\n 3. Relatorio de Producao");
    printf("\n 0. Sair do Programa \n");
    scanf("%d", &resp);

    switch (resp){
        case 1:
          cadastro();
          break;
        case 2:
          listar();
          break;
        case 3:
          relatorio_prod();
          break;
        case 0:
            exit(0);
            break;
        default:
            printf("Opcao invalida\n");
            system("pause");
            break;
    }

  } while (continua() == 'S');

  return 0;
}
/** Fim Programa **/

/** Funções **/

char continua (){
    char c;
    system("cls");
    printf("Deseja continuar ? S/N \n");
    getchar();
    scanf("%c", &c);

    if (c == 'S' || c== 's')
        return 'S';
    else
        return 'N';
}

void cadastro(){

    int c;

    system("cls");
    printf("CADASTRO DE FUNCIONARIOS\n");

    for (c=0; c < qtFunc; c++){
        system("cls");
        printf("\n Nome: ");
        scanf("%s", func[c].nome);
        getchar();
        printf("\n Genero: ");
        scanf("%c", &func[c].genero);
        printf("\n Producao: ");
        scanf("%d", &func[c].pecasProd);

    }
}

void listar(){
  system("cls");
  int l;
  for (l=0; l< qtFunc; l++){
    printf("\nNome: %s", func[l].nome);
    printf("\nGenero: %c", func[l].genero);
    printf("\nProduziu: %i pecas\n", func[l].pecasProd);
  }
  printf("\n");
  system("pause");
}

void relatorio_prod(){
    system("cls");
    int r;

    for (r=0; r < qtFunc; r++) {

        if(func[r].genero=='M')
            prod_m = prod_m + func[r].pecasProd;
        else
            prod_f = prod_f + func[r].pecasProd;

        if(func[r].pecasProd > aux){
            aux = func[r].pecasProd;
            func_do_mes = func[r].nome;
        }
  }
  printf("\n*********************RELATORIOS************************\n");
  printf("Producao do SEXO MASCULINO: %d\n", prod_m);
  printf("Producao do SEXO FEMININO: %d\n", prod_f);
  printf("Funcionario do Mes (que obteve mais vendas): %s \n", func_do_mes);
  system("pause");

}


