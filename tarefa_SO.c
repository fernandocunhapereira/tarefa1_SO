#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int filho1,filho2,neto1,neto2;
	printf("O pai nasceu...\n");
	
	sleep(14);
	
	filho1=fork();
	if(filho1<0){
		printf("Erro ao criar processo!!!\n");
		return 1;
	}
	if(filho1==0){
		printf("O filho 1 nasceu...\n");
		sleep(12);
		neto1=fork();
		if(neto1<0){
			printf("Erro ao criar processo!!!\n");
		}
		if(neto1==0){
			printf("O neto 1 nasceu...\n");
			sleep(12);
			printf("O neto 1 morreu...\n");
			exit(0);
		}
		sleep(18);
		printf("O filho 1 morreu...\n");
		exit(0);
	}

	sleep(2);

	filho2=fork();
	if(filho2<0){
		printf("Erro ao criar processo!!!\n");
		return 1;
	}
	if(filho2==0){
		printf("O filho 2 nasceu...\n");
		sleep(14);
		neto2=fork();
		if(neto2<0){
			printf("Erro ao criar processo!!!\n");
		}
		if(neto2==0){
			printf("O neto 2 nasceu...\n");
			sleep(18);
			printf("O neto 2 morreu...\n");
			exit(0);
		}
		sleep(16);
		printf("O filho 2 morreu...\n");
		exit(0);
	}
	
	sleep(44);
	printf("O pai morreu...\n");

	return 0;
}