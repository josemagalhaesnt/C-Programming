#include <stdio.h>
#include <stdlib.h>
#define NUM_P 30
#define NUM_S 80

struct dic {
  struct dic *left,*right;
  char palavra[NUM_P], significado[NUM_S];
}*Root=NULL;

typedef struct dic dicionario;
int checar(char[],char[]);
void inserir(dicionario *);
void pesquisar();
void view(dicionario *);

int checar(char a[],char b[]){
     int i,j,c;
     for(i=0,j=0 ; a[i]!='\0'&&b[j]!='\0' ; i++,j++){
       if(a[i]>b[j]){
         c=1;
         break;
       }
        else if(b[j]>a[i]){
          c=-1;
          break;
        }
      else
         c=0;
     }
     if(c==1)
       return 1;
      else if(c==-1)
        return -1;
      else
        return 0;
}

void pesquisar(){
  int flag=0;
  dicionario *ptr;
  ptr=Root;
  char w[NUM_P];
  printf("\nDigite a palavra: ");
  fgets(w, NUM_P, stdin);
  while(ptr!=NULL && flag==0){
    if(checar(w,ptr->palavra)>0)
       ptr=ptr->right;
    else if(checar(w,ptr->palavra)<0)
          ptr=ptr->left;
    else if(checar(w,ptr->palavra)==0){
       flag=1;
       printf("\nSignificado: %s",ptr->significado);
    }

    }
    if(flag==0)
      printf("\nPalavra nao encontrada!!\n");
}

void inserir(dicionario *temp){
  int flag=0;
  dicionario *ptr,*par;
  ptr=Root;

  if(Root==NULL)
     Root=temp;
  else{
     while(ptr!=NULL ){
       if(checar(temp->palavra,ptr->palavra)>0){
         par=ptr;
         ptr=ptr->right;
       }

       else if(checar(temp->palavra,ptr->palavra)<0)
     {
       par=ptr;
       ptr=ptr->left;
     }
       else if(checar(temp->palavra,ptr->palavra)==0){
          flag=1;
            printf("\nA palavra ja existe!!\n");
          break;
       }

   }
       if(flag==0 && ptr==NULL){

         if(checar(par->palavra,temp->palavra)==1)
            par->left=temp;
         else if(checar(par->palavra,temp->palavra)==-1)
            par->right=temp;
       }

     }

}

void view(dicionario *ptr){
  if(Root==NULL)
    printf("\nDicionario vazio\n");

  else if(ptr !=NULL){
   view(ptr->left);

   printf("\nPalavra: %s\n",ptr->palavra);
   printf("\nSignificado: %s\n",ptr->significado);

   view(ptr->right);
  }

}

int main(int argc, char const *argv[]) {
  int op;
  dicionario *temp;
  while(op!=4){
    system("cls");
    printf("\n1.Pesquisar no dicionario \n2.Inserir palavra\n3.Visualizar definicoes\n4.Fechar\nEscolha uma opcao.. ");
    scanf("%d",&op);
    switch (op) {
      case 1:
        getchar();
        pesquisar();
        system("pause");
        break;
      case 2:
        system("cls");
        temp=(dicionario*)malloc(sizeof(dicionario));
        temp->left=NULL;
        temp->right=NULL;
        getchar();
        printf("\nPalavra: \n");
        fgets(temp->palavra,NUM_P,stdin);
        printf("\nSignificado: \n");
        fgets(temp->significado,NUM_S,stdin);
        inserir(temp);
        system("pause");
        break;
      case 3:
        view(Root);
        system("pause");
        break;
      case 4:
        exit(0);
    }
  }
  return 0;
}