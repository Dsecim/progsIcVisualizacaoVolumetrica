#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
//#include "../Lib/lib.h"

void cria_arq(FILE *,char *);
void num_vertices(int* n,int* ncol);
void preencher(FILE *,char *);
int main(){
  FILE *fp;
  char nome[80];
  printf("Digite o nome da matriz a ser gerada:\n");
  scanf("%s",nome);
  cria_arq(fp,nome);
  preencher(fp,nome);

}

//Funcao que cria o arquivo
void cria_arq(FILE * fp, char * a){
  fp = fopen(a,"w");
  fflush(fp);
  fclose(fp);
}
//Funcao que preenche o arquivo com a matriz
void preencher(FILE * fp,char * nome){
  int num,nline,ncol;

  printf("comprimento da matriz em quadrados:\t");
  scanf("%d",&nline);
  printf("largura da matriz em quadrados:\t");
  scanf("%d",&ncol);
  float arr[nline+1][ncol+1];
  float val;
  //float val, coluna[ncol+2],linha[nline+2];
  /*+2 devido ao \0 de fim de vetor e uma necessidade percebida no algoritmo:
  Se quisermos uma imagem com dimensão 4linhas e 3 colunas, obteremos 20
  vértices (5x4), a dimensão da matriz de vertices deve ser sempre quantidade
   de linhas e colunas mais 1 (Matriz_Vertices[linhas+1][colunas+1])
  */


  srand(time(NULL));
  fp = fopen(nome,"w");
  fprintf(fp,"%dx%d\n",nline,ncol);

  for(int i=0;i<nline+1;i++){
    num_vertices(&num,&ncol);

    //preenche uma linha com os valores(todos positivos)
    for(int j=0;j<ncol+1;j++){
       val=rand()%1000000;
       arr[i][j]=val/1000000;
     }

     //sorteia os que terao valores negativos
     for(int x=0; x<num;x++){
                        //sorteia os vertices
                        int aux=rand()%ncol+1;
                        arr[i][aux]=arr[i][aux]*-1;
      }
     for(int k=0;k<ncol+1;k++){
        fprintf(fp,"%f\t",arr[i][k]);
      }
      fprintf(fp,"\n");
   }
   fprintf(fp, "#");
}
void num_vertices(int* n, int* ncol){
  *n=rand()%*ncol+1;
}

