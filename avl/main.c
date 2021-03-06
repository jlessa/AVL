#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(void)
{
    int enter = 0;
	AVL *a;
	a = cria();

	while(enter != 8) {
		printf("\nDigite a opcao:\n");
		printf("1 - Inserir\n");
        	printf("2 - Retirar\n");
	        printf("3 - Limpar\n");
		printf("4 - Alterar carga horaria\n");
		printf("5 - Alterar semestre\n");
		printf("6 - Imprime arvore\n");
		printf("7 - Carregar arquivo\n");
		printf("8 - Sair\n");
		scanf("%d",&enter);
		if(enter == 1){
			int m,nSem;
			float ch;
            char nome[50];
			printf("\nDigite os dados\n");
			printf("Matricula:");
			scanf("%d",&m);
			printf("Carga Horaria:");
			scanf("%f",&ch);
			printf("Semestre:");
			scanf("%d",&nSem);
			printf("Nome:");
			scanf(" %49[^\n]",nome);
			a = insere(a,m,ch,nSem,nome);
		}
		if(enter == 2){
			int i;
			printf("\nDigite a matricula do aluno que deseja remover\n");
			printf("Matricula:");
			scanf("%d",&i);
			a = retira(a,i);
		}
		if(enter == 3){
			a = limpeza2(a);
		}
		if(enter == 4){
			int m;
			float ch;
			printf("\nDigite a matricula do aluno que deseja alterar a Carga Horaria e a nova Carga Horaria\n");
			printf("Matricula:");
			scanf("%d",&m);
			printf("Carga Horaria:");
			scanf("%f",&ch);
			alteraCH(a,m,ch);
		}
		if(enter == 5){
			int m,nSem;
			printf("\nDigite a matricula do aluno que deseja alterar o numero de semestres cursados e o novo numero de semestres cursados\n");
			printf("Matricula:");
			scanf("%d",&m);
			printf("Semestre:");
			scanf("%d",&nSem);
			alteraSemestre(a,m,nSem);
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
					printf("\n%d %.2f %d %s inserido",mat,ch,nSem,nome);
				}
			}
			fclose(in);
		}
	}
    return 0;
}
