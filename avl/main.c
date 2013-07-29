#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(void)
{
    int enter = 0;
	AVL *a;	    
	a = cria();
	
	while(enter != 8) {		
		printf("Digite a opcao:\n");
		printf("1 - inserir\n");
        printf("2 - retirar\n");
        printf("3 - limpar\n");
		printf("4 - alterar carga horaria\n");
		printf("5 - alterar semestre\n");
		printf("6 - imprime arvore\n");
		printf("7 - Carregar arquivo\n");
		printf("8 - sair\n");
		scanf("%d",&enter);				
		if(enter == 1){			
			a = insere(a,4,3524,7,"Jeff");			
			a = insere(a,2,2000,13,"Tai");
			a = insere(a,1,1300,9,"Mateus");
			a = insere(a,3,2000,5,"Guilherme");
			a = insere(a,5,2000,3,"Gabriel");
			a = insere(a,6,2000,4,"Jesse");
			
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
		if(enter == 7){
			FILE * in;
			int mat,nSem,f,n,m;
			float ch;
			char nome[50],tab,linha;
			in = fopen("arq_teste2.txt","r");			
			if(in){				
				while(f = fgetc(in) != EOF){
					fscanf(in,"%d%f%d",&mat,&ch,&nSem);				
					fgets(nome,49,in);					
					for(n=0;n<49;n++){
						if(nome[n] == '\t')
							for(m=0;m<49;m++)
								nome[m] = nome[m+1];
						if(nome[n] == '\n')
							nome[n] = nome[n+1];
					}
					a = insere(a,mat,ch,nSem,nome);
					printf("\n%d %.2f %d %s inserido\n",mat,ch,nSem,nome);										
				}				
			}
			fclose(in);
		}
	}        								
    return 0;
}
