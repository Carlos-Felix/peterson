#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int turn;
int flag[2];

void proceso_0() {
	printf("Entrada del proceso: 0\n");
	flag[0] = 1;                      
      	turn = 1;                            
      	while( flag[1] && turn == 1 ){
		// { no hace nada; espera. } 
		      
		printf("Espera proceso: 0\n");
              
	 }                   
	 // sección crítica                        
		                                  
	printf("Sección crítica proceso: 0\n");

	for(int k=0; k<10000; k++);
	// fin de la sección crítica
	printf("Termina seccion crítica del proceso: 0\n");
	flag[0] = 0;
	printf("Sección NO crítica proceso: 0\n");
	printf("------Salida del proceso: 0----\n");
}

void proceso_1() {
	printf("Entrada del proceso: 1\n");
	flag[1] = 1;
      	turn = 0;
      	while( flag[0] && turn == 0 ){
		printf("Espera proceso: 1\n");
	}
               
	printf("Sección crítica proceso: 1\n");
	for(int k=0; k<10000; k++);
	printf("Termina seccion crítica del proceso: 1\n");
	flag[1] = 0;
	printf("Sección NO crítica proceso: 1\n");
	printf("-------Salida del proceso: 1----\n");

	
}

int main() {
	int dos = 2;
	flag[0] =0;
	flag[1] = 0;
	pthread_t th[dos];
	
	pthread_create(&th[0], NULL, (void *)proceso_0, NULL);
	pthread_create(&th[1], NULL, (void *)proceso_1, NULL);
	for (int k=0;k<dos;k++){
		pthread_join(th[k], NULL);
	}
}
