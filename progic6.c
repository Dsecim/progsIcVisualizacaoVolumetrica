#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#include<math.h>
//#include "../Lib/lib.h"

void cria_arq(FILE *,char *);
void num_vertices(int* n,int* ncol);
void  config(int);
void polariza(int,int,float,float **);
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
  int num,nline,ncol,aux_index;
  float alfa;
  aux_index=0;
  printf("comprimento da matriz em quadrados:\t");
  scanf("%d",&nline);
  printf("largura da matriz em quadrados:\t");
  scanf("%d",&ncol);
  printf("Valor alfa:");
  scanf("%f",&alfa); 
  //float arr[nline+1][ncol+1];
  float **arr = malloc((nline+1) * sizeof(*arr));
  for (int lin = 0; lin < nline+1; lin++) {
        arr[lin] = malloc((ncol+1) * sizeof(*arr[lin]));
  }
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
       aux_index=aux_index+1;
       val=rand()%1000000;
       arr[i][j]=(aux_index+val/1000000);
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
      fprintf(fp,"\n\n");
   }
   fprintf(fp, "#");
   polariza(nline,ncol,alfa,arr);
   //pode chamar as outras funções também
    
}
void num_vertices(int* n, int* ncol){
  *n=rand()%*ncol+1;
}
void polariza(int nline,int ncol, float alfa,float **matriz){
      float aux[4];
      for(int i =0;i<nline;i++){
                printf("quadrado da linha:%d\n",i);
      		for(int j=0;j<ncol;j++){

                    //teste para ver se a leitura de quadrado a quadrado está funcionando
		    //aux[0]=matriz[i][j];
                    //aux[1]=matriz[i+1][j];
                    //aux[2]=matriz[i+1][j+1];
                    //aux[3]=matriz[i][j+1];

                    int bin_dec=0;
                    if(matriz[i][j] < alfa){
			aux[0]=0;
		    }else{
                        aux[0]=1;
                        bin_dec= bin_dec + 1;
                    }
                    if(matriz[i+1][j] < alfa){
                        aux[1]=0;
                    }else{
                        aux[1]=1;
                        bin_dec = bin_dec + pow(2,1);
                    }
		    if(matriz[i+1][j+1] < alfa){
                        aux[2]=0;
                    }else{
                        aux[2]=1;
                        bin_dec = bin_dec + pow(2,2);
                    }
		    if(matriz[i][j+1] < alfa){
                        aux[3]=0;
                    }else{
                        aux[3]=1;
                        bin_dec = bin_dec + pow(2,3);
                    }
		    printf("%f\t%f\t%f\t%f\n",aux[3],aux[2],aux[1],aux[0]);
		    printf("config:\t%d\n",bin_dec);
		    config(bin_dec);
 
            
       
		 }
                 printf("\n");
	
      }
   
}
void  config(int conf){
	//5 representa que todos as arestas são interceptadas uma vez que 5 é a soma dos números que representam cada aresta 
	int tabela[][4]={{-1,-1,-1,-1},{3,0,-1,-1},{0,1,-1,-1},{3,1,-1,-1},{1,2,-1,-1},{0,1,2,3},{0,2,-1,-1},{3,2,-1,-1},{2,3,-1,-1},{0,2,-1,-1},{0,3,1,2},{2,1,-1,-1},{1,3,-1,-1},{1,0,-1,-1},{0,3,-1,-1},{5,5,5,5}};
        printf("Configuração da tabela:\t%d\t%d\t%d\t%d\n",tabela[conf][0],tabela[conf][1],tabela[conf][2],tabela[conf][3]);
}
