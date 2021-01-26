#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int filho1,filho2,neto1,neto2;
	printf("O pai nasceu...\n");
	double tempo;
	time_t inicio,fim;

	time(&inicio);

	sleep(14);

	time(&fim);
	tempo=difftime(fim,inicio);
	printf("O filho 1 nasceu as = %.2f\n",tempo);

	filho1=fork();
	if(filho1<0){
		printf("Erro ao criar processo!!!\n");
		return 1;
	}
	if(filho1==0){
		//printf("O filho 1 nasceu...\n");
		time_t inicio1,fim1;
		double tempo1;
		time(&inicio1);
		
		sleep(12);
		
		time(&fim1);
		tempo1=difftime(fim1,inicio1)+14;
		printf("O neto 1 nasceu as = %.2f\n", tempo1);

		neto1=fork();
		if(neto1<0){
			printf("Erro ao criar processo!!!\n");
		}
		if(neto1==0){
			//printf("O neto 1 nasceu...\n");
			time_t inicio3,fim3;
			double tempo3;
			time(&inicio3);
			
			sleep(12);
			
			time(&fim3);
			tempo3=difftime(fim3,inicio3);
			printf("O neto 1 morreu as = %.2f, e viveu %.0f anos\n", tempo3+26, tempo3);
			exit(0);
		}
		sleep(18);

		time(&fim1);
		tempo1=difftime(fim1,inicio1);
		printf("O filho 1 morreu as = %.2f, e viveu %.0f anos\n", tempo1+14, tempo1);
		exit(0);
	}

	sleep(2);

	time(&fim);
	tempo=difftime(fim,inicio);
	printf("O filho 2 nasceu as = %.2f\n",tempo);

	filho2=fork();
	if(filho2<0){
		printf("Erro ao criar processo!!!\n");
		return 1;
	}
	if(filho2==0){
		//printf("O filho 2 nasceu...\n");
		time_t inicio2,fim2;
		double tempo2;
		time(&inicio2);

		sleep(14);

		time(&fim2);
		tempo2=difftime(fim2,inicio2)+16;
		printf("O neto 2 nasceu as = %.2f\n", tempo2);
		
		neto2=fork();
		if(neto2<0){
			printf("Erro ao criar processo!!!\n");
		}
		if(neto2==0){
			//printf("O neto 2 nasceu...\n");
			time_t inicio4,fim4;
			double tempo4;
			time(&inicio4);

			sleep(18);

			time(&fim4);
			tempo4=difftime(fim4,inicio4);
			printf("O neto 2 morreu as = %.2f, e viveu %.0f\n", tempo4+30, tempo4);
			exit(0);
		}
		sleep(16);

		time(&fim2);
		tempo2=difftime(fim2,inicio2);
		printf("O filho 2 morreu as = %.2f, e viveu %.0f anos\n", tempo2+16, tempo2);
		exit(0);
	}
	
	sleep(44);
	//printf("O pai morreu...\n");
	time(&fim);
	tempo=difftime(fim,inicio);
	printf("O pai morreu as = %.2f, e viveu %.0f anos\n", tempo, tempo);
	return 0;
}