#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

//Prototipos das Funcoes
void cria_arq(FILE *, char *);
void preencher(FILE *,char *);
void num_vertices(int*);
float asymptotic_decider(float*,float);
float marching_square(float*);

//--------------------------------------------------------


//Main
int main(){
  int i = 0;
  FILE * fp;
  char nome[80];
  char numero[10];
  printf("Digite o nome do arquivo a ser gerado:\n");
  scanf("%s",nome);
  cria_arq(fp,nome);
  preencher(fp,nome);
}
//--------------------------------------------------------


//Funcao que cria o arquivo
void cria_arq(FILE * fp, char * a){
  fp = fopen(a,"w");
  fflush(fp);
  fclose(fp);
}

//Funcao que preenche o arquivo com os valores dos vertices
void preencher(FILE * fp,char * nome){
  int num,qt,cont;
  float val, vertices[4],alfa;
  printf("Quantidade de testes:");
  scanf("%d",&qt);
  printf("Valor alfa:");
  scanf("%f",&alfa);

  srand(time(NULL));
  fp = fopen(nome,"w");
  fprintf(fp,"Gerando %d sequencias de 4 valores aleatorios:\n V0\tV1\tV2\tV3\n%f\n%dx4\n",qt,alfa,qt);
  for(int i=0;i<qt;i++){
    num_vertices(&num);

    //preenche um vetor com os valores(todos positivos) dos vertices
    for(int j=0;j<4;j++){
       val=rand()%1000000;
       vertices[j]=val/1000000;
     }

     //Apenas os vertices de indice impar (1 e 3) serão negativos
     vertices[1]=vertices[1]*-1;
     vertices[3]=vertices[3]*-1;

     //Parte que testa os vertices no marching square e no asymptotic decider:
     float ad, ms;
     int rad, rms;
     ad = asymptotic_decider(vertices,alfa);
     ms = marching_square(vertices);
     if (ad >= alfa){
       rad = 1;
     }else{
       rad = 0;
     }
     if (ms >= alfa){
       rms = 1;
     }else{
       rms = 0;
     }
     if(rad!=rms){

       //Se houver divergencia de resultados plota no arquivo
       for(int k=0;k<4;k++){
         fprintf(fp,"%f\t",vertices[k]);
        }
        //coloca os valores dados por ambos algoritmos
       fprintf(fp,"/AD:%f/%d\tMS:%f/%d\n",ad,rad,ms,rms);
       cont++;
      }
   }
   fprintf(fp,"%d combinacoes, %d conflitos.",qt,cont);
}


void num_vertices(int* n){
	*n=rand()%4;
}

float asymptotic_decider(float* v,float a){
  float q1,q2,r,alfa;
  alfa = (a-v[0])/(v[1]-v[0]);
  q1 = (v[0]+(alfa*(v[1]-v[0])));
  q2 = (v[3]+(alfa*(v[2]-v[3])));
  r = (q1+(alfa*(q2-q1)));
  return r;
}
float marching_square(float* v){
  return ((v[0]+v[1]+v[2]+v[3])/4);
}