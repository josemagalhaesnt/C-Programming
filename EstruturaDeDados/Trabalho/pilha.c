#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 3

//Criação da Estrutura "Pilha"
struct pilha
{
    int topo;
    char nomes [N][10];
} typedef Pilha;

//Função para criar a pilha

Pilha criar_pilha()
{
    Pilha p; //damos o nome da pilha para "P"
    p.topo= -1; //atribuo o valor -1 (vazio) para o topo da pilha
    return p; //atualizo "p" (pilha "p" vazia)
}

//função que serve apenas para verificar se a pilha está vazia
int pilha_vazia (Pilha p) //recebe o valor de p (vazio ou não)
{
    if (p.topo==-1) //caso seja =-1(vazio) retorne "verdadeiro", caso não, "falso"
    return true;
    return false;
}

/*função parecida com a da função acima, mas esse serve para ver se a pilha
está cheia*/

int pilha_cheia (Pilha p)
{
    if (p.topo==N-1)
    /*se p.topo(indice do topo da nossa pilha "p") for = N-1
    significa que o topo está cheio*/
    return true;

    return false;
}
/*função que serve para empilhar
p está sendo passado por referência "&p",
está sendo uma variável string "val" para receber os nomes a serem empilhados */
int push (Pilha &p, char val[50])
{
    if (p.topo==N-1)
    return false;
    /*este "IF" acima serve para ver se a pilha está cheia, caso sim, retorna Falso
    e pára a execução da function*/
    p.topo++;//acrescenta um ao topo da pilha "p"
    strcpy(p.nomes [p.topo], val);
    /*este comando strcpy (string copy) serve para copiar um string para outra,
    neste caso, de string "val" para p.nomes[numero do topo]*/
    //na copia de strings em C++ (strcpy),é invertido do MS-DOS (destino, origem)
    return true;

}
//Função que serve para desepilhar
int pop (Pilha &p)
{
    if (p.topo==-1)
    //Se pilha estiver vazia (=-1), então retorne falso e encerre o modulo
    return false;
    p.topo—; //desempilha 1 por 1
    return true;
}
//Função para receber o valor desempilhado pela função anterior
int top (Pilha p, char val[50])
{
    if (pilha_vazia (p)==true)//caso a pilha esteja vazia, encerre o modulo
    return false;
    strcpy(val, p.nomes [p.topo]);//copia de p.nomes[índice do topo] para "val"
    return true;
}

//funcao principal
//aqui serão feitas as intervenções com io usuário
int main ()
{
    Pilha p; //cria uma pilha chamada "p" vazia
    p = criar_pilha(); //define a estrutura de "p" e aplica p.topo=N-1 (contido em Criar_Pilha)
    char nomes[50];//string para receber o que o usuário digita

    while (pilha_cheia(p)==false)//enquanto a pilha não estiver cheia faça(…)
    {
        printf ("Digite um nome (%d): n",p.topo);
        scanf("%s", nomes);
        push(p,nomes);
        /*leva para empilhar "p" e "nomes", que na função "Push"
        recebe o nome de "val"*/
    }
    //desempilhando
    while (pilha_vazia(p)==false)
    {
        //consulta a pilha
        top(p,nomes);
        printf("Vou desempilhar (%d): %sn",p.topo, nomes); //exibe o nome desempilhado
        pop(p); //desempilha 1
        //o "p.topo" mostra o valor atual do índice
    }
    system("Pause");
}
