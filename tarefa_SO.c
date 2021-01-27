#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

double tempo;
time_t t;

int main(){

	int filho1,filho2,neto1,neto2;
	time(&t);
	printf("O pai nasceu em %s\n", ctime(&t));
	
	time_t inicio,fim;

	time(&inicio);

	sleep(14);

	time(&fim);
	tempo=difftime(fim,inicio);
	time(&t);
	printf("O filho 1 nasceu em %s\n", ctime(&t));

	filho1=fork();
	if(filho1<0){
		printf("Erro ao criar processo!!!\n");
		return 1;
	}
	if(filho1==0){
		//printf("O filho 1 nasceu...\n");
		time_t inicio1,fim1;
		time(&inicio1);
		
		sleep(12);
		
		time(&fim1);
		tempo=tempo+difftime(fim1,inicio1);
		time(&t);
		printf("O neto 1 nasceu em %s\n", ctime(&t));

		neto1=fork();
		if(neto1<0){
			printf("Erro ao criar processo!!!\n");
		}
		if(neto1==0){
			//printf("O neto 1 nasceu...\n");
			time_t inicio3,fim3;
			time(&inicio3);
			
			sleep(12);
			
			time(&fim3);
			tempo=tempo+difftime(fim3,inicio3);
			time(&t);
			printf("O neto 1 morreu em %s, e viveu %.0f anos\n\n", ctime(&t), difftime(fim3,inicio3));
			exit(0);
		}
		sleep(18);

		time(&fim1);
		tempo=difftime(fim1,inicio);
		time(&t);
		printf("O filho 1 morreu em %s, e viveu %.0f anos\n\n", ctime(&t), difftime(fim1,inicio1));
		exit(0);
	}

	sleep(2);

	time(&fim);
	tempo=difftime(fim,inicio);
	time(&t);
	printf("O filho 2 nasceu em %s\n",ctime(&t));

	filho2=fork();
	if(filho2<0){
		printf("Erro ao criar processo!!!\n");
		return 1;
	}
	if(filho2==0){
		//printf("O filho 2 nasceu...\n");
		time_t inicio2,fim2;
		time(&inicio2);

		sleep(14);

		time(&fim2);
		tempo=tempo+difftime(fim2,inicio2);
		time(&t);
		printf("O neto 2 nasceu em %s\n", ctime(&t));
		
		neto2=fork();
		if(neto2<0){
			printf("Erro ao criar processo!!!\n");
		}
		if(neto2==0){
			//printf("O neto 2 nasceu...\n");
			time_t inicio4,fim4;
			time(&inicio4);

			sleep(18);

			time(&fim4);
			tempo=tempo+difftime(fim4,inicio4);
			time(&t);
			printf("O neto 2 morreu em %s, e viveu %.0f anos\n\n", ctime(&t), difftime(fim4,inicio4));
			exit(0);
		}
		sleep(16);

		time(&fim2);
		tempo=difftime(fim2,inicio);
		time(&t);
		printf("O filho 2 morreu em %s, e viveu %.0f anos\n\n", ctime(&t), difftime(fim2,inicio2));
		exit(0);
	}
	
	sleep(44);
	//printf("O pai morreu...\n");
	time(&fim);
	tempo=difftime(fim,inicio);
	time(&t);
	printf("O pai morreu em %s, e viveu %.0f anos\n\n", ctime(&t), tempo);
	return 0;
}
