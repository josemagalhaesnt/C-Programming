#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
    char nome[20];
    char sobrenome[20];
    int idade;
    int prioridade;
    struct node *prox;
};

struct node* head = NULL;
struct node* tail = NULL;
struct node* temp;

char nome[20], sobrenome[20];
int idade, pri;
char prioridade[10];

struct node* criarPessoa(char nome[], char sobrenome[], int idade, int prioridade)
{
    struct node* novaPessoa = (struct node*)malloc(sizeof(struct node));
    strcpy(novaPessoa->nome, nome);
    strcpy(novaPessoa->sobrenome, sobrenome);
    novaPessoa->idade = idade;
    novaPessoa->prioridade = prioridade;
    novaPessoa->prox = NULL;

    return novaPessoa;
};

void enfileirar(char nome[], char sobrenome[], int idade, int prioridade)
{
    struct node* pessoa = criarPessoa(nome, sobrenome, idade, prioridade);
    //if we have no node, we create head and tail node here
    if(head == NULL && tail == NULL)
    {
        head = pessoa;
        tail = pessoa;
    }
    else
    {
        //if new pessoa prioridade equal or smaller than head node, we should make it first node
        if(pessoa->prioridade <= head->prioridade)
        {
            temp = head;
            head = pessoa;
            pessoa->prox = temp;
            return;
        }
        //if new pessoas prioridade is equal or bigger than tail node, we should make it tail.
        if(pessoa->prioridade >= tail->prioridade)
        {
            tail->prox = pessoa;
            tail = pessoa;
        }

        //this is general algoritm for prioridade queues
        temp = head;
        while(temp->prox != NULL)
        {
            if(pessoa->prioridade < temp->prox->prioridade)
            {
                struct node* newy;
                newy = temp->prox;
                temp->prox = pessoa;
                pessoa->prox = newy;
            }
            temp = temp->prox;
        }
    }
}

void sairDaFila()
{
    temp = head;
    if(head == NULL)
    {
        printf("\nFila vazia");
        return;
    }

    if(head == tail)
    {
        head = NULL;
        tail = NULL;
        return;
    }

    head = temp->prox;
    free(temp);
}

struct node* whoprox()
{
    if(head == NULL)
    {
        printf("\nNao tem ninguem na fila");
        return 0;
    }

    return head;
}

void checkPri(int x)
{
    if(x == 1)
            strcpy(prioridade, "Alta");
        else if(x == 2)
            strcpy(prioridade, "Normal");
        else
            strcpy(prioridade, "Baixa");
}
void mostrarFila()
{

    int i = 1;
    if(head == NULL)
    {
        return;
    }
    temp = head;
    while(temp->prox != NULL)
    {
        checkPri(temp->prioridade);
        printf("\n%d. posicao => %s %s %d prioridade ==> %s ", i, temp->nome, temp->sobrenome, temp->idade, prioridade);
        temp = temp->prox;
        i++;
    }
    checkPri(temp->prioridade);
    printf("\n%d. posicao => %s %s %d prioridade ==> %s ", i, temp->nome, temp->sobrenome, temp->idade, prioridade);
}


void menu()
{
    int op;
    while( 1 == 1 )
    {
        printf("\n 1- Enfileirar ... ");
        printf("\n 2- Sair da fila ... ");
        printf("\n 3- Quem e o prox? ");
        printf("\nOpcao desejada: ");
        scanf("%d", &op);
        selection(op);
    }
}

void selection(int opEscolhida)
{
    switch(opEscolhida)
    {
        case 1:
            printf("\n Digite o nome ... ");
            scanf("%s", &nome);
            printf("\n Digite o sobrenome ... ");
            scanf("%s", &sobrenome);
            printf("\n Digite a idade ... ");
            scanf("%d", &idade);
            printf("\n Digite a prioridade ... (1 para Alta | 2 para Normal | 3 para Baixa) ");
            scanf("%d", &pri);
            enfileirar(nome, sobrenome, idade, pri);
            mostrarFila();
            break;
        case 2:
            sairDaFila();
            mostrarFila();
            break;
        case 3:
            temp = whoprox();
            printf("\n ****************** \n");
            if(temp != NULL)
            {
                printf("%s %s %d", temp->nome, temp->sobrenome, temp->idade);
            }
            break;
    }
}

int main()
{
    menu();
    return 0;
}
