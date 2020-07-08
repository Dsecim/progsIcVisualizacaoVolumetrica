
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void num_vertices(int* n){
	*n=rand()%5;
	//printf("%d\n",*n);
}
int main(void){
    int num;
    float val;
    float vertices[4];
    srand(time(NULL));
    printf("\nGerando 25 sequencias de 4  valores aleatorios:\n\n V1\tV2\tV3\tv4\n\n");
    for(int i=0;i<25;i++){
        num_vertices(&num);
	//preenche um vetor com os valores(todos positivos) dos vertices 
    	for(int j=0;j<4;j++){
    		val=rand()%1000000;
    		vertices[j]=val/1000000;
		//printf("%f\t\t",val/1000000);
    	}
	//sorteia os vertices que terao valores negativos
	for(int x=0; x<num;x++){
    		//sorteia os vertices 
    		int aux=rand()%5;
    		vertices[aux]=vertices[aux]*-1;

    	}
	//le o vetor já preenchido
    	for(int k=0;k<4;k++){
    		printf("%f\t",vertices[k]);
    	}
        printf("\n");
    }

}
