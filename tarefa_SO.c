#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){

	time_t t; //variavel para mostrar data/hora atual
	time_t inicio,fim; //variaveis para contar tempo de vida do pai
	time_t nasc,nasc1,nasc2,nasc3,nasc4; //variaveis que guardarao datas de nascimentos
	int filho1,filho2,neto1,neto2; //variaveis para identificar processos
	char str[30],str1[30],str2[30],str3[30],str4[30];//variaveis que guardarao datas de nascimento em strings

	time(&inicio);
	time(&t);

	time(&nasc);
	strcpy(str,ctime(&nasc));
	printf("O pai nasceu em %s\n", ctime(&t));
	
	sleep(14);

	time(&t);
	printf("O filho 1 nasceu em %s\n", ctime(&t));

	time(&nasc1);
	strcpy(str1,ctime(&nasc1));
	filho1=fork();
	if(filho1<0){
		printf("Erro ao criar processo!!!\n");
		return 1;
	}
	if(filho1==0){
		time_t inicio1,fim1; //variaveis para contar tempo de vida do filho 1
		time(&inicio1);
		
		sleep(12);
		
		time(&t);
		printf("O neto 1 nasceu em %s\n", ctime(&t));

		time(&nasc3);
		strcpy(str3,ctime(&nasc3));
		neto1=fork();
		if(neto1<0){
			printf("Erro ao criar processo!!!\n");
		}
		if(neto1==0){
			time_t inicio3,fim3; //variaveis para contar tempo de vida do neto 1
			time(&inicio3);
			
			sleep(12);
			
			time(&fim3);
			time(&t);
			printf("O neto 1 morreu em %sO neto 1 viveu %.0f anos. Nascido em %s\n", ctime(&t), difftime(fim3,inicio3), str3);
			exit(0);
		}

		sleep(18);

		time(&fim1);
		time(&t);
		printf("O filho 1 morreu em %sO filho 1 viveu %.0f anos. Nascido em %s\n", ctime(&t), difftime(fim1,inicio1), str1);
		exit(0);
	}

	sleep(2);
	
	time(&t);
	printf("O filho 2 nasceu em %s\n",ctime(&t));

	time(&nasc2);
	strcpy(str2,ctime(&nasc2));
	filho2=fork();
	if(filho2<0){
		printf("Erro ao criar processo!!!\n");
		return 1;
	}
	if(filho2==0){
		time_t inicio2,fim2; //variaveis para contar tempo de vida do filho 2
		time(&inicio2);

		sleep(14);
		
		time(&t);
		printf("O neto 2 nasceu em %s\n", ctime(&t));
		
		time(&nasc4);
		strcpy(str4,ctime(&nasc4));
		neto2=fork();
		if(neto2<0){
			printf("Erro ao criar processo!!!\n");
		}
		if(neto2==0){
			time_t inicio4,fim4; //variaveis para contar tempo de vida do neto 2
			time(&inicio4);

			sleep(18);

			time(&fim4);
			time(&t);
			printf("O neto 2 morreu em %sO neto 2 viveu %.0f anos. Nascido em %s\n", ctime(&t), difftime(fim4,inicio4), str4);
			exit(0);
		}

		sleep(16);

		time(&fim2);
		time(&t);
		printf("O filho 2 morreu em %sO filho 2 viveu %.0f anos. Nascido em %s\n", ctime(&t), difftime(fim2,inicio2), str2);
		exit(0);
	}
	
	sleep(44);

	time(&fim);
	time(&t);

	printf("O pai morreu em %sO pai viveu %.0f anos. Nascido em %s\n", ctime(&t), difftime(fim,inicio), str);
	return 0;
}
