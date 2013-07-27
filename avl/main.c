#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(void)
{
    int enter = 0;
	AVL *a;	    
	a = cria();
	
	while(enter != 7) {		
		printf("Digite a opcao:\n");
		printf("1 - inserir\n");
        printf("2 - retirar\n");
        printf("3 - limpar\n");
		printf("4 - alterar carga horaria\n");
		printf("5 - alterar semestre\n");
		printf("6 - imprime arvore\n");
		printf("7 - sair\n");
		scanf("%d",&enter);
		if(enter == 1){
			a = insere(a,4,"Jeff",3524,7);
			a = insere(a,4,"Jeff",3524,7);
			a = insere(a,2,"Tai",2000,13);
			a = insere(a,1,"Mateus",1300,9);
			a = insere(a,3,"Guilherme",2000,5);
			a = insere(a,5,"Gabriel",2000,3);
			a = insere(a,6,"Jesse",2000,4);	
		}
		if(enter == 2){
			int i;
			scanf("%d",&i);
			a = retira(a,i);
		}
		if(enter == 3){
			a = limpeza(a);
		}
		if(enter == 4){
			alteraCH(a,4,2300);
		}
		if(enter == 5){
			alteraSemestre(a,2,12);
		}
		if(enter == 6){
			printf("\nAlunos na Arvore: ");
			imprime(a);
		}							
	}        								
    return 0;
}
