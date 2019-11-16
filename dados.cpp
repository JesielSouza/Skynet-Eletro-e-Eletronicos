#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct lista_Cadastros{
    int ddd;
    char cod[3];
    char cel[11];
    int idade;
    float taxa;
    char nome[10];
};
int i , numCli = 0, rep = 0;
char mat[3], saida= 'n';

struct lista_Cadastros cadastro[2];

void cadCli(){
	char op = 's';
	while(op=='S' || op=='s'){
		if(numCli < 2){
	    	printf("Digite seu nome: ");
			scanf("%s", &cadastro[i].nome);
			printf("Insira o sua matrícula: ");
			scanf("%s", &cadastro[i].cod);
			printf("Insira seu DDD: ");
			scanf("%d", &cadastro[i].ddd);
			printf("Nº Celular: ");
			scanf("%s", &cadastro[i].cel);
			printf("Sua idade: ");
			scanf("%d", &cadastro[i].idade);
			if(cadastro[i].idade < 18){
				printf("\nNão é possivel realizar o cadastro!\n");
				printf("Deseja tentar outro Cadastro? [S]Sim [N]Não: ");
				scanf("%s",&op);
				return ;
			}
			printf("Deseja fazer outro Cadastro? [S]Sim [N]Não: ");
			scanf("%s",&op);
		}
		else{
			printf("Não é possível fazer mais cadastros!\n");
			return ;
		}
		numCli++;
	}
}

void lista(){
	char op = 'n';
	while(op =='N' || op=='n'){
		for(i=0;i<numCli;i++){
			printf("\nNome: %s\n", cadastro[i].nome);
			printf("Nº da Matrícula: %d\n", cadastro[i].cod);
			printf("Nº do Celular: (%d)", cadastro[i].ddd);
			printf("%s\n", cadastro[i].cel);
			printf("Idade: %d anos \n", cadastro[i].idade);
		}
		printf("Deseja voltar ao Menu Principal? [S]Sim [N]Não: ");
		scanf("%s",&op);
	}
}

void busca(){
	char op = 'n';
	printf("Digite o nº da matrícula: ");
	scanf("%s", &mat);
	if(mat == cadastro[i].cod){	
		while(op =='N' || op =='n'){	
			for(i=0;i<numCli;i++){
				printf("\nNome: %s\n", cadastro[i].nome);
				printf("Nº da Matrícula: %d\n", cadastro[i].cod);
				printf("Nº do Celular: (%d)%s\n", cadastro[i].ddd, cadastro[i].cel);
				printf("Idade: %d anos \n", cadastro[i].idade);
				printf("Taxa: R$%2.f \n", cadastro[i].taxa);
			}
		}
	}
	else{
		printf("\nEsse cadastro não está em nosso sistema!\n ");
	}
	printf("\nDeseja consultar outro cadastro? [S]Sim [N]Não: ");
	scanf("%s",&op);
}

void sair(){
	while(saida == 'N' || saida == 'n'){
		printf("Deseja encerrar o programa? [S]Sim [N]Não: ");
		scanf("%s", &saida);
		
		if(saida == 'S' || saida == 's'){
			rep = 1;
		}
		else{
			return ;
		}
	}
}

main(){
	int escolha;
	setlocale(LC_ALL, "portuguese");
	printf("-------------------------------------- \n| SEJA BEM-VINDO AO SISTEMA DA SkyNet|\n--------------------------------------\n");
	do{
		printf("\nSelecione o serviço desejado: \n[1 - Cadastrar] [2 - Listagem] [3 - Buscar] [0 - Sair] \n");
		scanf("%d", &escolha);	
		
		switch(escolha){
			case 1: cadCli();break;
			case 2: lista();break;
			case 3: busca();break;
			case 0: sair();break;
		}
		if(cadastro[i].idade < 18){
			cadastro[i].taxa = 3;
		}
		else{
			cadastro[i].taxa = 7;
		}
	}while(rep == 0);
}
