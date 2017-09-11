/** Questões 3 e 4 - Boletim Escolar **/

#include <stdio.h>
#include <stdlib.h>

/** Registro de Alunos **/
typedef struct {
  char nome[50];
  float notas[3];
  float media_final;
  float media_parcial;
} Aluno;

/** Variáveis Globais **/
int qtAlunos = 3;
Aluno alunos[3];
int resp;
float n1, n2, af;

/** Assinatura das Funções **/
void cadastro();
float calcular_MP(float n1, float n2);
float calcular_MF(float media, float af);
char continua();
void listar();

/** Programa **/
int main () {
  do {
    system("cls");
    printf("\n IFCE");
    printf("\n 1. Cadastro de Alunos");
    printf("\n 2. Lista de Alunos");
    printf("\n 0. Sair do Programa \n");
    scanf("%d", &resp);

    switch (resp){
        case 1:
          cadastro();
          break;
        case 2:
          listar();
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

/** Funções **/
void cadastro(){

    int c;

    system("cls");
    printf("CADASTRO DE ALUNOS\n");

    for (c=0; c < qtAlunos; c++){
        system("cls");
        printf("\n Nome: ");
        scanf("%s", alunos[c].nome);
        getchar();
        printf("\n AP1: ");
        scanf("%f", &n1);
        printf("\n AP2: ");
        scanf("%f", &n2);
        alunos[c].media_parcial = calcular_MP(n1,n2);

        if (alunos[c].media_parcial < 7) {
          printf("\n AF: ");
          scanf("%f", &af);
          alunos[c].media_final = calcular_MF(alunos[c].media_parcial,af);
          alunos[c].notas[0] = n1;
          alunos[c].notas[1] = n2;
          alunos[c].notas[2] = af;
        }
        else {
          alunos[c].media_final = alunos[c].media_parcial;
          alunos[c].notas[0] = n1;
          alunos[c].notas[1] = n2;
        }
    }
}

float calcular_MP(float n1, float n2){
    float mp = ((2 * n1) + (3 * n2))/5;
    return mp;
}

float calcular_MF(float media, float af){
    float mf = (media +  af)/2;
    return mf;
}
void listar(){
  system("cls");
  int l;
  for (l=0; l< qtAlunos; l++){
    printf("\nAluno: %s", alunos[l].nome);
    printf("\nN1: %.2f", alunos[l].notas[0]);
    printf("\nN2: %.2f", alunos[l].notas[1]);
    if (alunos[l].media_parcial < 7)
        printf("\nAF: %.2f", alunos[l].notas[2]);
    printf("\nMedia Final: %.2f", alunos[l].media_final);

    if (alunos[l].media_final >= 5)
        printf("\nStatus: Aprovado");
    else
        printf("\nStatus: Reprovado");

    printf("\n");

  }
  printf("\n");
  system("pause");
}

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
